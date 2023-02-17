using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace OOP_Lab7
{
    class Program
    {
        static void Main(string[] args)
        {
            Second();
            Third();
            Fourth();
        }

        public static void Second()
        {
            /* 2.Возьмите за основу лабораторную № 3 «Перегрузка операций» и
             сделайте из нее обобщенный тип(класс) CollectionType<T>, в который
             вложите обобщённую коллекцию.Наследуйте в обобщенном классе интерфейс
             из п.1.Реализуйте необходимые методы(добавления, удаления, поиска по
             предикату). Добавьте обработку исключений c finally. Наложите какое-либо
             ограничение на обобщение.*/
            try
            {
                Console.ForegroundColor = ConsoleColor.Green; // устанавливаем цвет
                Console.WriteLine("========Task_2========\n");
                Console.ResetColor(); // сбрасываем в стандартный
                var stack = new Stack<int>(5);
                Console.WriteLine("Создание стека из 5 элементов");
                stack.Push(1);
                stack.Push(2);
                stack.Push(3);
                stack.Push(4);
                stack.Push(5);
                Console.WriteLine("Вывод стека");
                stack.Print();
                Console.WriteLine("=====================================");
                stack.Pop();
                stack.Print();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                Console.WriteLine("=====================================");
                Console.WriteLine("Завершение работы программы\n");
            }

        }

        public static void Third()
        {
            /*3.Проверьте использование обобщения для стандартных типов данных(в
            качестве стандартных типов использовать целые, вещественные и т.д.).*/
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("========Task_3========\n");
            Console.ResetColor();

            var stringStack = new Stack<string>(3);
            var intStack = new Stack<int>(3);
            var doubleStack = new Stack<double>(3);

            Console.ForegroundColor = ConsoleColor.DarkYellow;
            Console.WriteLine("Стек типа string");
            Console.ResetColor();
            stringStack.Push("Hello");
            stringStack.Push("World");
            stringStack.Push("!!!");
            stringStack.Pop();
            stringStack.Print();

            Console.ForegroundColor = ConsoleColor.DarkYellow;
            Console.WriteLine("Стек типа int");
            Console.ResetColor();
            intStack.Push(1);
            intStack.Push(2);
            intStack.Push(3);
            intStack.Pop();
            intStack.Print();

            Console.ForegroundColor = ConsoleColor.DarkYellow;
            Console.WriteLine("Стек типа double");
            Console.ResetColor();
            doubleStack.Push(1.1);
            doubleStack.Push(2.2);
            doubleStack.Push(3.3);
            doubleStack.Pop();
            doubleStack.Print();


        }

        public static void Fourth()
        {
            /*Определить пользовательский класс, который будет использоваться в
            качестве параметра обобщения.Для пользовательского типа взять класс из
            лабораторной №4 «Наследование». */
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("========Task_4========\n");
            Console.ResetColor();

            var stack = new Stack<Human>(3);
            stack.Push(new Human("Ivan", 20));
            stack.Push(new Human("Petr", 30));
            stack.Push(new Human("Sidor", 40));
            stack.PushToFile(); // запись в json файл
            stack.Print();
        }
    }
}