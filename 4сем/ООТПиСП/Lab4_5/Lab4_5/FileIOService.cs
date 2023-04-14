using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;

namespace Lab4_5
{
    public class FileIOService
    {
        public readonly string PATH = @"C:\Users\dimat\Desktop\Lab4_5\flights.json";
        public BindingList<Flight> LoadData(){
            var fileExists = File.Exists(PATH);
            if (!fileExists) {
                File.CreateText(PATH).Dispose();
                return new BindingList<Flight>();
            }
            using (var reader = File.OpenText(PATH))
            {
                var data = reader.ReadToEnd();
                return JsonConvert.DeserializeObject<BindingList<Flight>>(data);
            }
        
        }

        public void SaveData(BindingList<Flight> all_flights)
        {
            using (StreamWriter writer = File.CreateText(PATH))
            {
                string output = JsonConvert.SerializeObject(all_flights);
                writer.Write(output);

            }
        }
    }
}
