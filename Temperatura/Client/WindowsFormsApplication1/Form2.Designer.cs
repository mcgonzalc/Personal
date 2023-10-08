namespace WindowsFormsApplication1
{
    partial class Form2
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.opcioncelsius = new System.Windows.Forms.RadioButton();
            this.label2 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.temperatura = new System.Windows.Forms.TextBox();
            this.numForm = new System.Windows.Forms.Label();
            this.opcionfahrenheit = new System.Windows.Forms.RadioButton();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.groupBox1.Controls.Add(this.opcionfahrenheit);
            this.groupBox1.Controls.Add(this.opcioncelsius);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.button2);
            this.groupBox1.Controls.Add(this.temperatura);
            this.groupBox1.Location = new System.Drawing.Point(272, 176);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox1.Size = new System.Drawing.Size(484, 249);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Peticion";
            // 
            // opcioncelsius
            // 
            this.opcioncelsius.AutoSize = true;
            this.opcioncelsius.Location = new System.Drawing.Point(155, 84);
            this.opcioncelsius.Margin = new System.Windows.Forms.Padding(4);
            this.opcioncelsius.Name = "opcioncelsius";
            this.opcioncelsius.Size = new System.Drawing.Size(275, 20);
            this.opcioncelsius.TabIndex = 8;
            this.opcioncelsius.TabStop = true;
            this.opcioncelsius.Text = "Dime si quieres la temperatura en Celsius";
            this.opcioncelsius.UseVisualStyleBackColor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(31, 31);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(169, 31);
            this.label2.TabIndex = 1;
            this.label2.Text = "Temperatura";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(169, 160);
            this.button2.Margin = new System.Windows.Forms.Padding(4);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(100, 28);
            this.button2.TabIndex = 5;
            this.button2.Text = "Enviar";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // temperatura
            // 
            this.temperatura.Location = new System.Drawing.Point(232, 40);
            this.temperatura.Margin = new System.Windows.Forms.Padding(4);
            this.temperatura.Name = "temperatura";
            this.temperatura.Size = new System.Drawing.Size(217, 22);
            this.temperatura.TabIndex = 3;
            // 
            // numForm
            // 
            this.numForm.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.numForm.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.numForm.Location = new System.Drawing.Point(40, 223);
            this.numForm.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.numForm.Name = "numForm";
            this.numForm.Size = new System.Drawing.Size(130, 113);
            this.numForm.TabIndex = 10;
            // 
            // opcionfahrenheit
            // 
            this.opcionfahrenheit.AutoSize = true;
            this.opcionfahrenheit.Location = new System.Drawing.Point(155, 112);
            this.opcionfahrenheit.Margin = new System.Windows.Forms.Padding(4);
            this.opcionfahrenheit.Name = "opcionfahrenheit";
            this.opcionfahrenheit.Size = new System.Drawing.Size(294, 20);
            this.opcionfahrenheit.TabIndex = 9;
            this.opcionfahrenheit.TabStop = true;
            this.opcionfahrenheit.Text = "Dime si quieres la temperatura en Fahrenheit";
            this.opcionfahrenheit.UseVisualStyleBackColor = true;
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(781, 601);
            this.Controls.Add(this.numForm);
            this.Controls.Add(this.groupBox1);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form2";
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.Form2_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton opcioncelsius;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox temperatura;
        private System.Windows.Forms.Label numForm;
        private System.Windows.Forms.RadioButton opcionfahrenheit;
    }
}