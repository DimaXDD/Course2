using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab11
{
    public class Course
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Hours { get; set; }
        public Lecturer Lecturer { get; set; }
        public int MaxStudents { get; set; }
        public List<Student> Students { get; set; }
    }
}
