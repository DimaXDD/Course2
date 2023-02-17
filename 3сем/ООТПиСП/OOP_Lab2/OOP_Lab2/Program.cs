using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab2
{
    class Program
      {
        static void Main(string[] args)
        {
            Airline airline1 = new Airline();
            Airline airline2 = new Airline("USA", 124, "Вторник");
            Airline airline3 = new Airline("Moscow");
            Airline airline4 = new Airline(4, "Berlin", 789, "Грузовой", "Четверг", 7, 30);
            Airline airline5 = new Airline(5, "Paris", 422, "Пассажирский", "Пятница", 9, 50);

            Airline[] airlines = { airline1, airline2, airline3, airline4, airline5 };


            Console.WriteLine("Информация о самолётах");
            airline1.Show();
            airline2.Show();
            airline3.Show();
            airline4.Show();
            airline5.Show();

            Airline.ShowStatic();

            Console.WriteLine("Airline-class object: {0}\n"  + 
    "Сравнение: {1}\n" +
    "Свойства вывода / методы: temp2.DepartureTime = {2}; temp2.GetHashCode() = {3}\n",
    airline1.GetType(), airline4.Equals(airline5), airline2.DepartureTime, airline2.GetHashCode());


            foreach (Airline plane in Airline.FindByDayOfWeek(ref airlines, "Понедельник"))
                Console.WriteLine(plane);

            foreach (Airline plane in Airline.FindByDestination(ref airlines, "Paris"))
                Console.WriteLine(plane);


            Console.WriteLine("Анонимный тип");
            var anonymousAirline = new
            {
                id = 213,
                destination = "Mexico",
                flightNumber = 417,
                planeType = "Пассажирский",
                day = "Четверг",
                departureTime = (hours: 7, minutes: 30),
                departureLocation = "Moscow"
            };

            Console.WriteLine(anonymousAirline);
        }
    }
}