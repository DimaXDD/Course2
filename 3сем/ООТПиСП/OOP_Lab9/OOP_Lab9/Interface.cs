using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab9

{
    interface IOrderedDictionary
    {
        void Add(object key, object value); // добавление элемента в коллекцию
        void Clear(); // очистка коллекции
        bool Contains(object key); // проверка наличия элемента в коллекции
        void Remove(); // удаление элемента из коллекции
        int Count { get; } // количество элементов в коллекции
        ICollection Keys { get; } // возвращает список ключей
        ICollection Values { get; } // возвращает список значений
        
    }
}
