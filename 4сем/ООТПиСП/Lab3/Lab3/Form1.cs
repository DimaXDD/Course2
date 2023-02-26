using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace Lab3
{
    public partial class Form1 : Form
    {

        // Поле для ввода дисциплины
        private void richTextBox1_TextChanged(object sender, EventArgs e) { }

        // Поле для ввода специальности
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e) { }

        // Поле для ввода курса
        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e) { }

        // Поле для ввода семестра
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e) { }

        // Радиокнопка для выбора варианта "Зачет"
        private void radioButton1_CheckedChanged(object sender, EventArgs e) { }

        // Радиокнопка для выбора варианта "Экзамен"
        private void radioButton2_CheckedChanged(object sender, EventArgs e) { }

        // Поле для ввода количества часов лекций
        private void richTextBox2_TextChanged(object sender, EventArgs e) { }

        // Поле для ввода количества часов лабораторных
        private void richTextBox3_TextChanged(object sender, EventArgs e) { }

        // Поле для ввода преподавателя
        private void maskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e) { }

        // Кафедры
        private void listBox2_SelectedIndexChanged(object sender, EventArgs e) { }

        // Поле для ввода аудитории
        private void richTextBox4_TextChanged(object sender, EventArgs e) { }

        // Ссылка на сайт
        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("https://www.belstu.by/fakultety");
        }

        // список, в котором хранятся все объекты
        public List<Discipline> listOfDisciplines = new List<Discipline>();

        // путь по которому будем записывать в xml-файл один(!) объект
        string path = @"E:\2_курс\4сем\ООТПиСП\Lab3\Lab3\out.xml";

        // счетчик кол-ва объектов для нижней строки состояния
        public int numOfObjects = 0;

        // поля для даты\времени
        ToolStripLabel dateLabel;
        ToolStripLabel timeLabel;
        ToolStripLabel infoLabel;
        ToolStripLabel eventLabel;
        Timer timer;

        // поля для передачи данных для сохранения
        IEnumerable<Discipline> listSearchLectorNameToSave = new List<Discipline>();

        public Form1()
        {
            InitializeComponent();
            // счетчик кол-ва объектов для нижней строки состояния
            toolStripStatusLabel1.Text += "0   ";
            // код с метанита для таймера даты и времени
            infoLabel = new ToolStripLabel();
            infoLabel.Text = "Текущие дата и время:";
            dateLabel = new ToolStripLabel();
            timeLabel = new ToolStripLabel();
            eventLabel = new ToolStripLabel();

            statusStrip1.Items.Add(infoLabel);
            statusStrip1.Items.Add(dateLabel);
            statusStrip1.Items.Add(timeLabel);
            statusStrip1.Items.Add(eventLabel);

            timer = new Timer() { Interval = 1000 };
            timer.Tick += timer_Tick;
            timer.Start();
        }

        void timer_Tick(object sender, EventArgs e)
        {
            dateLabel.Text = DateTime.Now.ToLongDateString();
            timeLabel.Text = DateTime.Now.ToLongTimeString();
        }

        public void ExceptionsCheck()
        {
            if (richTextBox1.Text == "")
            {
                throw new Exception("Не введена дисциплина!");
            }
            if (listBox1.SelectedIndex == -1)
            {
                throw new Exception("Не выбрана специальность!");
            }
            if (checkedListBox1.SelectedIndex == -1)
            {
                throw new Exception("Не выбран курс!");
            }
            if (comboBox1.SelectedIndex == -1)
            {
                throw new Exception("Не выбран семестр!");
            }
            if (richTextBox2.Text == "")
            {
                throw new Exception("Не введено количество часов лекций!");
            }
            if (richTextBox3.Text == "")
            {
                throw new Exception("Не введено количество часов лабораторных!");
            }
            if (maskedTextBox1.Text == "")
            {
                throw new Exception("Не введено имя преподавателя!");
            }
            if (listBox2.SelectedIndex == -1)
            {
                throw new Exception("Не выбрана кафедра!");
            }
            if (richTextBox4.Text == "")
            {
                throw new Exception("Не введена аудитория!");
            }
        }

        // Ввести дисциплину в объект (первая кнопка)
        private void button2_Click(object sender, EventArgs e)
        {
            ExceptionsCheck();  // вызов проверки корректности
            List<string> tempCourse = new List<string>();
            List<string> tempSpec = new List<string>();
            Lector tempLect = new Lector((string)listBox2.SelectedItem, maskedTextBox1.Text, richTextBox4.Text);
            string tempRadio = "";

            // перебор курсов
            foreach (var item in checkedListBox1.CheckedItems)
            {
                tempCourse.Add(item.ToString());
            }

            // перебор специальностей
            foreach (var item in listBox1.SelectedItems)
            {
                tempSpec.Add(item.ToString());
            }

            // перебор радиокнопок
            if (radioButton1.Checked)
            {
                tempRadio = radioButton1.Text;
            }
            else if (radioButton2.Checked)
            {
                tempRadio = radioButton2.Text;
            }

            var discToAdd = new Discipline(richTextBox1.Text, comboBox1.Text, tempCourse, tempSpec, Int32.Parse(richTextBox2.Text),
                Int32.Parse(richTextBox3.Text), tempRadio, tempLect);

            var results = new List<ValidationResult>();
            var context = new ValidationContext(discToAdd);
            if (Validator.TryValidateObject(discToAdd, context, results, true))
            {
                /// вывод сообщения что всё окей
                listOfDisciplines.Add(discToAdd);
                MessageBox.Show("Дисциплина проходит валидацию.\nИнформация записана в объект!", "DisciplineRedact", MessageBoxButtons.OK);
            }
            else
            {
                foreach (var error in results)
                    MessageBox.Show($"Ошибка: {error.ErrorMessage}");
                MessageBox.Show("Дисциплина не проходит валидацию.\nИнформация не записана.");
            }
            eventLabel.Text = "Сохранено в объект.";


            // а вот и код с третьей лабы для нижней строки состояния
            toolStripStatusLabel1.Text = "Кол-во объектов: " + listOfDisciplines.Count + "   ";
        }

        // Вывести на экран (вторая кнопка)
        private void button3_Click(object sender, EventArgs e)
        {
            string result = "==============================================\n\n";
            foreach (Discipline dist in listOfDisciplines)
                result += dist.ToString();
            eventLabel.Text = "Выведено на экран.";
            MessageBox.Show(result);
        }

        // Сохранить в файл (третья кнопка)
        private void button4_Click(object sender, EventArgs e)
        {
            /// обычный код для сериализации в XML
            XmlSerializer formatter = new XmlSerializer(typeof(List<Discipline>));

            using (FileStream fs = new FileStream(path, FileMode.Create))
            {
                formatter.Serialize(fs, listOfDisciplines);
            }
            eventLabel.Text = "Сохранено в файл.";
            MessageBox.Show("Информация записана в XML!", "DisciplineRedact", MessageBoxButtons.OK);
        }

        // Вывести из файла (четвертая кнопка)
        private void button5_Click(object sender, EventArgs e)
        {
            // обычный код для десериализации из XML
            XmlSerializer formatter = new XmlSerializer(typeof(List<Discipline>));
            List<Discipline> listOutOfFile = new List<Discipline>();

            using (FileStream fs = new FileStream(path, FileMode.OpenOrCreate))
            {
                listOutOfFile = (List<Discipline>)formatter.Deserialize(fs);
            }

            Discipline disOut = listOutOfFile[0];

            richTextBox1.Text = disOut.Name;
            comboBox1.Text = disOut.Semester;
            richTextBox2.Text = disOut.NumberOfLections.ToString();
            richTextBox3.Text = disOut.NumberOfLabs.ToString();

            if (disOut.Control == radioButton1.Text)
                radioButton1.Checked = true;
            else if (disOut.Control == radioButton2.Text)
                radioButton2.Checked = true;

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

            maskedTextBox1.Text = disOut.lector.Name;
            for (int i = 0; i < listBox2.Items.Count; i++)
                if (disOut.lector.Department == listBox2.Items[i].ToString())
                    listBox2.SetSelected(i, true);
            richTextBox2.Text = disOut.lector.Auditorium;

            eventLabel.Text = "Выведено из файла.";

            // сообщение о том что всё окей
            MessageBox.Show("Информация выведена!", "DisciplineRedact", MessageBoxButtons.OK);
        }


        // Кнопка "О программе"
        private void оПрограммеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            eventLabel.Text = "О программе.";
            MessageBox.Show("Версия v.0.1\nТрубач Дмитрий", "DisciplineRedact", MessageBoxButtons.OK);
        }

        // Поиск по лектору
        private void поЛектосуToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 newForm = new Form2(this);
            eventLabel.Text = "Поиск по лектору.";
            newForm.Show();
        }

        // Поиск по семестру
        private void поСеместруToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form3 newForm = new Form3(this);
            eventLabel.Text = "Поиск по семестру.";
            newForm.Show();
        }

        // Поиск по курсу
        private void поКурсуToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form4 newForm = new Form4(this);
            eventLabel.Text = "Поиск по курсу.";
            newForm.Show();
        }

        // Сортировка по кол-ву лекций
        private void поКолвуЛекцийToolStripMenuItem_Click(object sender, EventArgs e)
        {
            List<Discipline> listSortLectures;
            var res = from d in listOfDisciplines
                      orderby d.NumberOfLections
                      select d;

            listSortLectures = res.ToList();

            string result = "==============================================\n\n";
            foreach (Discipline dist in listSortLectures)
                result += dist.ToString();


            string pathSortLectures = @"E:\2_курс\4сем\ООТПиСП\Lab3\Lab3\sortLectures.xml";
            XmlSerializer formatter = new XmlSerializer(typeof(List<Discipline>));
            using (FileStream fs = new FileStream(pathSortLectures, FileMode.Create))
            {
                formatter.Serialize(fs, listSortLectures);
            }
            eventLabel.Text = "Отсортировано по лекциям.";
            MessageBox.Show(result);
        }

        // Сортировка по виду контроля
        private void поВидуКонтроляToolStripMenuItem_Click(object sender, EventArgs e)
        {
            List<Discipline> listSortControl;
            var res = from d in listOfDisciplines
                      orderby d.Control
                      select d;

            listSortControl = res.ToList();

            string result = "==============================================\n\n";
            foreach (Discipline dist in listSortControl)
                result += dist.ToString();

            string pathSortControl = @"E:\2_курс\4сем\ООТПиСП\Lab3\Lab3\sortControl.xml";
            XmlSerializer formatter = new XmlSerializer(typeof(List<Discipline>));
            using (FileStream fs = new FileStream(pathSortControl, FileMode.Create))
            {
                formatter.Serialize(fs, listSortControl);
            }
            eventLabel.Text = "Отсортировано по контролю.";
            MessageBox.Show(result);
        }

        // Сохранить поиск по лектору
        private void поЛекторуToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string pathSearchLector = @"E:\2_курс\4сем\ООТПиСП\Lab3\Lab3\searchLectorName.xml";

            XmlSerializer formatter = new XmlSerializer(typeof(List<Discipline>));
            List<Discipline> listOutOfFileSearchLector = new List<Discipline>();

            using (FileStream fs = new FileStream(pathSearchLector, FileMode.OpenOrCreate))
            {
                listOutOfFileSearchLector = (List<Discipline>)formatter.Deserialize(fs);
            }

            string result = "==============================================\n\n";
            foreach (Discipline dist in listOutOfFileSearchLector)
                result += dist.ToString();
            eventLabel.Text = "Сохранено по лекторам.";
            MessageBox.Show(result);
        }

        // Сохранить поиск по семестру
        private void поСеместруToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            string pathSearchSemester = @"E:\2_курс\4сем\ООТПиСП\Lab3\Lab3\searchSemester.xml";

            XmlSerializer formatter = new XmlSerializer(typeof(List<Discipline>));
            List<Discipline> listOutOfFileSearchSemester = new List<Discipline>();

            using (FileStream fs = new FileStream(pathSearchSemester, FileMode.OpenOrCreate))
            {
                listOutOfFileSearchSemester = (List<Discipline>)formatter.Deserialize(fs);
            }

            string result = "==============================================\n\n";
            foreach (Discipline dist in listOutOfFileSearchSemester)
                result += dist.ToString();
            eventLabel.Text = "Сохранено по семестрам.";
            MessageBox.Show(result);
        }

        private void поКурсуToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            string pathSearchCourse = @"E:\2_курс\4сем\ООТПиСП\Lab3\Lab3\searchCourse.xml";

            XmlSerializer formatter = new XmlSerializer(typeof(List<Discipline>));
            List<Discipline> listOutOfFileSearchCourse = new List<Discipline>();

            using (FileStream fs = new FileStream(pathSearchCourse, FileMode.OpenOrCreate))
            {
                listOutOfFileSearchCourse = (List<Discipline>)formatter.Deserialize(fs);
            }

            string result = "==============================================\n\n";
            foreach (Discipline dist in listOutOfFileSearchCourse)
                result += dist.ToString();
            eventLabel.Text = "Сохранено по курсам.";
            MessageBox.Show(result);
        }

        // Десериализация и вывод на экран сортировки по лекциям
        private void поКолвуЛекцийToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            string pathSortLectures = @"E:\2_курс\4сем\ООТПиСП\Lab3\Lab3\sortLectures.xml";

            XmlSerializer formatter = new XmlSerializer(typeof(List<Discipline>));
            List<Discipline> listOutOfFileSortLectures = new List<Discipline>();

            using (FileStream fs = new FileStream(pathSortLectures, FileMode.OpenOrCreate))
            {
                listOutOfFileSortLectures = (List<Discipline>)formatter.Deserialize(fs);
            }

            string result = "==============================================\n\n";
            foreach (Discipline dist in listOutOfFileSortLectures)
                result += dist.ToString();
            eventLabel.Text = "Сохранен сорт по лекциям.";
            MessageBox.Show(result);
        }

        // Десериализация и вывод на экран сортировки по контролю
        private void поВидуКонтроляToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            string pathSortControl = @"E:\2_курс\4сем\ООТПиСП\Lab3\Lab3\sortControl.xml";

            XmlSerializer formatter = new XmlSerializer(typeof(List<Discipline>));
            List<Discipline> listOutOfFileSortControl = new List<Discipline>();

            using (FileStream fs = new FileStream(pathSortControl, FileMode.OpenOrCreate))
            {
                listOutOfFileSortControl = (List<Discipline>)formatter.Deserialize(fs);
            }

            string result = "==============================================\n\n";
            foreach (Discipline dist in listOutOfFileSortControl)
                result += dist.ToString();
            eventLabel.Text = "Сохранен сорт по контролю.";
            MessageBox.Show(result);
        }


        // Кнопка "Очистить"
        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
            for (int i = 0; i < listBox1.Items.Count; i++)
                listBox1.SetSelected(i, false);
            for (int i = 0; i < checkedListBox1.Items.Count; i++)
                checkedListBox1.SetItemCheckState(i, CheckState.Unchecked);
            comboBox1.Text = "";
            radioButton1.Checked = false;
            radioButton2.Checked = false;
            richTextBox2.Text = "";
            richTextBox3.Text = "";
            maskedTextBox1.Text = "";
            for (int i = 0; i < listBox2.Items.Count; i++)
                listBox2.SetSelected(i, false);
            richTextBox4.Text = "";
            eventLabel.Text = "Очищено.";
        }


        // Кнопка "Удалить"
        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            listOfDisciplines.Clear();
            eventLabel.Text = "Удалено.";
            MessageBox.Show("Список дисциплин очищен.", "DisciplineRedact", MessageBoxButtons.OK);
        }

        // Кнопка "Вперед"
        private void toolStripButton3_Click(object sender, EventArgs e)
        {

        }

        // Кнопка "Назад"
        private void toolStripButton4_Click(object sender, EventArgs e)
        {

        }

        // Кнопка "Скрыть"
        private void toolStripButton5_Click(object sender, EventArgs e)
        {
            toolStrip1.Visible = (toolStrip1.Visible) ? false : true;
            button1.Visible = (button1.Visible) ? false : true;
        }

        // Кнопка "Показать"
        private void button1_Click(object sender, EventArgs e)
        {
            toolStrip1.Visible = true;
            button1.Visible = false;
        }
    }
}
