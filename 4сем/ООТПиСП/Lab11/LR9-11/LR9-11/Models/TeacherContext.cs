using System;
using System.Data.Entity;
using System.Linq;

namespace LR9_11.Models
{
    public class TeacherContext : DbContext
    {

        public TeacherContext()
            : base("name=TeacherContext")
        {
        }

        public  DbSet<Teacher> Teachers { get; set; }
    }

}