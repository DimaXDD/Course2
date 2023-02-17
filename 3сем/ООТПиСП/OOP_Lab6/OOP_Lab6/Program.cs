using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace OOP_Lab6
{
    class Program
    {
        static void Main(string[] args)
        {
            // Логгер
            Logger Log = new();
            try
            {
                Console.WriteLine("----------------------------------------");
                StructCont structCont = new StructCont((int)Enum.Сентябрь, "Сентябрь");
                Console.WriteLine($"{structCont.Num} - {structCont.Str}");
                Sea sea = new Sea("Черное море", 100, 200, 330);
                Sea sea1 = new Sea("Средиземное море", 11, 67, 125);
                Continent continent = new Continent("Умеренный", "Евразия", 24, "Подзолистая", "Холмы");
                State state = new State("Россия", "Человек", 24, "Евразия", 111);
                State state1 = new State("Чехия", "Человек", 11, "Европа", 139);
                Island island = new Island("Остров", "Крит", 11, "Песок", "Горы");
                Island island1 = new Island("Остров", "Апеннинский", 88, "Подзолистая", "Равнина");
                Island island2 = new Island("Остров", "Корсико", 22, "Грунт", "Склоны");

                Log.WriteLine("Созданы 8 объектов");


                // Универсальный обработчик исключений
                Planet planet = new Planet(8);

                Log.WriteLine("Создан объект класса Planet");

                // Первое исключение (удаление объекта, которого нет)
                planet.Remove(state);

                planet.Add(sea);
                planet.Add(sea1);
                planet.Add(continent);
                planet.Add(state);
                planet.Add(state1);
                planet.Add(island);
                planet.Add(island1);
                planet.Add(island2);

                // Второе исключение (переполнение)
                //planet.Add(island);
                planet.Out();
                Log.WriteLine("Произведён вывод на экран");



                Console.WriteLine("----------------------------------------");
                planet.Remove(continent);
                planet.Out();

                Log.WriteLine("Удалили объект класса Continent и произвели вывод на экран");

                Console.WriteLine("----------------------------------------");
                Console.WriteLine($"Количество морей: {Controller.Sea(planet)}");
                Console.WriteLine("----------------------------------------");

                Log.WriteLine("Посчитали количество морей");

                Controller.State(planet, continent);

                Log.WriteLine("Вывели на экран все государства, расположенные на континенте");

                Console.WriteLine("----------------------------------------");

                Controller.Island(planet);

                Log.WriteLine("Вывели на экран все острова");

                Console.WriteLine("----------------------------------------");

                Controller.ZeroEx(6, 2);
                Controller.FormatEx();
                Controller.IndexEx();
                Controller.AssertEx();
            }
            catch (Ex1 ex1)
            {
                // пример всех методов класса Exception
                Log.WriteError(ex1.Message);
                Console.WriteLine(ex1.Message);
                Console.WriteLine(ex1.TargetSite);
                Console.WriteLine(ex1.StackTrace);
                Console.WriteLine(ex1.Source);
                Console.WriteLine(ex1.InnerException);
            }
            catch (Ex2 ex2)
            {
                Log.WriteError(ex2.Message);
                Console.WriteLine(ex2.Message);
                Console.WriteLine(ex2.TargetSite);
                Console.WriteLine(ex2.StackTrace);
            }
            catch (Ex3 ex3)
            {
                Log.WriteError(ex3.Message);
                Console.WriteLine(ex3.Message);
                Console.WriteLine(ex3.TargetSite);
                Console.WriteLine(ex3.StackTrace);
            }
            catch (FormatException f)
            {
                Log.WriteError(f.Message);
                Console.WriteLine(f.Message);
                Console.WriteLine(f.TargetSite);
                Console.WriteLine(f.StackTrace);
            }
            catch (IndexOutOfRangeException ind)
            {
                Log.WriteError(ind.Message);
                Console.WriteLine(ind.Message);
                Console.WriteLine(ind.TargetSite);
                Console.WriteLine(ind.StackTrace);
            }
            catch
            {
                // Непридвиденная ошибка
                Console.WriteLine("Сработал универсальный обработчик");
            }
            finally
            {
                // Данный блок будет всегда выполняться
                Console.WriteLine("Программа завершена");
            }
            Log.WriteEnd();
            

        }
    }
}