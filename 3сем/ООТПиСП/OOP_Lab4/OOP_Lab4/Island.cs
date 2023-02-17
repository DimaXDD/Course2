using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab4
{
    class Island : Land
    {
        public string Type { get; set; }
        public string Name { get; set; }
        public Island(string type, string name, int square, string soil, string relief)
        {
            Type = type;
            Name = name;
            Square = square;
            Soil = soil;
            Relief = relief;
        }

        public override string ToString()
        {
            return $"{GetType()} {Type} {Name} {Square} {Soil} {Relief}";
        }
    }
}