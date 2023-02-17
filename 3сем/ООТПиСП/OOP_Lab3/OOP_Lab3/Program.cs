using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using static OOP_Lab3.Stack<int>;

namespace OOP_Lab3
{
    class Program
    {
        static void Main(string[] args)
        {
            Stack<int> stack = new(5);
            Console.WriteLine("Введите элементы первого стека:");
            for (int i = 0; i < 5; i++)
            {
                stack.Push(int.Parse(Console.ReadLine()));
            }
            Console.WriteLine("Сумма элементов стека: " + StatisticOperation.Sum(stack));
            Console.WriteLine("Разница между максимальным и минимальным элементами стека: " + StatisticOperation.Diff(stack));
            Console.WriteLine("Количество элементов стека: " + StatisticOperation.Count(stack));
            // первый метод расширения
            Console.WriteLine("Среднее арифметическое элементов стека: " + stack.Average());
            stack.Pop();
            stack.Pop();
            stack += 10;
            stack += 206;
            stack--;
            Console.WriteLine("\nСтек после изменений:");
            stack.Print();

            Stack<int> stack2 = new(5);
            Console.WriteLine("Введите элементы второго стека:");
            for (int i = 0; i < 5; i++)
            {
                stack2.Push(int.Parse(Console.ReadLine()));
            }
            stack = stack > stack2;
            Console.WriteLine("\nСтек после изменений:");
            stack.Print();
            stack = stack < stack2;
            Console.WriteLine("\nСтек после изменений:");
            stack.Print();
            
            Stack<string> stack3 = new Stack<string>(5);
            stack3.Push("Первое предложение.");
            stack3.Push("Второе предложение");
            stack3.Push("Третье предложение!");
            stack3.Push("Четвёртое предложение.");
            stack3.Push("Пятое предложение?");
            Console.WriteLine("Введите знак конца предложения: ");
            string symbol = Console.ReadLine();
            // второй метод расширения
            int count = stack3.CountSentences(symbol);
            Console.WriteLine("Количество предложение с знаком " + symbol + " - " + count);

            Stack<int>.Production production = new Stack<int>.Production();
            production.Id = 1;
            production.Name = "Минск";
            Console.WriteLine(production.Id);
            Console.WriteLine(production.Name);
            
            Stack<int>.Production.Developer developer = new Stack<int>.Production.Developer();
            developer.Fio = "Трубач Дмитрий Сергеевич";
            developer.Id = 1;
            developer.Department = "ФИТ БГТУ";
            Console.WriteLine(developer.Fio);
        }
    }
}