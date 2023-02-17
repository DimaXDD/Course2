using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab4
{
    sealed class Sea : Water // запечатанный
    {
        public string Name { get; set; }

        public Sea(string name, int volume, int square, int temperature)
        {
            Name = name;
            Volume = Volume;
            Square = Square;
            Temperature = Temperature;
        }

        public override void Info()
        {
            Console.WriteLine($"Море: Название - {Name}, Объем  - {Volume}, Площадь  - {Square}, Температура  - {Temperature}");
        }

        public override string ToString()
        {
            return $"{GetType()} {Name} {Volume} {Square} {Temperature}";
        }
    }
}
