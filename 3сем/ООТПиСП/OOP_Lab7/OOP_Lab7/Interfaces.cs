using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab7
{
    public interface IComparable<T>
    {
        void Push(T item);
        T Pop();
        void Print();
    }
}
