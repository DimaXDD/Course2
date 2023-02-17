using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab4
{
    class Water : ForWater, IWater
    {
        public int Volume { get; set; }
        public int Square { get; set; }
        public int Temperature { get; set; }
        public Water() { Volume = 10; Square = 20; Temperature = 25; }
        public Water(int volume, int square, int temperature)
        {
            Volume = volume;
            Square = square;
            Temperature = temperature;
        }
        public override void InfoTemp()
        {
            Console.WriteLine($"Температура: {Temperature}");
        }
        public void Sum()
        {
            Console.WriteLine($"Сумма исходных даннных: {Volume + Square + Temperature}");
        }
        public virtual void Info()
        {
            Console.WriteLine($"Вода: Объем - {Volume}, Площадь - {Square}, Температура - {Temperature}");
        }

        public override string ToString()
        {
            return $"{GetType()} {Volume} {Square} {Temperature}";
        }
    }
}
