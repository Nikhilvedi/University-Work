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
    public partial class Email_Confirmation : Form
    {
        public Email_Confirmation()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            GUI g1 = new GUI();
            Form2 f2 = new Form2();
          //  MessageBox.Show("All Attendees Have been notified! ");
            MessageBox.Show(textBox1.Text + "\nAll Attendees Have been notified");
            this.Close();
            this.Hide(); 
        }
    }
}
