using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab5
{
    struct StructCont
    {
        public int Num { get; set; }
        public string Str { get; set; }
        public StructCont(int num, string str)
        {
            Num = num;
            Str = str;
        }
    }
        enum Enum 
        { 
            Сентябрь = 9, 
            Октябрь, 
            Ноябрь
        }

        abstract class ForPlanet
        {
            public abstract void Add(object obj);
            public abstract void Remove(object obj);
            public abstract void Out();

        }

        class Planet : ForPlanet
        {
            public object[] Arr { get; set; }
            public int Maxsize { get; set; }
            public int Size { get; set; }
            public Planet(int num)
            {
                Arr = new object[num];
                Maxsize = num;
                Size = 0;
            }
            public override void Add(object объект)
            {
                if (Size < Maxsize)
                {
                    Arr[Size] = объект;
                    Size++;
                }
                else
                {
                    /*throw new Ex2("Невозможно добавить элемент: контейнер заполнен");*/
                }
            }
            public override void Remove(object объект)
            {
                if (Size != 0)
                {
                    for (int i = 0; i < Size; i++)
                    {
                        if (Arr[i] == объект)
                        {
                            for (int j = i; j < Size - 1; j++)
                            {
                                Arr[j] = Arr[j + 1];
                            }
                            Size--;
                            i--;
                        }
                    }
                }
                else
                {
                    /*throw new Ex1("Невозможно удалить элемент: контейнер пуст");*/
                }

            }
            public override void Out()
            {
                for (int i = 0; i < Size; i++)
                {
                    Console.WriteLine(Arr[i].ToString());
                }
            }
        }
}
    

