using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab9
{
    public class Services
    {
        public string Name { get; set; }
        public int Price { get; set; }
        public Services(string name, int price)
        {
            Name = name;
            Price = price;
        }
        public override string ToString()
        {
            return $"Name: {Name}, Price: {Price}";
        }
    }
}
