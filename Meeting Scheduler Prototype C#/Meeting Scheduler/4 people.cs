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
    public partial class _4_people : Form
    {
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
        public _4_people()
        {
            InitializeComponent();
        }

        private void _4_people_Load(object sender, EventArgs e)
        {

        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox15_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox20_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox25_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
         
        }

       private void button1_Click_1(object sender, EventArgs e)
        {
            Form2 f1 = new Form2();
            one = textBox127.Text;
            two = comboBox1.Text;
            three = comboBox2.Text;
            four = comboBox3.Text;
      
            //monday
            if (textBox1.Text.Equals(" ") | textBox1.Text.Equals("P") && textBox30.Text.Equals(" ") | textBox30.Text.Equals("P") && textBox55.Text.Equals(" ")
                | textBox55.Text.Equals("P") && textBox80.Text.Equals(" ") | textBox80.Text.Equals("P") )
            {
                //   MessageBox.Show("Meeting Booked for Monday at 10-11 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Monday at 10-11";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();

            }
            else if (textBox10.Text.Equals(" ") | textBox10.Text.Equals("P") && textBox35.Text.Equals(" ") | textBox35.Text.Equals("P") && textBox60.Text.Equals(" ")
               | textBox60.Text.Equals("P") && textBox85.Text.Equals(" ") | textBox85.Text.Equals("P"))
            {
                //MessageBox.Show("Meeting Booked for Monday at 11-12 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Monday at 11-12 in";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox15.Text.Equals(" ") | textBox15.Text.Equals("P") && textBox40.Text.Equals(" ") | textBox40.Text.Equals("P") && textBox65.Text.Equals(" ")
          | textBox65.Text.Equals("P") && textBox90.Text.Equals(" ") | textBox90.Text.Equals("P") )
            {
                //  MessageBox.Show("Meeting Booked for Monday at 12-1 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Monday at 12-1 in";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox20.Text.Equals(" ") | textBox20.Text.Equals("P") && textBox45.Text.Equals(" ") | textBox45.Text.Equals("P") && textBox70.Text.Equals(" ")
          | textBox70.Text.Equals("P") && textBox95.Text.Equals(" ") | textBox95.Text.Equals("P") )
            {
                f1.textBox1.Text = "Meeting Booked for Monday at 2-3 in";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();

                //  MessageBox.Show("Meeting Booked for Monday at 2-3 in: " + nm);
            }
            else if (textBox25.Text.Equals(" ") | textBox25.Text.Equals("P") && textBox50.Text.Equals(" ") | textBox50.Text.Equals("P") && textBox75.Text.Equals(" ")
          | textBox75.Text.Equals("P") && textBox100.Text.Equals(" ") | textBox100.Text.Equals("P") )
            {
                //MessageBox.Show("Meeting Booked for Monday at 3+ in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Monday at 3+ in";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }

    //tuesday
            else if (textBox5.Text.Equals(" ") | textBox5.Text.Equals("P") && textBox26.Text.Equals(" ") | textBox26.Text.Equals("P") && textBox51.Text.Equals(" ")
          | textBox51.Text.Equals("P") && textBox76.Text.Equals(" ") | textBox76.Text.Equals("P") )
            {
                // MessageBox.Show("Meeting Booked for Tuesday at 10-11 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Tuesday at 10-11";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox6.Text.Equals(" ") | textBox6.Text.Equals("P") && textBox31.Text.Equals(" ") | textBox31.Text.Equals("P") && textBox56.Text.Equals(" ")
               | textBox56.Text.Equals("P") && textBox81.Text.Equals(" ") | textBox81.Text.Equals("P") )
            {
                //MessageBox.Show("Meeting Booked for Tuesday at 11-12 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Tuesday at 11-12";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox11.Text.Equals(" ") | textBox11.Text.Equals("P") && textBox36.Text.Equals(" ") | textBox36.Text.Equals("P") && textBox61.Text.Equals(" ")
          | textBox61.Text.Equals("P") && textBox86.Text.Equals(" ") | textBox86.Text.Equals("P") )
            {
                // MessageBox.Show("Meeting Booked for Tuesday at 12-1 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Tuesday at 12-1";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox16.Text.Equals(" ") | textBox16.Text.Equals("P") && textBox41.Text.Equals(" ") | textBox41.Text.Equals("P") && textBox66.Text.Equals(" ")
          | textBox66.Text.Equals("P") && textBox91.Text.Equals(" ") | textBox91.Text.Equals("P") )
            {
                // MessageBox.Show("Meeting Booked for Tuesday at 2-3 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Tuesday at 2-3";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox21.Text.Equals(" ") | textBox21.Text.Equals("P") && textBox46.Text.Equals(" ") | textBox46.Text.Equals("P") && textBox71.Text.Equals(" ")
          | textBox71.Text.Equals("P") && textBox96.Text.Equals(" ") | textBox96.Text.Equals("P") )
            {
                // MessageBox.Show("Meeting Booked for Tuesday at 3+ in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Tuesday at 3+";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }

      //wednesday
            else if (textBox4.Text.Equals(" ") | textBox4.Text.Equals("P") && textBox27.Text.Equals(" ") | textBox27.Text.Equals("P") && textBox52.Text.Equals(" ")
          | textBox52.Text.Equals("P") && textBox77.Text.Equals(" ") | textBox77.Text.Equals("P"))
            {
                // MessageBox.Show("Meeting Booked for Wednesday at 10-11 in :" + nm);

                f1.textBox1.Text = "Meeting Booked for Wednesday at 10-11";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox7.Text.Equals(" ") | textBox7.Text.Equals("P") && textBox32.Text.Equals(" ") | textBox32.Text.Equals("P") && textBox57.Text.Equals(" ")
               | textBox57.Text.Equals("P") && textBox82.Text.Equals(" ") | textBox82.Text.Equals("P") )
            {
                //MessageBox.Show("Meeting Booked for Wednesday at 11-12 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Wednesday at 11-12";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox12.Text.Equals(" ") | textBox12.Text.Equals("P") && textBox37.Text.Equals(" ") | textBox37.Text.Equals("P") && textBox62.Text.Equals(" ")
          | textBox62.Text.Equals("P") && textBox87.Text.Equals(" ") | textBox87.Text.Equals("P") )
            {
                // MessageBox.Show("Meeting Booked for Wednesday at 12-1 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Wednesday at 12-1";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox17.Text.Equals(" ") | textBox17.Text.Equals("P") && textBox42.Text.Equals(" ") | textBox42.Text.Equals("P") && textBox67.Text.Equals(" ")
          | textBox67.Text.Equals("P") && textBox92.Text.Equals(" ") | textBox92.Text.Equals("P") )
            {
                //MessageBox.Show("Meeting Booked for Wednesday at 2-3 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Wednesday at 2-3";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox22.Text.Equals(" ") | textBox22.Text.Equals("P") && textBox47.Text.Equals(" ") | textBox47.Text.Equals("P") && textBox72.Text.Equals(" ")
          | textBox72.Text.Equals("P") && textBox97.Text.Equals(" ") | textBox97.Text.Equals("P") )
            {
                //  MessageBox.Show("Meeting Booked for Wednesday at 3+" + nm);

                f1.textBox1.Text = "Meeting Booked for Wednesday at 3+";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            //thursday
            else if (textBox3.Text.Equals(" ") | textBox3.Text.Equals("P") && textBox28.Text.Equals(" ") | textBox28.Text.Equals("P") && textBox53.Text.Equals(" ")
          | textBox53.Text.Equals("P") && textBox78.Text.Equals(" ") | textBox78.Text.Equals("P") )
            {
                //  MessageBox.Show("Meeting Booked for Thursday at 10-11 in :" + nm);

                f1.textBox1.Text = "Meeting Booked for Thursday at 10-11";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox8.Text.Equals(" ") | textBox8.Text.Equals("P") && textBox33.Text.Equals(" ") | textBox33.Text.Equals("P") && textBox58.Text.Equals(" ")
               | textBox58.Text.Equals("P") && textBox83.Text.Equals(" ") | textBox83.Text.Equals("P") )
            {
                // MessageBox.Show("Meeting Booked for Thursday at 11-12 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Thursday at 11-12";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox13.Text.Equals(" ") | textBox13.Text.Equals("P") && textBox38.Text.Equals(" ") | textBox38.Text.Equals("P") && textBox63.Text.Equals(" ")
          | textBox63.Text.Equals("P") && textBox88.Text.Equals(" ") | textBox88.Text.Equals("P"))
            {
                // MessageBox.Show("Meeting Booked for Thursday at 12-1 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Thursday at 12-1";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox18.Text.Equals(" ") | textBox18.Text.Equals("P") && textBox43.Text.Equals(" ") | textBox43.Text.Equals("P") && textBox68.Text.Equals(" ")
          | textBox68.Text.Equals("P") && textBox93.Text.Equals(" ") | textBox93.Text.Equals("P") )
            {
                // MessageBox.Show("Meeting Booked for Thursday at 2-3 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Thursday at 2-3";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox23.Text.Equals(" ") | textBox23.Text.Equals("P") && textBox48.Text.Equals(" ") | textBox48.Text.Equals("P") && textBox73.Text.Equals(" ")
          | textBox73.Text.Equals("P") && textBox98.Text.Equals(" ") | textBox98.Text.Equals("P") )
            {
                //MessageBox.Show("Meeting Booked for Thursday at 3+" + nm);

                f1.textBox1.Text = "Meeting Booked for Thursday at 3+";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            //friday
            else if (textBox2.Text.Equals(" ") | textBox2.Text.Equals("P") && textBox29.Text.Equals(" ") | textBox29.Text.Equals("P") && textBox54.Text.Equals(" ")
          | textBox54.Text.Equals("P") && textBox79.Text.Equals(" ") | textBox79.Text.Equals("P"))
            {
                // MessageBox.Show("Meeting Booked for Friday at 10-11 in :" + nm);

                f1.textBox1.Text = "Meeting Booked for Friday at 10-11";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox9.Text.Equals(" ") | textBox9.Text.Equals("P") && textBox34.Text.Equals(" ") | textBox34.Text.Equals("P") && textBox59.Text.Equals(" ")
               | textBox59.Text.Equals("P") && textBox84.Text.Equals(" ") | textBox84.Text.Equals("P") )
            {
                //MessageBox.Show("Meeting Booked for Friday at 11-12 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Friday at 11-12";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox14.Text.Equals(" ") | textBox14.Text.Equals("P") && textBox39.Text.Equals(" ") | textBox39.Text.Equals("P") && textBox64.Text.Equals(" ")
          | textBox64.Text.Equals("P") && textBox89.Text.Equals(" ") | textBox89.Text.Equals("P") )
            {
                // MessageBox.Show("Meeting Booked for Friday at 12-1 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Friday at 12-1";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox19.Text.Equals(" ") | textBox19.Text.Equals("P") && textBox44.Text.Equals(" ") | textBox44.Text.Equals("P") && textBox69.Text.Equals(" ")
          | textBox69.Text.Equals("P") && textBox94.Text.Equals(" ") | textBox94.Text.Equals("P") )
            {
                // MessageBox.Show("Meeting Booked for Friday at 2-3 in: " + nm);

                f1.textBox1.Text = "Meeting Booked for Friday at 2-3";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }
            else if (textBox24.Text.Equals(" ") | textBox24.Text.Equals("P") && textBox49.Text.Equals(" ") | textBox49.Text.Equals("P") && textBox74.Text.Equals(" ")
          | textBox74.Text.Equals("P") && textBox99.Text.Equals(" ") | textBox99.Text.Equals("P") )
            {
                //MessageBox.Show("Meeting Booked for Friday at 3+" + nm);

                f1.textBox1.Text = "Meeting Booked for Friday at 3+";
                f1.textBox2.Text = (one + ", " + two + ", " + three + ", " + four + " and " );
                f1.ShowDialog();
            }

            else
            {
                //create form here to resolve conflicts 
                Conflicts con = new Conflicts();
                con.button1 = button10;

                con.textBox1.Text = "No Meeting Available, how would you like to resolve conflicts?";

                con.ShowDialog();
                this.Close();

            }

        }
        string one, two, three, four;
        private void button9_Click_1(object sender, EventArgs e)
        {

            one = textBox127.Text;
            two = comboBox1.Text;
            three = comboBox2.Text;
            four = comboBox3.Text;
          

            MessageBox.Show("All Attendees : " + one + ", " + two + ", " + three + ", " + four + " and " + " Have been notified! ");
        }

        private void button5_Click(object sender, EventArgs e)
        {

            counter = (counter + 1) % 6;
            textBox26.Clear();
            textBox27.Clear();
            textBox28.Clear();
            textBox29.Clear();
            textBox30.Clear();
            textBox31.Clear();
            textBox32.Clear();
            textBox33.Clear();
            textBox34.Clear();
            textBox35.Clear();
            textBox36.Clear();
            textBox37.Clear();
            textBox38.Clear();
            textBox39.Clear();
            textBox40.Clear();
            textBox41.Clear();
            textBox42.Clear();
            textBox43.Clear();
            textBox44.Clear();
            textBox45.Clear();
            textBox46.Clear();
            textBox47.Clear();
            textBox48.Clear();
            textBox49.Clear();
            textBox50.Clear();
            textBox26.Text = pref2[counter];
            textBox27.Text = pref25[counter];
            textBox28.Text = pref13[counter];
            textBox29.Text = pref23[counter];
            textBox30.Text = pref12[counter];
            textBox31.Text = pref8[counter];
            textBox32.Text = pref6[counter];
            textBox33.Text = pref5[counter];
            textBox34.Text = pref22[counter];
            textBox35.Text = pref11[counter];
            textBox36.Text = pref3[counter];
            textBox37.Text = pref24[counter];
            textBox38.Text = pref19[counter];
            textBox39.Text = pref9[counter];
            textBox40.Text = pref10[counter];
            textBox41.Text = pref1[counter];
            textBox42.Text = pref14[counter];
            textBox43.Text = pref16[counter];
            textBox44.Text = pref23[counter];
            textBox45.Text = pref25[counter];
            textBox46.Text = pref1[counter];
            textBox47.Text = pref9[counter];
            textBox48.Text = pref5[counter];
            textBox49.Text = pref3[counter];
            textBox50.Text = pref23[counter];
        }

        private void button2_Click(object sender, EventArgs e)
        {


        }

        private void checkBox9_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox6_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox8_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox10_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox7_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {



        }

        private void label58_Click(object sender, EventArgs e)
        {

        }

        private void textBox126_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox127_TextChanged(object sender, EventArgs e)
        {

        }

      
        private void button10_Click_1(object sender, EventArgs e)
        {

            this.timer1.Start();
            counter = (counter + 1) % 6;
            counter = (counter + 1) % 6;
            textBox80.Clear();
            textBox81.Clear();
            textBox82.Clear();
            textBox83.Clear();
            textBox84.Clear();
            textBox85.Clear();
            textBox86.Clear();
            textBox87.Clear();
            textBox88.Clear();
            textBox89.Clear();
            textBox90.Clear();
            textBox91.Clear();
            textBox92.Clear();
            textBox93.Clear();
            textBox94.Clear();
            textBox95.Clear();
            textBox96.Clear();
            textBox97.Clear();
            textBox98.Clear();
            textBox99.Clear();
            textBox100.Clear();
            textBox76.Clear();
            textBox77.Clear();
            textBox78.Clear();
            textBox79.Clear();
            textBox76.Text = pref1[counter];
            textBox77.Text = pref2[counter];
            textBox78.Text = pref3[counter];
            textBox79.Text = pref4[counter];
            textBox80.Text = pref5[counter];
            textBox81.Text = pref6[counter];
            textBox82.Text = pref7[counter];
            textBox83.Text = pref8[counter];
            textBox84.Text = pref9[counter];
            textBox85.Text = pref10[counter];
            textBox86.Text = pref11[counter];
            textBox87.Text = pref12[counter];
            textBox88.Text = pref13[counter];
            textBox89.Text = pref14[counter];
            textBox90.Text = pref15[counter];
            textBox91.Text = pref16[counter];
            textBox92.Text = pref17[counter];
            textBox93.Text = pref18[counter];
            textBox94.Text = pref19[counter];
            textBox95.Text = pref20[counter];
            textBox96.Text = pref21[counter];
            textBox97.Text = pref22[counter];
            textBox98.Text = pref23[counter];
            textBox99.Text = pref24[counter];
            textBox100.Text = pref25[counter];
            textBox26.Clear();
            textBox27.Clear();
            textBox28.Clear();
            textBox29.Clear();
            textBox30.Clear();
            textBox31.Clear();
            textBox32.Clear();
            textBox33.Clear();
            textBox34.Clear();
            textBox35.Clear();
            textBox36.Clear();
            textBox37.Clear();
            textBox38.Clear();
            textBox39.Clear();
            textBox40.Clear();
            textBox41.Clear();
            textBox42.Clear();
            textBox43.Clear();
            textBox44.Clear();
            textBox45.Clear();
            textBox46.Clear();
            textBox47.Clear();
            textBox48.Clear();
            textBox49.Clear();
            textBox50.Clear();
            textBox26.Text = pref2[counter];
            textBox27.Text = pref25[counter];
            textBox28.Text = pref13[counter];
            textBox29.Text = pref23[counter];
            textBox30.Text = pref12[counter];
            textBox31.Text = pref8[counter];
            textBox32.Text = pref6[counter];
            textBox33.Text = pref5[counter];
            textBox34.Text = pref22[counter];
            textBox35.Text = pref11[counter];
            textBox36.Text = pref3[counter];
            textBox37.Text = pref24[counter];
            textBox38.Text = pref19[counter];
            textBox39.Text = pref9[counter];
            textBox40.Text = pref10[counter];
            textBox41.Text = pref1[counter];
            textBox42.Text = pref14[counter];
            textBox43.Text = pref16[counter];
            textBox44.Text = pref23[counter];
            textBox45.Text = pref25[counter];
            textBox46.Text = pref1[counter];
            textBox47.Text = pref9[counter];
            textBox48.Text = pref5[counter];
            textBox49.Text = pref3[counter];
            textBox50.Text = pref23[counter];
            textBox51.Clear();
            textBox52.Clear();
            textBox53.Clear();
            textBox54.Clear();
            textBox55.Clear();
            textBox56.Clear();
            textBox57.Clear();
            textBox58.Clear();
            textBox59.Clear();
            textBox60.Clear();
            textBox61.Clear();
            textBox62.Clear();
            textBox63.Clear();
            textBox64.Clear();
            textBox65.Clear();
            textBox66.Clear();
            textBox67.Clear();
            textBox68.Clear();
            textBox69.Clear();
            textBox70.Clear();
            textBox71.Clear();
            textBox72.Clear();
            textBox73.Clear();
            textBox74.Clear();
            textBox75.Clear();
            textBox51.Text = pref21[counter];
            textBox52.Text = pref14[counter];
            textBox53.Text = pref12[counter];
            textBox54.Text = pref6[counter];
            textBox55.Text = pref3[counter];
            textBox56.Text = pref23[counter];
            textBox57.Text = pref25[counter];
            textBox58.Text = pref11[counter];
            textBox59.Text = pref10[counter];
            textBox60.Text = pref20[counter];
            textBox61.Text = pref2[counter];
            textBox62.Text = pref22[counter];
            textBox63.Text = pref17[counter];
            textBox64.Text = pref3[counter];
            textBox65.Text = pref4[counter];
            textBox66.Text = pref19[counter];
            textBox67.Text = pref4[counter];
            textBox68.Text = pref15[counter];
            textBox69.Text = pref7[counter];
            textBox70.Text = pref11[counter];
            textBox71.Text = pref22[counter];
            textBox72.Text = pref21[counter];
            textBox73.Text = pref19[counter];
            textBox74.Text = pref17[counter];
            textBox75.Text = pref23[counter];
            counter = (counter + 1) % 6;
            
        }
    
        private void button6_Click_1(object sender, EventArgs e)
        {
            counter = (counter + 1) % 6;
            textBox51.Clear();
            textBox52.Clear();
            textBox53.Clear();
            textBox54.Clear();
            textBox55.Clear();
            textBox56.Clear();
            textBox57.Clear();
            textBox58.Clear();
            textBox59.Clear();
            textBox60.Clear();
            textBox61.Clear();
            textBox62.Clear();
            textBox63.Clear();
            textBox64.Clear();
            textBox65.Clear();
            textBox66.Clear();
            textBox67.Clear();
            textBox68.Clear();
            textBox69.Clear();
            textBox70.Clear();
            textBox71.Clear();
            textBox72.Clear();
            textBox73.Clear();
            textBox74.Clear();
            textBox75.Clear();
            textBox51.Text = pref21[counter];
            textBox52.Text = pref14[counter];
            textBox53.Text = pref12[counter];
            textBox54.Text = pref6[counter];
            textBox55.Text = pref3[counter];
            textBox56.Text = pref23[counter];
            textBox57.Text = pref25[counter];
            textBox58.Text = pref11[counter];
            textBox59.Text = pref10[counter];
            textBox60.Text = pref20[counter];
            textBox61.Text = pref2[counter];
            textBox62.Text = pref22[counter];
            textBox63.Text = pref17[counter];
            textBox64.Text = pref3[counter];
            textBox65.Text = pref4[counter];
            textBox66.Text = pref19[counter];
            textBox67.Text = pref4[counter];
            textBox68.Text = pref15[counter];
            textBox69.Text = pref7[counter];
            textBox70.Text = pref11[counter];
            textBox71.Text = pref22[counter];
            textBox72.Text = pref21[counter];
            textBox73.Text = pref19[counter];
            textBox74.Text = pref17[counter];
            textBox75.Text = pref23[counter];
        }
    

        private void button7_Click_1(object sender, EventArgs e)
        {

            counter = (counter + 1) % 6;
            textBox80.Clear();
            textBox81.Clear();
            textBox82.Clear();
            textBox83.Clear();
            textBox84.Clear();
            textBox85.Clear();
            textBox86.Clear();
            textBox87.Clear();
            textBox88.Clear();
            textBox89.Clear();
            textBox90.Clear();
            textBox91.Clear();
            textBox92.Clear();
            textBox93.Clear();
            textBox94.Clear();
            textBox95.Clear();
            textBox96.Clear();
            textBox97.Clear();
            textBox98.Clear();
            textBox99.Clear();
            textBox100.Clear();
            textBox76.Clear();
            textBox77.Clear();
            textBox78.Clear();
            textBox79.Clear();
            textBox76.Text = pref1[counter];
            textBox77.Text = pref2[counter];
            textBox78.Text = pref3[counter];
            textBox79.Text = pref4[counter];
            textBox80.Text = pref5[counter];
            textBox81.Text = pref6[counter];
            textBox82.Text = pref7[counter];
            textBox83.Text = pref8[counter];
            textBox84.Text = pref9[counter];
            textBox85.Text = pref10[counter];
            textBox86.Text = pref11[counter];
            textBox87.Text = pref12[counter];
            textBox88.Text = pref13[counter];
            textBox89.Text = pref14[counter];
            textBox90.Text = pref15[counter];
            textBox91.Text = pref16[counter];
            textBox92.Text = pref17[counter];
            textBox93.Text = pref18[counter];
            textBox94.Text = pref19[counter];
            textBox95.Text = pref20[counter];
            textBox96.Text = pref21[counter];
            textBox97.Text = pref22[counter];
            textBox98.Text = pref23[counter];
            textBox99.Text = pref24[counter];
            textBox100.Text = pref25[counter];
        }

   

        private void textBox80_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox105_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox128_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox129_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox130_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox131_TextChanged(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
        }

        private void progressBar1_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            Rooms ss = new Rooms();
            ss.Show();

        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {

        }

     

    }
}
