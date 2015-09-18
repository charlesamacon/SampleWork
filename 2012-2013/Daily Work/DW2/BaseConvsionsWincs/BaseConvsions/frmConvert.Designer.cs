namespace BaseConvsions
{
    partial class frmConvert
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.cboBase = new System.Windows.Forms.ComboBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radBase10ToBase = new System.Windows.Forms.RadioButton();
            this.radBaseToTen = new System.Windows.Forms.RadioButton();
            this.label2 = new System.Windows.Forms.Label();
            this.txtNumber = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txtResult = new System.Windows.Forms.TextBox();
            this.btnConvert = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(75, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Select a base:";
            // 
            // cboBase
            // 
            this.cboBase.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cboBase.FormattingEnabled = true;
            this.cboBase.Items.AddRange(new object[] {
            "2",
            "8",
            "16"});
            this.cboBase.Location = new System.Drawing.Point(95, 13);
            this.cboBase.Name = "cboBase";
            this.cboBase.Size = new System.Drawing.Size(121, 21);
            this.cboBase.TabIndex = 1;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radBase10ToBase);
            this.groupBox1.Controls.Add(this.radBaseToTen);
            this.groupBox1.Location = new System.Drawing.Point(16, 52);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(284, 100);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Conversion";
            // 
            // radBase10ToBase
            // 
            this.radBase10ToBase.AutoSize = true;
            this.radBase10ToBase.Location = new System.Drawing.Point(7, 68);
            this.radBase10ToBase.Name = "radBase10ToBase";
            this.radBase10ToBase.Size = new System.Drawing.Size(164, 17);
            this.radBase10ToBase.TabIndex = 1;
            this.radBase10ToBase.Text = "Convert from base 10 to base";
            this.radBase10ToBase.UseVisualStyleBackColor = true;
            // 
            // radBaseToTen
            // 
            this.radBaseToTen.AutoSize = true;
            this.radBaseToTen.Checked = true;
            this.radBaseToTen.Location = new System.Drawing.Point(7, 20);
            this.radBaseToTen.Name = "radBaseToTen";
            this.radBaseToTen.Size = new System.Drawing.Size(164, 17);
            this.radBaseToTen.TabIndex = 0;
            this.radBaseToTen.TabStop = true;
            this.radBaseToTen.Text = "Convert from base to base 10";
            this.radBaseToTen.UseVisualStyleBackColor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(23, 168);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(98, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Number to convert:";
            // 
            // txtNumber
            // 
            this.txtNumber.Location = new System.Drawing.Point(139, 168);
            this.txtNumber.Name = "txtNumber";
            this.txtNumber.Size = new System.Drawing.Size(161, 20);
            this.txtNumber.TabIndex = 4;
            this.txtNumber.Tag = "Number to convert";
            this.txtNumber.Text = "\r\n";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(23, 206);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(99, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Converted Number:";
            // 
            // txtResult
            // 
            this.txtResult.Location = new System.Drawing.Point(139, 203);
            this.txtResult.Name = "txtResult";
            this.txtResult.ReadOnly = true;
            this.txtResult.Size = new System.Drawing.Size(161, 20);
            this.txtResult.TabIndex = 6;
            // 
            // btnConvert
            // 
            this.btnConvert.Location = new System.Drawing.Point(26, 256);
            this.btnConvert.Name = "btnConvert";
            this.btnConvert.Size = new System.Drawing.Size(75, 23);
            this.btnConvert.TabIndex = 7;
            this.btnConvert.Text = "Convert";
            this.btnConvert.UseVisualStyleBackColor = true;
            this.btnConvert.Click += new System.EventHandler(this.btnConvert_Click);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(126, 256);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(75, 23);
            this.btnClear.TabIndex = 8;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // btnExit
            // 
            this.btnExit.Location = new System.Drawing.Point(237, 256);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(75, 23);
            this.btnExit.TabIndex = 9;
            this.btnExit.Text = "Exit";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // frmConvert
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(395, 324);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnConvert);
            this.Controls.Add(this.txtResult);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtNumber);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.cboBase);
            this.Controls.Add(this.label1);
            this.Name = "frmConvert";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Convert numbers to/from base 10 to another base ";
            this.Load += new System.EventHandler(this.frmConvert_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cboBase;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton radBase10ToBase;
        private System.Windows.Forms.RadioButton radBaseToTen;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtNumber;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtResult;
        private System.Windows.Forms.Button btnConvert;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Button btnExit;
    }
}

