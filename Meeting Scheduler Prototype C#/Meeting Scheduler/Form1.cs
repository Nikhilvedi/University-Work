using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Meeting_Scheduler
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            textBox2.PasswordChar = '*';
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            String username = "user";
            String password = "password";
            String username1 = "Mehmet Ozcan";
            String username2 = "Mike Meridith";
            String username3 = "Vacher Pascal";
            GUI ss = new GUI();

            if ((textBox1.Text == username) && (textBox2.Text == password))
            {
                this.Hide();
                ss.ShowDialog();
               // ss.Passvalue2 = textBox1.Text;

            }
            else
                if ((textBox1.Text == username1) && (textBox2.Text == password))
                {
                    this.Hide();
                    ss.ShowDialog();
                    ss.textBox127.Text = textBox1.Text;
                   // ss.Passvalue2 = textBox1.Text;

                }
                else
                    if ((textBox1.Text == username2) && (textBox2.Text == password))
                    {
                        this.Hide();
                        ss.ShowDialog();
                        ss.textBox127.Text = textBox1.Text;
                      //  ss.Passvalue2 = textBox1.Text;

                    }
                    else
                        if ((textBox1.Text == username3) && (textBox2.Text == password))
                        {
                            this.Hide();
                            ss.ShowDialog();
                            ss.textBox127.Text = textBox1.Text;
                        //    ss.Passvalue2 = textBox1.Text;

                        }
                        else
                        {
                            MessageBox.Show("Please Check Username and Password");
                             ss.Close();
                             textBox1.ResetText();
                             textBox2.ResetText();
                        }
  
            ss.Passvalue2 = textBox1.Text;

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
