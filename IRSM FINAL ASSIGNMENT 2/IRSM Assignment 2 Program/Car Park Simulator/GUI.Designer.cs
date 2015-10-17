namespace Car_Park_Simulator
{
    partial class GUI
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
            this.btnEnterCarPark = new System.Windows.Forms.Button();
            this.btnPressForCoin = new System.Windows.Forms.Button();
            this.btnCarArrives = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.btnStart = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btnCarArrivesAtExit = new System.Windows.Forms.Button();
            this.btnEnterCoin = new System.Windows.Forms.Button();
            this.btnExitCarPark = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.txtAvailableCoins = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.txtAvailableSpaces = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.txtExitBarrier = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txtEntryBarrier = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.txtFullSign = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.txtCoinMachine = new System.Windows.Forms.TextBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.btnPaymentforCoin = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnEnterCarPark
            // 
            this.btnEnterCarPark.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.btnEnterCarPark.Location = new System.Drawing.Point(6, 126);
            this.btnEnterCarPark.Name = "btnEnterCarPark";
            this.btnEnterCarPark.Size = new System.Drawing.Size(105, 46);
            this.btnEnterCarPark.TabIndex = 0;
            this.btnEnterCarPark.Text = "Enter Car Park";
            this.btnEnterCarPark.UseVisualStyleBackColor = true;
            this.btnEnterCarPark.Visible = false;
            this.btnEnterCarPark.Click += new System.EventHandler(this.btnEnterCarPark_Click);
            // 
            // btnPressForCoin
            // 
            this.btnPressForCoin.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.btnPressForCoin.Location = new System.Drawing.Point(6, 74);
            this.btnPressForCoin.Name = "btnPressForCoin";
            this.btnPressForCoin.Size = new System.Drawing.Size(105, 46);
            this.btnPressForCoin.TabIndex = 0;
            this.btnPressForCoin.Text = "Press for Coin";
            this.btnPressForCoin.UseVisualStyleBackColor = true;
            this.btnPressForCoin.Visible = false;
            this.btnPressForCoin.Click += new System.EventHandler(this.btnPressForCoin_Click);
            // 
            // btnCarArrives
            // 
            this.btnCarArrives.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.btnCarArrives.Location = new System.Drawing.Point(6, 22);
            this.btnCarArrives.Name = "btnCarArrives";
            this.btnCarArrives.Size = new System.Drawing.Size(105, 46);
            this.btnCarArrives.TabIndex = 0;
            this.btnCarArrives.Text = "Car Arrives at Car Park";
            this.btnCarArrives.UseVisualStyleBackColor = true;
            this.btnCarArrives.Visible = false;
            this.btnCarArrives.Click += new System.EventHandler(this.btnCarArrives_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 30F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(12, 9);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(357, 46);
            this.label3.TabIndex = 2;
            this.label3.Text = "Car Park Simulator";
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(18, 85);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(320, 46);
            this.btnStart.TabIndex = 0;
            this.btnStart.Text = "START";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnCarArrives);
            this.groupBox1.Controls.Add(this.btnPressForCoin);
            this.groupBox1.Controls.Add(this.btnEnterCarPark);
            this.groupBox1.Location = new System.Drawing.Point(6, 159);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(117, 184);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Car Arrival Simulator";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btnCarArrivesAtExit);
            this.groupBox2.Controls.Add(this.btnEnterCoin);
            this.groupBox2.Controls.Add(this.btnExitCarPark);
            this.groupBox2.Location = new System.Drawing.Point(255, 159);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(127, 184);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Car Exit Simulator";
            // 
            // btnCarArrivesAtExit
            // 
            this.btnCarArrivesAtExit.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.btnCarArrivesAtExit.Location = new System.Drawing.Point(6, 22);
            this.btnCarArrivesAtExit.Name = "btnCarArrivesAtExit";
            this.btnCarArrivesAtExit.Size = new System.Drawing.Size(115, 46);
            this.btnCarArrivesAtExit.TabIndex = 0;
            this.btnCarArrivesAtExit.Text = "Car Arrives at Exit";
            this.btnCarArrivesAtExit.UseVisualStyleBackColor = true;
            this.btnCarArrivesAtExit.Visible = false;
            this.btnCarArrivesAtExit.Click += new System.EventHandler(this.btnCarArrivesAtExit_Click);
            // 
            // btnEnterCoin
            // 
            this.btnEnterCoin.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.btnEnterCoin.Location = new System.Drawing.Point(6, 74);
            this.btnEnterCoin.Name = "btnEnterCoin";
            this.btnEnterCoin.Size = new System.Drawing.Size(115, 46);
            this.btnEnterCoin.TabIndex = 0;
            this.btnEnterCoin.Text = "Enter Coin";
            this.btnEnterCoin.UseVisualStyleBackColor = true;
            this.btnEnterCoin.Visible = false;
            this.btnEnterCoin.Click += new System.EventHandler(this.btnEnterCoin_Click);
            // 
            // btnExitCarPark
            // 
            this.btnExitCarPark.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.btnExitCarPark.Location = new System.Drawing.Point(6, 126);
            this.btnExitCarPark.Name = "btnExitCarPark";
            this.btnExitCarPark.Size = new System.Drawing.Size(115, 46);
            this.btnExitCarPark.TabIndex = 0;
            this.btnExitCarPark.Text = "Exit Car Park";
            this.btnExitCarPark.UseVisualStyleBackColor = true;
            this.btnExitCarPark.Visible = false;
            this.btnExitCarPark.Click += new System.EventHandler(this.btnExitCarPark_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.txtAvailableCoins);
            this.groupBox3.Controls.Add(this.label7);
            this.groupBox3.Controls.Add(this.txtAvailableSpaces);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Controls.Add(this.txtExitBarrier);
            this.groupBox3.Controls.Add(this.label4);
            this.groupBox3.Controls.Add(this.txtEntryBarrier);
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.txtFullSign);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Location = new System.Drawing.Point(392, 159);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(230, 184);
            this.groupBox3.TabIndex = 4;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Internal Data";
            // 
            // txtAvailableCoins
            // 
            this.txtAvailableCoins.Location = new System.Drawing.Point(111, 152);
            this.txtAvailableCoins.Name = "txtAvailableCoins";
            this.txtAvailableCoins.Size = new System.Drawing.Size(123, 20);
            this.txtAvailableCoins.TabIndex = 1;
            this.txtAvailableCoins.TextChanged += new System.EventHandler(this.txtAvailableCoins_TextChanged);
            // 
            // label7
            // 
            this.label7.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(19, 155);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(79, 13);
            this.label7.TabIndex = 0;
            this.label7.Text = "Available Coins";
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // txtAvailableSpaces
            // 
            this.txtAvailableSpaces.Location = new System.Drawing.Point(111, 118);
            this.txtAvailableSpaces.Name = "txtAvailableSpaces";
            this.txtAvailableSpaces.Size = new System.Drawing.Size(123, 20);
            this.txtAvailableSpaces.TabIndex = 1;
            this.txtAvailableSpaces.TextChanged += new System.EventHandler(this.txtAvailableSpaces_TextChanged);
            // 
            // label5
            // 
            this.label5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(16, 121);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(89, 13);
            this.label5.TabIndex = 0;
            this.label5.Text = "Available Spaces";
            // 
            // txtExitBarrier
            // 
            this.txtExitBarrier.Location = new System.Drawing.Point(111, 84);
            this.txtExitBarrier.Name = "txtExitBarrier";
            this.txtExitBarrier.Size = new System.Drawing.Size(123, 20);
            this.txtExitBarrier.TabIndex = 1;
            // 
            // label4
            // 
            this.label4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(16, 91);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(57, 13);
            this.label4.TabIndex = 0;
            this.label4.Text = "Exit Barrier";
            // 
            // txtEntryBarrier
            // 
            this.txtEntryBarrier.Location = new System.Drawing.Point(111, 58);
            this.txtEntryBarrier.Name = "txtEntryBarrier";
            this.txtEntryBarrier.Size = new System.Drawing.Size(123, 20);
            this.txtEntryBarrier.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(16, 58);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(64, 13);
            this.label2.TabIndex = 0;
            this.label2.Text = "Entry Barrier";
            // 
            // txtFullSign
            // 
            this.txtFullSign.Location = new System.Drawing.Point(111, 24);
            this.txtFullSign.Name = "txtFullSign";
            this.txtFullSign.Size = new System.Drawing.Size(123, 20);
            this.txtFullSign.TabIndex = 1;
            this.txtFullSign.TextChanged += new System.EventHandler(this.txtFullSign_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(19, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(47, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Full Sign";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.txtCoinMachine);
            this.groupBox4.Location = new System.Drawing.Point(372, 85);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(250, 46);
            this.groupBox4.TabIndex = 5;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Coin Machine Display";
            // 
            // txtCoinMachine
            // 
            this.txtCoinMachine.Location = new System.Drawing.Point(6, 20);
            this.txtCoinMachine.Name = "txtCoinMachine";
            this.txtCoinMachine.Size = new System.Drawing.Size(209, 20);
            this.txtCoinMachine.TabIndex = 0;
            this.txtCoinMachine.TextChanged += new System.EventHandler(this.txtCoinMachine_TextChanged);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.btnPaymentforCoin);
            this.groupBox5.Location = new System.Drawing.Point(124, 159);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(128, 184);
            this.groupBox5.TabIndex = 6;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Car Payment Simulator";
            this.groupBox5.Enter += new System.EventHandler(this.groupBox5_Enter);
            // 
            // btnPaymentforCoin
            // 
            this.btnPaymentforCoin.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.btnPaymentforCoin.Location = new System.Drawing.Point(6, 22);
            this.btnPaymentforCoin.Name = "btnPaymentforCoin";
            this.btnPaymentforCoin.Size = new System.Drawing.Size(116, 150);
            this.btnPaymentforCoin.TabIndex = 0;
            this.btnPaymentforCoin.Text = "Payment for Coin";
            this.btnPaymentforCoin.UseVisualStyleBackColor = true;
            this.btnPaymentforCoin.Visible = false;
            this.btnPaymentforCoin.Click += new System.EventHandler(this.button1_Click);
            // 
            // GUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(634, 358);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.btnStart);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "GUI";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Car Park Simulator";
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnEnterCarPark;
        private System.Windows.Forms.Button btnPressForCoin;
        private System.Windows.Forms.Button btnCarArrives;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnCarArrivesAtExit;
        private System.Windows.Forms.Button btnEnterCoin;
        private System.Windows.Forms.Button btnExitCarPark;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox txtAvailableCoins;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtAvailableSpaces;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtExitBarrier;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtEntryBarrier;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtFullSign;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.TextBox txtCoinMachine;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Button btnPaymentforCoin;
    }
}

