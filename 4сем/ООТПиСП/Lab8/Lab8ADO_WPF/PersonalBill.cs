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
        public Owner owner = new Lab2.Owner();
        public DateTime sendDate;
        public string services = "";
        public int Number = 0;
        public int startBalance { get; set;}
        public string town;
        public override string ToString()
        {
         return $"Счёт #{this.Number}, валюта - {this.owner.wallet}\n" +
                $"Владелец      : {this.owner.FIO}\n" +
                $"Дата рождения : {this.owner.birthDate.Date}\n" +
                $"Контакты      : +{this.owner.phoneNumber}\n" +
                $"Дата получения: {this.sendDate.Date}\n" +
                $"Начальный баланс = {this.startBalance}";
        }
    }
}
