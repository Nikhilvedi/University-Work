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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Person 2 swapped!\n Meeting booked with Mehmet Ozcan, David Cooper, Chris Bates, Jan Graba and Claire Hornock");
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Not Implemented in Prototype");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Not Implemented in Prototype");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Not Implemented in Prototype");
        }
    }
}
