using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace robot_test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            radiusbox_KeyDown(null,new KeyEventArgs(Keys.Enter));
        }





        double dx, dy, dz;
        private void textbox_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode==Keys.Enter)
            {
                dx = double.Parse(Xbox.Text);
                dy = double.Parse(Ybox.Text);
                dz = double.Parse(Zbox.Text);

                calculate_delta(dx, dy, dz);

                delta_x_lab.Text = delta[0].ToString();
                delta_y_lab.Text = delta[1].ToString();
                delta_z_lab.Text = delta[2].ToString();
            }
        }
        double diagonal_rod;

        double delta_radius;

        double offset;

        double height;

        double offset_1_x;
        double offset_1_y;
        double offset_2_x;
        double offset_2_y;
        double offset_3_x;
        double offset_3_y;


        double delta_tower1_x;
        double delta_tower1_y;
        double delta_tower2_x;
        double delta_tower2_y;
        double delta_tower3_x;
        double delta_tower3_y;
        double delta_diagonal_rod_2;

        private void radiusbox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                delta_radius = double.Parse(radiusbox.Text);
                diagonal_rod = double.Parse(rodbox.Text);
                offset = double.Parse(offsetbox.Text);
                height = double.Parse(heightbox.Text);

                offset_1_x = -Math.Sin(Math.PI * 60 / 180) * offset;
                offset_1_y = -Math.Cos(Math.PI * 60 / 180) * offset;
                offset_2_x = Math.Sin(Math.PI * 60 / 180) * offset;
                offset_2_y = -Math.Cos(Math.PI * 60 / 180) * offset;
                offset_3_x = 0;
                offset_3_y = offset;

                delta_tower1_x = -Math.Sin(Math.PI*60/180) * delta_radius;
                delta_tower1_y = -Math.Cos(Math.PI*60/180) * delta_radius;
                t1lab.Text = "(" + delta_tower1_x.ToString()+","+ delta_tower1_y.ToString()+")";
                delta_tower2_x = Math.Sin(Math.PI * 60 / 180) * delta_radius;
                delta_tower2_y = -Math.Cos(Math.PI * 60 / 180) * delta_radius;
                t2lab.Text = "(" + delta_tower2_x.ToString() + "," + delta_tower2_y.ToString() + ")";
                delta_tower3_x = 0;
                delta_tower3_y = delta_radius;
                t3lab.Text = "(" + delta_tower3_x.ToString() + "," + delta_tower3_y.ToString() + ")";
                delta_diagonal_rod_2 = Math.Pow(diagonal_rod, 2);
            }  
        }




        double[] delta=new double[3] { 0,0,0};

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        double Z_CALC_OFFSET = 100;

     


        public void calculate_delta(double x,double y, double z)
        {
            //delta[0] = Math.Sqrt(delta_diagonal_rod_2
            //    - Math.Pow(delta_tower1_x - x, 2)
            //    - Math.Pow((delta_tower1_y - y), 2)
            //    ) + z;
            //delta[1] = Math.Sqrt(delta_diagonal_rod_2
            //    - Math.Pow(delta_tower2_x - x, 2)
            //    - Math.Pow(delta_tower2_y - y, 2)
            //    ) + z;
            //delta[2] = Math.Sqrt(delta_diagonal_rod_2
            //    - Math.Pow(delta_tower3_x - x, 2)
            //    - Math.Pow(delta_tower3_y - y, 2)
            //    ) + z;

            delta[0] = Math.Sqrt(delta_diagonal_rod_2
                - Math.Pow(delta_tower1_x - x - offset_1_x, 2)
                - Math.Pow((delta_tower1_y - y - offset_1_y), 2)
                ) + z;
            delta[1] = Math.Sqrt(delta_diagonal_rod_2
                - Math.Pow(delta_tower2_x - x - offset_2_x, 2)
                - Math.Pow(delta_tower2_y - y - offset_2_y, 2)
                ) + z;
            delta[2] = Math.Sqrt(delta_diagonal_rod_2
                - Math.Pow(delta_tower3_x - x - offset_3_x, 2)
                - Math.Pow(delta_tower3_y - y - offset_3_y, 2)
                ) + z;
        }

        //public int delta_calcAngleYZ(double x0,double y0,double z0,ref double[] theta)
        //{
            
        //}
    }
}
