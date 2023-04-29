using LR9_11.Commands;
using LR9_11.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using System.Xml.Linq;

namespace LR9_11.ViewModels
{
    internal class TeacherViewModel : ViewModelBase
    {
        #region Data
        private Teacher teacher;
        public Teacher Teacher
        {
            get { return teacher; }
            set 
            { 
                teacher = value;
                OnPropertyChanged("Teacher");
            }
        }

        public TeacherViewModel(Teacher teacher)
        {
            this.Teacher = teacher;
        }
        public DateTime Date
        {
            get { return teacher.date; }
            set
            {
                teacher.date = value;
                OnPropertyChanged("Date");
            }
        }

        public string Subject
        {
            get { return teacher.subject; }
            set
            {
                teacher.subject = value;
                OnPropertyChanged("Subject");
            }
        }

        public string FIO
        {
            get { return teacher.fio; }
            set
            {
                teacher.fio = value;
                OnPropertyChanged("FIO");
            }
        }

        public int Time
        {
            get { return teacher.time; }
            set
            {
                teacher.time = value;
                OnPropertyChanged("Time");
            }
        }
        #endregion

        #region Command


        #endregion
    }
}
