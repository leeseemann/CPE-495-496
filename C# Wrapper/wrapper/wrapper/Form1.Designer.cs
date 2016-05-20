/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

Program.cs - C# wrapper which utilizes a DLL to run the C++ source code of the project

*/

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
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.profileStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.lengthStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.colorStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.quantityStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.splitter1 = new System.Windows.Forms.Splitter();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // startButton
            // 
            this.startButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.startButton.Location = new System.Drawing.Point(78, 147);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(292, 161);
            this.startButton.TabIndex = 0;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // endButton
            // 
            this.endButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.endButton.Location = new System.Drawing.Point(402, 147);
            this.endButton.Name = "endButton";
            this.endButton.Size = new System.Drawing.Size(282, 161);
            this.endButton.TabIndex = 1;
            this.endButton.Text = "End";
            this.endButton.UseVisualStyleBackColor = true;
            this.endButton.Click += new System.EventHandler(this.endButton_Click);
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.SystemColors.HotTrack;
            this.textBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.ForeColor = System.Drawing.SystemColors.InactiveBorder;
            this.textBox1.Location = new System.Drawing.Point(78, 62);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(606, 48);
            this.textBox1.TabIndex = 7;
            this.textBox1.Text = "Steelcase Answer Pack Verification";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.profileStatus,
            this.toolStripStatusLabel1,
            this.lengthStatus,
            this.colorStatus,
            this.quantityStatus});
            this.statusStrip1.Location = new System.Drawing.Point(0, 378);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(774, 50);
            this.statusStrip1.TabIndex = 6;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // profileStatus
            // 
            this.profileStatus.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.profileStatus.Font = new System.Drawing.Font("Segoe UI", 16F);
            this.profileStatus.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.profileStatus.Name = "profileStatus";
            this.profileStatus.Size = new System.Drawing.Size(111, 45);
            this.profileStatus.Text = "Profile";
            this.profileStatus.Click += new System.EventHandler(this.statusLabel_Click);
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(0, 45);
            // 
            // lengthStatus
            // 
            this.lengthStatus.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lengthStatus.Font = new System.Drawing.Font("Segoe UI", 16F);
            this.lengthStatus.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.lengthStatus.Name = "lengthStatus";
            this.lengthStatus.Size = new System.Drawing.Size(118, 45);
            this.lengthStatus.Text = "Length";
            // 
            // colorStatus
            // 
            this.colorStatus.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.colorStatus.Font = new System.Drawing.Font("Segoe UI", 16F);
            this.colorStatus.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.colorStatus.Name = "colorStatus";
            this.colorStatus.Size = new System.Drawing.Size(97, 45);
            this.colorStatus.Text = "Color";
            // 
            // quantityStatus
            // 
            this.quantityStatus.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.quantityStatus.Font = new System.Drawing.Font("Segoe UI", 16F);
            this.quantityStatus.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.quantityStatus.Name = "quantityStatus";
            this.quantityStatus.Size = new System.Drawing.Size(141, 45);
            this.quantityStatus.Text = "Quantity";
            // 
            // splitter1
            // 
            this.splitter1.Location = new System.Drawing.Point(0, 0);
            this.splitter1.Name = "splitter1";
            this.splitter1.Size = new System.Drawing.Size(3, 378);
            this.splitter1.TabIndex = 8;
            this.splitter1.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(774, 428);
            this.Controls.Add(this.splitter1);
            this.Controls.Add(this.statusStrip1);
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
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel profileStatus;
        private System.Windows.Forms.ToolStripStatusLabel lengthStatus;
        private System.Windows.Forms.ToolStripStatusLabel colorStatus;
        private System.Windows.Forms.ToolStripStatusLabel quantityStatus;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.Splitter splitter1;
    }
}

