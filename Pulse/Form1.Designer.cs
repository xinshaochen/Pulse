namespace Pulse
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.getdata = new System.Windows.Forms.Button();
            this.scannbut = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.speedtra = new System.Windows.Forms.TrackBar();
            this.label1 = new System.Windows.Forms.Label();
            this.speedlab = new System.Windows.Forms.Label();
            this.resetbut = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.absrad = new System.Windows.Forms.RadioButton();
            this.xdrad = new System.Windows.Forms.RadioButton();
            this.delta_z_lab = new System.Windows.Forms.Label();
            this.delta_y_lab = new System.Windows.Forms.Label();
            this.delta_x_lab = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.Zdeltabox = new System.Windows.Forms.TextBox();
            this.Ydeltabox = new System.Windows.Forms.TextBox();
            this.Xdeltabox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.dcr_z_lab = new System.Windows.Forms.Label();
            this.Zdcrbox = new System.Windows.Forms.TextBox();
            this.dcr_y_lab = new System.Windows.Forms.Label();
            this.Ydcrbox = new System.Windows.Forms.TextBox();
            this.dcr_x_lab = new System.Windows.Forms.Label();
            this.Xdcrbox = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.heightbox = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.htorodbox = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.ptorodbox = new System.Windows.Forms.TextBox();
            this.motorDbox = new System.Windows.Forms.TextBox();
            this.rodlenbox = new System.Windows.Forms.TextBox();
            this.label18 = new System.Windows.Forms.Label();
            this.label20 = new System.Windows.Forms.Label();
            this.label22 = new System.Windows.Forms.Label();
            this.setlowbut = new System.Windows.Forms.Button();
            this.g1rad = new System.Windows.Forms.RadioButton();
            this.g0rad = new System.Windows.Forms.RadioButton();
            ((System.ComponentModel.ISupportInitialize)(this.speedtra)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // getdata
            // 
            this.getdata.Location = new System.Drawing.Point(197, 118);
            this.getdata.Name = "getdata";
            this.getdata.Size = new System.Drawing.Size(75, 23);
            this.getdata.TabIndex = 10;
            this.getdata.Text = "获取数据";
            this.getdata.UseVisualStyleBackColor = true;
            this.getdata.Click += new System.EventHandler(this.getdata_Click);
            // 
            // scannbut
            // 
            this.scannbut.Location = new System.Drawing.Point(12, 118);
            this.scannbut.Name = "scannbut";
            this.scannbut.Size = new System.Drawing.Size(75, 23);
            this.scannbut.TabIndex = 9;
            this.scannbut.Text = "扫描";
            this.scannbut.UseVisualStyleBackColor = true;
            this.scannbut.Click += new System.EventHandler(this.scannbut_Click);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 12;
            this.listBox1.Location = new System.Drawing.Point(12, 12);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(260, 100);
            this.listBox1.TabIndex = 8;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // speedtra
            // 
            this.speedtra.Location = new System.Drawing.Point(48, 288);
            this.speedtra.Maximum = 10000;
            this.speedtra.Name = "speedtra";
            this.speedtra.Size = new System.Drawing.Size(263, 45);
            this.speedtra.TabIndex = 11;
            this.speedtra.Value = 5000;
            this.speedtra.Scroll += new System.EventHandler(this.speedtra_Scroll);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 302);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 12;
            this.label1.Text = "Speed:";
            // 
            // speedlab
            // 
            this.speedlab.AutoSize = true;
            this.speedlab.Location = new System.Drawing.Point(317, 302);
            this.speedlab.Name = "speedlab";
            this.speedlab.Size = new System.Drawing.Size(11, 12);
            this.speedlab.TabIndex = 13;
            this.speedlab.Text = "0";
            // 
            // resetbut
            // 
            this.resetbut.Location = new System.Drawing.Point(334, 297);
            this.resetbut.Name = "resetbut";
            this.resetbut.Size = new System.Drawing.Size(75, 23);
            this.resetbut.TabIndex = 14;
            this.resetbut.Text = "复位";
            this.resetbut.UseVisualStyleBackColor = true;
            this.resetbut.Click += new System.EventHandler(this.resetbut_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.absrad);
            this.groupBox1.Controls.Add(this.xdrad);
            this.groupBox1.Controls.Add(this.delta_z_lab);
            this.groupBox1.Controls.Add(this.delta_y_lab);
            this.groupBox1.Controls.Add(this.delta_x_lab);
            this.groupBox1.Controls.Add(this.label11);
            this.groupBox1.Controls.Add(this.label12);
            this.groupBox1.Controls.Add(this.label13);
            this.groupBox1.Controls.Add(this.Zdeltabox);
            this.groupBox1.Controls.Add(this.Ydeltabox);
            this.groupBox1.Controls.Add(this.Xdeltabox);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Location = new System.Drawing.Point(278, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(303, 139);
            this.groupBox1.TabIndex = 15;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Delta";
            // 
            // absrad
            // 
            this.absrad.AutoSize = true;
            this.absrad.Checked = true;
            this.absrad.Location = new System.Drawing.Point(95, 113);
            this.absrad.Name = "absrad";
            this.absrad.Size = new System.Drawing.Size(71, 16);
            this.absrad.TabIndex = 25;
            this.absrad.TabStop = true;
            this.absrad.Text = "绝对模式";
            this.absrad.UseVisualStyleBackColor = true;
            // 
            // xdrad
            // 
            this.xdrad.AutoSize = true;
            this.xdrad.Location = new System.Drawing.Point(18, 113);
            this.xdrad.Name = "xdrad";
            this.xdrad.Size = new System.Drawing.Size(71, 16);
            this.xdrad.TabIndex = 16;
            this.xdrad.Text = "相对模式";
            this.xdrad.UseVisualStyleBackColor = true;
            // 
            // delta_z_lab
            // 
            this.delta_z_lab.AutoSize = true;
            this.delta_z_lab.Location = new System.Drawing.Point(209, 80);
            this.delta_z_lab.Name = "delta_z_lab";
            this.delta_z_lab.Size = new System.Drawing.Size(11, 12);
            this.delta_z_lab.TabIndex = 24;
            this.delta_z_lab.Text = "0";
            // 
            // delta_y_lab
            // 
            this.delta_y_lab.AutoSize = true;
            this.delta_y_lab.Location = new System.Drawing.Point(209, 59);
            this.delta_y_lab.Name = "delta_y_lab";
            this.delta_y_lab.Size = new System.Drawing.Size(11, 12);
            this.delta_y_lab.TabIndex = 23;
            this.delta_y_lab.Text = "0";
            // 
            // delta_x_lab
            // 
            this.delta_x_lab.AutoSize = true;
            this.delta_x_lab.Location = new System.Drawing.Point(209, 38);
            this.delta_x_lab.Name = "delta_x_lab";
            this.delta_x_lab.Size = new System.Drawing.Size(11, 12);
            this.delta_x_lab.TabIndex = 22;
            this.delta_x_lab.Text = "0";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(131, 80);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(59, 12);
            this.label11.TabIndex = 21;
            this.label11.Text = "delta[Z]:";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(131, 59);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(59, 12);
            this.label12.TabIndex = 20;
            this.label12.Text = "delta[Y]:";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(131, 38);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(59, 12);
            this.label13.TabIndex = 19;
            this.label13.Text = "delta[X]:";
            // 
            // Zdeltabox
            // 
            this.Zdeltabox.Location = new System.Drawing.Point(39, 83);
            this.Zdeltabox.Name = "Zdeltabox";
            this.Zdeltabox.Size = new System.Drawing.Size(86, 21);
            this.Zdeltabox.TabIndex = 5;
            this.Zdeltabox.Text = "0";
            this.Zdeltabox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.box_KeyDown);
            // 
            // Ydeltabox
            // 
            this.Ydeltabox.Location = new System.Drawing.Point(39, 56);
            this.Ydeltabox.Name = "Ydeltabox";
            this.Ydeltabox.Size = new System.Drawing.Size(86, 21);
            this.Ydeltabox.TabIndex = 4;
            this.Ydeltabox.Text = "0";
            this.Ydeltabox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.box_KeyDown);
            // 
            // Xdeltabox
            // 
            this.Xdeltabox.Location = new System.Drawing.Point(39, 29);
            this.Xdeltabox.Name = "Xdeltabox";
            this.Xdeltabox.Size = new System.Drawing.Size(86, 21);
            this.Xdeltabox.TabIndex = 3;
            this.Xdeltabox.Text = "0";
            this.Xdeltabox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.box_KeyDown);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(16, 86);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(17, 12);
            this.label3.TabIndex = 2;
            this.label3.Text = "Z:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(16, 59);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(17, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "Y:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(16, 32);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(17, 12);
            this.label4.TabIndex = 0;
            this.label4.Text = "X:";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.g1rad);
            this.groupBox2.Controls.Add(this.g0rad);
            this.groupBox2.Controls.Add(this.dcr_z_lab);
            this.groupBox2.Controls.Add(this.Zdcrbox);
            this.groupBox2.Controls.Add(this.dcr_y_lab);
            this.groupBox2.Controls.Add(this.Ydcrbox);
            this.groupBox2.Controls.Add(this.dcr_x_lab);
            this.groupBox2.Controls.Add(this.Xdcrbox);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.label10);
            this.groupBox2.Controls.Add(this.label14);
            this.groupBox2.Controls.Add(this.label15);
            this.groupBox2.Controls.Add(this.label16);
            this.groupBox2.Location = new System.Drawing.Point(278, 157);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(303, 134);
            this.groupBox2.TabIndex = 16;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "笛卡尔坐标";
            // 
            // dcr_z_lab
            // 
            this.dcr_z_lab.AutoSize = true;
            this.dcr_z_lab.Location = new System.Drawing.Point(173, 80);
            this.dcr_z_lab.Name = "dcr_z_lab";
            this.dcr_z_lab.Size = new System.Drawing.Size(11, 12);
            this.dcr_z_lab.TabIndex = 18;
            this.dcr_z_lab.Text = "0";
            // 
            // Zdcrbox
            // 
            this.Zdcrbox.Location = new System.Drawing.Point(39, 83);
            this.Zdcrbox.Name = "Zdcrbox";
            this.Zdcrbox.Size = new System.Drawing.Size(86, 21);
            this.Zdcrbox.TabIndex = 5;
            this.Zdcrbox.Text = "0";
            this.Zdcrbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.dcrbox_KeyDown);
            // 
            // dcr_y_lab
            // 
            this.dcr_y_lab.AutoSize = true;
            this.dcr_y_lab.Location = new System.Drawing.Point(173, 59);
            this.dcr_y_lab.Name = "dcr_y_lab";
            this.dcr_y_lab.Size = new System.Drawing.Size(11, 12);
            this.dcr_y_lab.TabIndex = 17;
            this.dcr_y_lab.Text = "0";
            // 
            // Ydcrbox
            // 
            this.Ydcrbox.Location = new System.Drawing.Point(39, 56);
            this.Ydcrbox.Name = "Ydcrbox";
            this.Ydcrbox.Size = new System.Drawing.Size(86, 21);
            this.Ydcrbox.TabIndex = 4;
            this.Ydcrbox.Text = "0";
            this.Ydcrbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.dcrbox_KeyDown);
            // 
            // dcr_x_lab
            // 
            this.dcr_x_lab.AutoSize = true;
            this.dcr_x_lab.Location = new System.Drawing.Point(173, 38);
            this.dcr_x_lab.Name = "dcr_x_lab";
            this.dcr_x_lab.Size = new System.Drawing.Size(11, 12);
            this.dcr_x_lab.TabIndex = 16;
            this.dcr_x_lab.Text = "0";
            // 
            // Xdcrbox
            // 
            this.Xdcrbox.Location = new System.Drawing.Point(39, 29);
            this.Xdcrbox.Name = "Xdcrbox";
            this.Xdcrbox.Size = new System.Drawing.Size(86, 21);
            this.Xdcrbox.TabIndex = 3;
            this.Xdcrbox.Text = "0";
            this.Xdcrbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.dcrbox_KeyDown);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(131, 80);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(17, 12);
            this.label8.TabIndex = 15;
            this.label8.Text = "Z:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(16, 86);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(17, 12);
            this.label9.TabIndex = 2;
            this.label9.Text = "Z:";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(131, 59);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(17, 12);
            this.label10.TabIndex = 14;
            this.label10.Text = "Y:";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(16, 59);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(17, 12);
            this.label14.TabIndex = 1;
            this.label14.Text = "Y:";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(131, 38);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(17, 12);
            this.label15.TabIndex = 13;
            this.label15.Text = "X:";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(16, 32);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(17, 12);
            this.label16.TabIndex = 0;
            this.label16.Text = "X:";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.heightbox);
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Controls.Add(this.htorodbox);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Controls.Add(this.ptorodbox);
            this.groupBox3.Controls.Add(this.motorDbox);
            this.groupBox3.Controls.Add(this.rodlenbox);
            this.groupBox3.Controls.Add(this.label18);
            this.groupBox3.Controls.Add(this.label20);
            this.groupBox3.Controls.Add(this.label22);
            this.groupBox3.Location = new System.Drawing.Point(587, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(88, 279);
            this.groupBox3.TabIndex = 19;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "设置 ";
            // 
            // heightbox
            // 
            this.heightbox.Location = new System.Drawing.Point(6, 200);
            this.heightbox.Name = "heightbox";
            this.heightbox.Size = new System.Drawing.Size(58, 21);
            this.heightbox.TabIndex = 9;
            this.heightbox.Text = "100";
            this.heightbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.settingbox_KeyDown);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 185);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(41, 12);
            this.label6.TabIndex = 8;
            this.label6.Text = "高度：";
            // 
            // htorodbox
            // 
            this.htorodbox.Location = new System.Drawing.Point(6, 161);
            this.htorodbox.Name = "htorodbox";
            this.htorodbox.Size = new System.Drawing.Size(58, 21);
            this.htorodbox.TabIndex = 7;
            this.htorodbox.Text = "0";
            this.htorodbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.settingbox_KeyDown);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(6, 146);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(77, 12);
            this.label5.TabIndex = 6;
            this.label5.Text = "滑台到杆长：";
            // 
            // ptorodbox
            // 
            this.ptorodbox.Location = new System.Drawing.Point(6, 122);
            this.ptorodbox.Name = "ptorodbox";
            this.ptorodbox.Size = new System.Drawing.Size(58, 21);
            this.ptorodbox.TabIndex = 5;
            this.ptorodbox.Text = "35";
            this.ptorodbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.settingbox_KeyDown);
            // 
            // motorDbox
            // 
            this.motorDbox.Location = new System.Drawing.Point(6, 83);
            this.motorDbox.Name = "motorDbox";
            this.motorDbox.Size = new System.Drawing.Size(58, 21);
            this.motorDbox.TabIndex = 4;
            this.motorDbox.Text = "127.017";
            this.motorDbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.settingbox_KeyDown);
            // 
            // rodlenbox
            // 
            this.rodlenbox.Location = new System.Drawing.Point(6, 44);
            this.rodlenbox.Name = "rodlenbox";
            this.rodlenbox.Size = new System.Drawing.Size(58, 21);
            this.rodlenbox.TabIndex = 3;
            this.rodlenbox.Text = "216";
            this.rodlenbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.settingbox_KeyDown);
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(6, 107);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(77, 12);
            this.label18.TabIndex = 2;
            this.label18.Text = "平台到杆长：";
            // 
            // label20
            // 
            this.label20.AutoSize = true;
            this.label20.Location = new System.Drawing.Point(6, 68);
            this.label20.Name = "label20";
            this.label20.Size = new System.Drawing.Size(65, 12);
            this.label20.TabIndex = 1;
            this.label20.Text = "电机半径：";
            // 
            // label22
            // 
            this.label22.AutoSize = true;
            this.label22.Location = new System.Drawing.Point(6, 29);
            this.label22.Name = "label22";
            this.label22.Size = new System.Drawing.Size(41, 12);
            this.label22.TabIndex = 0;
            this.label22.Text = "杆长：";
            // 
            // setlowbut
            // 
            this.setlowbut.Location = new System.Drawing.Point(600, 297);
            this.setlowbut.Name = "setlowbut";
            this.setlowbut.Size = new System.Drawing.Size(75, 23);
            this.setlowbut.TabIndex = 20;
            this.setlowbut.Text = "置底";
            this.setlowbut.UseVisualStyleBackColor = true;
            this.setlowbut.Click += new System.EventHandler(this.setlowbut_Click);
            // 
            // g1rad
            // 
            this.g1rad.AutoSize = true;
            this.g1rad.Checked = true;
            this.g1rad.Location = new System.Drawing.Point(59, 109);
            this.g1rad.Name = "g1rad";
            this.g1rad.Size = new System.Drawing.Size(35, 16);
            this.g1rad.TabIndex = 27;
            this.g1rad.TabStop = true;
            this.g1rad.Text = "G1";
            this.g1rad.UseVisualStyleBackColor = true;
            // 
            // g0rad
            // 
            this.g0rad.AutoSize = true;
            this.g0rad.Location = new System.Drawing.Point(18, 109);
            this.g0rad.Name = "g0rad";
            this.g0rad.Size = new System.Drawing.Size(35, 16);
            this.g0rad.TabIndex = 26;
            this.g0rad.Text = "G0";
            this.g0rad.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(683, 341);
            this.Controls.Add(this.setlowbut);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.resetbut);
            this.Controls.Add(this.speedlab);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.speedtra);
            this.Controls.Add(this.getdata);
            this.Controls.Add(this.scannbut);
            this.Controls.Add(this.listBox1);
            this.KeyPreview = true;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyUp);
            ((System.ComponentModel.ISupportInitialize)(this.speedtra)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button getdata;
        private System.Windows.Forms.Button scannbut;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.TrackBar speedtra;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label speedlab;
        private System.Windows.Forms.Button resetbut;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox Zdeltabox;
        private System.Windows.Forms.TextBox Ydeltabox;
        private System.Windows.Forms.TextBox Xdeltabox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label delta_z_lab;
        private System.Windows.Forms.Label delta_y_lab;
        private System.Windows.Forms.Label delta_x_lab;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.RadioButton absrad;
        private System.Windows.Forms.RadioButton xdrad;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label dcr_z_lab;
        private System.Windows.Forms.TextBox Zdcrbox;
        private System.Windows.Forms.Label dcr_y_lab;
        private System.Windows.Forms.TextBox Ydcrbox;
        private System.Windows.Forms.Label dcr_x_lab;
        private System.Windows.Forms.TextBox Xdcrbox;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox ptorodbox;
        private System.Windows.Forms.TextBox motorDbox;
        private System.Windows.Forms.TextBox rodlenbox;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.Label label20;
        private System.Windows.Forms.Label label22;
        private System.Windows.Forms.TextBox htorodbox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox heightbox;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button setlowbut;
        private System.Windows.Forms.RadioButton g1rad;
        private System.Windows.Forms.RadioButton g0rad;
    }
}

