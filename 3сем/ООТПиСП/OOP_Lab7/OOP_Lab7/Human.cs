using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab7
{
    public class Human : IComparable
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public Human(string name, int age)
        {
            Name = name;
            Age = age;
        }
        public Human()
        {
            
        }
        public override string ToString()
        {
            return $"Name: {Name}, Age: {Age}";
        }

        public int CompareTo(object? obj)
        {

            if (obj as Human == null)
            {
                throw new ArgumentException("Объект не человек");
            }
            Human human = obj as Human;
            if (this.Age > human.Age)
            {
                return 1;
            }
            else if (this.Age < human.Age)
            {
                return -1;
            }
            else
            {
                return 0;
            }

        }
    }
}
