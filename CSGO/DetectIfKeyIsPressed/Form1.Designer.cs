
namespace DetectIfKeyIsPressed
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.lblKdrDefictValue = new System.Windows.Forms.Label();
            this.lblKdrDefictLabel = new System.Windows.Forms.Label();
            this.txtTargetKDR = new System.Windows.Forms.TextBox();
            this.lblKdrValue = new System.Windows.Forms.Label();
            this.lblKdrLabel = new System.Windows.Forms.Label();
            this.txtKills = new System.Windows.Forms.TextBox();
            this.txtDeaths = new System.Windows.Forms.TextBox();
            this.lblKills = new System.Windows.Forms.Label();
            this.lblDeaths = new System.Windows.Forms.Label();
            this.lblTargetKdr = new System.Windows.Forms.Label();
            this.btnApply = new System.Windows.Forms.Button();
            this.btnReset = new System.Windows.Forms.Button();
            this.btnKills = new System.Windows.Forms.Button();
            this.btnDeaths = new System.Windows.Forms.Button();
            this.btnFeedBack = new System.Windows.Forms.Button();
            this.btnBinds = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            this.lblDummy = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblKdrDefictValue
            // 
            this.lblKdrDefictValue.AutoSize = true;
            this.lblKdrDefictValue.Font = new System.Drawing.Font("Bahnschrift", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblKdrDefictValue.ForeColor = System.Drawing.Color.White;
            this.lblKdrDefictValue.Location = new System.Drawing.Point(160, 127);
            this.lblKdrDefictValue.Name = "lblKdrDefictValue";
            this.lblKdrDefictValue.Size = new System.Drawing.Size(35, 18);
            this.lblKdrDefictValue.TabIndex = 1;
            this.lblKdrDefictValue.Text = "TBA";
            // 
            // lblKdrDefictLabel
            // 
            this.lblKdrDefictLabel.AutoSize = true;
            this.lblKdrDefictLabel.Font = new System.Drawing.Font("Bahnschrift", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblKdrDefictLabel.ForeColor = System.Drawing.Color.White;
            this.lblKdrDefictLabel.Location = new System.Drawing.Point(12, 127);
            this.lblKdrDefictLabel.Name = "lblKdrDefictLabel";
            this.lblKdrDefictLabel.Size = new System.Drawing.Size(148, 18);
            this.lblKdrDefictLabel.TabIndex = 2;
            this.lblKdrDefictLabel.Text = "Kills to Reach Target:";
            // 
            // txtTargetKDR
            // 
            this.txtTargetKDR.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.txtTargetKDR.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtTargetKDR.Font = new System.Drawing.Font("Bahnschrift", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtTargetKDR.ForeColor = System.Drawing.Color.White;
            this.txtTargetKDR.Location = new System.Drawing.Point(154, 64);
            this.txtTargetKDR.Name = "txtTargetKDR";
            this.txtTargetKDR.Size = new System.Drawing.Size(36, 25);
            this.txtTargetKDR.TabIndex = 3;
            this.txtTargetKDR.Text = "0";
            this.txtTargetKDR.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtTargetKDR.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtTargetKDR_KeyDown);
            // 
            // lblKdrValue
            // 
            this.lblKdrValue.AutoSize = true;
            this.lblKdrValue.Font = new System.Drawing.Font("Bahnschrift", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblKdrValue.ForeColor = System.Drawing.Color.White;
            this.lblKdrValue.Location = new System.Drawing.Point(51, 99);
            this.lblKdrValue.Name = "lblKdrValue";
            this.lblKdrValue.Size = new System.Drawing.Size(35, 18);
            this.lblKdrValue.TabIndex = 4;
            this.lblKdrValue.Text = "0.00";
            // 
            // lblKdrLabel
            // 
            this.lblKdrLabel.AutoSize = true;
            this.lblKdrLabel.Font = new System.Drawing.Font("Bahnschrift", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblKdrLabel.ForeColor = System.Drawing.Color.White;
            this.lblKdrLabel.Location = new System.Drawing.Point(12, 99);
            this.lblKdrLabel.Name = "lblKdrLabel";
            this.lblKdrLabel.Size = new System.Drawing.Size(41, 18);
            this.lblKdrLabel.TabIndex = 5;
            this.lblKdrLabel.Text = "KDR:";
            // 
            // txtKills
            // 
            this.txtKills.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.txtKills.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtKills.Font = new System.Drawing.Font("Bahnschrift", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtKills.ForeColor = System.Drawing.Color.White;
            this.txtKills.Location = new System.Drawing.Point(154, 8);
            this.txtKills.Name = "txtKills";
            this.txtKills.Size = new System.Drawing.Size(36, 25);
            this.txtKills.TabIndex = 6;
            this.txtKills.TabStop = false;
            this.txtKills.Text = "0";
            this.txtKills.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // txtDeaths
            // 
            this.txtDeaths.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.txtDeaths.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtDeaths.Font = new System.Drawing.Font("Bahnschrift", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtDeaths.ForeColor = System.Drawing.Color.White;
            this.txtDeaths.Location = new System.Drawing.Point(154, 36);
            this.txtDeaths.Name = "txtDeaths";
            this.txtDeaths.Size = new System.Drawing.Size(36, 25);
            this.txtDeaths.TabIndex = 7;
            this.txtDeaths.TabStop = false;
            this.txtDeaths.Text = "0";
            this.txtDeaths.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lblKills
            // 
            this.lblKills.AutoSize = true;
            this.lblKills.Font = new System.Drawing.Font("Bahnschrift", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblKills.ForeColor = System.Drawing.Color.White;
            this.lblKills.Location = new System.Drawing.Point(12, 15);
            this.lblKills.Name = "lblKills";
            this.lblKills.Size = new System.Drawing.Size(41, 18);
            this.lblKills.TabIndex = 9;
            this.lblKills.Text = "Kills:";
            // 
            // lblDeaths
            // 
            this.lblDeaths.AutoSize = true;
            this.lblDeaths.Font = new System.Drawing.Font("Bahnschrift", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDeaths.ForeColor = System.Drawing.Color.White;
            this.lblDeaths.Location = new System.Drawing.Point(12, 43);
            this.lblDeaths.Name = "lblDeaths";
            this.lblDeaths.Size = new System.Drawing.Size(58, 18);
            this.lblDeaths.TabIndex = 10;
            this.lblDeaths.Text = "Deaths:";
            // 
            // lblTargetKdr
            // 
            this.lblTargetKdr.AutoSize = true;
            this.lblTargetKdr.Font = new System.Drawing.Font("Bahnschrift", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTargetKdr.ForeColor = System.Drawing.Color.White;
            this.lblTargetKdr.Location = new System.Drawing.Point(12, 71);
            this.lblTargetKdr.Name = "lblTargetKdr";
            this.lblTargetKdr.Size = new System.Drawing.Size(86, 18);
            this.lblTargetKdr.TabIndex = 11;
            this.lblTargetKdr.Text = "Target KDR:";
            // 
            // btnApply
            // 
            this.btnApply.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.btnApply.FlatAppearance.BorderSize = 0;
            this.btnApply.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnApply.Font = new System.Drawing.Font("Bahnschrift", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnApply.Location = new System.Drawing.Point(20, 154);
            this.btnApply.Name = "btnApply";
            this.btnApply.Size = new System.Drawing.Size(73, 23);
            this.btnApply.TabIndex = 12;
            this.btnApply.TabStop = false;
            this.btnApply.Text = "Apply";
            this.btnApply.UseVisualStyleBackColor = false;
            this.btnApply.Click += new System.EventHandler(this.btnApply_Click);
            // 
            // btnReset
            // 
            this.btnReset.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.btnReset.FlatAppearance.BorderSize = 0;
            this.btnReset.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnReset.Font = new System.Drawing.Font("Bahnschrift", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnReset.Location = new System.Drawing.Point(114, 154);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(73, 23);
            this.btnReset.TabIndex = 13;
            this.btnReset.TabStop = false;
            this.btnReset.Text = "Reset";
            this.btnReset.UseVisualStyleBackColor = false;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // btnKills
            // 
            this.btnKills.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.btnKills.FlatAppearance.BorderSize = 0;
            this.btnKills.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnKills.Font = new System.Drawing.Font("Bahnschrift", 10F, System.Drawing.FontStyle.Bold);
            this.btnKills.Location = new System.Drawing.Point(23, 29);
            this.btnKills.Name = "btnKills";
            this.btnKills.Size = new System.Drawing.Size(160, 29);
            this.btnKills.TabIndex = 14;
            this.btnKills.TabStop = false;
            this.btnKills.Text = "Bind Kills (Space)";
            this.btnKills.UseVisualStyleBackColor = false;
            this.btnKills.Visible = false;
            this.btnKills.Click += new System.EventHandler(this.btnKills_Click);
            this.btnKills.KeyDown += new System.Windows.Forms.KeyEventHandler(this.btnKills_KeyDown);
            this.btnKills.Leave += new System.EventHandler(this.btnKills_Leave);
            // 
            // btnDeaths
            // 
            this.btnDeaths.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.btnDeaths.FlatAppearance.BorderSize = 0;
            this.btnDeaths.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnDeaths.Font = new System.Drawing.Font("Bahnschrift", 10F, System.Drawing.FontStyle.Bold);
            this.btnDeaths.Location = new System.Drawing.Point(23, 67);
            this.btnDeaths.Name = "btnDeaths";
            this.btnDeaths.Size = new System.Drawing.Size(160, 29);
            this.btnDeaths.TabIndex = 15;
            this.btnDeaths.TabStop = false;
            this.btnDeaths.Text = "Bind Deaths (F)";
            this.btnDeaths.UseVisualStyleBackColor = false;
            this.btnDeaths.Visible = false;
            this.btnDeaths.Click += new System.EventHandler(this.btnDeaths_Click);
            this.btnDeaths.KeyDown += new System.Windows.Forms.KeyEventHandler(this.btnDeaths_KeyDown);
            this.btnDeaths.Leave += new System.EventHandler(this.btnDeaths_Leave);
            // 
            // btnFeedBack
            // 
            this.btnFeedBack.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.btnFeedBack.FlatAppearance.BorderSize = 0;
            this.btnFeedBack.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnFeedBack.Font = new System.Drawing.Font("Bahnschrift", 10F, System.Drawing.FontStyle.Bold);
            this.btnFeedBack.Location = new System.Drawing.Point(23, 105);
            this.btnFeedBack.Name = "btnFeedBack";
            this.btnFeedBack.Size = new System.Drawing.Size(160, 29);
            this.btnFeedBack.TabIndex = 16;
            this.btnFeedBack.TabStop = false;
            this.btnFeedBack.Text = "Bind FeedBack (4)";
            this.btnFeedBack.UseVisualStyleBackColor = false;
            this.btnFeedBack.Visible = false;
            this.btnFeedBack.Click += new System.EventHandler(this.btnFeedBack_Click);
            this.btnFeedBack.KeyDown += new System.Windows.Forms.KeyEventHandler(this.btnFeedBack_KeyDown);
            this.btnFeedBack.Leave += new System.EventHandler(this.btnFeedBack_Leave);
            // 
            // btnBinds
            // 
            this.btnBinds.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.btnBinds.FlatAppearance.BorderSize = 0;
            this.btnBinds.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnBinds.Font = new System.Drawing.Font("Bahnschrift", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnBinds.Location = new System.Drawing.Point(66, 185);
            this.btnBinds.Name = "btnBinds";
            this.btnBinds.Size = new System.Drawing.Size(75, 23);
            this.btnBinds.TabIndex = 17;
            this.btnBinds.TabStop = false;
            this.btnBinds.Text = "Binds Menu";
            this.btnBinds.UseVisualStyleBackColor = false;
            this.btnBinds.Click += new System.EventHandler(this.btnBinds_Click);
            // 
            // btnExit
            // 
            this.btnExit.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.btnExit.FlatAppearance.BorderSize = 0;
            this.btnExit.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnExit.Font = new System.Drawing.Font("Bahnschrift", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnExit.Location = new System.Drawing.Point(66, 185);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(75, 23);
            this.btnExit.TabIndex = 18;
            this.btnExit.TabStop = false;
            this.btnExit.Text = "Exit";
            this.btnExit.UseVisualStyleBackColor = false;
            this.btnExit.Visible = false;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // lblDummy
            // 
            this.lblDummy.AutoSize = true;
            this.lblDummy.Location = new System.Drawing.Point(93, 113);
            this.lblDummy.Name = "lblDummy";
            this.lblDummy.Size = new System.Drawing.Size(0, 13);
            this.lblDummy.TabIndex = 19;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.ClientSize = new System.Drawing.Size(204, 219);
            this.Controls.Add(this.lblDummy);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.btnApply);
            this.Controls.Add(this.lblTargetKdr);
            this.Controls.Add(this.lblDeaths);
            this.Controls.Add(this.lblKills);
            this.Controls.Add(this.txtDeaths);
            this.Controls.Add(this.txtKills);
            this.Controls.Add(this.lblKdrLabel);
            this.Controls.Add(this.lblKdrValue);
            this.Controls.Add(this.txtTargetKDR);
            this.Controls.Add(this.lblKdrDefictValue);
            this.Controls.Add(this.lblKdrDefictLabel);
            this.Controls.Add(this.btnFeedBack);
            this.Controls.Add(this.btnDeaths);
            this.Controls.Add(this.btnKills);
            this.Controls.Add(this.btnBinds);
            this.Controls.Add(this.btnExit);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximumSize = new System.Drawing.Size(220, 258);
            this.MinimumSize = new System.Drawing.Size(220, 258);
            this.Name = "Form1";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label lblKdrDefictValue;
        private System.Windows.Forms.Label lblKdrDefictLabel;
        private System.Windows.Forms.TextBox txtTargetKDR;
        private System.Windows.Forms.Label lblKdrValue;
        private System.Windows.Forms.Label lblKdrLabel;
        private System.Windows.Forms.TextBox txtKills;
        private System.Windows.Forms.TextBox txtDeaths;
        private System.Windows.Forms.Label lblKills;
        private System.Windows.Forms.Label lblDeaths;
        private System.Windows.Forms.Label lblTargetKdr;
        private System.Windows.Forms.Button btnApply;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.Button btnKills;
        private System.Windows.Forms.Button btnDeaths;
        private System.Windows.Forms.Button btnFeedBack;
        private System.Windows.Forms.Button btnBinds;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.Label lblDummy;
    }
}

