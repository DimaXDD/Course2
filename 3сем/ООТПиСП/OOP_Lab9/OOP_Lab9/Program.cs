using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab9
{
    class Program
    {
        static void Main(string[] args)
        {
            MyCollection<Services> myCollection = new MyCollection<Services>();
            Services services1 = new Services("Haircut", 100);
            Services services2 = new Services("Shampoo", 50);
            Services services3 = new Services("Hair coloring", 200);
            myCollection.Add(services1, services1);
            myCollection.Add(services2, services2);
            myCollection.Add(services3, services3);
            myCollection.Print();
            Console.WriteLine("Количество элементов в очереди: " + myCollection.Count);
            Console.WriteLine("---------------------------");
            Console.WriteLine("Пример remove");
            myCollection.Remove();
            Console.WriteLine("---------------------------");
            myCollection.Print();
            Console.WriteLine($"Элемент {services1.Name} содержится в очереди: {myCollection.Contains(services1)}");
            Console.WriteLine($"Элемент {services2.Name} содержится в очереди: {myCollection.Contains(services2)}");
            Console.WriteLine("---------------------------");
            Console.WriteLine("Очистка очереди");
            myCollection.Clear();
            myCollection.Print();
            Console.WriteLine("Количество элементов в очереди: " + myCollection.Count);

            MyCollection<int> myCollection2 = new MyCollection<int>();
            for (int i = 0; i < 6; i++)
            {
                myCollection2.Add(0, i);
            }
            
            myCollection2.Print();
            Console.WriteLine("------------------------------------");

            Console.Write("Введите n (кол-во удалений): ");
            string str;
            str = Console.ReadLine();
            int n = Convert.ToInt32(str);
            while (n > 0)
            {
                myCollection2.RemoveAt(--n);
            }
            Console.WriteLine("------------------------------------");
            myCollection2.Print();

            LinkedList<int> link = new LinkedList<int>();

            for (int i = 0; i < myCollection2.Count; i++)
            {
                link.AddLast(myCollection2.Value(i));
            }
            Console.WriteLine("Вторая коллекция:");
            foreach (var item in link)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("Тип первой коллекции: " + myCollection.GetType());
            Console.WriteLine("Тип второй коллекции: " + myCollection2.GetType());
            Console.WriteLine("Тип третьей коллекции: " + link.GetType());
            Console.WriteLine("------------------------------------");

            int a = 2;

            foreach (int item in link)
            {
                if (item == a)
                {
                    Console.WriteLine("Элемент найден");
                }
            }

            var myCollection3 = new ObservableCollection<Services>();
            Services services4 = new Services("Example", 2000);

            myCollection3.CollectionChanged += Collection3_CollectionChanged;
            myCollection3.Add(services4);
            myCollection3.Remove(services4);

        }
        private static void Collection3_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
        {
            switch (e.Action)
            {
                case NotifyCollectionChangedAction.Add:
                    Console.WriteLine($"Добавлен новый объект");
                    break;

                case NotifyCollectionChangedAction.Remove:
                    Console.WriteLine($"Удален объект");
                    break;
            }
        }
    }
}