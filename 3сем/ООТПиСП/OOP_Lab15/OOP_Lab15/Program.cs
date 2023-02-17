using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab15
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                TPL.Task8();
                TPL.Task1(2200);
                TPL.Task2(6000);
                TPL.Task4_1();
                TPL.Task4_2();
                TPL.Task5();
                TPL.Task6();
                TPL.Task7();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            Thread.Sleep(1000000);
        }
    }
}
