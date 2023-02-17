using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;   

namespace OOP_Lab1
{
    class Program
    {
        static void Main(string[] args)
        {
            //1) типы данных
            //a)
            bool bool_var = true;
            byte byte_var = 255;
            sbyte sbyte_var = -128;
            char char_var = 'a'; 
            decimal decimal_var = 1.2m; 
            double double_var = 1.2d; 
            float float_var = 1.2f; 
            int int_var = -10; 
            uint uint_var = uint.MaxValue; 
            nint nint_var = nint.MaxValue; 
            nuint nuint_var = 45; 
            long long_var = long.MaxValue; 
            ulong ulong_var = 123456789; 
            short short_var = short.MinValue;
            ushort ushort_var = ushort.MaxValue; 

            Console.WriteLine($"bool_var = {bool_var} - byte_var = {byte_var} - sbyte_var = {sbyte_var} - char_var = {char_var} - decimal_var = {decimal_var} - double_var = {double_var} - float_var = {float_var} - int_var = {int_var} - uint_var = {uint_var} - nint_var = {nint_var} - nuint_var = {nuint_var} - long_var = {long_var} - ulong_var = {ulong_var} - short_var = {short_var} - ushort_var = {ushort_var}");

            Console.WriteLine("\n" + "Ввод данных");
            bool bool1 = bool.Parse(Console.ReadLine());
            byte byte1 = byte.Parse(Console.ReadLine());
            sbyte sbyte1 = sbyte.Parse(Console.ReadLine());
            char char1 = char.Parse(Console.ReadLine());
            decimal decimal1 = decimal.Parse(Console.ReadLine());
            double double1 = double.Parse(Console.ReadLine());
            float float1 = float.Parse(Console.ReadLine());
            int int1 = int.Parse(Console.ReadLine());
            uint uint1 = uint.Parse(Console.ReadLine());
            nint nint1 = nint.Parse(Console.ReadLine());
            nuint nuint1 = nuint.Parse(Console.ReadLine());
            long long1 = long.Parse(Console.ReadLine());
            ulong ulong1 = ulong.Parse(Console.ReadLine());
            short short1 = short.Parse(Console.ReadLine());
            ushort ushort1 = ushort.Parse(Console.ReadLine());

            Console.WriteLine($"bool1 = {bool1} - byte1 = {byte1} - sbyte1 = {sbyte1} - char1 = {char1} - decimal1 = {decimal1} - double1 = {double1} - float1 = {float1} - int1 = {int1} - uint1 = {uint1} - nint1 = {nint1} - nuint1 = {nuint1} - long1 = {long1} - ulong1 = {ulong1} - short1 = {short1} - ushort1 = {ushort1}");
         
            Console.WriteLine("\n" + "Явное преобразование");

            //б) 5 операций явного и неявного приведения

            // Явное

            int firstint = 10;
            int secondint = 2;
            byte thirdint = (byte)(firstint + secondint);
            Console.WriteLine($"thirdint = {thirdint}");
            
            
            char firstchar = 'a';
            string secondchar = firstchar.ToString();
            Console.WriteLine($"secondchar = {secondchar}");

            
            double firstdouble = 4.0d;
            decimal seconddouble = (decimal)(firstdouble);
            Console.WriteLine($"seconddouble = {seconddouble}");

            
            double nextdouble = 5.5d;
            float nexttdouble = (float)nextdouble;
            Console.WriteLine($"nexttdouble = {nexttdouble}");

            
            string firststring = "5";
            int secondstring = int.Parse(firststring);
            Console.WriteLine($"secondstring = {secondstring}");

            //Неявное преобразование
            Console.WriteLine("\n" + "Неявное преобразование");
            byte b = 5;
            short s = b;
            int i = b;
            long l = b;
            float f = b;
            double d = b;
            Console.WriteLine($"{b}-{b.GetType()}\n{s}-{s.GetType()}\n{i}-{i.GetType()}\n{l}-{l.GetType()}\n{f}-{f.GetType()}\n{d}-{d.GetType()}");
            
            //c
            Console.WriteLine("\n" + "Упаковка и распаковка");
            int number = 11;
            object obj = number;
            Console.WriteLine(obj);
            int number2 = (int)obj;
            Console.WriteLine(number2 + " " + number2.GetType());

            //d
            //Работа с неявно типизированными переменными
            Console.WriteLine("\n" + "Неявно типизированные переменные");
            var firstvar = 10;
            var secondvar = 2.5;
            var thirdvar = "Hello";
            var fourthvar = 'a';
            var fifthvar = true;
            Console.WriteLine($"firstvar = {firstvar} - {firstvar.GetType()}");
            Console.WriteLine($"secondvar = {secondvar} - {secondvar.GetType()}");
            Console.WriteLine($"thirdvar = {thirdvar} - {thirdvar.GetType()}");
            Console.WriteLine($"fourthvar = {fourthvar} - {fourthvar.GetType()}");
            Console.WriteLine($"fifthvar = {fifthvar} - {fifthvar.GetType()}");

            //e
            Console.WriteLine("\n" + "Работа с Nullable переменной");
            int? nullableInt = null;
            Console.WriteLine(nullableInt);
            nullableInt = 5;
            Console.WriteLine(nullableInt);
            Console.WriteLine(nullableInt.HasValue);
            Console.WriteLine(nullableInt.Value);

            //f
            Console.WriteLine("\n" + "Объявление через var");
            // var check = true;
            // check = 14;





            //2) Строки

            //а)
            var strFirstVar = "123";
            var strSecondVar = "456";
            Console.WriteLine($"{strFirstVar == strSecondVar}");

            //б)
            var stringFirstVar = "Dmitry";
            var stringSecondVar = "Trubach";
            var stringThirdVar = "Belarusian state technological university";
            //сцепление
            Console.WriteLine($"{string.Concat(stringFirstVar, stringSecondVar, stringThirdVar)} - сцепление");
            //копирование
            Console.WriteLine($"{string.Copy(stringSecondVar)} - копирование");
            //выделение подстроки
            Console.WriteLine($"{stringThirdVar.Substring(0, 7)} - подстрока");
            //разделение строки на слова
            string[] Words = stringThirdVar.Split(new[] { ' ' });
            foreach (string word in Words) Console.Write($"{word} | ");
            //вставка подстроки в заданную позицию
            Console.WriteLine($"\n{stringThirdVar.Insert(0, "Hello ")} - вставка подстроки");
            //удаление заданной подстроки
            Console.WriteLine($"{stringThirdVar.Remove(0, 7)} - удаление подстроки");

            //с)
            Console.WriteLine("\n" + "Пустая и null строка");
            string str = string.Empty;
            string str1 = null;
            Console.WriteLine(string.IsNullOrEmpty(str));
            Console.WriteLine(string.IsNullOrEmpty(str1));

            //d)
            Console.WriteLine("\n" + "Строка на основе StringBuilder");
            StringBuilder str0 = new StringBuilder("Hello");
            str0.Remove(0, 2);
            Console.WriteLine(str0);
            str0.Insert(0, "Hi");
            Console.WriteLine(str0);
            str0.Append("!");
            Console.WriteLine(str0);


            //3)Массивы
            //a)
            Console.WriteLine("\n" + "Двумерный массив");
            //Создайте целый двумерный массив и выведите его на консоль в отформатированном виде(матрица)
            int[,] numbers = { { 1, 2, 3 }, { 4, 5, 6 } };

            int rows = numbers.GetUpperBound(0) + 1;    // количество строк
            int columns = numbers.Length / rows;        // количество столбцов
                                                        // или так
                                                        // int columns = numbers.GetUpperBound(1) + 1;

            for (int cnt = 0; cnt < rows; cnt++)
            {
                for (int j = 0; j < columns; j++)
                {
                    Console.Write($"{numbers[cnt, j]}" + "  ");
                }
                Console.WriteLine();
            }

            //b)
            Console.WriteLine("\n" + "Одномерный массив строк");
            var stringArr = new[] { "One", "Two", "Three" };
            Console.WriteLine("Массив:");
            for (int cnt1 = 0; cnt1 < stringArr.Length; cnt1++)
            {
                Console.Write("{0} ", stringArr[cnt1]);
            }
            Console.WriteLine($"\nДлина массива - {stringArr.Length}");
            Console.WriteLine("Введите номер элемента массива:");
            int index = int.Parse(Console.ReadLine());
            if (index >= stringArr.Length)
                throw new ArgumentOutOfRangeException();
            Console.WriteLine("Введите новое значение элемента массива:");
            string value = Console.ReadLine();
            stringArr[index] = value;
            Console.WriteLine("Массив после изменения:");
            for (int cnt1 = 0; cnt1 < stringArr.Length; cnt1++)
            {
                Console.Write("{0} ", stringArr[cnt1]);
            }

            //c)
            Console.WriteLine("\n" + "Ступенчатый массив с вещественными числами");
            double[][] myArr = new double[3][] { new double[2], new double[3], new double[4] };
            for (int cnt2 = 0; cnt2 < myArr.Length; cnt2++)
            {
                for (int j = 0; j < myArr[cnt2].Length; j++)
                {
                    Console.Write($"myArr[{cnt2}][{j}] = ");
                    myArr[cnt2][j] = double.Parse(Console.ReadLine());
                }
            }
            Console.WriteLine("\n");
            for (int cnt2 = 0; cnt2 < myArr.Length; cnt2++)
            {
                Console.WriteLine(string.Join(" ", myArr[cnt2]));
            }

            //d)
            Console.WriteLine("\n" + "Неявно типизированные переменные для хранения массива и строки");
            var array = new[] { 1, 2, 3, 4, 5 };
            var str_not_type = "Hello";
            Console.WriteLine("Массив:");
            for (int cnt3 = 0; cnt3 < array.Length; cnt3++)
            {
                Console.Write("{0} ", array[cnt3]);
            }
            Console.WriteLine();
            Console.WriteLine("Строка:");
            for (int cnt4 = 0; cnt4 < str.Length; cnt4++)
            {
                Console.Write(str_not_type[cnt4]);
            }

            //4)
            //a)
            var tuple = (1, "Two", '3', "Four", 6ul);
            //b)
            Console.WriteLine("\n" + "Вывод кортежа");
            Console.WriteLine(tuple);
            Console.WriteLine(tuple.Item1);
            Console.WriteLine(tuple.Item3);
            Console.WriteLine(tuple.Item4);
            //c)
            //Выполните распаковку кортежа в переменные
            Console.WriteLine("\n" + "Распаковка кортежа");
            var (a_1, b_1, c_1, d_1, e_1) = tuple;
            Console.WriteLine(a_1);
            Console.WriteLine(b_1);
            Console.WriteLine(c_1);
            Console.WriteLine(d_1);
            Console.WriteLine(e_1);
            //d)
            //Продемонстрируйте различные способы распаковки кортежа. Продемонстрируйте использование переменной(_). 
            Console.WriteLine("\n" + "Использование переменной(_)");
            var (f_1, _, _, j_1, _) = tuple;
            Console.WriteLine(f_1);
            Console.WriteLine(j_1);
            //d) Сравнить два кортежа
            Console.WriteLine("\n" + "Сравнение двух кортежей");
            var tuple1 = (3, "Two", '3', "Four", 6ul);
            Console.WriteLine($"{tuple == tuple1}");

            //5)
            Console.WriteLine("\n" + "Локальная функция");
            static (int, int, int, char) LocalFunction(int[] arrVar, string strVar)
            {
                int maxArrayElement = arrVar.Max();
                int minArrayElement = arrVar.Min();
                int arrayElementsSum = arrVar.Sum();
                char firstStringChar = strVar[0];
                return (maxArrayElement, minArrayElement, arrayElementsSum, firstStringChar);
            }
            //6)
            void CheckedFunc()
            {
                checked
                {
                    int Max = int.MaxValue;
                    Console.WriteLine(Max);
                }
            }
            void Unchecked()
            {
                unchecked
                {
                    int Max = int.MaxValue;
                    Console.WriteLine(Max);
                }
            }
            CheckedFunc();
            Unchecked();
            
        }
    }
}
