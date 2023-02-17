using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab3
{
    class Stack<T>
    {
        #region Fields
        private T[] stack; // для хранения элементов стека
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

        #region Methods
        public void Push(T item)
        {
            if (top == size - 1)
            {
                Console.WriteLine("Стек полон");
                return;
            }
            stack[++top] = item;
        }

        public T Pop()
        {
            if (top == -1)
            {
                Console.WriteLine("Стек пуст");
                return default(T);
            }
            return stack[top--];
        }

        public void Print()
        {
            for (int i = 0; i < top + 1; i++)
            {
                Console.WriteLine(stack[i]);
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

        #region Production and Developer
        public class Production
        {
            public int Id { get; set; }
            public string Name { get; set; }

            public class Developer
            {
                public string Fio { get; set; }
                public int Id { get; set; }
                public string Department { get; set; }

            }
        }
        #endregion        
        
    }
}