using System;
using System.Collections.Generic;
using System.IO.Pipes;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace OOP_Lab7
{
    public class Stack<T, P> where T : IComparable
    {
        #region Fields
        private const string fileName = "Stack.json";
        private T[] stack;
        private int top;
        private int size;
        #endregion

        #region Constructors
        public Stack(int size)
        {
            this.size = size;
            stack = new T[size];
            top = -1;
        }
        #endregion

        #region Properties
        public T[] AllElements
        {
            get
            {
                T[] allElements = new T[top + 1];
                Array.Copy(stack, allElements, top + 1);
                return allElements;
            }

        }
        #endregion

        #region Methods
        public void Push(T item)
        {
            if (top == size - 1)
            {
                Console.WriteLine("Стек полон");
            }
            else
            {
                stack[++top] = item;
            }
        }

        public T Pop()
        {
            if (top == -1)
            {
                Console.WriteLine("Стек пуст");
                return default(T);
            }
            else
            {
                return stack[top--];
            }
        }

        public void Print()
        {
            if (top == -1)
            {
                Console.WriteLine("Стек пуст");
            }
            else
            {
                for (int i = top; i >= 0; i--)
                {
                    Console.WriteLine(stack[i]);
                }
            }
        }
        #endregion

        #region Overloads
        // Перегрузка оператора +(добавление элемента в стек)
        public static Stack<T> operator +(Stack<T> stack, T element)
        {
            stack.Push(element);
            return stack;
        }

        // Перегрузка оператора -(извлечь элемент из стека)
        public static Stack<T> operator --(Stack<T> stack)
        {
            stack.Pop();
            return stack;
        }

        // Перегрузка оператора true(проверка на пустоту стека)
        public static bool operator true(Stack<T> stack)
        {
            return stack.top == -1;
        }

        public static bool operator false(Stack<T> stack)
        {
            return stack.top != -1;
        }

        // Перегрузка оператора >(копирование одного стека в другой с сортировкой в возрастающем порядке)
        public static Stack<T> operator >(Stack<T> stack1, Stack<T> stack2)
        {
            for (int i = 0; i < stack1.size; i++)
            {
                stack2.stack[i] = stack1.stack[i];
            }
            Array.Sort(stack2.stack);
            return stack2;
        }
        public static Stack<T> operator <(Stack<T> stack1, Stack<T> stack2)
        {
            for (int i = 0; i < stack1.size; i++)
            {
                stack2.stack[i] = stack1.stack[i];
            }
            Array.Sort(stack2.stack);
            Array.Reverse(stack2.stack);
            return stack2;
        }
        #endregion

        /*5. Добавьте методы сохранения объектов обобщённого типа
CollectionType<T> в файл и чтения из него ( на выбор: текстовый | xml | json). */
        #region Json
        public void PushToFile()
        {
            using StreamWriter sw = new("Stack.json");
            var str = JsonSerializer.Serialize(stack);
            sw.WriteLine(str);

        }

        public void ReadFromFile()
        {
            using StreamReader sr = new("Stack.json");
            var str = sr.ReadToEnd();
            stack = JsonSerializer.Deserialize<T[]>(str);
        }
        #endregion
    }
}





#region Question9
/* class Class1<T>
 {

 }

 // Унаследованный обобщенный класс
 class Class2_1<T> : Class1
 {

 }

 // Еще один унаследованный обобщенный класс с своими параметрами
 class Class2_2<T, V> : Class1
 {

 }


 class Class3<T, V, K> : Class2_2
 {


 }

 // Обычный необобщенный класс
 class someClass
 {

 }


 // Унаследованный от обычного класса обобщенный класс
 class ObClass<T> : SomeClass
 {

 }
*/
#endregion

#region Question11
/*class Person<T>
{
    public static T? code
        Person<int>.code = 1234;
Person<string> code = "1234"

}*/
#endregion