using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Meeting_Scheduler
{
    
    public partial class Form2 : Form
    {
       
        public Form2()
        {
            InitializeComponent();
            GUI g1 = new GUI();
            textBox2.Text = g1.textBox127.Text;
            textBox2.Text = g1.comboBox1.Text;
            textBox2.Text = g1.comboBox2.Text;
            textBox2.Text = g1.comboBox3.Text;
            textBox2.Text = g1.comboBox4.Text;
            this.textBox3.Text = "HH:MM";
            //if (textBox3.Click == true)
            //{
            //    textBox3.Clear();
            //}
        }
        
        private void button1_Click(object sender, EventArgs e)
        {
            //this.Hide();
           // this.Close();
            Rooms ss = new Rooms();
            ss.Show();
         
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            GUI g1 = new GUI();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            GUI g1 = new GUI();
            g1.Hide();
            g1.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Rooms r1 = new Rooms();
      
            GUI g1 = new GUI();
            Email_Confirmation e1 = new Email_Confirmation();
            e1.textBox1.Text = "Meeting Booked with: " + textBox2.Text  + "\n at: " + textBox3.Text + " in: Cantor 9321";
            e1.ShowDialog();
            this.Close();
     
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {

            MessageBox.Show("TimeSlot " + textBox3.Text + " Booked!");
            button4.Hide();
            button5.Show();
           
        }

        private void button5_Click(object sender, EventArgs e)
        {
            MessageBox.Show("TimeSlot " + textBox3.Text + " Booked!");
          
        }
        string text;
        public void getData(string a)
        {
         text  = a.ToString();
        }
    }
}
