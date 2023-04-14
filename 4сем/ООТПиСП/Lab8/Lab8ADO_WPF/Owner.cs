using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2
{
    [Serializable]
    public class Owner
    {

        public string FIO { get; set;}
        public DateTime birthDate { get; set; }

        public string phoneNumber { get; set; }
        public string wallet { get; set; }

        public string PassportInfo { get; set; }
    }
}
