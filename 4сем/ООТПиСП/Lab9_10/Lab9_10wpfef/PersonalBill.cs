using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Lab2
{
    [Serializable]
    public class PersonalBill
    {
        public int ID { get; set; }
        public DateTime SendDate;
        public string Services { get; set; }
        public string Wallet { get; set; }
        public int StartBalance { get; set;}
        public string Town { get; set; }
        public override string ToString()
        {
         return $"Счёт #{this.ID}, валюта - {this.Wallet}\n" +
                $"Дата получения: {this.SendDate.Date}\n" +
                $"Начальный баланс = {this.StartBalance}";
        }
    }
}
