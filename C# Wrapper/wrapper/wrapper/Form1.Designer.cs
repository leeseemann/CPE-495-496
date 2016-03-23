namespace wrapper
{
    partial class Form1
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
            this.startButton = new System.Windows.Forms.Button();
            this.endButton = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.profileStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.lengthStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.colorStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.quantityStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // startButton
            // 
            this.startButton.Location = new System.Drawing.Point(190, 147);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(180, 47);
            this.startButton.TabIndex = 0;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // endButton
            // 
            this.endButton.Location = new System.Drawing.Point(402, 147);
            this.endButton.Name = "endButton";
            this.endButton.Size = new System.Drawing.Size(180, 47);
            this.endButton.TabIndex = 1;
            this.endButton.Text = "End";
            this.endButton.UseVisualStyleBackColor = true;
            this.endButton.Click += new System.EventHandler(this.endButton_Click);

            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(0, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(100, 23);
            this.label1.TabIndex = 5;
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.profileStatus,
            this.lengthStatus,
            this.colorStatus,
            this.quantityStatus});
            this.statusStrip1.Location = new System.Drawing.Point(0, 564);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(874, 30);
            this.statusStrip1.TabIndex = 6;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // profileStatus
            // 
            this.profileStatus.Name = "profileStatus";
            this.profileStatus.Size = new System.Drawing.Size(62, 25);
            this.profileStatus.Text = "Profile";
            this.profileStatus.Click += new System.EventHandler(this.statusLabel_Click);
            // 
            // lengthStatus
            // 
            this.lengthStatus.Name = "lengthStatus";
            this.lengthStatus.Size = new System.Drawing.Size(66, 25);
            this.lengthStatus.Text = "Length";
            // 
            // colorStatus
            // 
            this.colorStatus.Name = "colorStatus";
            this.colorStatus.Size = new System.Drawing.Size(55, 25);
            this.colorStatus.Text = "Color";
            // 
            // quantityStatus
            // 
            this.quantityStatus.Name = "quantityStatus";
            this.quantityStatus.Size = new System.Drawing.Size(80, 25);
            this.quantityStatus.Text = "Quantity";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(874, 594);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.endButton);
            this.Controls.Add(this.startButton);
            this.Name = "Form1";
            this.Text = "Form1";
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button startButton;
        private System.Windows.Forms.Button endButton;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel profileStatus;
        private System.Windows.Forms.ToolStripStatusLabel lengthStatus;
        private System.Windows.Forms.ToolStripStatusLabel colorStatus;
        private System.Windows.Forms.ToolStripStatusLabel quantityStatus;
    }
}

