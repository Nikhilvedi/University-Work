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
    public partial class Rooms : Form
    {
        private Form2 frm2;
        public Rooms()
        {
            InitializeComponent();
        }
     
        private void Rooms_Load(object sender, EventArgs e)
        {
            frm2 = new Form2();
        }

        private void toolStripDropDownButton1_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
           // frm2.textBox3.Text = comboBox1.SelectedValue.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            GUI gg = new GUI();
            Form2 f1 = new Form2();
           // Email_Confirmation e1 = new Email_Confirmation();
            MessageBox.Show("Room : " + comboBox1.Text + " Booked!" );
          //  e1.ShowDialog();
          //  Form2 f3 = new Form2();
      //   f1.textBox3.Text = comboBox1.SelectedText.ToString(); 
            this.Hide();
            this.Close();
            f1.getData(comboBox1.Text.ToString());
           
            
     
        }

        private void Rooms_Load_1(object sender, EventArgs e)
        {

        }

     
    }
}
