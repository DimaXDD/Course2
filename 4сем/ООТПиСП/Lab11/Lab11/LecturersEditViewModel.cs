using GalaSoft.MvvmLight.CommandWpf;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab11
{
    public class LecturersEditViewModel: INotifyPropertyChanged
    {
        private readonly UnitOfWork _unitOfWork;
        private Lecturer _selectedLecturer = new Lecturer();
        private ObservableCollection<Course> _courses;
        private Course _selectedCourse = new Course();
        private Repository<Course> reposCourses = new Repository<Course>(new Context());
        private Repository<Lecturer> reposLecturer = new Repository<Lecturer>(new Context());

        
        public LecturersEditViewModel()
        {
            _unitOfWork = new UnitOfWork(new Context());
            AddLecturerCommand = new RelayCommand(AddLecturer);
            UpdateLecturerCommand = new RelayCommand(UpdateLecturerOnCourse);


        }

        public event PropertyChangedEventHandler? PropertyChanged = delegate { };
        public RelayCommand AddLecturerCommand { get; set; }
        public RelayCommand UpdateLecturerCommand { get; set; }
        public Lecturer SelectedLecturer
        {
            get { return _selectedLecturer; }
            set
            {
                _selectedLecturer = value;
                OnPropertyChanged(nameof(_selectedLecturer));
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
        private void OnPropertyChanged(string propertyName)
        {
            PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
        }
        public List<Course> Courses => _unitOfWork.CourseRepository.GetAll().ToList();
        public void AddLecturer()
        {
            _unitOfWork.LecturerRepository.Add(SelectedLecturer);
            _unitOfWork.SaveChanges();
            SelectedCourse = null;
        }
        public void UpdateLecturerOnCourse()
        {
            SelectedCourse.Lecturer = SelectedLecturer;
           // _unitOfWork.CourseRepository.Update(SelectedCourse);
            _unitOfWork.SaveChanges();
            SelectedCourse = null;
            SelectedLecturer = null;
        }
    }
}
