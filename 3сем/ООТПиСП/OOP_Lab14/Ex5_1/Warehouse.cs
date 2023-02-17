using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex5_1
{
    class Warehouse
    {
        private uint count;
        private static object locker = new();


        public uint? Count
        {
            get => count;
            set => count = value ??
                           0;
        }


        public Warehouse(uint? count) => Count = count;

        public void Get(object time)
        {
            while (Count != 0)
            {
                lock (locker)
                {
                    Count--;
                    Console.WriteLine($"{Thread.CurrentThread.Name} разгрузил. Теперь {Count}");
                }

                Thread.Sleep((int)time);
            }
        }
    }
}
