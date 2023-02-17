using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ControlWork2
{
    public class NewDic<T, R>
    {
        public Dictionary<T, R> dictionary = new Dictionary<T, R>();

        public void Add(T key, R value)
        {
            dictionary.Add(key, value);
        }

        public R Find(T key)
        {
            if (dictionary.ContainsKey(key))
            {
                return dictionary[key];
            }
            else
            {
                throw new Exception("Такого ключа нет");
            }
        }
    }



    public class Program
    {

        static void Main(string[] args)
        {
            Console.WriteLine("=====NewDic=====");
            NewDic<int, string> newDic = new NewDic<int, string>();
            newDic.Add(1, "one");
            newDic.Add(2, "two");
            newDic.Add(3, "three");
            newDic.Add(4, "four");
            newDic.Add(5, "five");

            Console.WriteLine(newDic.Find(1));
            Console.WriteLine(newDic.Find(2));
            Console.WriteLine(newDic.Find(3));
            Console.WriteLine(newDic.Find(4));
            Console.WriteLine(newDic.Find(5));
            //Console.WriteLine(newDic.Find(6));

            string[] str = { "Dima", "Andrey", "Pasha", "Roma", "Sasha" };
            var str2 = str.Take(4).OrderBy(x => x);
            Console.WriteLine("=====LINQ=====");
            foreach (var item in str2)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("=====Delegate=====");
            Del2 del2 = new Del2(First);
            del2 += Second;
            del2 += Third;

            del2.Invoke("Новый");
            del2.Invoke("13");
            del2.Invoke("Январь");
            Console.WriteLine();

        }

        public delegate void Del2(string k);

        public static void First(string k)
        {
            Console.WriteLine(k + " " + "телефон");
        }

        public static void Second(string k)
        {
            Console.WriteLine(k + " " + "2022");
        }

        public static void Third(string k)
        {
            Console.WriteLine(k + " " + "месяц");
        }
    }
}
