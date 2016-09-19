namespace robot_test
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.delta_z_lab = new System.Windows.Forms.Label();
            this.Zbox = new System.Windows.Forms.TextBox();
            this.delta_y_lab = new System.Windows.Forms.Label();
            this.Ybox = new System.Windows.Forms.TextBox();
            this.delta_x_lab = new System.Windows.Forms.Label();
            this.Xbox = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.radiusbox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.t1lab = new System.Windows.Forms.Label();
            this.t2lab = new System.Windows.Forms.Label();
            this.t3lab = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.rodbox = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.offsetbox = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.heightbox = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.delta_z_lab);
            this.groupBox1.Controls.Add(this.Zbox);
            this.groupBox1.Controls.Add(this.delta_y_lab);
            this.groupBox1.Controls.Add(this.Ybox);
            this.groupBox1.Controls.Add(this.delta_x_lab);
            this.groupBox1.Controls.Add(this.Xbox);
            this.groupBox1.Controls.Add(this.label11);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label12);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label13);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(14, 118);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(329, 116);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "笛卡尔坐标";
            // 
            // delta_z_lab
            // 
            this.delta_z_lab.AutoSize = true;
            this.delta_z_lab.Location = new System.Drawing.Point(209, 80);
            this.delta_z_lab.Name = "delta_z_lab";
            this.delta_z_lab.Size = new System.Drawing.Size(11, 12);
            this.delta_z_lab.TabIndex = 18;
            this.delta_z_lab.Text = "0";
            // 
            // Zbox
            // 
            this.Zbox.Location = new System.Drawing.Point(39, 83);
            this.Zbox.Name = "Zbox";
            this.Zbox.Size = new System.Drawing.Size(86, 21);
            this.Zbox.TabIndex = 5;
            this.Zbox.Text = "0";
            this.Zbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textbox_KeyDown);
            // 
            // delta_y_lab
            // 
            this.delta_y_lab.AutoSize = true;
            this.delta_y_lab.Location = new System.Drawing.Point(209, 59);
            this.delta_y_lab.Name = "delta_y_lab";
            this.delta_y_lab.Size = new System.Drawing.Size(11, 12);
            this.delta_y_lab.TabIndex = 17;
            this.delta_y_lab.Text = "0";
            // 
            // Ybox
            // 
            this.Ybox.Location = new System.Drawing.Point(39, 56);
            this.Ybox.Name = "Ybox";
            this.Ybox.Size = new System.Drawing.Size(86, 21);
            this.Ybox.TabIndex = 4;
            this.Ybox.Text = "0";
            this.Ybox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textbox_KeyDown);
            // 
            // delta_x_lab
            // 
            this.delta_x_lab.AutoSize = true;
            this.delta_x_lab.Location = new System.Drawing.Point(209, 38);
            this.delta_x_lab.Name = "delta_x_lab";
            this.delta_x_lab.Size = new System.Drawing.Size(11, 12);
            this.delta_x_lab.TabIndex = 16;
            this.delta_x_lab.Text = "0";
            // 
            // Xbox
            // 
            this.Xbox.Location = new System.Drawing.Point(39, 29);
            this.Xbox.Name = "Xbox";
            this.Xbox.Size = new System.Drawing.Size(86, 21);
            this.Xbox.TabIndex = 3;
            this.Xbox.Text = "0";
            this.Xbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textbox_KeyDown);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(131, 80);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(59, 12);
            this.label11.TabIndex = 15;
            this.label11.Text = "delta[Z]:";
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
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(131, 59);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(59, 12);
            this.label12.TabIndex = 14;
            this.label12.Text = "delta[Y]:";
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
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(131, 38);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(59, 12);
            this.label13.TabIndex = 13;
            this.label13.Text = "delta[X]:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(16, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(17, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "X:";
            // 
            // radiusbox
            // 
            this.radiusbox.Location = new System.Drawing.Point(53, 18);
            this.radiusbox.Name = "radiusbox";
            this.radiusbox.Size = new System.Drawing.Size(86, 21);
            this.radiusbox.TabIndex = 6;
            this.radiusbox.Text = "127.017";
            this.radiusbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.radiusbox_KeyDown);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 21);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 12);
            this.label4.TabIndex = 6;
            this.label4.Text = "半径：";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 50);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(53, 12);
            this.label5.TabIndex = 7;
            this.label5.Text = "T1坐标：";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(12, 71);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(53, 12);
            this.label6.TabIndex = 8;
            this.label6.Text = "T2坐标：";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(12, 92);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 12);
            this.label7.TabIndex = 9;
            this.label7.Text = "T3坐标：";
            // 
            // t1lab
            // 
            this.t1lab.AutoSize = true;
            this.t1lab.Location = new System.Drawing.Point(90, 50);
            this.t1lab.Name = "t1lab";
            this.t1lab.Size = new System.Drawing.Size(23, 12);
            this.t1lab.TabIndex = 10;
            this.t1lab.Text = "(,)";
            // 
            // t2lab
            // 
            this.t2lab.AutoSize = true;
            this.t2lab.Location = new System.Drawing.Point(90, 71);
            this.t2lab.Name = "t2lab";
            this.t2lab.Size = new System.Drawing.Size(23, 12);
            this.t2lab.TabIndex = 11;
            this.t2lab.Text = "(,)";
            // 
            // t3lab
            // 
            this.t3lab.AutoSize = true;
            this.t3lab.Location = new System.Drawing.Point(90, 92);
            this.t3lab.Name = "t3lab";
            this.t3lab.Size = new System.Drawing.Size(23, 12);
            this.t3lab.TabIndex = 12;
            this.t3lab.Text = "(,)";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(145, 21);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(53, 12);
            this.label8.TabIndex = 13;
            this.label8.Text = "杆长度：";
            // 
            // rodbox
            // 
            this.rodbox.Location = new System.Drawing.Point(204, 18);
            this.rodbox.Name = "rodbox";
            this.rodbox.Size = new System.Drawing.Size(86, 21);
            this.rodbox.TabIndex = 14;
            this.rodbox.Text = "216";
            this.rodbox.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            this.rodbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.radiusbox_KeyDown);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(299, 21);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(89, 12);
            this.label9.TabIndex = 15;
            this.label9.Text = "平台中心到杆：";
            // 
            // offsetbox
            // 
            this.offsetbox.Location = new System.Drawing.Point(394, 18);
            this.offsetbox.Name = "offsetbox";
            this.offsetbox.Size = new System.Drawing.Size(86, 21);
            this.offsetbox.TabIndex = 16;
            this.offsetbox.Text = "35";
            this.offsetbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.radiusbox_KeyDown);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(347, 50);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(41, 12);
            this.label10.TabIndex = 17;
            this.label10.Text = "高度：";
            // 
            // heightbox
            // 
            this.heightbox.Location = new System.Drawing.Point(394, 45);
            this.heightbox.Name = "heightbox";
            this.heightbox.Size = new System.Drawing.Size(86, 21);
            this.heightbox.TabIndex = 18;
            this.heightbox.Text = "100";
            this.heightbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.radiusbox_KeyDown);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(525, 267);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.heightbox);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.offsetbox);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.rodbox);
            this.Controls.Add(this.t3lab);
            this.Controls.Add(this.t2lab);
            this.Controls.Add(this.t1lab);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.radiusbox);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox Zbox;
        private System.Windows.Forms.TextBox Ybox;
        private System.Windows.Forms.TextBox Xbox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox radiusbox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label t1lab;
        private System.Windows.Forms.Label t2lab;
        private System.Windows.Forms.Label t3lab;
        private System.Windows.Forms.Label delta_z_lab;
        private System.Windows.Forms.Label delta_y_lab;
        private System.Windows.Forms.Label delta_x_lab;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox rodbox;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox offsetbox;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox heightbox;
    }
}

