using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab8
{
    class ProgrammingLanguage
    {
        public string nameLang { get; set; }
        public double versionLang { get; set; }
        public string[] optionsArr { get; set; }

        public ProgrammingLanguage(string nameLang, double versionLang, params string[] optionsArr)
        {
            this.nameLang = nameLang;
            this.versionLang = versionLang;
            this.optionsArr = optionsArr;
        }

        public override string ToString()
        {
            string s = "";
            for (int i = 0; i < this.optionsArr.Length; i++)
            {
                s = s + " " + this.optionsArr[i];
            }

            return $"Язык: {this.nameLang} версии {this.versionLang}\n Операции:{s}";
        }

        public void AddOperation(string operation)
        {
            string[] temp = new string[this.optionsArr.Length + 1];
            for (int i = 0; i < this.optionsArr.Length; i++)
            {
                temp[i] = this.optionsArr[i];
            }
            temp[temp.Length - 1] = operation;
            this.optionsArr = temp;
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"Мы добавили в язык {nameLang} операцию: {operation}");
            Console.ResetColor();
        }


        #region DelegateMethods
        public void Add(Object sender, EventArgs e)
        {
            Console.WriteLine($"Add");
            AddOperation(Console.ReadLine());
        }

        public void Delete(Object sender, EventArgs e)
        {
            Console.WriteLine($"Delete");
            DeleteOperation(Console.ReadLine());

        }
        public void Rename_L(Object sender, EventArgs e)
        {
            Console.WriteLine($"Rename");
            NewName(Console.ReadLine());
        }

        public void NewVersion_L(Object sender, EventArgs e)
        {
            Console.WriteLine($"NewVersion");
            NewVersion(Convert.ToDouble(Console.ReadLine()));
        }
        #endregion

        public void DeleteOperation(string operation)
        {
            for (int o = 0; o < optionsArr.Length; o++)
            {
                if (optionsArr[o] == operation)
                    optionsArr[o] = "";
            }
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine($"Мы исключили из языка {nameLang} операцию: {operation}");
            Console.ResetColor();
        }

        public void NewVersion(double vers)
        {
            versionLang = vers;
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine($"Мы используем новую версию нашего языка: {nameLang} {versionLang}");
            Console.ResetColor();
        }


        public void NewName(string name)
        {
            nameLang = name;
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine($"Мы переименовали язык: {nameLang}");
            Console.ResetColor();
        }
    }
}
