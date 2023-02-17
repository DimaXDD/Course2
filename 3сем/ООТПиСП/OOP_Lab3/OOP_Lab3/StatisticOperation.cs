using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab3;

static class StatisticOperation
{ 
    public static int Sum(Stack<int> stack)
    {
        return stack.AllElements.Sum();
    }
    public static int Diff(Stack<int> stack)
    {
        return stack.AllElements.Max() - stack.AllElements.Min();
    }
    public static int Count(Stack<int> stack)
    {
        return stack.AllElements.Length;
    }

    #region ExtensionMethods
    public static int Average(this Stack<int> stack)
    {
        return stack.AllElements.Sum() / stack.AllElements.Length;
    }
    public static int CountSentences(this Stack<string> stack, string sentence)
    {
        int count = 0;
        foreach (var item in stack.AllElements)
        {
            if (item.Contains(sentence))
            {
                count++;
            }
        }
        return count;
    }
    #endregion

}