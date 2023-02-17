using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab10
{
    class Program
    {
        static void Main(string[] args)
        {
            // Задание 1
            Console.WriteLine("Задание 1");
            string[] Month = { "Janyary", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Запрос выбирающий последовательность месяцев с длиной строки равной n");
            Console.ResetColor();
            Console.WriteLine("Введите число n");
            int n1 = Convert.ToInt32(Console.ReadLine());
            // Использование синтаксиса запросов
            IEnumerable<string> result1 = from n in Month
                                          where n.Length == n1
                                          select n;

            //Использование точечной нотации (операции)
            /*IEnumerable<string> result1 = Month
            .Where(n => n.Length == n1)
            .Select(n => n);*/

            Console.WriteLine($"Вывод месяцев, длина которых равна {n1} символа: ");
            foreach (string name in result1)
                Console.WriteLine("{0}", name);
            Console.WriteLine("----------------------------------------\n");

            // Запрос, возвращающий только летние и зимние месяцы
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Запрос, возвращающий только летние и зимние месяцы");
            Console.ResetColor();
            IEnumerable<string> result2 = Month
                 .Where(n => n == "June" || n == "July" || n == "August" || n == "December" || n == "January" || n == "February")
                .Select(n => n);

            foreach (string name in result2)
                Console.WriteLine("{0}", name);
            Console.WriteLine("----------------------------------------\n");

            // Запрос, вывода месяцев в алфавитном порядке
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Запрос, вывода месяцев в алфавитном порядке");
            Console.ResetColor();
            IEnumerable<string> result3 = Month
                .OrderBy(n => n)
                .Select(n => n);

            foreach (string name in result3)
                Console.WriteLine("{0}", name);
            Console.WriteLine("----------------------------------------\n");

            // Запрос, считающий количество месяцев, содержащих букву «u» и длинной строки не менее 4 символов
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Запрос, считающий количество месяцев, содержащих букву «u» и длинной строки не менее 4 символов");
            Console.ResetColor();
            int result4 = Month
                .Where(n => n.Contains("u") && n.Length >= 4)
                .Count();

            Console.WriteLine($"Количество месяцев, содержащих букву «u» и длинной строки не менее 4 символов: {result4}");
            Console.WriteLine("----------------------------------------\n");

            // Задание 2
            Console.WriteLine("Задание 2");
            List<Airline> ListOne = new List<Airline>();
            ListOne.Add(new Airline("Minsk", 1, "Boeing 737", 8, 30, "Monday"));
            ListOne.Add(new Airline("Moscow", 2, "Boeing 747", 9, 45, "Tuesday"));
            ListOne.Add(new Airline("London", 3, "Boeing 777", 10, 15, "Wednesday"));
            ListOne.Add(new Airline("Paris", 4, "Boeing 787", 11, 20, "Thursday"));
            ListOne.Add(new Airline("Berlin", 5, "Boeing 767", 12, 35, "Friday"));
            ListOne.Add(new Airline("Japan", 6, "Boeing 737", 13, 40, "Saturday"));
            ListOne.Add(new Airline("Minsk", 7, "Boeing 747", 14, 55, "Sunday"));
            ListOne.Add(new Airline("Moscow", 8, "Boeing 777", 15, 00, "Monday"));
            ListOne.Add(new Airline("London", 9, "Boeing 787", 16, 25, "Tuesday"));
            ListOne.Add(new Airline("Paris", 10, "Boeing 767", 17, 30, "Wednesday"));

            // Cписок рейсов для заданного пункта назначения
            Console.ForegroundColor = ConsoleColor.DarkYellow;
            Console.WriteLine("Cписок рейсов для заданного пункта назначения");
            Console.ResetColor();
            IEnumerable<Airline> result5 = ListOne
                .Where(n => n.Destination == "Minsk")
                .Select(n => n);

            foreach (Airline name in result5)
                Console.WriteLine("{0}", name);
            Console.WriteLine("----------------------------------------\n");

            // Список рейсов для заданного дня недели
            Console.ForegroundColor = ConsoleColor.DarkYellow;
            Console.WriteLine("Список рейсов для заданного дня недели");
            Console.ResetColor();
            IEnumerable<Airline> result6 = ListOne
                .Where(n => n.DayOfWeek == "Monday")
                .Select(n => n);

            foreach (Airline name in result6)
                Console.WriteLine("{0}", name);
            Console.WriteLine("----------------------------------------\n");

            // Максимальный по дню недели рейс
            Console.ForegroundColor = ConsoleColor.DarkYellow;
            Console.WriteLine("Максимальный по дню недели рейс");
            Console.ResetColor();
            var result7 = ListOne
                .GroupBy(n => n.DayOfWeek)
                .Select(n => new { DayOfWeek = n.Key, Max = n.Max(x => x.FlightNumber) });

            /*IEnumerable<Airline> result7 = (IEnumerable<Airline>)ListOne
                             .GroupBy(n => n.DayOfWeek)
                              .Select(n => new { DayOfWeek = n.Key, Max = n.Max(x => x.FlightNumber) });*/

            foreach (var name in result7)
                Console.WriteLine("{0}", name);
            Console.WriteLine("----------------------------------------\n");

            // Все рейсы в определенный день недели и с самым поздним временем вылета
            Console.ForegroundColor = ConsoleColor.DarkYellow;
            Console.WriteLine("Все рейсы в определенный день недели и с самым поздним временем вылета");
            Console.ResetColor();
            var result8 = ListOne
                .GroupBy(n => n.DayOfWeek)
                .Select(n => new { DayOfWeek = n.Key, MaxHours = n.Max(x => x.HourTime), MaxMinutes = n.Max(x => x.MinuteTime) });

            foreach (var name in result8)
                Console.WriteLine("{0}", name);
            Console.WriteLine("----------------------------------------\n");

            // Упорядоченные по дню и времени рейсы
            Console.ForegroundColor = ConsoleColor.DarkYellow;
            Console.WriteLine("Упорядоченные по дню и времени рейсы");
            Console.ResetColor();
            var result9 = ListOne
                .OrderBy(n => n.DayOfWeek);

            foreach (var name in result9)
                Console.WriteLine("{0}", name);
            Console.WriteLine("----------------------------------------\n");

            // Количество рейсов для заданного типа самолета
            Console.ForegroundColor = ConsoleColor.DarkYellow;
            Console.WriteLine("Количество рейсов для заданного типа самолета");
            Console.ResetColor();
            Console.WriteLine("Введите самолет: ");
            string plane = Convert.ToString(Console.ReadLine());
            var result10 = ListOne
                     .Where(n => n.AircraftType == plane)
                     .Count();

            Console.WriteLine("Количество рейсов для заданного типа самолета: {0}", result10);

            // Задание 4
            Console.WriteLine("Задание 4");
            Console.WriteLine("Собственный запрос: ");
            IEnumerable<Airline> CustomFiltered = from n in ListOne
                                                  where n.Destination.StartsWith("M")
                                                  where n.DayOfWeek == "Monday"
                                                  orderby n.DayOfWeek, n.HourTime, n.MinuteTime
                                                  select n;

            foreach (Airline name in CustomFiltered)
                Console.WriteLine("{0}", name);
            Console.WriteLine("----------------------------------------\n");

            // Задание 5
            Console.WriteLine("Задание 5");
            Console.WriteLine("Запрос с оператором Join");
            IEnumerable<Airline> PartOne = from n in ListOne
                                           where n.HourTime <= 10
                                           select n;

            IEnumerable<Airline> PartTwo = from n in ListOne
                                           where n.HourTime >= 15
                                           join m in ListOne on n.HourTime equals m.HourTime
                                           select n;

            IEnumerable<Airline> JoinResult = PartOne.Union(PartTwo);
            
            foreach (Airline name in JoinResult)
                Console.WriteLine("{0}", name);
            Console.WriteLine("----------------------------------------\n");
        }
    }
}
