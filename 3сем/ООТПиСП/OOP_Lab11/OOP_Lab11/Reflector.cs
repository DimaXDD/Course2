using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab11
{
    static class Reflector<T>
    {
        public static void Find(T Obj)
        {
            Type myType = Obj.GetType();

            string ReturnString = "";
            Console.WriteLine("Информация о классе:");
            ReturnString += "Info: " + myType.AssemblyQualifiedName + "\n";
            ReturnString += "Name: " + myType.Name + "\n";
            ReturnString += "FullName: " + myType.FullName + "\n";
            ReturnString += "Namespace: " + myType.Namespace + "\n";
            ReturnString += "IsValueType: " + myType.IsValueType + "\n";
            ReturnString += "IsClass: " + myType.IsClass + "\n";

            ReturnString += "\n";
            foreach (var i in myType.GetConstructors())
            {
                ReturnString += "Конструкторы: " + i.Name + "\n";
            }

            ReturnString += "\n";
            foreach (var i in myType.GetMethods())
            {
                ReturnString += "Методы: " + i.Name + "\n";
                foreach (var parm in i.GetParameters())
                    ReturnString += "\nПараметры: " + parm.ParameterType + "\n";
            }

            ReturnString += "\n";
            foreach (var i in myType.GetFields())
            {
                ReturnString += "Поля: " + i.Name + "\n";
            }

            ReturnString += "\n";

            foreach (var i in myType.GetInterfaces())
            {
                ReturnString += "Интерфейсы: " + i.Name + "\n";
            }

            ReturnString += "\n";

            FileStream? fstream = null;
            using (fstream = new FileStream("ClassInfo.txt", FileMode.Create))
            {
                byte[] input = Encoding.Default.GetBytes(ReturnString);
                fstream.Write(input, 0, input.Length);
                fstream.Close();
            }
            Console.WriteLine(ReturnString);
        }

        public static object Create(T obj)
        {
            Type ObjType = obj.GetType();
            return Activator.CreateInstance(ObjType);
        }
    }
}

