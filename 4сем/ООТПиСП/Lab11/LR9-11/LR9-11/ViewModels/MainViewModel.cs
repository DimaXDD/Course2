using LR9_11.Commands;
using LR9_11.Models;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace LR9_11.ViewModels
{
    internal class MainViewModel : ViewModelBase
    {
        public ObservableCollection<TeacherViewModel> TeacherList { get; set; }
        public TeacherViewModel selectedTeacher { get; set; }

        #region Constructor

        public MainViewModel(List<Teacher> teachers)
            {
                TeacherList = new ObservableCollection<TeacherViewModel>(teachers.Select(t => new TeacherViewModel(t)));
            }

            #endregion

        public TeacherViewModel SelectedTeacher
        {
            get { return selectedTeacher; }
            set 
            {
                selectedTeacher = value;
                OnPropertyChanged("SelectedTeacher");
            }
        }

        #region Command
        private DelegateCommand addNoteCommand;
        public ICommand AddNoteCommand
        {
            get
            {
                if (addNoteCommand == null)
                {
                    addNoteCommand = new DelegateCommand(AddNote);
                }
                return addNoteCommand;
            }
        }

        private void AddNote()
        {
            if (TeacherList != null)
            {
                Teacher teacher = new Teacher();
                teacher.date = DateTime.Now;
                teacher.time = 2;
                teacher.fio = "Fio";
                teacher.subject = "Subject";
                TeacherList.Add(new TeacherViewModel(teacher));
            }
        }

        /// ////////
        private DelegateCommand deleteNoteCommand;
        public ICommand DeleteNoteCommand
        {
            get
            {
                if (deleteNoteCommand == null)
                {
                    deleteNoteCommand = new DelegateCommand(DeleteNote);
                }
                return deleteNoteCommand;
            }
        }

        private void DeleteNote()
        {
            TeacherList.Remove(selectedTeacher);
        }

        //////////////////////////
        private DelegateCommand saveChangesCommandd;
        public ICommand SaveChangesCommand
        {
            get
            {
                if (saveChangesCommandd == null)
                {
                    saveChangesCommandd = new DelegateCommand(SaveChanges);
                }
                return saveChangesCommandd;
            }
        }

        private void SaveChanges()
        {
            using (TeacherContext db = new TeacherContext())
            {
                List<Teacher> teachers = db.Teachers.ToList<Teacher>();

                foreach (TeacherViewModel tvm in TeacherList)
                {
                    foreach (Teacher t in teachers)
                    {
                        if(tvm.Teacher.TeacherID == t.TeacherID)
                        {
                            teachers.Remove(t);
                            break;
                        }    
                    }

                    db.Teachers.Add(tvm.Teacher);
                }

                db.SaveChanges();
            }
        }


        #endregion
    }
}
