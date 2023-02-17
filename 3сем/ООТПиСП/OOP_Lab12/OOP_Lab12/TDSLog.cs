using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace OOP_Lab12
{
    static class TDSLog
    {
        private const string PATH_TO_FILE = "TDSlogfile.json";

        public static void WriteToFile(string methodName, string className)
        {
            Data datas = new(methodName, className);
            datas.Print();
            var newData = JsonSerializer.Serialize(datas);
            using (StreamWriter sw = new(PATH_TO_FILE, true))
            {
                sw.WriteLine(newData);
            }
        }
        public static void FindByRangeDate(DateTime start, DateTime end)
        {
            using (StreamReader sr = new(PATH_TO_FILE))
            {
                var data = sr.ReadToEnd();
                var datas = JsonSerializer.Deserialize<Data>(data);
                List<Data> datas1 = new();
                datas1.Add(datas);
                datas1.Where(d => d.date >= start && d.date <= end).ToList().ForEach(d => d.Print());
            }
        }
        public static void FindDate(DateTime date)
        {
            using (StreamReader sr = new(PATH_TO_FILE))
            {
                var data = sr.ReadToEnd();
                var datas = JsonSerializer.Deserialize<Data>(data);
                List<Data> datas1 = new();
                datas1.Add(datas);
                datas1.Where(x => x.date == date).ToList().ForEach(x => x.Print());
            }
        }
    }
    class Data
    {
        public string Name { get; set; }
        public DateTime date { get; set; }
        public string NameClass { get; set; }

        public Data(string methodName, string className)
        {
            Name = methodName ?? "undefined";
            NameClass = className ?? "undefined";
            date = DateTime.Now;
        }
        public void Print()
        {
            Console.WriteLine($"Method name: {Name} Class name: {NameClass} Date: {date}");
        }
    }
}
