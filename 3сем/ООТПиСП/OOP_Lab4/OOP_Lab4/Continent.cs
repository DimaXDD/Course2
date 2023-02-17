using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab4
{
    class Continent : Land
    {
        public string Belt { get; set; }
        public string NameCont { get; set; }
        public Continent() { Belt = "Экваториальный"; NameCont = "Африка"; Square = 130; Soil = "Грунт"; Relief = "Равнина"; }
        public Continent(string belt, string cont, int square, string soil, string relief)
        {
            Belt = belt;
            NameCont = cont;
            Square = square;
            Soil = soil;
            Relief = relief;
        }

        public override string ToString()
        {
            return $"{GetType()} {Belt} {NameCont} {Square} {Soil} {Relief}";
        }
    }
}