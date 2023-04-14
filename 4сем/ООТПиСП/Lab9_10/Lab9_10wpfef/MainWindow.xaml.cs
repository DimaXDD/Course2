using Lab2;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Lab9_10wpfef
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        IEnumerable<object> AllData;
        public Owner owner = new Owner();
        public PersonalBill pb = new PersonalBill();
        public MainWindow()
        {
            InitializeComponent();
        }

        private void FIO_Container_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            Regex regex = new Regex("[^a-zA-Zа-яА-Я\\-]+");
            e.Handled = regex.IsMatch(e.Text);
        }

        private void BirthD_Picker_SelectedDateChanged(object sender, SelectionChangedEventArgs e)
        {
            DateTime? selectedDate = BirthD_Picker.SelectedDate;
            if (selectedDate != null)
            {
                this.owner.BirthDate = selectedDate.Value;
                /*                this.DateOfG.Text = selectedDate.Value.ToShortDateString();*/
                this.pb.SendDate = DateTime.Today.AddDays(7);
            }
        }

        private void Pasport_Container_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            Regex regex = new Regex("[^a-zA-Zа-яА-Я0-9]+"); // регулярное выражение для поиска символов, отличных от букв и цифр
            e.Handled = regex.IsMatch(e.Text); // проверяем, соответствует ли вводимый символ регулярному выражению
        }

        private void USD_Checked(object sender, RoutedEventArgs e)
        {
            this.pb.Wallet = "";
            RadioButton radioButton = sender as RadioButton;

            // Изменяем свойство класса в зависимости от выбранной кнопки
            if (radioButton != null && radioButton.IsChecked == true)
            {
                switch (radioButton.Name)
                {
                    case "RUB":
                        this.pb.Wallet = "RUB";
                        this.DateOfG.Text = radioButton.Name;
                        break;
                    case "BYN":
                        this.pb.Wallet = "BYN";
                        this.DateOfG.Text = radioButton.Name;
                        break;
                    case "USD":
                        this.pb.Wallet = "USD";
                        this.DateOfG.Text = radioButton.Name;
                        break;
                }
            }
        }

        private void Cashback_Checked(object sender, RoutedEventArgs e)
        {
            CheckBox cb = (CheckBox)sender;
            if (cb.IsChecked == true)
            {
                this.pb.Services = cb.Content.ToString();
                this.DateOfG.Text = cb.Content.ToString();
            }
        }

        private void StartB_Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            int sliderVal = Convert.ToInt32(StartB_Slider.Value);
            this.pb.StartBalance = sliderVal;
        }

        private void Town_Box_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ComboBox comboBox = (ComboBox)sender;
            this.pb.Town = comboBox.Text;
        }

        private void PhoneNum_TextChanged(object sender, TextChangedEventArgs e)
        {
            this.owner.PhoneNumber = PhoneNum.Text;
        }

        private void PhoneNum_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            foreach (var ch in e.Text)
            {
                if (!char.IsDigit(ch))
                {
                    e.Handled = true;
                    return;
                }
            }
        }

        private void Create_Click(object sender, RoutedEventArgs e)
        {
            this.owner.FIO = FIO_Container.Text;
            this.owner.PassportInfo = Pasport_Container.Text;
            this.owner.PersonalBills = new List<PersonalBill>();
/*            this.pb.Wallet = "USD";
            this.pb.Services = "Banking";*/
            this.owner.PersonalBills.Add(this.pb);

            using (var unitOfWork = new UnitOfWork(new Context()))
            {
                var ownerRepository = unitOfWork.Repository<Owner>();
                ownerRepository.Add(owner);
                unitOfWork.Save();
            }

        }

        private void Show_all_bills_Click(object sender, RoutedEventArgs e)
        {
            using (var unitOfWork = new UnitOfWork(new Context()))
            {
                AllData = unitOfWork.Repository<PersonalBill>().GetAll();
                dgResults.ItemsSource = AllData;
            }


            }

        private void Show_all_owners_Click(object sender, RoutedEventArgs e)
        {
            using (var unitOfWork = new UnitOfWork(new Context()))
            {
                AllData = unitOfWork.Repository<Owner>().GetAll();
                dgResults.ItemsSource = AllData;
            }
        }

        private void Delete_Click(object sender, RoutedEventArgs e)
        {
            using (var _unitOfWork = new UnitOfWork(new Context()))
            {
                try
                {
                    int billid = Convert.ToInt32(NumToDelete.Text);
                    var billRep = _unitOfWork.Repository<PersonalBill>();
                    var bill = billRep.GetById(billid);
                    if (bill != null) // Проверяем, что запись с таким идентификатором найдена
                    {
                        billRep.Remove(bill);
                        _unitOfWork.Save(); // Сохраняем изменения
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Ошибка!", MessageBoxButton.OK, MessageBoxImage.Error);
                }
            }
        }

        private void SortByNum_Click(object sender, RoutedEventArgs e)
        {
            using var context = new Context();
            var allowners = context.Owners.FromSql(FormattableStringFactory.Create("SELECT * FROM Owners order by ID")).ToList();
            dgResults.ItemsSource = allowners;
        }

        private void SortByFIO_Click(object sender, RoutedEventArgs e)
        {
            using var context = new Context();
            var allowners = context.Owners.FromSql(FormattableStringFactory.Create("SELECT * FROM Owners order by FIO")).ToList();
            dgResults.ItemsSource = allowners;
        }

        private void Wallet_Search_Click(object sender, RoutedEventArgs e)
        {
            using (Context context = new Context())
            {
                using (var tran = context.Database.BeginTransaction())
                {
                    try
                    {
                        var allowners = context.Bills.FromSql(FormattableStringFactory.Create($"SELECT * FROM Bills where Wallet = \'{Wallet_Search_tb.Text}\'")).ToList();
                        if(allowners != null)
                        dgResults.ItemsSource = allowners;
                        tran.Commit();
                    }
                    catch (Exception ex)
                    {
                        tran.Rollback();
                        Console.WriteLine(ex.ToString());
                    }
                }
            }
        }

        private void FIO_Search_Click(object sender, RoutedEventArgs e)
        {
            using (Context context = new Context())
            {
                using (var tran = context.Database.BeginTransaction())
                {
                    try
                    {
                        var allowners = context.Owners.FromSql(FormattableStringFactory.Create($"SELECT * FROM Owners where FIO like \'{FIO_SEARCH_TB.Text}%\'")).ToList();
                        dgResults.ItemsSource = allowners;
                        tran.Commit();
                    }
                    catch (Exception ex)
                    {
                        tran.Rollback();
                        Console.WriteLine(ex.ToString());
                    }
                }
            }
        }
    }
}
