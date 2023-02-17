using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab11
{
    class Program
    {
        static void Main(string[] args)
        {
            Prod test = new Prod();
            Reflector<Prod>.Find(test); // Reflector<Prod>.Find(new Prod());

            Type objType = Type.GetType("OOP_Lab11.Prod");
            ConstructorInfo objConstr = objType.GetConstructor(Type.EmptyTypes);
            Object ProdObj = objConstr.Invoke(new object[] { });

            Console.WriteLine(ProdObj);
            MethodInfo method = objType.GetMethod("Method_with_r");
            object result = method.Invoke(ProdObj, new object[] { 100 });
            Console.WriteLine(result);


            object result2 = Reflector<Prod>.Create(new Prod());
            Console.WriteLine(result2);
        }
    }
}
