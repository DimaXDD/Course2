using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab2
{
    partial class Airline
    {
        #region Fields
        public readonly int id; // только для чтения
        public const string departureLocation = "Minsk"; // константа
        // поля
        private string destination;
        private int? flightNumber;
        private string planeType;
        private (int? hours, int? minutes) departureTime;
        private string day;
        private static int kol_voOject = 0;

        private static string ststr;
        #endregion
            
        #region Methods
        // свойства
        public string Destination
        {
            get => destination;
            set
            {
                destination = value;
            }
        }
        public int? FlightNumber
        {
            get => flightNumber;
            set
            {
                if (value > 0)
                {
                    flightNumber = value;
                }
                else
                {
                    throw new Exception("Номер должен быть положительным");
                }
            }
        }
        public string PlaneType
        {
            get => planeType;
            set
            {
                string[] planeTypes = { "Пассажирский", "Грузовой" };
                if (planeTypes.Contains(value) || value == null)
                {
                    planeType = value;
                }
                else
                {
                    throw new Exception("Тип самолета может быть Пассажирский или Грузовой!");
                }

            }
        }

        public (int? hours, int? minutes) DepartureTime
        {
            get => departureTime;
            set
            {
                if (
                    (value.hours >= 0 && value.hours < 24) &&
                    (value.minutes >= 0 && value.minutes < 60) ||
                    (value.minutes == null && value.minutes == null)
                )
                {
                    departureTime = value;
                }
                else
                {
                    throw new Exception("Время вылета должно быть в диапазоне от 00:00 до 23:59");
                }
            }
        }

        public string Day
        {
            get => day;
            set
            {
                string[] daysOfWeek = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
                if (daysOfWeek.Contains(value) || value == null)
                {
                    day = value;
                }
                else
                {
                    throw new Exception("День недели должен быть в диапазоне от Понедельника до Воскресенья");
                }
            }
        }
        #endregion

        #region Constructors
        // конструкторы
        static Airline()
        {
            Console.WriteLine("Начата работа с AirLine");
        }
                   

        private Airline(int hours, int minutes)
        {
            Console.WriteLine("Приватный конструктор был вызван");
            destination = null;
            flightNumber = null;
            planeType = null;
            departureTime = (hours, minutes);
            day = null;
            kol_voOject++;
        }
        public Airline()
        {
            id = 1;
            destination = "Moscow";
            flightNumber = 154;
            planeType = "Пассажирский";
            departureTime = (12, 45);
            day = "Понедельник";
            kol_voOject++;
        }

        public Airline(string destination, int flightNumber, string day)
        {
            id = 2;
            this.destination = destination;
            this.flightNumber = flightNumber;
            planeType = "Грузовой";
            departureTime = (7, 50);
            this.day = day;
            kol_voOject++;
        }


        public Airline(int id, string destination, int flightNumber, string planeType, string day, int hours, int minutes)
        {
            Console.WriteLine("Конструктор с параметрами был вызван");
            this.id = id;
            this.destination = destination;
            this.flightNumber = flightNumber;
            this.planeType = planeType;
            this.departureTime = (hours, minutes);
            this.day = day;
            kol_voOject++;
        }

        
        public Airline(string destination, int flightNumber = 323)
        {
            this.id = id;
            this.destination = destination;
            this.flightNumber = flightNumber;
            planeType = "Грузовой";
            departureTime = (17, 50);
            day = "Среда";
            kol_voOject++;
        }

        // переопределение методов
        public override bool Equals(object obj)
        {
            Airline al = obj as Airline;

            if (al != null)
            {
                if (
                    al.destination == this.destination && al.flightNumber == this.flightNumber &&
                    al.day == this.day && al.planeType == this.planeType && al.departureTime == this.departureTime
                )
                    return true;
                else return false;
            }
            else return false;
        }
        public override string ToString()
        {
            return $"{"".PadLeft(20, '-')}\n" +
                $"{Airline.departureLocation}-{this.Destination}\n" +
                $"{this.planeType} №{this.flightNumber}\n" +
                $"{this.day} {this.departureTime.hours}:{this.departureTime.minutes}\n" +
                $"{"".PadLeft(20, '-')}\n";
        }

        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }

        // методы
        public static void ShowStatic()
        {
            Console.WriteLine($"Количество объектов: {kol_voOject}");
        }

        public void Show()
        {
            Console.WriteLine(this.ToString());
        }

        #endregion

        #region Tasks
        // поиск по заданному пункту назначения
        public static Airline[] FindByDestination(ref Airline[] arr, string destination)
        {
            return arr.Where(el => el.destination == destination).ToArray();
        }

        // поиск по дню недели
        public static Airline[] FindByDayOfWeek(ref Airline[] arr, string dayOfWeek)
        {
            return arr.Where(el => el.day == dayOfWeek).ToArray();
        }
        #endregion
    }
}
