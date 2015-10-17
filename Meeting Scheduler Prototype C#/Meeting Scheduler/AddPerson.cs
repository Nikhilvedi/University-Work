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
    public partial class AddPerson : Form
    {
        public AddPerson()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            GUI g1 = new GUI();
            string namestr = textBox1.Text;
            g1.comboBox1.Items.Add(namestr);
            g1.comboBox2.Items.Add(namestr);
            g1.comboBox3.Items.Add(namestr);
            g1.comboBox4.Items.Add(namestr);
            this.Close();
            g1.ShowDialog();
        }
    }
}
