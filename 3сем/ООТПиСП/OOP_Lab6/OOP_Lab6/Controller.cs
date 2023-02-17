using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;  

namespace OOP_Lab6
{
    static class Controller
    {
        static int numOfsea = 0;
        static public int Sea(Planet planet)
        {
            Sea sea = new Sea("", 0 , 0, 0);
            for (int i = 0; i < planet.Size; i++)
            {
                if ((planet.Arr[i]).GetType() == sea.GetType())
                {
                    numOfsea++;
                }
            }
            return numOfsea;
        }

        static public void State(Planet planet, Continent continent)
        {
            State state = new State("", "", 0, "", 0);
            for (int i = 0; i < planet.Size; i++)
            {
                if ((planet.Arr[i]).GetType() == state.GetType())
                {
                    state = (State)planet.Arr[i];
                    if (continent.NameCont == state.NameCont)
                    {
                        Console.WriteLine(state.ToString());
                    }

                }
            }
        }

        static public void Island(Planet planet)
        {
            Island[] str = new Island[10];
            int num = 0;
            Island island = new Island("", "", 0, "", "");
            for (int i = 0; i < planet.Size; i++)
            {
                if ((planet.Arr[i]).GetType() == island.GetType())
                {
                    str[num] = (Island)planet.Arr[i];
                    num++;
                }
            }
            for (int i = 0; i < num - 1; i++)
            {
                if (str[i].Name.CompareTo(str[i + 1].Name) > 0)
                {
                    island = str[i];
                    str[i] = str[i + 1];
                    str[i + 1] = island;
                }
            }
            for (int i = 0; i < num; i++)
            {
                Console.WriteLine(str[i].ToString());
            }
        }

        static public void ZeroEx(int x, int y) 
        {
            if (y == 0)
            {
                throw new Ex3("Деление на 0 невозможно");
            }
            else
            {
                Console.WriteLine($"{x} / {y} = {x / y}");
            }
        }

        static public void FormatEx()
        {
            Console.WriteLine("Введите число");
            int x;
            string input = Console.ReadLine();
            if (Int32.TryParse(input, out x))
            {
                x *= x;
                Console.WriteLine("Квадрат числа: " + x);
            }
            else
            {
                throw new FormatException("Недопустимый формат введенного значения");
            }
        }

        static public void IndexEx()
        {
            int[] arr = new int[5];
            for (int i = 0; i < 5; i++)
            {
                arr[i] = i;
            }
            Console.WriteLine("Введите индекс: ");
            int x;
            string input = Console.ReadLine();
            if (Int32.TryParse(input, out x))
            {
                if (x < 0 || x > 4)
                {
                    throw new IndexOutOfRangeException("Индекс выходит за границы массива");
                }
                else
                {
                    Console.WriteLine("Элемент массива: " + arr[x]);
                }
            }
            else
            {
                throw new FormatException("Недопустимый формат введенного значения");
            }
        }

        static public void AssertEx()
        {
            int aa = 1;
            Debug.Assert(aa != 1, "Некорректно");
        }

        // Debug.Assert нужен для проверки условий, которые должны выполняться во время выполнения программы.
        // Если условие не выполняется, то программа останавливается и выводится сообщение об ошибке.
        // Если условие выполняется, то программа продолжает работу.
        
    }



}
