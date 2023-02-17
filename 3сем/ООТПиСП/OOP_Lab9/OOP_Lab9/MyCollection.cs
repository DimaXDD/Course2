using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab9
{
    public class MyCollection<T> : IOrderedDictionary
    {
        Queue<T> queue = new Queue<T>(); // очередь
        LinkedList<T> link = new LinkedList<T>(); // связный список

        public int Count => queue.Count; // количество элементов в коллекции

        public void Add(object key, object value) // добавление элемента в коллекцию
        {
            queue.Enqueue((T)value);
        }

        public void Clear()
        {
            queue.Clear();
        }

        public bool Contains(object key)
        {
            return queue.Contains((T)key);
        }

        public void Remove()
        {
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("Удаление элемента из очереди (первый элемент): " + queue.Dequeue());
            Console.ResetColor();
        }
        
        public void Print()
        {
            foreach (var item in queue)
            {
                Console.WriteLine(item);
            }
        }
        public T Value(int index)
        {
            return queue.ElementAt((int)index);
        }

        public void RemoveAt(T item)
        {
            queue.Dequeue();
        }

        public ICollection Keys => queue.ToArray(); 

        public ICollection Values => queue.ToArray();


    }
}
