using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace Pulse
{
    public partial class Form1 : Form
    {
        wifipact wifi = new wifipact(System.Enum.GetNames(typeof(SetCmd)).Length, System.Enum.GetNames(typeof(GetCmd)).Length);

        enum GetCmd
        {
            All = 0,
        }
        enum SetCmd
        {
            EnumF=0,
            Enumcconxyz,
            EnumReset,
            Enumxyz,
            EnumDCRxyz,
            EnumSetting,
            EnumSetlow,
        }

        public Form1()
        {
            InitializeComponent();
        }

        void scann_ok()
        {
            Invoke(new MethodInvoker(() =>
            {
                scannbut.Text = "扫描";
                scannbut.Enabled = true;
                foreach (wifipact.EquiPmentData bufe in wifi.Equi)
                {
                    listBox1.Items.Add(bufe.num.ToString() + "  " + bufe.ip.ToString() + "  " + bufe.id.ToString());
                }
            }));
        }
        private void scannbut_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            wifi.scann(scann_ok);
            scannbut.Text = "扫描中";
            scannbut.Enabled = false;
        }


        double JQX;
        double JQY;
        double JQZ;
        double dcrX;
        double dcrY;
        double dcrZ;
        void GetAllEvent(wifipact e)
        {
            JQX = e.ReadInt32();
            JQY = e.ReadInt32();
            JQZ = e.ReadInt32();
            dcrX = e.ReadInt32();
            dcrY = e.ReadInt32();
            dcrZ = e.ReadInt32();
            JQX /= 100;
            JQY /= 100;
            JQZ /= 100;
            dcrX /= 10000;
            dcrY /= 10000;
            dcrZ /= 10000;
            Invoke(new MethodInvoker(() =>
            {
                delta_x_lab.Text = JQX.ToString();
                delta_y_lab.Text = JQY.ToString();
                delta_z_lab.Text = JQZ.ToString();
                dcr_x_lab.Text = dcrX.ToString();
                dcr_y_lab.Text = dcrY.ToString();
                dcr_z_lab.Text = dcrZ.ToString();
            }));
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            wifi.getComRegistered((byte)GetCmd.All, GetAllEvent);
            wifi.timeOutCount = 10;


        }

        bool gbut=false;
        private void getdata_Click(object sender, EventArgs e)
        {
            gbut = !gbut;
            if (gbut)
            {
                wifi.conGatCmd((byte)GetCmd.All);
                getdata.Text = "获取中";
            }
            else
            {
                wifi.stopConGatCmd((byte)GetCmd.All);
                getdata.Text = "获取数据";
            }
        }

        private void speetra_Scroll(object sender, EventArgs e)
        {

        }

        private void speedtra_Scroll(object sender, EventArgs e)
        {
            speedlab.Text = speedtra.Value.ToString();
            wifi.setData((byte)SetCmd.EnumF, (short)speedtra.Value);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            wifi.SelectEqui(listBox1.SelectedIndex);
            
        }

        byte status=0;
        byte laststatus = 0;
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.ControlKey:
                    status = 10;
                    break;
                case Keys.ShiftKey:
                    status = 9;
                    break;
                case Keys.Up:
                    status = 1;
                    break;
                case Keys.Down:
                    status = 5;
                    break;
                case Keys.Left:
                    status= 7;
                    break;
                case Keys.Right:
                    status= 3;
                    break;
            }
            if (status != laststatus)
            {
                laststatus = status;
                wifi.setData((byte)SetCmd.Enumcconxyz, (byte)status);
            }

        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.ControlKey || e.KeyCode == Keys.ShiftKey||e.KeyCode==Keys.Up||e.KeyCode==Keys.Down
                ||e.KeyCode==Keys.Left||e.KeyCode==Keys.Right)
            {
                status &= 0x00;
            }
            if (status != laststatus)
            {
                laststatus = status;
                wifi.setData((byte)SetCmd.Enumcconxyz, (byte)status);
            }
        }

        private void resetbut_Click(object sender, EventArgs e)
        {
            wifi.setData((byte)SetCmd.EnumReset);
        }

        double xdelta, ydelta, zdelta;
        double xdcr, ydcr, zdcr;

        private void setlowbut_Click(object sender, EventArgs e)
        {
            wifi.setData((byte)SetCmd.EnumSetlow);
        }

        double rod,motorD,ptorod,htorod,height;
        private void settingbox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                rod = double.Parse(rodlenbox.Text);
                motorD = double.Parse(motorDbox.Text);
                ptorod = double.Parse(ptorodbox.Text);
                htorod = double.Parse(htorodbox.Text);
                height = double.Parse(heightbox.Text);
                rod *= 1000;
                motorD *= 1000;
                ptorod *= 1000;
                htorod *= 1000;
                height *= 1000;
                wifi.setData((byte)SetCmd.EnumSetting,(int)rod, (int)motorD, (int)ptorod, (int)htorod, (int)height);
            }
        }

        private void dcrbox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                xdcr = double.Parse(Xdcrbox.Text);
                ydcr = double.Parse(Ydcrbox.Text);
                zdcr = double.Parse(Zdcrbox.Text);
                xdcr *= 100;
                ydcr *= 100;
                zdcr *= 100;

                if (g1rad.Checked)
                {
                    wifi.setData((byte)SetCmd.EnumDCRxyz,(byte)1,(int)xdcr, (int)ydcr, (int)zdcr);
                }
                else
                {
                    wifi.setData((byte)SetCmd.EnumDCRxyz, (byte)0, (int)xdcr, (int)ydcr, (int)zdcr);
                }
                
            }
        }

        private void box_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                xdelta = double.Parse(Xdeltabox.Text);
                ydelta = double.Parse(Ydeltabox.Text);
                zdelta = double.Parse(Zdeltabox.Text);
                xdelta *= 100;
                ydelta *= 100;
                zdelta *= 100;
                if (xdrad.Checked)//相对模式
                {
                    wifi.setData((byte)SetCmd.Enumxyz, (byte)1, (int)xdelta, (int)ydelta, (int)zdelta);
                }
                else
                {
                    wifi.setData((byte)SetCmd.Enumxyz,(byte)0,(int)xdelta, (int)ydelta, (int)zdelta);
                }
            }
        }
    }
}
