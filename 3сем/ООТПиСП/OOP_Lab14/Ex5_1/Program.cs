using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace Ex5_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Warehouse wh = new(10);

            Thread m1 = new(new ParameterizedThreadStart(wh.Get));
            Thread m2 = new(new ParameterizedThreadStart(wh.Get));

            m1.Name = "Машина 1";
            m2.Name = "Машина 2";

            m1.Start(2000);
            m2.Start(1000);
        }
    }
}
