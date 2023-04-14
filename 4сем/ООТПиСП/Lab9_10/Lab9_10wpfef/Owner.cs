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
        public int ID { get; set; }
        public string FIO { get; set;}
        public DateTime BirthDate { get; set; }
        public string PhoneNumber { get; set; }
        public string PassportInfo { get; set; }
        public List<PersonalBill> PersonalBills { get; set;}

    }
}
