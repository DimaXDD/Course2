using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Diagnostics.Metrics;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace OOP_Lab14
{
    static class Info
    {
        private static string name_file = "text.txt";
        private static Mutex mutex = new();

        #region Task1
        public static void ShowProcesses()
        {
            /*Определите и выведите на консоль / в файл все запущенные процессы:id, имя, приоритет,
            время запуска, текущее состояние, сколько всего времени использовал процессор и т.д.*/

            Console.ForegroundColor = ConsoleColor.Green;
            var allProcesses = Process.GetProcesses();

            foreach (var process in allProcesses)
            {
                try
                {
                    Console.WriteLine($"Id процесса - {process.Id}\n" +
                                  $"Имя процесса - {process.ProcessName}\n" +
                                  $"Приоритет процесса - {process.BasePriority}\n" +
                                  $"Время запуска процесса - {process.StartTime}\n" +
                                  $"Текущее состояние процесса - {process.Responding}\n" +
                                  $"Время работы процесса - {process.TotalProcessorTime}\n" +
                                  $"Время загрузки процесса - {process.UserProcessorTime}\n");
                }
                catch (Exception e)
                {

                }
            }
            Console.ForegroundColor = ConsoleColor.DarkRed;
            Console.WriteLine($"Количество процессов - {allProcesses.Length}");
            Console.ForegroundColor = ConsoleColor.White;
        }
        #endregion

        #region Task2
        public static void ShowDomains()
        {
            /*Исследуйте текущий домен вашего приложения: имя, детали конфигурации, все сборки,
            загруженные в домен.Создайте новый домен.Загрузите туда сборку.Выгрузите домен.*/

            Console.ForegroundColor = ConsoleColor.Blue;
            AppDomain domain = AppDomain.CurrentDomain; // текущий домен приложения
            Console.WriteLine($"Имя домена - {domain.FriendlyName}");
            Console.WriteLine("Базовый каталог:\n" + domain.BaseDirectory);
            Console.WriteLine($"Детали конфигурации - {domain.SetupInformation}");
            Console.WriteLine("Сборки, загруженные в домен:");
            
            Assembly[] assemblies = domain.GetAssemblies();
            foreach (Assembly asm in assemblies)
            {
                Console.WriteLine(asm.GetName().Name);
            }

            /*// Либо так
            foreach (Assembly assembly in domain.GetAssemblies())
            {
                Console.WriteLine(assembly.GetName().Name);
            }*/

            /*AppDomain newDomain = AppDomain.CreateDomain("New Domain"); // создание нового домена
            newDomain.Load(Assembly.GetExecutingAssembly().FullName);   // загрузка сборки
            AppDomain.Unload(newDomain);                                // выгрузка домена + всех содержащихся в нём сборок*/
            Console.ForegroundColor = ConsoleColor.White;
        }
        #endregion

        #region Task3
        public static void ShowSimpleNumbers()
        {
            /*Создайте в отдельном потоке следующую задачу расчета(можно сделать sleep для
            задержки) и записи в файл и на консоль простых чисел от 1 до n(задает пользователь).
            Вызовите методы управления потоком(запуск, приостановка, возобновление и т.д.) Во
            время выполнения выведите информацию о статусе потока, имени, приоритете, числовой
            идентификатор и т.д.*/

            Console.ForegroundColor = ConsoleColor.Yellow;
            var first = new Thread(PrintSimpleNumbers);
            first.Start();
            first.Name = "Simple_numbers";
            first.Join();
            Console.WriteLine();

        }
        public static void ShowInfo(object thread)
        {
            var z = thread as Thread;
            Console.WriteLine($"Имя потока - {z.Name}\n" +
                              $"Приоритет потока - {z.Priority}\n" +
                              $"Статус потока - {z.ThreadState}\n" +
                              $"Поток фоновый - {z.IsBackground}\n" +
                              $"Поток запущен - {z.IsAlive}\n" +
                              $"Поток приостановлен - {z.IsThreadPoolThread}\n");
        }
        public static void PrintSimpleNumbers()
        {
            var first = new Thread(ShowInfo);
            first.Start(Thread.CurrentThread);
            first.Join();

            Console.WriteLine("Введите n:");
            int n = int.Parse(Console.ReadLine());
            // Проверка на простоту
            for (int i = 2; i < n; i++)
            {
                bool isPrime = true;
                for (int j = 2; j < i; j++)
                {
                    if (i % j == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime)
                {
                    Console.WriteLine(i);
                    Thread.Sleep(100);
                }
            }
        }
        #endregion

        #region Task4
        public static void ThoThreads()
        {
            // создаем новый поток
            var first = new Thread(OddNumbers) { Priority = ThreadPriority.Highest };
            var two = new Thread(EvenNumbers);

            first.Start();
            two.Start();
            FirstlyEvenSecondlyOdd();
            ShowOneByOne();
        }
        private static void ShowOneByOne()
        {
            var mutex = new Mutex();
            var even = new Thread(ShowEvenNumbers);
            var odd = new Thread(ShowOddNumbers);
            odd.Start();
            even.Start();
            even.Join();
            odd.Join();

            void ShowEvenNumbers()
            {
                for (var i = 0; i < 15; i++)
                {
                    mutex.WaitOne();
                    Console.ForegroundColor = ConsoleColor.Gray;
                    if (i % 2 == 0)
                        Console.Write(i + " ");
                    mutex.ReleaseMutex();
                }
            }

            void ShowOddNumbers()
            {
                for (var i = 0; i < 10; i++)
                {
                    mutex.WaitOne();
                    Thread.Sleep(200);
                    Console.ForegroundColor = ConsoleColor.DarkGreen;
                    if (i % 2 != 0)
                        Console.Write(i + " ");
                    mutex.ReleaseMutex();
                }
            }
        }
        private static void FirstlyEvenSecondlyOdd()
        {
            var objectToLock = new object();
            var even = new Thread(ShowEvenNumbers);
            var odd = new Thread(ShowOddNumbers);
            even.Start();
            odd.Start();
            even.Join();
            odd.Join();

            void ShowEvenNumbers()
            {
                lock (objectToLock)
                {
                    for (var i = 0; i < 15; i++)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        if (i % 2 == 0)
                            Console.Write(i + " ");
                    }
                }
            }

            void ShowOddNumbers()
            {
                for (var i = 0; i < 10; i++)
                {
                    Thread.Sleep(200);
                    Console.ForegroundColor = ConsoleColor.Blue;
                    if (i % 2 != 0)
                        Console.Write(i + " ");
                }
            }
        }
        public static void OddNumbers()
        {
            string txt = string.Empty;
            for (int i = 0; i < 10; i++)
            {
                Thread.Sleep(200);
                Console.ForegroundColor = ConsoleColor.White;
                if (i % 2 != 0)
                {
                    txt += i + " ";
                    Console.WriteLine(i + " ");
                }

            }
            txt += "\n";
            File.AppendAllText(name_file, txt);

        }
        public static void EvenNumbers()
        {
            string txt = string.Empty;
            for (int i = 0; i < 15; i++)
            {
                Thread.Sleep(300);
                Console.ForegroundColor = ConsoleColor.Yellow;
                if (i % 2 == 0)
                {
                    txt += i + " ";
                    Console.WriteLine(i + " ");
                }

            }
            txt += "\n";
            File.AppendAllText(name_file, txt);

        }
        #endregion


        public static void ReadFile()
        {
            var file = File.ReadAllText(name_file);
            Console.WriteLine(file);
        }
    }
}
