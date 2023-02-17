using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_1
{
    public partial class Form1 : Form
    {
        public double[] RuSize = new double[14] { 35, 36, 36.5, 37, 37.5, 38, 39, 40, 41, 42, 43, 44, 45, 46 };
        public double[] EuSize = new double[14] { 36, 37, 37.5, 38, 38.5, 39, 40, 41, 42, 43, 44, 45, 46, 47 };
        public double[] UkSize = new double[14] { 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 10, 11, 12, 13 };
        public double[] UsSize = new double[14] { 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 10.5, 11.5, 12.5, 14 };
        public int index = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text += "1";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text += "2";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Text += "3";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.Text += "4";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox1.Text += "5";
        }

        private void button6_Click(object sender, EventArgs e)
        {
            textBox1.Text += "6";
        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox1.Text += "7";
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBox1.Text += "8";
        }

        private void button9_Click(object sender, EventArgs e)
        {
            textBox1.Text += "9";
        }

        private void button10_Click(object sender, EventArgs e)
        {
            textBox1.Text += "0";
        }

        private void button12_Click(object sender, EventArgs e)
        {
            textBox1.Text += ",";
        }

        private void button11_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
        }

        private void button13_Click(object sender, EventArgs e)
        {
            try
            {
                double size;
                size = Convert.ToDouble(textBox1.Text);
                if (checkBox1.Checked)
                {
                    index = Array.IndexOf(RuSize, size);
                }
                else if (checkBox4.Checked)
                {
                    index = Array.IndexOf(UsSize, size);
                }
                else if (checkBox2.Checked)
                {
                    index = Array.IndexOf(EuSize, size);
                }
                else if (checkBox3.Checked)
                {
                    index = Array.IndexOf(UkSize, size);
                }
                else if (checkBox3.Checked)
                {
                    index = Array.IndexOf(UkSize, size);
                }
                else if (!checkBox3.Checked && !checkBox1.Checked && !checkBox2.Checked && !checkBox4.Checked)
                {
                    throw new Exception("Не выбрана изначальная система измерения");
                }
                if (checkBox7.Checked)
                {
                    textBox2.Text = EuSize[index].ToString();
                }
                else if (checkBox8.Checked)
                {
                    textBox2.Text = RuSize[index].ToString();
                }
                else if (checkBox5.Checked)
                {
                    textBox2.Text = UsSize[index].ToString();
                }
                else if (checkBox6.Checked)
                {
                    textBox2.Text = UkSize[index].ToString();
                }
                else { throw new Exception("Не выбрана конечная система измерения"); };
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
