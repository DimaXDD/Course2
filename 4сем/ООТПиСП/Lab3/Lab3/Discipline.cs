using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab3
{
    [Serializable]
    public class Discipline
    {
        [RegularExpression(@"^[а-яА-Я]{3,10}$")]
        public string Name { get; set; }                /// название дисциплины
        //[RegularExpression(@"^[1-9]?$")]
        [SemesterValidate]
        public string Semester { get; set; }            /// строка со значением семестра
        public List<string> Course { get; set; }        /// курс на котором читается (мб несколько)
        public List<string> Speciality { get; set; }    /// специальность (тоже мб несколько)
        [RegularExpression(@"^\d+$")]
        public int NumberOfLections { get; set; }       /// кол-во лекций
        [RegularExpression(@"^\d+$")]
        public int NumberOfLabs { get; set; }           /// кол-во лабораторных
        public string Control { get; set; }             /// экзамен\зачёт
        public Lector lector { get; set; }              /// лектор (агрегируемый объект)

        public Discipline()                             /// корректный конструктор без параметров
        {
            Course = new List<string>();
            Speciality = new List<string>();
            lector = new Lector();
        }

        /// конструктор который дальше будет использоваться для красивой записи инфы в объект
        public Discipline(string name, string sem, List<string> course, List<string> spec,
            int numLect, int numLabs, string ctrl, Lector lect)
        {
            Name = name;
            Semester = sem;
            Course = course;
            Speciality = spec;
            NumberOfLections = numLect;
            NumberOfLabs = numLabs;
            Control = ctrl;
            lector = lect;
        }

        public override string ToString()   /// вывод инфы об объекте
        {
            string course = "";
            string speciality = "";
            foreach (string c in Course)
                course += c + "; ";
            foreach (string s in Speciality)
                speciality += s + "; ";

            string res = $"Название: {Name}\nКурс: {course}\nСеместр: {Semester}\n" +
                $"Специальность: {speciality}\nЧасов лекций: {NumberOfLections}\n" +
                $"Часов лабораторных: {NumberOfLabs}\nТип контроля: {Control}\n" +
                $"ФИО лектора: {lector.Name}\nКафедра: {lector.Department}\n" +
                $"Аудитория: {lector.Auditorium}\n\n==============================================\n\n";
            return res;
        }
    }




    public class SemesterValidateAttribute : ValidationAttribute
    {
        public override bool IsValid(object value)
        {
            if (value is string semesterName)
            {
                if (semesterName == "1" || semesterName == "2")
                    return true;
                else
                    ErrorMessage = "Некорректный номер семестра.";
            }
            return false;
        }
    }
}
