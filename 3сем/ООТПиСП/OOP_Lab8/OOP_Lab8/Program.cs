using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab8
{
    class Program
    {
        static void Main(string[] args)
        {
            Programmer p1 = new Programmer("Дмитрий");

            //создать некоторое количество объектов (языков программирования)
            ProgrammingLanguage Lang1 = new ProgrammingLanguage("JavaScript", 4.5f, "Add", "Del", "Rename");
            ProgrammingLanguage Lang2 = new ProgrammingLanguage("C#", 7.0f, "Add", "Del");

            Console.WriteLine(Lang1);
            Console.WriteLine("--------------------------------------------------");
            Console.WriteLine(Lang2);
            Console.WriteLine("--------------------------------------------------");

            //Подпишите объекты на события произвольным образом.
            p1.Rename += Lang1.Rename_L;
            p1.Rename += Lang2.Rename_L;
            p1.NewProperty += Lang1.Add;
            p1.NewProperty += Lang1.Add;
            p1.NewProperty += Lang2.Add;
            p1.NewProperty += Lang2.Add;
            p1.NewProperty += Lang1.Delete;
            p1.NewProperty += Lang2.Delete;


            //Реакция на события может быть следующая: изменение имени/версии, добавление новых операций, технологий или понятий.
            p1.CommandRenaneOperation();
            p1.CommandAddOperation();

            Console.WriteLine(Lang1);
            Console.WriteLine("--------------------------------------------------");
            Console.WriteLine(Lang2);
            Console.WriteLine("--------------------------------------------------");
            


            #region Delegate
            Func<string, string> test1;  //обобщенный делегат, второй параметр - возврат 
            Action<string> test2;       //не возвр значений
            Func<string, string> test3;
            Func<string, string> test4;
            Func<string, string> test5;
            test1 = str1 =>
            {  //блочное лямбда-выражение(упрощенная запись анонимных методов) 
                char[] sign = { '.', ',', '!', '?', '-', ':' };
                for (int i = 0; i < str1.Length; i++)
                {
                    if (sign.Contains(str1[i]))
                    {
                        str1 = str1.Remove(i, 1);
                    }
                }
                Console.WriteLine(str1);
                return str1;
            };
            test2 = delegate (string str2)   //анонимный метод
            {
                str2 += " World";
                Console.WriteLine(str2);
            };
            test3 = str3 =>
            {
                str3 = str3.Replace(" ", string.Empty);
                Console.WriteLine(str3);
                return str3;
            };
            test4 = str4 =>
            {
                str4 = str4.ToUpper();
                Console.WriteLine(str4);
                return str4;
            };
            test5 = str5 =>
            {
                str5 = str5.ToLower();
                Console.WriteLine(str5);
                return str5;
            };

            string str = "Hel?lo!";
            Console.WriteLine("Строка в начале: " + str);
            Console.WriteLine("Строки в конце: ");
            string s1, s2, s3;
            s1 = StringWork.RemoveS(str, test1);
            StringWork.AddToString(s1, test2);
            s2 = StringWork.RemoveSpaces(s1, test3);
            s3 = StringWork.Upper(s2, test4);
            StringWork.Lower(s3, test5);
            #endregion
        }
    }
}

