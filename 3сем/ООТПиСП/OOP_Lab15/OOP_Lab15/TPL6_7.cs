using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab15
{
    static partial class TPL
    {
        public static void Task6()
        {
            Parallel.Invoke(
                () =>
                {
                    Thread.Sleep(4000);
                    Console.WriteLine("Первая функция выполнена!");
                },
                () =>
                {
                    Thread.Sleep(2000);
                    Console.WriteLine("Вторая функция выполнена!");
                },
                () =>
                {
                    Thread.Sleep(1000);
                    Console.WriteLine("Третья функция выполнена!");
                },
                () =>
                {
                    Thread.Sleep(2500);
                    Console.WriteLine("Четвертая функция выполнена!");
                }
                );
        }

        public static void Task7()
        {
            BlockingCollection<Product> products = new();
            Task provider1 = new(() =>
            {
                int cnt = 0;
                while (cnt < 2 && products.TryAdd(new Product()))
                {
                    cnt++;
                    Console.WriteLine("Поставщик 1 добавил товар");
                    Thread.Sleep(1700);
                }
            });
            Task provider2 = new(() =>
            {
                int cnt = 0;
                while (cnt < 2 && products.TryAdd(new Product()))
                {
                    cnt++;
                    Console.WriteLine("Поставщик 2 добавил товар");
                    Thread.Sleep(2000);
                }
            });
            Task provider3 = new(() =>
            {
                int cnt = 0;
                while (cnt < 2 && products.TryAdd(new Product()))
                {
                    cnt++;
                    Console.WriteLine("Поставщик 3 добавил товар");
                    Thread.Sleep(600);
                }
            });
            Task provider4 = new(() =>
            {
                int cnt = 0;
                while (cnt < 2 && products.TryAdd(new Product()))
                {
                    cnt++;
                    Console.WriteLine("Поставщик 4 добавил товар");
                    Thread.Sleep(3000);
                }
            });
            Task provider5 = new(() =>
            {
                int cnt = 0;
                while (cnt < 2 && products.TryAdd(new Product()))
                {
                    cnt++;
                    Console.WriteLine("Поставщик 5 добавил товар");
                    Thread.Sleep(1250);
                }
            });

            Task client1 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 1 забрал продукт");
                    }
                }
            });
            Task client2 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 2 забрал продукт");
                    }
                }
            });
            Task client3 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 3 забрал продукт");
                    }
                }
            });
            Task client4 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 4 забрал продукт");
                    }
                }
            });
            Task client5 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 5 забрал продукт");
                    }
                }
            });
            Task client6 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 6 забрал продукт");
                    }
                }
            });
            Task client7 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 7 забрал продукт");
                    }
                }
            });
            Task client8 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 8 забрал продукт");
                    }
                }
            });
            Task client9 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 9 забрал продукт");
                    }
                }
            });
            Task client10 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 10 забрал продукт");
                    }
                }
            });

            provider1.Start();
            provider2.Start();
            provider3.Start();
            provider4.Start();
            provider5.Start();
            
            client1.Start();
            client2.Start();
            client3.Start();
            client4.Start();
            client5.Start();
            client6.Start();
            client7.Start();
            client8.Start();
            client9.Start();
            client10.Start();
        }
    }

    class Product
    {
        public string Name { get; set; }
        public uint Price { get; set; }

        public Product(string name,
                       uint price)
        {
            Name = name;
            Price = price;
        }

        public Product()
        {
            Name = String.Empty;
            Price = 0;
        }

        public override string ToString() => $"Имя: {Name}, Цена: {Price}";
    }
}
