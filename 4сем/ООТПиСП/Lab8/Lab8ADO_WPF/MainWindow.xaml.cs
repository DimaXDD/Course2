using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Text;
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
using System.Configuration;
using Lab2;
using System.Text.RegularExpressions;
using System.IO;
using System.Xml.Serialization;

namespace Lab8ADO_WPF
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        SqlConnection conn;
        PersonalBill pb = new PersonalBill();

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            conn = new SqlConnection(ConfigurationManager.ConnectionStrings["myConnection"].ConnectionString);
            conn.Open();
            BirthD_Picker.DisplayDateEnd = DateTime.Now.AddYears(-18);
            BirthD_Picker.DisplayDateStart = DateTime.Now.AddYears(-100);
            BirthD_Picker.SelectedDate = DateTime.Now.AddYears(-18).AddDays(-31);
            DateOfG.Text = $"Примерная дата выдачи \n {DateTime.Now.AddDays(7).ToShortDateString()}";
        }

        private void Show_all_Click(object sender, RoutedEventArgs e)
        {
            DataTable dataTable = GetDataFromDatabase("SELECT * FROM PersonalBill");
            dgResults.ItemsSource = dataTable.DefaultView;

        }

        private DataTable GetDataFromDatabase(string _query)
        {
                SqlDataAdapter adapter = new SqlDataAdapter(_query, conn);
                DataTable dataTable = new DataTable();
                adapter.Fill(dataTable);
                return dataTable;
        }

        private void SortByNum_Click(object sender, RoutedEventArgs e)
        {
            DataTable dataTable = GetDataFromDatabase("SELECT * FROM PersonalBill order by Id asc");
            dgResults.ItemsSource = dataTable.DefaultView;

        }

        private void SortByFIO_Click(object sender, RoutedEventArgs e)
        {
            DataTable dataTable = GetDataFromDatabase("SELECT * FROM Owner order by FIO asc");
            dgResults.ItemsSource = dataTable.DefaultView;

        }

        private void NumToDelete_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
       
        }

        private void Delete_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                DataTable dataTable = GetDataFromDatabase($"begin tran delete PersonalBill where FIO like \'{NumToDelete.Text}%\'; commit tran;");
                DataTable dataTablex0 = GetDataFromDatabase($"begin tran delete Owner where FIO like \'{NumToDelete.Text}%\'; commit tran;");
            }
            catch (SqlException ex)
            {
                string errormsg = "";
                foreach (SqlError err in ex.Errors)
                {
                    errormsg += err.Message + ",";
                }
                MessageBox.Show(errormsg, "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            finally
            {
                DataTable dataTablex1 = GetDataFromDatabase("SELECT * FROM PersonalBill");
                dgResults.ItemsSource = dataTablex1.DefaultView;
            }
        }

        private void Create_Click(object sender, RoutedEventArgs e)
        {
            this.pb.owner.FIO = FIO_Container.Text;
            this.pb.owner.PassportInfo = Pasport_Container.Text;
            try
            {
                SqlCommand c = new SqlCommand();
                c.Connection = conn;
                c.CommandText = "Begin tran " +
                    "INSERT OWNER values (@value1, @value2, @value3, @value4, @value5);" +
                    "commit tran;";
                c.Parameters.AddWithValue("@value1", this.pb.owner.FIO);
                c.Parameters.AddWithValue("@value2", this.pb.owner.birthDate);
                c.Parameters.AddWithValue("@value3", this.pb.owner.phoneNumber);
                c.Parameters.AddWithValue("@value4", this.pb.owner.wallet);
                c.Parameters.AddWithValue("@value5", this.pb.owner.PassportInfo);
                int rowsAffected = c.ExecuteNonQuery();
                if (rowsAffected != 1)
                {
                    MessageBox.Show("Неудачная операция вставки", "Ошибка");
                    return;
                }
                c.CommandText = "Begin tran " +
                      "INSERT into PersonalBill(FIO, sendDate, startBalance, town, services) values (@value01, @value02, @value03, @value04, @value05);" +
                      "commit tran;";
                c.Parameters.AddWithValue("@value01", this.pb.owner.FIO);
                c.Parameters.AddWithValue("@value02", this.pb.sendDate);
                c.Parameters.AddWithValue("@value03", this.pb.startBalance);
                c.Parameters.AddWithValue("@value04", this.pb.town);
                c.Parameters.AddWithValue("@value05", this.pb.services);
                rowsAffected = c.ExecuteNonQuery();
                if (rowsAffected != 1)
                {
                    MessageBox.Show("Неудачная операция вставки", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
                    return;
                }
                MessageBox.Show("Cчет создан!", "Поздравляем", MessageBoxButton.OK, MessageBoxImage.Information);
                pb = new PersonalBill();
            }
            catch (SqlException ex)
            {
                string errormsg = "";
                foreach(SqlError err in ex.Errors)
                {
                    errormsg += err.Message + ",";
                }
                MessageBox.Show(errormsg, "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
            }


        }

        private void Town_Box_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ComboBox comboBox = (ComboBox)sender;
            this.pb.town = comboBox.Text;
/*            DateOfG.Text = comboBox.Text;*/
        }

        private void RUB_Checked(object sender, RoutedEventArgs e)
        {
            RadioButton radioButton = sender as RadioButton;

            // Изменяем свойство класса в зависимости от выбранной кнопки
            if (radioButton != null && radioButton.IsChecked == true)
            {
                switch (radioButton.Name)
                {
                    case "RUB":
                        this.pb.owner.wallet = "RUB";
                        this.DateOfG.Text = radioButton.Name;
                        break;
                    case "BYN":
                        this.pb.owner.wallet = "BYN";
                        this.DateOfG.Text = radioButton.Name;
                        break;
                    case "USD":
                        this.pb.owner.wallet = "USD";
                        this.DateOfG.Text = radioButton.Name;
                        break;
                }
            }
        }

        private void BirthD_Picker_SelectedDateChanged(object sender, SelectionChangedEventArgs e)
        {
            DateTime? selectedDate = BirthD_Picker.SelectedDate;
            if (selectedDate != null)
            {
                this.pb.owner.birthDate = selectedDate.Value;
/*                this.DateOfG.Text = selectedDate.Value.ToShortDateString();*/
                this.pb.sendDate = DateTime.Today.AddDays(7);
            }
        }

        private void StartB_Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            int sliderVal = Convert.ToInt32(StartB_Slider.Value);
            this.pb.startBalance = sliderVal;
/*            this.DateOfG.Text = Convert.ToInt32(StartB_Slider.Value).ToString();*/
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            this.pb.owner.phoneNumber = PhoneNum.Text;
        }

        private void FIO_Container_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            Regex regex = new Regex("[^a-zA-Zа-яА-Я\\-]+");
            e.Handled = regex.IsMatch(e.Text);
        }

        private void Pasport_Container_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            Regex regex = new Regex("[^a-zA-Zа-яА-Я0-9]+"); // регулярное выражение для поиска символов, отличных от букв и цифр
            e.Handled = regex.IsMatch(e.Text); // проверяем, соответствует ли вводимый символ регулярному выражению
        }

        private void Banking_Checked(object sender, RoutedEventArgs e)
        {
            CheckBox cb = (CheckBox)sender;
            if(cb.IsChecked == true)
            {
                this.pb.services = cb.Content.ToString();
                this.DateOfG.Text = cb.Content.ToString();
            }

        }

        private void Show_all_owners_Click(object sender, RoutedEventArgs e)
        {
            DataTable dataTable = GetDataFromDatabase("SELECT * FROM Owner");
            dgResults.ItemsSource = dataTable.DefaultView;
        }

        private void Wallet_Search_tb_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            foreach (var ch in e.Text)
            {
                if (!char.IsLetter(ch))
                {
                    e.Handled = true;
                    return;
                }
            }
        }

        private void Wallet_Search_Click(object sender, RoutedEventArgs e)
        {
            DataTable dataTable = GetDataFromDatabase($"exec Find_bill_by_type @wallet = \'{Wallet_Search_tb.Text}\'");
            dgResults.ItemsSource = dataTable.DefaultView;

        }

        private void FIO_Search_Click(object sender, RoutedEventArgs e)
        {
            DataTable dataTable = GetDataFromDatabase($"exec Find_bill_By_Surname @srnm = \'{FIO_SEARCH_TB.Text}\'");
            dgResults.ItemsSource = dataTable.DefaultView;
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            conn.Close();
        }
    }
}
