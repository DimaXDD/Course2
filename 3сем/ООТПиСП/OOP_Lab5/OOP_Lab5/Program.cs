using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace OOP_Lab5
{
    class Program
    {
        static void Main(string[] args)
        {
            /* Console.WriteLine("Создание объекта класса Water");
             Water water = new Water(10, 20, 33);
             Console.WriteLine("Вывод информации: ");
             water.Info();
             Console.WriteLine("Вывод только температуры: ");
             water.InfoTemp();
             Console.WriteLine("Сумма параметров: ");
             water.Sum();
             Console.WriteLine("----------------------------------------");
             Console.WriteLine("\nСоздание объекта класса Sea, наследующего класс Water");
             Sea sea = new Sea("Черное море", 100, 200, 330);
             Console.WriteLine("Вывод информации: ");
             sea.Info();
             Console.WriteLine("Вывод только температуры: ");
             sea.InfoTemp();
             Console.WriteLine("Сумма параметров: ");
             sea.Sum();
             Console.WriteLine("----------------------------------------");

             Console.WriteLine("\nIs: ");
             if (water is Water) // true
             {
                 Water Water1 = water;
                 Water1.InfoTemp();
             }
             if (water is IWater) // true
             {
                 IWater Water2 = water;
                 Water2.Sum();
             }
             if (sea is Water) // true
             {
                 Water Water3 = sea;
                 Water3.InfoTemp();
             }
             Console.WriteLine("----------------------------------------");
             Console.WriteLine("\nAs: ");
             Console.WriteLine(water as Water);
             Console.WriteLine(water as IWater);
             Console.WriteLine(sea as Water);
             Console.WriteLine("----------------------------------------");
             Console.WriteLine("\nСоздание двух объектов класса Land");
             Land land = new Land(110, "Грунт", "Ровнина");
             Land land1 = new Land(1, "Песок", "Горы");
             Console.WriteLine("Сравнение через Equals: " + land.Equals(land1));
             Console.WriteLine("Метод ToString: " + land.ToString());
             Console.WriteLine("Clone: " + land.Clone(land1));
             Console.WriteLine("Клонированный объект: " + land.ToString());
             Console.WriteLine("Интерфейс IClone: " + ((IClone)land).Clone(land1));
             Console.WriteLine("----------------------------------------");
             Console.WriteLine("Создание объектов Island, Continent, State");
             Island island = new Island("ПолуIsland", "Корсико", 12, "Грунт", "Ровнина");
             Continent continent = new Continent("Умеренный", "Евразия", 24, "Ползолистая", "Холмы");
             State state = new State("Россия", "Путин", 100000000, "Евразия", 24);
             Console.WriteLine();


             Printer print = new Printer();
             print.IAmPrinting(land);
             print.IAmPrinting(island);
             print.IAmPrinting(continent);
             print.IAmPrinting(state);*/
            
            Console.WriteLine("----------------------------------------");
            StructCont structCont = new StructCont((int)Enum.Сентябрь, "Сентябрь");
            Console.WriteLine($"{structCont.Num} - {structCont.Str}");
            Sea sea = new Sea("Черное море", 100, 200, 330);
            Sea sea1 = new Sea("Средиземное море", 11, 67, 125);
            Continent continent = new Continent("Умеренный", "Евразия", 24, "Подзолистая", "Холмы");
            State state = new State("Россия", "Человек", 24, "Евразия", 111);
            State state1 = new State("Чехия", "Человек", 11, "Европа", 139);
            Island island = new Island("Остров", "Крит", 11, "Песок", "Горы");
            Island island1 = new Island("Остров", "Апеннинский", 88, "Подзолистая", "Равнина");
            Island island2 = new Island("Остров", "Корсико", 22, "Грунт", "Склоны");
            
            Planet planet = new Planet(8);
            //planet.Remove(state);

            Console.WriteLine("----------------------------------------");
            string json = JsonSerializer.Serialize(island);
            Console.WriteLine(json);
            Island? restoredIsland = JsonSerializer.Deserialize<Island>(json);
            Console.WriteLine(restoredIsland?.Type);
            Console.WriteLine("----------------------------------------");
            
            
            planet.Add(sea);
            planet.Add(sea1);
            planet.Add(continent);
            planet.Add(state);
            planet.Add(state1);
            planet.Add(island);
            planet.Add(island1);
            planet.Add(island2);
            planet.Out();

            //planet.Add(island);

            Console.WriteLine("----------------------------------------");
            planet.Remove(continent);
            planet.Out();

            Console.WriteLine("----------------------------------------");
            Console.WriteLine($"Количество морей: {Controller.Sea(planet)}");
            Console.WriteLine("----------------------------------------");

            Controller.State(planet, continent);

            Console.WriteLine("----------------------------------------");

            Controller.Island(planet);

            Console.WriteLine("----------------------------------------");

        }

    }
}