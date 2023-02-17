using System;

namespace ControlWork1
{
    class Time
    {
        public interface ICheck
        {
            void Check();
        }
        public void Check()
        {
            string str = "";

            int hours = Hours;
            if (hours >= 0 && hours <= 6)
            {
                str = "Ночь";
            }
            else if (hours > 6 && hours <= 12)
            {
                str = "Утро";
            }
            else if (hours > 12 && hours <= 18)
            {
                str = "День";
            }
            else if (hours > 18 && hours < 24)
            {
                str = "Вечер";
            }

            Console.WriteLine(str);

        }

        public int Hours { get; set; }
        public int Minutes { get; set; }
        public int Seconds { get; set; }

        public Time(int hours, int minutes, int seconds)
        {
            Hours = hours;
            Minutes = minutes;
            Seconds = seconds;
        }

        public Time()
        {
            Hours = 0;
            Minutes = 0;
            Seconds = 0;
        }

        public enum TimeOfDay
        {
            AM,
            PM
        }

        public override string ToString()
        {
            TimeOfDay time_format = TimeOfDay.AM;
            int hours = Hours;
            if (hours > 12)
            {
                hours -= 12;
                time_format = TimeOfDay.PM;
            }
            return $"{hours}:{Minutes}:{Seconds} {time_format}";
        }


        public static Time operator <(Time time1, Time time2)
        {
            if (time1.Hours < time2.Hours)
            {
                return time1;
            }
            else if (time1.Hours > time2.Hours)
            {
                return time2;
            }
            else
            {
                if (time1.Minutes < time2.Minutes)
                {
                    return time1;
                }
                else if (time1.Minutes > time2.Minutes)
                {
                    return time2;
                }
                else
                {
                    if (time1.Seconds < time2.Seconds)
                    {
                        return time1;
                    }
                    else if (time1.Seconds > time2.Seconds)
                    {
                        return time2;
                    }
                    else
                    {
                        return time1;
                    }
                }
            }
        }
        public static Time operator >(Time time1, Time time2)
        {

            if (time1.Hours > time2.Hours)
            {
                return time1;
            }
            else if (time1.Hours < time2.Hours)
            {
                return time2;
            }
            else
            {
                if (time1.Minutes > time2.Minutes)
                {
                    return time1;
                }
                else if (time1.Minutes < time2.Minutes)
                {
                    return time2;
                }
                else
                {
                    if (time1.Seconds > time2.Seconds)
                    {
                        return time1;
                    }
                    else if (time1.Seconds < time2.Seconds)
                    {
                        return time2;
                    }
                    else
                    {
                        return time1;
                    }
                }
            }
        }
        public static bool operator ==(Time time1, Time time2)
        {
            if (time1.Hours == time2.Hours && time1.Minutes == time2.Minutes && time1.Seconds == time2.Seconds)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public static bool operator !=(Time time1, Time time2)
        {
            if (time1.Hours != time2.Hours || time1.Minutes != time2.Minutes || time1.Seconds != time2.Seconds)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


    }

    class FullTime : Time
    {

        public interface ICheck
        {
            void Check();
        }
        public FullTime(int hours, int minutes, int seconds) : base(hours, minutes, seconds)
        {

        }

        public void Check()
        {
            int hours = 24 - Hours;
            int minutes = 60 - Minutes;
            if (minutes == 60)
            {
                minutes = 0;
            }
            else
            {
                hours--;
            }
            int seconds = 60 - Seconds;
            if (seconds == 60)
            {
                seconds = 0;
            }
            Console.WriteLine($"До полуночи осталось {hours}ч:{minutes}м:{seconds}с");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int short_max = short.MaxValue;
            Console.WriteLine(short_max);

            // Получить из массива чисел строку, где числа разделены запятыми
            int[] numbers = { 1, 2, 3, 4, 5 };
            string numbers_string = string.Join(",", numbers);
            Console.WriteLine(numbers_string);


            Time time = new Time(12, 30, 45);
            Time time1 = new Time(13, 45, 50);
            Console.WriteLine(time.ToString());
            Console.WriteLine(time1.ToString());

            Console.WriteLine("Сравнение времени");
            Time time2 = time < time1;
            Console.WriteLine(time2);
            Time time3 = time > time1;
            Console.WriteLine(time3);
            Console.WriteLine(time == time1);

            Console.WriteLine("Метод check в классе FullTime");
            FullTime fullTime = new FullTime(20, 20, 0);
            fullTime.Check();

            Console.WriteLine("Метод check в классе Time");
            Time time4 = new Time(13, 30, 45);
            time4.Check();
        }
    }
}
