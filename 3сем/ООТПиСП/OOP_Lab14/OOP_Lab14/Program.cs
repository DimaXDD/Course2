using Microsoft.VisualBasic;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab14
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Задание 1\n");
            Info.ShowProcesses();
            Console.WriteLine("---------------------------");
            Console.WriteLine("Задание 2\n");
            Info.ShowDomains();
            Console.WriteLine("---------------------------");
            Console.WriteLine("Задание 3\n");
            Info.ShowSimpleNumbers();
            Console.WriteLine("---------------------------");
            Console.WriteLine("Задание 4\n");
            Info.ThoThreads();
            Console.WriteLine("---------------------------");
        }
    }
}