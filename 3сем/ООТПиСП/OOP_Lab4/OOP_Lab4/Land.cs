
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab4
{
    class Land : ForClone, IClone
    {
        public int Square { get; set; }
        public string Soil { get; set; }
        public string Relief { get; set; }

        public Land() { Square = 10; Soil = "песок"; Relief = "Горы"; }
        public Land(int square, string soil, string relief)
        {
            Square = square;
            Soil = soil;
            Relief = relief;
        }

        public override bool Clone(object Obj)
        {
            Land land = (Land)Obj;
            Square = land.Square;
            Soil = land.Soil;
            Relief = land.Relief;
            Console.WriteLine("Клонирование успешно");
            return true;
        }

        bool IClone.Clone(object Obj)
        {
            Land land = (Land)Obj;
            Console.WriteLine($"Площадь - {Square}, Почва - {Soil}, Рельеф - {Relief}");
            return true;
        }

        public override string ToString()
        {
            return $"{GetType()} {Square} {Soil} {Relief}";
        }
    }
}