using GalaSoft.MvvmLight.Command;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Lab11
{
    public class AddStudentViewModel : INotifyPropertyChanged
    {
        private readonly UnitOfWork _unitOfWork;
        private ObservableCollection<Student> _students;
        private ObservableCollection<Course> _courses;
        private Student _selectedStudent = new Student();
        private Course _selectedCourse = new Course();
        private Repository<Student> repos = new Repository<Student>(new Context());

        public AddStudentViewModel()
        {
            _unitOfWork = new UnitOfWork(new Context());
            LoadStudents();
            SelectedStudent.Courses = new List<Course>();
            _selectedStudent.Courses = new List<Course>();

            AddStudentToCourseCommand = new RelayCommand(AddStudentToCourse);
        }

        public event PropertyChangedEventHandler PropertyChanged = delegate { };

        public ObservableCollection<Student> Students
        {
            get { return _students; }
            set
            {
                _students = value;
                OnPropertyChanged(nameof(Students));
            }
        }

        public List<Course> Courses => _unitOfWork.CourseRepository.GetAll().ToList();


        public Student SelectedStudent
        {
            get { return _selectedStudent; }
            set
            {
                _selectedStudent = value;
                OnPropertyChanged(nameof(SelectedStudent));
            }
        }

        public Course SelectedCourse
        {
            get { return _selectedCourse; }
            set
            {
                _selectedCourse = value;
                OnPropertyChanged(nameof(SelectedCourse));
            }
        }

        public RelayCommand AddStudentToCourseCommand { get; set; }

        private void LoadStudents()
        {
            Students = new ObservableCollection<Student>(_unitOfWork.StudentRepository.GetAll());
        }

        private void AddStudentToCourse()
        {
            // Проверяем, что выбран курс и студент
            if (SelectedCourse == null || SelectedStudent == null)
            {
                return;
            }

            SelectedStudent.Courses.Add(SelectedCourse);
            repos.Add(SelectedStudent);
            _unitOfWork.SaveChanges();

            // Обновляем список записей на курсы
            SelectedCourse = null;
            SelectedStudent = null;
        }

        private void OnPropertyChanged(string propertyName)
        {
            PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
