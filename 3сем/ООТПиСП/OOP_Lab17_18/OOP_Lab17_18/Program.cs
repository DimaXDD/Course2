using OOP_Lab17_18;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab17_18
{
    #region Abstract Factory
    interface IQuality
    {
        string Name { get; set; }
    }

    class Prime : IQuality
    {
        public string Name { get; set; } = "Prime";
        public Prime()
        {
            
        }

        public Prime(string name) => Name = name;
    }

    class Standard : IQuality
    {
        public string Name { get; set; } = "Standard";
        public Standard()
        {

        }

        public Standard(string name) => Name = name;
    }

    interface IOrder : IPrototype<IOrder>
    {
        string Name { get; set; }
        IQuality Quality { get; set; }
        uint Count { get; set; }
    }

    class PrimeOrder : IOrder
    {
        public string Name { get; set; } = "PrimeOrder";
        public IQuality Quality { get; set; } = new Prime();
        public uint Count { get; set; }

        public PrimeOrder(string name, uint count, IQuality quality)
        {
            Name = name;
            Count = count;
            Quality = quality;
        }

        public IOrder Clone()
        {
            return new PrimeOrder(Name, Count, new Prime(Quality.Name));
        }
    }

    class StandardOrder : IOrder
    {
        public string Name { get; set; } = "StandardOrder";
        public IQuality Quality { get; set; } = new Standard();
        public uint Count { get; set; }

        public StandardOrder(string name, uint count, IQuality quality)
        {
            Name = name;
            Count = count;
            Quality = quality;
        }

        public IOrder Clone()
        {
            return new StandardOrder(Name, Count, new Standard(Quality.Name));
        }
    }

    interface IOrderFactory
    {
        IQuality GetQuality();
        IOrder GetOrder(string name, uint count, IQuality quality);
    }

    class PrimeOrderFactory : IOrderFactory
    {
        public IQuality GetQuality() => new Prime();

        public IOrder GetOrder(string name, uint count, IQuality quality) => new PrimeOrder(name, count, quality);

    }

    class StandardOrderFactory : IOrderFactory
    {
        public IQuality GetQuality() => new Standard();

        public IOrder GetOrder(string name, uint count, IQuality quality) => new StandardOrder(name, count, quality);
    }

    #endregion

    #region Builder
    interface ISystemBuilder
    {
        public uint MaxCount { get; set; }
        public string Name { get; set; }
        public IAdministrator Administrator { get; set; }
        List<IOrder> Orders { get; set; }
    }

    class System : ISystemBuilder
    {
        public uint MaxCount { get; set; }
        public string Name { get; set; }

        public IAdministrator Administrator { get; set; }

        public List<IOrder> Orders { get; set; }

        private System() { }

        private System(uint count, string name, IAdministrator administrator, params IOrder[] orders)
        {
            this.SetMaxCount(count);
            this.SetName(name);
            this.SetAdministrator(administrator);
            this.SetOrders(orders);
        }

        public void SetMaxCount(uint count) => MaxCount = count;
        public void SetName(string name) => Name = name;
        public void SetAdministrator(IAdministrator administrator)
        {
            Administrator = administrator;
            Administrator.System = this;
        }
        public void SetOrders(params IOrder[] orders) => Orders = new List<IOrder>(orders);

        public static System CreateSystem(uint count, string name, IAdministrator administrator, params IOrder[] orders)
        {
            return new System(count, name, administrator, orders);
        }
    }
    #endregion

    #region Person
    interface IPerson
    {
        string Name { get; set; }
    }
    #endregion

    #region Administrator
    interface IAdministrator : IPerson
    {
        ISystemBuilder System { get; set; }
        IOrder GiveOrder(string name);
    }

    class Administrator : IAdministrator
    {
        public string Name { get; set; } = "Unknown";
        public ISystemBuilder System { get; set; }
        public IOrder GiveOrder(string name)
        {
            var order = System.Orders.Find(el => el.Name == name);
            if (order is null)
            {
                Console.WriteLine("Order not found");
                return null;
            }
            
            if (order.Count == 0)
            {
                Console.WriteLine("Order is empty");
                return null;
            }

            order.Count--;
            return order;
        }

        public Administrator(string name)
        {
            Name = name;
        }

        public Administrator()
        {
            this.Name = "Unknown";
        }
    }
    #endregion

    #region Client
    interface IClient : IPerson
    {
        List<IOrder> Orders { get; set; }
        void TakeOrder(IAdministrator administrator, string name);
    }

    class Client : IClient
    {
        public string Name { get; set; } = "Unknown";
        public List<IOrder> Orders { get; set; } = new List<IOrder>();

        public Client(string name)
        {
            Name = name;
        }

        public Client()
        {
            this.Name = "Unknown";
        }

        public void TakeOrder(IAdministrator administrator, string name)
        {
            var order = administrator.GiveOrder(name);
            if (order is not null)
            {
                Orders.Add(order);
            }
        }
    }
    #endregion

    class Program
    {
        static public void Main()
        {
            var admin = Admin.GetAdmin();
            admin.ChangeBGColor(ConsoleColor.Red);

            PrimeOrderFactory pof = new();
            StandardOrderFactory sof = new();

            IOrder po = pof.GetOrder("Fligth to London", 10, pof.GetQuality());
            IOrder so = sof.GetOrder("Fligth to Kongo", 10, sof.GetQuality());

            IAdministrator administrator = new Administrator("Dima Trubach");

            ISystemBuilder system = System.CreateSystem(100, "System 1", administrator, po, so);

            IClient client = new Client("Vasya Pupkin");

            client.TakeOrder(administrator, "Fligth to London");

            so.Name = "Fligth to Russia";
            IOrder so2 = so.Clone();
            so2.Name = "Fligth to USA";
            so2.Quality.Name = "Prime";

            Console.WriteLine("Orders:");
            foreach (var order in system.Orders)
            {
                Console.WriteLine($"Name: {order.Name}, Count: {order.Count}, Quality: {order.Quality.Name}");
            }

            Console.WriteLine("Client orders:");
            foreach (var order in client.Orders)
            {
                Console.WriteLine($"Name: {order.Name}, Count: {order.Count}, Quality: {order.Quality.Name}");
            }
        }
    }

    #region Admin
    class Admin
    {
        public static string Name { get; set; }
        private static Admin admin = null;
        private Admin() { }

        static Admin()
        {
            if (admin is null)
            {
                admin = new Admin();
            }
        }

        public static Admin GetAdmin() => admin;

        public void ChangeBGColor(ConsoleColor color) => Console.BackgroundColor = color;

        // Изменить шрифт консоли
        public void ChangeFontColor(ConsoleColor color) => Console.ForegroundColor = color;

        // Изменить размер консоли
        public void ChangeConsoleSize(int width, int height) => Console.SetWindowSize(width, height);

        // Изменить заголовок консоли
        public void ChangeConsoleTitle(string title) => Console.Title = title;

        // Изменить курсор консоли
        public void ChangeCursorSize(int size) => Console.CursorSize = size;

        // Изменить видимость курсора
        public void ChangeCursorVisibility(bool visibility) => Console.CursorVisible = visibility;

        // Изменить позицию курсора
        public void ChangeCursorPosition(int x, int y) => Console.SetCursorPosition(x, y);
    }
    #endregion

    #region Prototype
    interface IPrototype<T>
    {
        T Clone();
    }
    #endregion
}