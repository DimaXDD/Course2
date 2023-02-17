using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab15
{
    static partial class TPL
    {
        // Отличие for от foreach в том, что for позволяет изменять значение счетчика
        // foreach же позволяет только перебирать элементы

        // Параллельный for выполняет итерации в нескольких потоках одновременно, а простой for выполняет итерации последовательно
        // Параллельный foreach выполняет итерации в нескольких потоках одновременно



        public static void Task5()
        {
            Console.WriteLine("-----------Задание 5---------");
            int size = 3000;
            int[] arr = new int[size];
            Random rand = new();

            for (int i = 0; i < size; i++)
            {
                arr[i] = rand.Next(-100000, 100000);
            }

            int[] temp = new int[size];

            arr.CopyTo(temp, 0);

            Stopwatch sw = new();
            sw.Start();
            TPL.Sort(arr);
            sw.Stop();

            Console.WriteLine("Результат пятого задания обычными циклами: " + sw.ElapsedMilliseconds + " мс");

            sw.Reset();
            temp.CopyTo(arr, 0);
            // Parallel.For()
            {
                sw.Start();

                bool isSorted = false;
                while (!isSorted)
                {
                    isSorted = true;
                    Parallel.For(0, size - 2, n =>
                    {
                        if (temp[n].CompareTo(temp[n + 1]) > 0)
                        {
                            int temp1 = temp[n];
                            temp[n] = temp[n + 1];
                            temp[n + 1] = temp1;
                            isSorted = false;
                        }
                    });
                }
                sw.Stop();
            }
            Console.WriteLine("Время выполнения параллельного алгоритма(For): " + sw.ElapsedMilliseconds + " мс");

            sw.Reset();
            // Parallel.ForEach()
            {
                sw.Start();
                List<int> list = arr.ToList();
                int min = int.MaxValue;
                Index index = 0;

                for (int i = 0; i < arr.Length; i++)
                {
                    list = arr[i..].ToList();
                    min = int.MaxValue;

                    Parallel.ForEach(list, el =>
                    {
                        if (min > el)
                        {
                            min = el;
                            index = Array.IndexOf(arr, min);
                        }
                    });

                    arr[index] = arr[i];
                    arr[i] = min;
                }

                sw.Stop();
            }

            Console.WriteLine("Время выполнения параллельного алгоритма(ForEach): " + sw.ElapsedMilliseconds + " мс");
        }

        public static T[] Sort<T>(T[] arr) where T : IComparable
        {
            bool isSorted = false;

            while (!isSorted)
            {
                isSorted = true;
                for (int i = 0; i < arr.Length - 2; i++)
                {
                    if (arr[i].CompareTo(arr[i + 1]) > 0)
                    {
                        T temp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = temp;
                        isSorted = false;
                    }
                }
            }

            return arr;
        }
    }
}
