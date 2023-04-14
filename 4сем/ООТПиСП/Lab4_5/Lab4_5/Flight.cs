using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4_5
{
    public class Flight
    {
        public int Num { get; set; }
        public string DepartureCity { get; set; }
        public string DestinationCity { get; set; }
        public DateTime DepTime { get; set; }
        public DateTime DestinationTime { get; set; }
        public int Price { get; set; }
    }
}
