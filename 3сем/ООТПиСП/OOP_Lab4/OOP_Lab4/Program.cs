using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Создание объекта класса Water");
            Water water = new Water(10, 20, 33);
            water.Info();
            water.InfoTemp();
            water.Sum();
            Console.WriteLine("\nСоздание объекта класса Sea, наследующего класс Water");
            Sea sea = new Sea("Черное море", 100, 200, 330);
            sea.Info(); sea.InfoTemp(); sea.Sum();
            Console.WriteLine("\nIs и As");
            if (water is Water)
            {
                Water Water1 = water;
                Water1.InfoTemp();
            }
            if (water is IWater)
            {
                IWater Water2 = water;
                Water2.Sum();
            }
            Console.WriteLine(water is Water);
            Console.WriteLine("\nСоздание двух объектов класса Land");
            Land land = new Land(110, "Грунт", "Ровнина");
            Land land1 = new Land(1, "Песок", "Горы");
            Console.WriteLine();
            Console.WriteLine(land.ToString());
            Console.WriteLine(land.Clone(land1));
            Console.WriteLine("Клонированный объект: " + land.ToString());
            Console.WriteLine();
            Console.WriteLine(((IClone)land).Clone(land1));
            Console.WriteLine();
            Island island = new Island("Полуостров", "Корсико", 12, "Грунт", "Ровнина");
            Continent continent = new Continent("Умеренный", "Евразия", 24, "Ползолистая", "Холмы");

            Printer print = new Printer();
            print.IAmPrinting(land);
            print.IAmPrinting(island);
            print.IAmPrinting(continent);
        }

    }
}