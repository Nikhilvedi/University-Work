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
    public partial class Conflicts : Form
    {
        public Conflicts()
        {
            InitializeComponent();
        }
        string[] pref1 = { "X", "P", "X", " ", " ", "P" };
        string[] pref2 = { "X", " ", "P", "X", " ", "P" };
        string[] pref3 = { " ", "P", " ", " ", "X", " " };
        string[] pref4 = { " ", " ", " ", " ", "P", "X" };
        string[] pref5 = { "P", "P", "P", "P", "P", "X" };
        string[] pref6 = { " ", "X", "P", "P", "P", "P" };
        string[] pref7 = { "X", "X", "P", " ", " ", "P" };
        string[] pref8 = { " ", "P", "P", " ", " ", " " };
        string[] pref9 = { " ", "P", " ", " ", "X", " " };
        string[] pref10 = { "X", "P", "X", "X", "X", " " };
        string[] pref11 = { " ", " ", "P", "P", "X", " " };
        string[] pref12 = { " ", "X", "X", " ", " ", "X" };
        string[] pref13 = { "P", " ", " ", " ", "P", " " };
        string[] pref14 = { " ", "P", "X", "X", "P", "P" };
        string[] pref15 = { "X", " ", " ", "X", " ", "P" };
        string[] pref16 = { "X", " ", "P", " ", "X", " " };
        string[] pref17 = { " ", "P", "X", " ", "X", " " };
        string[] pref18 = { " ", "P", " ", "P", " ", " " };
        string[] pref19 = { " ", "X", " ", "X", "P", "X" };
        string[] pref20 = { "P", "P", "X", " ", "X", "X" };
        string[] pref21 = { "P", "X", "X", "P", "X", "X" };
        string[] pref22 = { " ", "P", " ", "P", " ", "X" };
        string[] pref23 = { "X", "P", "X", "X", " ", " " };
        string[] pref24 = { "X", " ", "X", "X", " ", "P" };
        string[] pref25 = { "X", " ", "P", " ", "X", "X" };
        string[] meetings = { "Monday Slot 1", "Monday Slot 2", "Wednesday Slot 4", "Friday Slot 3" };
        int counter = 1;
        string mustBePresentString2;
        string mustBePresentString3;
        string mustBePresentString4;
        string mustBePresentString5;
        private void Conflicts_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            GUI g1 = new GUI();

            counter = (counter + 1) % 6;
            counter = (counter + 1) % 6;
            g1.textBox80.Clear();
            g1.textBox81.Clear();
            g1.textBox82.Clear();
            g1.textBox83.Clear();
            g1.textBox84.Clear();
            g1.textBox85.Clear();
            g1.textBox86.Clear();
            g1.textBox87.Clear();
            g1.textBox88.Clear();
            g1.textBox89.Clear();
            g1.textBox90.Clear();
            g1.textBox91.Clear();
            g1.textBox92.Clear();
            g1.textBox93.Clear();
            g1.textBox94.Clear();
            g1.textBox95.Clear();
            g1.textBox96.Clear();
            g1.textBox97.Clear();
            g1.textBox98.Clear();
            g1.textBox99.Clear();
            g1.textBox100.Clear();
            g1.textBox76.Clear();
            g1.textBox77.Clear();
            g1.textBox78.Clear();
            g1.textBox79.Clear();
            g1.textBox76.Text = pref1[counter];
            g1.textBox77.Text = pref2[counter];
            g1.textBox78.Text = pref5[counter];
            g1.textBox79.Text = pref4[counter];
            g1.textBox80.Text = pref3[counter];
            g1.textBox81.Text = pref6[counter];
            g1.textBox82.Text = pref7[counter];
            g1.textBox83.Text = pref1[counter];
            g1.textBox84.Text = pref9[counter];
            g1.textBox85.Text = pref10[counter];
            g1.textBox86.Text = pref19[counter];
            g1.textBox87.Text = pref12[counter];
            g1.textBox88.Text = pref13[counter];
            g1.textBox89.Text = pref14[counter];
            g1.textBox90.Text = pref15[counter];
            g1.textBox91.Text = pref16[counter];
            g1.textBox92.Text = pref17[counter];
            g1.textBox93.Text = pref18[counter];
            g1.textBox94.Text = pref12[counter];
            g1.textBox95.Text = pref20[counter];
            g1.textBox96.Text = pref22[counter];
            g1.textBox97.Text = pref21[counter];
            g1.textBox98.Text = pref23[counter];
            g1.textBox99.Text = pref25[counter];
            g1.textBox100.Text = pref24[counter];
            g1.textBox26.Clear();
            g1.textBox27.Clear();
            g1.textBox28.Clear();
            g1.textBox29.Clear();
            g1.textBox30.Clear();
            g1.textBox31.Clear();
            g1.textBox32.Clear();
            g1.textBox33.Clear();
            g1.textBox34.Clear();
            g1.textBox35.Clear();
            g1.textBox36.Clear();
            g1.textBox37.Clear();
            g1.textBox38.Clear();
            g1.textBox39.Clear();
            g1.textBox40.Clear();
            g1.textBox41.Clear();
            g1.textBox42.Clear();
            g1.textBox43.Clear();
            g1.textBox44.Clear();
            g1.textBox45.Clear();
            g1.textBox46.Clear();
            g1.textBox47.Clear();
            g1.textBox48.Clear();
            g1.textBox49.Clear();
            g1.textBox50.Clear();
            g1.textBox26.Text = pref2[counter];
            g1.textBox27.Text = pref23[counter];
            g1.textBox28.Text = pref13[counter];
            g1.textBox29.Text = pref23[counter];
            g1.textBox30.Text = pref16[counter];
            g1.textBox31.Text = pref8[counter];
            g1.textBox32.Text = pref6[counter];
            g1.textBox33.Text = pref1[counter];
            g1.textBox34.Text = pref22[counter];
            g1.textBox35.Text = pref11[counter];
            g1.textBox36.Text = pref5[counter];
            g1.textBox37.Text = pref24[counter];
            g1.textBox38.Text = pref19[counter];
            g1.textBox39.Text = pref9[counter];
            g1.textBox40.Text = pref19[counter];
            g1.textBox41.Text = pref1[counter];
            g1.textBox42.Text = pref15[counter];
            g1.textBox43.Text = pref16[counter];
            g1.textBox44.Text = pref23[counter];
            g1.textBox45.Text = pref25[counter];
            g1.textBox46.Text = pref1[counter];
            g1.textBox47.Text = pref9[counter];
            g1.textBox48.Text = pref5[counter];
            g1.textBox49.Text = pref3[counter];
            g1.textBox50.Text = pref3[counter];
            g1.textBox51.Clear();
            g1.textBox52.Clear();
            g1.textBox53.Clear();
            g1.textBox54.Clear();
            g1.textBox55.Clear();
            g1.textBox56.Clear();
            g1.textBox57.Clear();
            g1.textBox58.Clear();
            g1.textBox59.Clear();
            g1.textBox60.Clear();
            g1.textBox61.Clear();
            g1.textBox62.Clear();
            g1.textBox63.Clear();
            g1.textBox64.Clear();
            g1.textBox65.Clear();
            g1.textBox66.Clear();
            g1.textBox67.Clear();
            g1.textBox68.Clear();
            g1.textBox69.Clear();
            g1.textBox70.Clear();
            g1.textBox71.Clear();
            g1.textBox72.Clear();
            g1.textBox73.Clear();
            g1.textBox74.Clear();
            g1.textBox75.Clear();
            g1.textBox51.Text = pref24[counter];
            g1.textBox52.Text = pref14[counter];
            g1.textBox53.Text = pref12[counter];
            g1.textBox54.Text = pref6[counter];
            g1.textBox55.Text = pref3[counter];
            g1.textBox56.Text = pref23[counter];
            g1.textBox57.Text = pref25[counter];
            g1.textBox58.Text = pref11[counter];
            g1.textBox59.Text = pref10[counter];
            g1.textBox60.Text = pref20[counter];
            g1.textBox61.Text = pref2[counter];
            g1.textBox62.Text = pref12[counter];
            g1.textBox63.Text = pref17[counter];
            g1.textBox64.Text = pref3[counter];
            g1.textBox65.Text = pref4[counter];
            g1.textBox66.Text = pref19[counter];
            g1.textBox67.Text = pref4[counter];
            g1.textBox68.Text = pref15[counter];
            g1.textBox69.Text = pref17[counter];
            g1.textBox70.Text = pref11[counter];
            g1.textBox71.Text = pref2[counter];
            g1.textBox72.Text = pref21[counter];
            g1.textBox73.Text = pref1[counter];
            g1.textBox74.Text = pref10[counter];
            g1.textBox75.Text = pref20[counter];
            counter = (counter + 1) % 6;
            g1.textBox101.Clear();
            g1.textBox102.Clear();
            g1.textBox103.Clear();
            g1.textBox104.Clear();
            g1.textBox105.Clear();
            g1.textBox106.Clear();
            g1.textBox107.Clear();
            g1.textBox108.Clear();
            g1.textBox109.Clear();
            g1.textBox110.Clear();
            g1.textBox111.Clear();
            g1.textBox112.Clear();
            g1.textBox113.Clear();
            g1.textBox114.Clear();
            g1.textBox115.Clear();
            g1.textBox116.Clear();
            g1.textBox117.Clear();
            g1.textBox118.Clear();
            g1.textBox119.Clear();
            g1.textBox120.Clear();
            g1.textBox121.Clear();
            g1.textBox122.Clear();
            g1.textBox123.Clear();
            g1.textBox124.Clear();
            g1.textBox125.Clear();
            g1.textBox101.Text = pref1[counter];
            g1.textBox102.Text = pref2[counter];
            g1.textBox103.Text = pref3[counter];
            g1.textBox104.Text = pref4[counter];
            g1.textBox105.Text = pref5[counter];
            g1.textBox106.Text = pref6[counter];
            g1.textBox107.Text = pref5[counter];
            g1.textBox108.Text = pref8[counter];
            g1.textBox109.Text = pref9[counter];
            g1.textBox110.Text = pref10[counter];
            g1.textBox111.Text = pref1[counter];
            g1.textBox112.Text = pref16[counter];
            g1.textBox113.Text = pref13[counter];
            g1.textBox114.Text = pref16[counter];
            g1.textBox115.Text = pref15[counter];
            g1.textBox116.Text = pref14[counter];
            g1.textBox117.Text = pref17[counter];
            g1.textBox118.Text = pref12[counter];
            g1.textBox119.Text = pref11[counter];
            g1.textBox120.Text = pref20[counter];
            g1.textBox121.Text = pref24[counter];
            g1.textBox122.Text = pref21[counter];
            g1.textBox123.Text = pref21[counter];
            g1.textBox124.Text = pref1[counter];
            g1.textBox125.Text = pref15[counter];
            g1.Show();
            this.Close();
            g1.comboBox1.Text = "Mike Meridith";
            g1.comboBox3.Text = "Jan Graba";
            g1.comboBox2.Text = "Chris Bates";
            g1.comboBox4.Text = "Claire Hornock";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            mustBePresent2();
            mustBePresent3();
            mustBePresent4();
            mustBePresent5();
            Form3 f3 = new Form3();
            f3.textBox1.Text = (mustBePresentString2 + ", " + mustBePresentString3 + ", " + mustBePresentString4 + ", " + mustBePresentString5);
            f3.ShowDialog();
            this.Hide();
            this.Close();
        }
        GUI g1 = new GUI();

        public string mustBePresent2()
        {
            if (g1.checkBox2.Checked)
            {
                mustBePresentString2 = "Person 1 must be present";
            }

            else
            {
                mustBePresentString2 = "Person 1 is not necessary";
            }

            return mustBePresentString2;
        }
        public string mustBePresent3()
        {
            if (g1.checkBox3.Checked)
            {
                mustBePresentString3 = "Person 2 must be present";
            }

            else
            {
                mustBePresentString3 = "Person 2 is not necessary";
            }

            return mustBePresentString3;
        }
        public string mustBePresent4()
        {
            if (g1.checkBox4.Checked)
            {
                mustBePresentString4 = "Person 3 must be present";
            }

            else
            {
                mustBePresentString4 = "Person 3 is not necessary";
            }

            return mustBePresentString4;
        }
        public string mustBePresent5()
        {
            if (g1.checkBox5.Checked)
            {
                mustBePresentString5 = "Person 5 must be present";
            }

            else
            {
                mustBePresentString5 = "Person 5 is not necessary";
            }

            return mustBePresentString5;
        }

        private void button3_Click(object sender, EventArgs e)
        {
           GUI g1 = new GUI();
           _4_people a4 = new _4_people();
           a4.comboBox1.Text = "Mike Meridith";
           a4.comboBox3.Text = "Jan Graba";
           a4.comboBox2.Text = "Chris Bates";
           a4.checkBox2.Checked = true;
           a4.checkBox3.Checked = true;
           a4.checkBox4.Checked = true;

           a4.textBox1.Text = g1.textBox1.Text;
           a4.textBox2.Text = g1.textBox2.Text;
           a4.textBox3.Text = g1.textBox3.Text;
           a4.textBox4.Text = g1.textBox4.Text;
           a4.textBox5.Text = g1.textBox5.Text;
           a4.textBox6.Text = g1.textBox6.Text;
           a4.textBox7.Text = g1.textBox7.Text;
           a4.textBox8.Text = g1.textBox8.Text;
           a4.textBox9.Text = g1.textBox9.Text;
           a4.textBox10.Text = g1.textBox10.Text;
           a4.textBox11.Text = g1.textBox11.Text;
           a4.textBox12.Text = g1.textBox12.Text;
           a4.textBox13.Text = g1.textBox13.Text;
           a4.textBox14.Text = g1.textBox14.Text;
           a4.textBox15.Text = g1.textBox15.Text;
           a4.textBox16.Text = g1.textBox16.Text;
           a4.textBox17.Text = g1.textBox17.Text;
           a4.textBox18.Text = g1.textBox18.Text;
           a4.textBox19.Text = g1.textBox19.Text;
           a4.textBox20.Text = g1.textBox20.Text;
           a4.textBox21.Text = g1.textBox21.Text;
           a4.textBox22.Text = g1.textBox22.Text;
           a4.textBox23.Text = g1.textBox23.Text;
           a4.textBox24.Text = g1.textBox24.Text;
           a4.textBox25.Text = g1.textBox25.Text;

           a4.textBox76.Text = pref2[counter];
           a4.textBox77.Text = pref5[counter];
           a4.textBox78.Text = pref3[counter];
           a4.textBox79.Text = pref4[counter];
           a4.textBox80.Text = pref5[counter];
           a4.textBox81.Text = pref1[counter];
           a4.textBox82.Text = pref7[counter];
           a4.textBox83.Text = pref8[counter];
           a4.textBox84.Text = pref9[counter];
           a4.textBox85.Text = pref1[counter];
           a4.textBox86.Text = pref11[counter];
           a4.textBox87.Text = pref12[counter];
           a4.textBox88.Text = pref23[counter];
           a4.textBox89.Text = pref14[counter];
           a4.textBox90.Text = pref15[counter];
           a4.textBox91.Text = pref16[counter];
           a4.textBox92.Text = pref7[counter];
           a4.textBox93.Text = pref18[counter];
           a4.textBox94.Text = pref19[counter];
           a4.textBox95.Text = pref10[counter];
           a4.textBox96.Text = pref1[counter];
           a4.textBox97.Text = pref22[counter];
           a4.textBox98.Text = pref23[counter];
           a4.textBox99.Text = pref14[counter];
           a4.textBox100.Text = pref25[counter];
      
           a4.textBox26.Text = pref2[counter];
           a4.textBox27.Text = pref15[counter];
           a4.textBox28.Text = pref13[counter];
           a4.textBox29.Text = pref13[counter];
           a4.textBox30.Text = pref12[counter];
           a4.textBox31.Text = pref8[counter];
           a4.textBox32.Text = pref6[counter];
           a4.textBox33.Text = pref5[counter];
           a4.textBox34.Text = pref22[counter];
           a4.textBox35.Text = pref11[counter];
           a4.textBox36.Text = pref23[counter];
           a4.textBox37.Text = pref14[counter];
           a4.textBox38.Text = pref19[counter];
           a4.textBox39.Text = pref9[counter];
           a4.textBox40.Text = pref20[counter];
           a4.textBox41.Text = pref1[counter];
           a4.textBox42.Text = pref14[counter];
           a4.textBox43.Text = pref16[counter];
           a4.textBox44.Text = pref23[counter];
           a4.textBox45.Text = pref15[counter];
           a4.textBox46.Text = pref1[counter];
           a4.textBox47.Text = pref9[counter];
           a4.textBox48.Text = pref5[counter];
           a4.textBox49.Text = pref13[counter];
           a4.textBox50.Text = pref3[counter];
        
           a4.textBox51.Text = pref11[counter];
           a4.textBox52.Text = pref14[counter];
           a4.textBox53.Text = pref12[counter];
           a4.textBox54.Text = pref6[counter];
           a4.textBox55.Text = pref3[counter];
           a4.textBox56.Text = pref21[counter];
           a4.textBox57.Text = pref24[counter];
           a4.textBox58.Text = pref11[counter];
           a4.textBox59.Text = pref10[counter];
           a4.textBox60.Text = pref21[counter];
           a4.textBox61.Text = pref2[counter];
           a4.textBox62.Text = pref22[counter];
           a4.textBox63.Text = pref7[counter];
           a4.textBox64.Text = pref3[counter];
           a4.textBox65.Text = pref4[counter];
           a4.textBox66.Text = pref19[counter];
           a4.textBox67.Text = pref14[counter];
           a4.textBox68.Text = pref15[counter];
           a4.textBox69.Text = pref7[counter];
           a4.textBox70.Text = pref11[counter];
           a4.textBox71.Text = pref22[counter];
           a4.textBox72.Text = pref21[counter];
           a4.textBox73.Text = pref19[counter];
           a4.textBox74.Text = pref17[counter];
           a4.textBox75.Text = pref23[counter];
           a4.ShowDialog();

            //if (g1.checkBox1.Checked && g1.checkBox2.Checked  && g1.checkBox3.Checked  && g1.checkBox4.Checked  && g1.checkBox5.Checked  )
            //{
            //    MessageBox.Show("Cannot Remove, All Attendees are Vital!");
            //}
            //else if (g1.checkBox1.Checked == false && g1.checkBox2.Checked == false && g1.checkBox3.Checked == false && g1.checkBox4.Checked == false && g1.checkBox5.Checked == false)
            //{
            //    MessageBox.Show("Any Can be Removed!");
            //}
            //else if (g1.checkBox2.Checked == true && g1.checkBox3.Checked == true && g1.checkBox4.Checked == true && g1.checkBox5.Checked == true)
            //{
            //    MessageBox.Show("Person one can be Removed!");
            //}
            //else if (g1.checkBox1.Checked == true && g1.checkBox3.Checked == true && g1.checkBox4.Checked == true && g1.checkBox5.Checked == true)
            //{
            //    MessageBox.Show("Person two can be Removed!");
            //}
            //else if (g1.checkBox2.Checked == true && g1.checkBox1.Checked == true && g1.checkBox4.Checked == true && g1.checkBox5.Checked == true)
            //{
            //    MessageBox.Show("Person three can be Removed!");
            //}
            //else if (g1.checkBox2.Checked == true && g1.checkBox3.Checked == true && g1.checkBox1.Checked == true && g1.checkBox5.Checked == true)
            //{
            //    MessageBox.Show("Person four can be Removed!");
            //}
            //else if (g1.checkBox2.Checked == true && g1.checkBox3.Checked == true && g1.checkBox4.Checked == true && g1.checkBox1.Checked == true)
            //{
            //    MessageBox.Show("Person five can be Removed!");
            //}

        //   MessageBox.Show(mustBePresentString2 + ", " + mustBePresentString3 + ", " + mustBePresentString4 + ", " + mustBePresentString5);
        }
    }
     
}
