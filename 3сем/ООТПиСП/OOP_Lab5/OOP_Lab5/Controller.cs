using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;  

namespace OOP_Lab5
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

        // считывание данных из файла
        static public void ReadFile(Planet planet)
        {
            string[] str = System.IO.File.ReadAllLines(@"E:\2_курс\3сем\ООТПиСП\OOP_Lab5\OOP_Lab5\bin\Debug\input.txt");
            for (int i = 0; i < str.Length; i++)
            {
                string[] str1 = str[i].Split(' ');
                if (str1[0] == "Continent")
                {
                    Continent continent = new Continent(str1[1], str1[2], Convert.ToInt32(str1[3]), str1[4], str1[5]);
                    planet.Add(continent);
                }
                else if (str1[0] == "State")
                {
                    State state = new State(str1[1], str1[2], Convert.ToInt32(str1[3]), str1[4], Convert.ToInt32(str1[5]));
                    planet.Add(state);
                }
                else if (str1[0] == "Island")
                {
                    Island island = new Island(str1[1], str1[2], Convert.ToInt32(str1[3]), str1[4], str1[5]);
                    planet.Add(island);
                }
                else if (str1[0] == "Sea")
                {
                    Sea sea = new Sea(str1[1], Convert.ToInt32(str1[2]), Convert.ToInt32(str1[3]), Convert.ToInt32(str1[4]));
                    planet.Add(sea);
                }
            }
        }
    }

}
