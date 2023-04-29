using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace LR9_11.Models
{
    public class Teacher
    {
        [Key]
        public int TeacherID { get; set; }
        public DateTime date { get; set; }
        public int time { get; set; }
        public string fio { get; set; }
        public string subject { get; set; }

    }
}
