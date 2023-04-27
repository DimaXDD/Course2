using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab11
{
    public class UnitOfWork : IDisposable
    {
        private readonly Context _context;
        private readonly Repository<Course> _courseRepository;
        private readonly Repository<Student> _studentRepository;
        private readonly Repository<Lecturer> _lecturerRepository;

        public UnitOfWork(Context context)
        {
            _context = context;
            _courseRepository = new Repository<Course>(_context);
            _studentRepository = new Repository<Student>(_context);
            _lecturerRepository = new Repository<Lecturer>(_context);
        }

        public Repository<Course> CourseRepository => _courseRepository;

        public Repository<Student> StudentRepository => _studentRepository;

        public Repository<Lecturer> LecturerRepository => _lecturerRepository;

        public void SaveChanges()
        {
            _context.SaveChanges();
        }

        public void Dispose()
        {
            _context.Dispose();
        }
    }

}
