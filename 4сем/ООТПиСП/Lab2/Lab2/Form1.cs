using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace Lab2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public List<Discipline> listOfDisciplines = new List<Discipline>();
        Discipline discipline = new Discipline();   /// в этот объект пишем всю инфу из формы
        string path = @"E:\2_курс\4сем\ООТПиСП\Lab2\Lab2\out.xml";
        /// путь по которому будем записывать в xml-файл объект

        public void ExceptionsCheck()
        {
            if (richTextBox1.Text == "")
                throw new Exception("Введите название дисциплины.");
            if (listBox1.SelectedItems.Count == 0)
                throw new Exception("Выберите специальность.");
            if (checkedListBox1.SelectedItems.Count == 0)
                throw new Exception("Выберите курс.");
            if (comboBox1.Text == "")
                throw new Exception("Выберите номер семестра.");
            if (!radioButton1.Checked && !radioButton2.Checked)
                throw new Exception("Выберите тип контроля.");
            if (richTextBox2.Text == "")
                throw new Exception("Введите кол-во лекций.");
            if (richTextBox3.Text == "")
                throw new Exception("Введите кол-во лабораторных.");
            if (maskedTextBox1.Text == "")
                throw new Exception("Введите преподавателя.");
            if (listBox2.SelectedItems.Count == 0)
                throw new Exception("Выберите кафедру.");
            if (richTextBox4.Text == "")
                throw new Exception("Введите номер аудитории.");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ExceptionsCheck();  // вызов проверки корректности

            List<string> tempCourse = new List<string>();
            List<string> tempSpec = new List<string>();
            string tempRadio = "";
            Lector tempLect = new Lector((string)listBox2.SelectedItem, maskedTextBox1.Text, richTextBox4.Text);

            foreach (string item in checkedListBox1.CheckedItems)
                tempCourse.Add(item);
            foreach (string item in listBox1.SelectedItems)
                tempSpec.Add(item);

            if (radioButton1.Checked)
                tempRadio = radioButton1.Text;
            else if (radioButton2.Checked)
                tempRadio = radioButton2.Text;

            // само заполнение этого объекта информацией через конструктор
            discipline = new Discipline(richTextBox1.Text, comboBox1.Text,
                tempCourse, tempSpec, Int32.Parse(richTextBox2.Text),
                Int32.Parse(richTextBox3.Text), tempRadio, tempLect);

            listOfDisciplines.Add(discipline);

            // вывод сообщения что всё окей
            MessageBox.Show("Информация записана в объект!", "DisciplineRedact", MessageBoxButtons.OK);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            XmlSerializer formatter = new XmlSerializer(typeof(Discipline));

            using (FileStream fs = new FileStream(path, FileMode.Create))
            {
                formatter.Serialize(fs, discipline);
            }

            MessageBox.Show("Информация записана в XML!", "DisciplineRedact", MessageBoxButtons.OK);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            // обычный код для десериализации из XML
            XmlSerializer formatter = new XmlSerializer(typeof(Discipline));
            Discipline disOut = new Discipline();

            using (FileStream fs = new FileStream(path, FileMode.OpenOrCreate))
            {
                disOut = (Discipline)formatter.Deserialize(fs);
            }

            // Присвоение инфы полям
            richTextBox1.Text = disOut.Name;
            comboBox1.Text = disOut.Semester;
            richTextBox2.Text = disOut.NumberOfLections.ToString();
            richTextBox3.Text = disOut.NumberOfLabs.ToString();

            for (int i = 0; i < checkedListBox1.Items.Count; i++)
                for (int j = 0; j < disOut.Course.Count; j++)
                {
                    // отметить те курсы, которые были выбраны для записи в файл,
                    // и убрать отметку с тех, кто не был выбран
                    if (checkedListBox1.Items[i].ToString() == disOut.Course[j].ToString())
                        checkedListBox1.SetItemCheckState(i, CheckState.Checked);
                    else
                        checkedListBox1.SetItemCheckState(i, CheckState.Unchecked);
                }

            for (int i = 0; i < listBox1.Items.Count; i++)
                for (int j = 0; j < disOut.Speciality.Count; j++)
                {
                    // то же самое: отмечаем выбранные записи и снимаем те которых не было
                    if (listBox1.Items[i].ToString() == disOut.Speciality[j].ToString())
                        listBox1.SetSelected(i, true);
                    else
                        listBox1.SetSelected(i, false);
                }

            // Про зачет или экз
            if (disOut.Control == radioButton1.Text)
                radioButton1.Checked = true;
            else if (disOut.Control == radioButton2.Text)
                radioButton2.Checked = true;

            // Лектор
            maskedTextBox1.Text = disOut.lector.Name;

            for (int i = 0; i < listBox2.Items.Count; i++)
                if (disOut.lector.Department == listBox2.Items[i].ToString())
                    listBox2.SetSelected(i, true);
            richTextBox4.Text = disOut.lector.Auditorium;

            /// сообщение о том что всё окей
            MessageBox.Show("Информация выведена!", "DisciplineRedact", MessageBoxButtons.OK);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            listBox1.ClearSelected();
            checkedListBox1.ClearSelected();
            comboBox1.Items.Clear();
            radioButton1.Checked = false;
            radioButton2.Checked = false;
            richTextBox2.Clear();
            richTextBox3.Clear();
            maskedTextBox1.Clear();
            listBox2.ClearSelected();
            richTextBox4.Clear();
            MessageBox.Show("Вся введенная информация очищена!", "DisciplineRedact", MessageBoxButtons.OK);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        // Название дисциплины
        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("https://www.belstu.by/fakultety");
        }

        // Выбор спецухи
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        // Выбор курса
        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        // Выбор семестра
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        // Выбор либо зачет, либо экз
        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        // Лекционные часы
        private void richTextBox2_TextChanged(object sender, EventArgs e)
        {

        }

        // Лабораторные часы
        private void richTextBox3_TextChanged(object sender, EventArgs e)
        {

        }

        // Преподаватель
        private void maskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        // Кафедры
        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        // Аудитория
        private void richTextBox4_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
