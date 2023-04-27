using GalaSoft.MvvmLight.Command;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Lab11
{
    public class MainWindowViewModel: INotifyPropertyChanged
    {
        private readonly UnitOfWork _unitOfWork;
        private ObservableCollection<Student> _students;
        private ObservableCollection<Course> _courses;
        private ObservableCollection<Lecturer> _lecturers;
        public MainWindowViewModel()
        {
            _unitOfWork = new UnitOfWork(new Context());
            LoadAll();
            LoadLectures();
            AddStudentsWindowShowCommand = new RelayCommand(AddStudentsWindowShow);
            EditLecturersWindowShowCommand = new RelayCommand(EditLecturersWindowShow);

        }

        public event PropertyChangedEventHandler? PropertyChanged = delegate { };

        public RelayCommand AddStudentsWindowShowCommand { get; set; }
        public RelayCommand EditLecturersWindowShowCommand { get; set; }

        public void AddStudentsWindowShow()
        {
            AddStudentView mdl = new AddStudentView();
            mdl.Show();
        }
        public void EditLecturersWindowShow()
        {
           LecturersEditView lecturersEditView = new LecturersEditView();
            lecturersEditView.Show();
        }
        private void OnPropertyChanged(string propertyName)
        {
            PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
        }

        public ObservableCollection<Student> Students
        {
            get { return _students; }
            set
            {
                _students = value;
                OnPropertyChanged(nameof(Students));
            }
        }
        public ObservableCollection<Course> Courses
        {
            get { return _courses; }
            set
            {
                _courses = value;
                OnPropertyChanged(nameof(Courses));
            }
        }
        public ObservableCollection<Lecturer> Lecturers
        {
            get { return _lecturers; }
            set
            {
                _lecturers = value;
                OnPropertyChanged(nameof(Lecturers));
            }
        }
        public void LoadAll()
        {
            Students = new ObservableCollection<Student>(_unitOfWork.StudentRepository.GetAll().ToList());
            Courses = new ObservableCollection<Course>(_unitOfWork.CourseRepository.GetAll().ToList());
        }
        public void LoadLectures()
        {
            using (var context = new Context())
            {
                var allStudents = context.Lecturers.FromSql(FormattableStringFactory.Create("select * from Lecturers")).ToList();
                Lecturers = new ObservableCollection<Lecturer>(allStudents);
            }
        }
    }
}
