using LR9_11.Models;
using LR9_11.ViewModels;
using LR9_11.Views;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace LR9_11
{
    /// <summary>
    /// Логика взаимодействия для App.xaml
    /// </summary>
    public partial class App : Application
    {
        private void OnStartup(object sender, StartupEventArgs e)
        {
            List<Teacher> teachers;
            using (TeacherContext db = new TeacherContext())
            {
                /*                Teacher teacher = new Teacher();
                                teacher.date = DateTime.Now;
                                teacher.time = 2;
                                teacher.fio = "Fio";
                                teacher.subject = "Subject";

                                db.Teachers.Add(teacher);
                                db.SaveChanges();
                */
                teachers = db.Teachers.ToList<Teacher>();
            }

            MainView view = new MainView(); // создали View
            MainViewModel viewModel = new ViewModels.MainViewModel(teachers); // Создали ViewModel
            view.DataContext = viewModel; // положили ViewModel во View в качестве DataContext
            view.Show();
        }
    }
}