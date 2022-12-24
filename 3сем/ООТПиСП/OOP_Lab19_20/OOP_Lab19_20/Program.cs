using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab_19_20
{
    #region Abstract Factory

    interface IQuality : IGift
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

        public Gift GiveGift() => new("Билет в Китай");
    }

    class Standard : IQuality
    {
        public string Name { get; set; } = "Standard";

        public Standard()
        {

        }

        public Standard(string name) => Name = name;

        public Gift GiveGift() => new("Билет в Конго");
    }

    interface IOrder : IPrototype<IOrder>
    {
        string Name { get; set; }
        IQuality Quality { get; set; }
        uint Count { get; set; }

        string Context { get; set; }

        void GetInfo();
    }

    class PrimeOrder : IOrder
    {
        public string Name { get; set; } = "Prime Order";
        public IQuality Quality { get; set; } = new Prime();
        public uint Count { get; set; }

        public string Context { get; set; } = "Prime Order Context";

        public void GetInfo() => Console.WriteLine($"Name: {Name},\n" +
                                                   $"Quality: {Quality.Name},\n" +
                                                   $"Count: {Count}\n");

        public PrimeOrder(string name,
                           uint count,
                           IQuality quality)
        {
            Name = name;
            Count = count;
            Quality = quality;
        }

        public IOrder Clone() => new PrimeOrder(Name.Clone() as string, Count, new Prime(Name as string));

        public override string ToString() => Name;
    }

    class StandardOrder : IOrder
    {
        public string Name { get; set; } = "Standard Order";
        public IQuality Quality { get; set; }
        public uint Count { get; set; } = 0;

        public string Context { get; set; } = "Standard Order Context";

        public void GetInfo() => Console.WriteLine($"Name: {Name},\n" +
                                                   $"Quality: {Quality.Name},\n" +
                                                   $"Count: {Count}\n");

        public StandardOrder(string name,
                             uint count,
                             IQuality quality)
        {
            Name = name;
            Count = count;
            Quality = quality;
        }

        public IOrder Clone() => new StandardOrder(Name as string, Count, new Standard(Name as string));

        public override string ToString() => Name;
    }

    interface IOrderFactory
    {
        IQuality GetQuality();

        IOrder GetOrder(string name,
                      uint count,
                      IQuality quality);
    }

    class StandardOrderFactory : IOrderFactory
    {
        public IQuality GetQuality() => new Standard();
        
        public IOrder GetOrder(string name,
                             uint count,
                             IQuality quality) => new StandardOrder(name, count, quality);
    }

    class PrimeOrderFactory : IOrderFactory
    {
        public IQuality GetQuality() => new Prime();

        public IOrder GetOrder(string name,
                             uint count,
                             IQuality quality) => new PrimeOrder(name, count, quality);
    }

    #endregion
    
    #region Adapter

    interface IOrderAdapter
    {
        void Info();
    }

    class OrderAdapter : IOrderAdapter
    {
        private readonly IOrder _order;

        public OrderAdapter(IOrder order) => _order = order;

        public void Info() => _order.GetInfo();
    }

    #endregion

    #region Decorator

    abstract class BCD
    {
        protected BCD bcd { get; set; }
        public BCD(BCD bcd = null) => this.bcd = bcd;
        public abstract void Decore(IOrder order);
    }
    
    class Uppper : BCD
    {
        public Uppper(BCD bcd = null) : base(bcd) { }

        public override void Decore(IOrder order)
        {
            order.Context = order.Context.ToUpper();
            bcd?.Decore(order);
        }
    }

    class DeleteSpaces : BCD
    {
        public DeleteSpaces(BCD bcd = null) : base(bcd) { }

        public override void Decore(IOrder order)
        {
            order.Context = order.Context.Replace(" ", "");
            bcd?.Decore(order);
        }
    }

    class Changer : BCD
    {
        public Changer(BCD bcd = null) : base(bcd) { }

        public override void Decore(IOrder order)
        {
            order.Context = order.Context.Replace("Е", "е").Replace('И', 'и');
            bcd?.Decore(order);
        }
    }

    #endregion

    #region Command

    interface ICommandSystem
    {
        void Execute();
    }
    
    class SortOrdersByName : ICommandSystem
    {
        private ISystemBuilder system;
        public void Execute() => system.Orders = system.Orders.OrderBy(el => el.Name).ToList();

        public SortOrdersByName(ISystemBuilder system) => this.system = system;
    }

    class SortOrdersByQuality : ICommandSystem
    {
        private ISystemBuilder system;
        public void Execute() => system.Orders = system.Orders.OrderBy(el => el.Quality.Name).ToList();

        public SortOrdersByQuality(ISystemBuilder system) => this.system = system;
    }


    class Commander
    {
        private List<ICommandSystem> commands = new();

        public void SetCommand(ICommandSystem command) => commands.Add(command);

        public void DoCommand(int num) => commands[num].Execute();
    }

    #endregion

    #region Strategy

    interface IGift
    {
        Gift GiveGift();
    }

    class Gift
    {
        public string Name { get; set; } = "";

        public Gift(string name) => Name = name;

        public override string ToString() => "Подарок: " + Name;
    }

    #endregion

    #region Observer 

    interface IObserver
    {
        List<IPerson> Persons { get; set; }

        void Observe(string info);
    }

    interface IObserved
    {
        void Observe(string info);
    }

    #endregion

    #region Builder

    interface ISystemBuilder : IPerson, IObserver
    {
        uint MaxCount { get; set; }
        IAdministrator Administrator { get; set; }
        
        void AddOrder(IOrder order);
    }

    class System : ISystemBuilder
    {
        public uint MaxCount { get; set; }
        public string Name { get; set; }
        public List<IOrder> Orders { get; set; }
        public IAdministrator Administrator { get; set; }
        public List<IPerson> Persons { get; set; } = new();
        
        private System() { }
        private System(uint count,
                        string name,
                        IAdministrator administrator,
                        params IOrder[] orders)
        {
            this.SetMaxCount(count);
            this.SetName(name);
            this.SetAdministrator(administrator);
            this.SetOrders(orders);
        }

        private void SetMaxCount(uint count) => MaxCount = count;
        private void SetName(string name) => Name = name;
        private void SetOrders(params IOrder[] orders) => Orders = new(orders);
        private void SetAdministrator(IAdministrator administrator)
        {
            Administrator = administrator;
            Administrator.System = this;
        }

        public static System CreateSystem(uint count,
                                            string name,
                                            IAdministrator administrator,
                                            params IOrder[] orders)
        {
            return new System(count, name, administrator, orders);
        }

        public void AddOrder(IOrder order)
        {
            Orders.Add(order);

            string info = "";

            info = $"Добавленый ордер {order}";

            this.Observe(info);
        }

        public void Observe(string info)
        {
            Persons.ForEach(el => el.Observe(info));
        }
    }

    #endregion

    #region Person

    interface IPerson : IObserved
    {
        string Name { get; set; }
        List<IOrder> Orders { get; set; }
    }

    class Person : IPerson
    {
        public string Name { get; set; }
        public List<IOrder> Orders { get; set; }

        public Person(string name) => Name = name;

        public void Observe(string info) => Console.WriteLine($"Dear {Name}.\n{info}");
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
        public List<IOrder> Orders { get; set; }

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
                Console.WriteLine("Order is not available");
                return null;
            }

            var gift = order.Quality.GiveGift();

            Console.WriteLine($"Вы взяли order {order.Name}. Плюс ко всему вы получаете подарок {gift} за качество {order.Quality.Name}\n\n");

            order.Count--;
            return order;
        }

        public void Observe(string info) => Console.WriteLine($"Dear {Name}.\n{info}");

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
        void TakeOrder(IAdministrator administrator,
                      string name);
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

        public void TakeOrder(IAdministrator administrator,
                             string name)
        {
            var order = administrator.GiveOrder(name);
            if (order is not null)
            {
                Orders.Add(order);
            }
        }

        public void Observe(string info) => Console.WriteLine($"Dear {Name}. \n{info}");
    }

    #endregion

    class Program
    {
        static void Main()
        {
            var admin = Admin.GetAdmin();
            // admin.ChangeBGColor(ConsoleColor.Red);

            PrimeOrderFactory pof = new();
            StandardOrderFactory sof = new();

            IOrder po = pof.GetOrder("Билет to London", 228, pof.GetQuality());
            IOrder po2 = pof.GetOrder("Билет to Minsk", 5, pof.GetQuality());
            IOrder so = pof.GetOrder("Билет to Russia", 1200, sof.GetQuality());
            IOrder so2 = pof.GetOrder("Билет to USA", 100, sof.GetQuality());

            IAdministrator administrator = new Administrator("Администратор Дмитрий");

            ISystemBuilder system = System.CreateSystem(10, "Система заказов", administrator, po, so);
            system.Persons.Add(administrator);

            system.AddOrder(po2);
            system.AddOrder(so2);

            administrator.GiveOrder("Билет to London");

            Console.WriteLine("Ордера в системе: ");
            foreach (var order in system.Orders)
            {
                Console.WriteLine(order.Name);
            }
            Console.WriteLine("\n\n");

            IOrderAdapter adapter = new OrderAdapter(po);
            adapter.Info();

            po.Context = "Билет to Paris";

            BCD decorator = new Uppper(new DeleteSpaces(new Changer()));

            decorator.Decore(po);
            Console.WriteLine(po.Context);
            Console.WriteLine("\n\n");

            Commander commander = new();

            ICommandSystem sortByName = new SortOrdersByName(system);
            ICommandSystem sortByQuality = new SortOrdersByQuality(system);

            commander.SetCommand(sortByName);
            commander.SetCommand(sortByQuality);

            commander.DoCommand(0);

            Console.WriteLine("Ордера в системе after command: ");
            foreach (var order in system.Orders)
            {
                Console.WriteLine(order.Name);
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