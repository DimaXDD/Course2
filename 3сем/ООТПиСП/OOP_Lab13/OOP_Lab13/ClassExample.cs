using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace OOP_Lab13
{
    [Serializable]
    public abstract class Document
    {
        public readonly int id;
        public string title;
        public DateTime dateOfSignature;
        public string client;
        public string organization;
        public Document() { }
        public Document(string title, DateTime dateOfSignature, string client, string organization)
        {
            id = (int)title.GetHashCode() + (int)dateOfSignature.GetHashCode();
            this.title = title;
            this.dateOfSignature = dateOfSignature;
            this.client = client;
            this.organization = organization;
        }

        public string Title
        {
            get => title;
            set => title = value;
        }
        public DateTime DateOfSignature
        {
            get => dateOfSignature;
            set => dateOfSignature = value;
        }

        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;
            if (obj.GetType() != this.GetType())
                return false;
            return this.Title == ((Document)obj).Title;
        }
        public override int GetHashCode()
        {
            int hash = 47, d = 32;
            string a = Convert.ToString(Title);
            hash = string.IsNullOrEmpty(a) ? 0 : Title.GetHashCode();
            hash = (hash * 47) + d.GetHashCode();
            return hash;
        }
        public abstract void Info();
        virtual public int GetTotalPrice() { return 0; }
    }
    
    [Serializable]
    [XmlRoot]
    public class Check : Document
    {
        //[NonSerialized]
        public int totalPrice;
        public Check() { }
        public Check(string title, DateTime dateOfSignature, string client, string organization, int totalPrice)
               : base(title, dateOfSignature, client, organization)
        {
            this.totalPrice = totalPrice;
        }
        public string ToString()
        {
            return Title + " " + DateOfSignature.ToString("MM/dd/yyyy") + " " + client + " " + organization + " " + totalPrice + "\n--------------------------------------\n";
        }
        public override void Info()
        {
            Console.WriteLine("-----------" + Title + "-----------\n" + "Дата заключения: " + DateOfSignature.ToString("MM/dd/yyyy") + "\n" + "Клиент: " + client + "\n" + "Организация: " + organization + "\n" + "Итоговая стоимость: " + totalPrice);
        }
        override public int GetTotalPrice()
        {
            return totalPrice;
        }

    }
}
