using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;
using System.Xml.Serialization;

namespace OOP_Lab13
{
    class Program
    {
        static void Main(string[] args)
        {
            Check check1 = new Check("NewCheck", new DateTime(2022, 11, 14), "Dima", "OOP_Lab13", 100);
            Check check2 = new Check("NewCheck", new DateTime(2022, 11, 13), "Andrey", "OOP_Lab13", 200);
            Check check3 = new Check("NewCheck", new DateTime(2022, 11, 12), "Pavel", "OOP_Lab13", 300);

            Console.WriteLine("Бинарная сериализация");
            CustomSerializer.Serialize("check1.bin", check1);

            Console.WriteLine("JSON сериализация");
            CustomSerializer.Serialize("check2.json", check2);

            Console.WriteLine("XML сериализация");
            CustomSerializer.Serialize("check3.xml", check3);

            Console.WriteLine("\n\nБинарная десериализация");
            CustomSerializer.Deserialize("check1.bin");

            Console.WriteLine("JSON десериализация");
            CustomSerializer.Deserialize("check2.json");

            Console.WriteLine("XML десериализация");
            CustomSerializer.Deserialize("check3.xml");

            XmlSerializer serializer = new XmlSerializer(typeof(List<Check>));
            List<Check> checks = new List<Check>();
            checks.Add(check1);
            checks.Add(check2);
            checks.Add(check3);

            using (FileStream fs = new FileStream("Collection.xml", FileMode.Create))
            {
                serializer.Serialize(fs, checks);
            }

            Console.WriteLine("XML сериализация коллекции");
            using (FileStream fr = new FileStream("Collection.xml", FileMode.Open))
            {
                List<Check> newLst = (List<Check>)serializer.Deserialize(fr);
                foreach (var item in newLst)
                {
                    Console.WriteLine($"Десеарелизован: " + item.ToString());
                }
            }

            XmlDocument document = new XmlDocument(); // Создаем XML-документ
            document.Load("Collection.xml"); // Загружаем XML-документ из файла
            XmlNode xmlRoot = document.DocumentElement; // Получаем корневой элемент
            XmlNodeList allPlants = xmlRoot.SelectNodes("*"); // Получаем список всех узлов в документе
            foreach (XmlNode node in allPlants)
            {
                Console.WriteLine(node.InnerText);
            }

            XElement language;
            XElement name;
            XAttribute year;

            XDocument Lang = new XDocument();
            XElement root = new XElement("ЯП");

            language = new XElement("language");
            name = new XElement("name");
            name.Value = "C#";
            year = new XAttribute("year", "1998");
            language.Add(name);
            language.Add(year);
            root.Add(language);

            language = new XElement("language");
            name = new XElement("name");
            name.Value = "C++";
            year = new XAttribute("year", "1983");
            language.Add(name);
            language.Add(year);
            root.Add(language);

            language = new XElement("language");
            name = new XElement("name");
            name.Value = "Java";
            year = new XAttribute("year", "1995");
            language.Add(name);
            language.Add(year);
            root.Add(language);

            Lang.Add(root);
            Lang.Save("Lang.xml");


            Console.WriteLine("Введите год для поиска: ");
            string yearXML = Console.ReadLine();
            var allAlbums = root.Elements("language");

            foreach (var item in allAlbums)
            {
                if (item.Attribute("year").Value == yearXML)
                {
                    Console.WriteLine(item.Value);
                }
            }
        }
    }
}