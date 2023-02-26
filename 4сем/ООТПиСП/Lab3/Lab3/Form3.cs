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

namespace Lab3
{
    public partial class Form3 : Form
    {
        public Form3() { InitializeComponent(); }
        public void richTextBox1_TextChanged(object sender, EventArgs e) { }

        public Form1 form1;
        List<Discipline> listOfDisciplines = new List<Discipline>();
        List<Discipline> listSearchSemesterToSave = new List<Discipline>();
        string path = @"E:\2_курс\4сем\ООТПиСП\Lab3\Lab3\searchSemester.xml";


        public Form3(Form1 f)
        {
            InitializeComponent();
            form1 = f;
            listOfDisciplines = form1.listOfDisciplines;
        }

        private void button1_Click(object sender, EventArgs e)   /// кнопка поиска; сразу выводит
        {
            DataTransfer.semesterSearch = richTextBox1.Text;
            string searchSemesterOut = "==============================================\n\n";

            string semesterSearch = DataTransfer.semesterSearch;
            List<Discipline> semesterList = new List<Discipline>();

            var res = from dist in listOfDisciplines
                      where dist.Semester == semesterSearch
                      select dist;
            foreach (Discipline dis in res)
                searchSemesterOut += dis.ToString();
            MessageBox.Show(searchSemesterOut);

            listSearchSemesterToSave = res.ToList();
            XmlSerializer formatter = new XmlSerializer(typeof(List<Discipline>));

            using (FileStream fs = new FileStream(path, FileMode.Create))
            {
                formatter.Serialize(fs, listSearchSemesterToSave);
            }

            Close();
        }
    }
}
