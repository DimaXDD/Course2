using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Drawing;
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
using System.Windows.Shapes;

namespace Lab4_5
{
    /// <summary>
    /// Логика взаимодействия для Results.xaml
    /// </summary>
    public partial class Results : Window
    {
        private FileIOService _fos = new FileIOService();
        private BindingList<Flight> all_flights = new BindingList<Flight>();
        private BindingList<Flight> searchNsort = new BindingList<Flight>();
        private Flight fl = new Flight();
        private Flight lastAdded = new Flight();
        private Flight LastRemoved = new Flight();
        string lastAction = "";
        string undoAction;
        string depCity;
        string desCity;
        DateTime depT;

        public Results(string depc, string desc, DateTime dt)
        {
                 /*      Cursor c = new Cursor("E:\\2_курс\\4сем\\ООТПиСП\\Lab4_5\\Lab4_5\\images\\cursor.cur");
                        this.Cursor = c;*/
            depCity = depc;
            desCity = desc;
            depT = Convert.ToDateTime(dt);
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            try
            {
                all_flights = _fos.LoadData();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                Close();
            }

            var res = all_flights
                .Where(x => x.DepartureCity == depCity)
                .Where(x => x.DestinationCity == desCity)
                .Where(x => x.DepTime.Date == depT.Date);
            if (res.Count() > 0)
            {
                foreach (var el in res)
                    searchNsort.Add(el);
                dgResults.ItemsSource = searchNsort;
            }
            else
                MessageBox.Show("Рейсы для ваших параметров отсутствуют :(", "Что-то пошло не так", MessageBoxButton.OK, MessageBoxImage.Warning);
            /* dgResults.ItemsSource = all_flights;*/
            depPicker.DisplayDateStart = DateTime.Now;
            depPicker.SelectedDate = DateTime.Today;
            dPickerFrom.DisplayDateStart = DateTime.Today;
            dPickerFrom.SelectedDate = DateTime.Today;
            dPickerTo.DisplayDateStart = DateTime.Today.AddDays(1);
            dPickerTo.SelectedDate = DateTime.Today.AddDays(1);
        }

        private void HoursInFlight_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            e.Handled = !IsNumber(e.Text);
        }
        private bool IsNumber(string text)
        {
            int result;
            return int.TryParse(text, out result);
        }

        private void desDep_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            foreach (char c in e.Text)
            {
                if (!Char.IsLetter(c))
                {
                    e.Handled = true;
                    break;
                }
            }
        }

        private void CreateFlight_Click(object sender, RoutedEventArgs e)
        {

            if (depFrom.Text == "Minsk" || desTo.Text == "Minsk" || desTo.Text == depFrom.Text)
            {
                MessageBox.Show("Ошибка ввода локации", "Внимание!", MessageBoxButton.OK, MessageBoxImage.Information);
                depFrom.Text = "";
                desTo.Text = "";
                return;
            }
            fl.DepartureCity = depFrom.Text;
            fl.DestinationCity = desTo.Text;
            fl.Num = Convert.ToInt32(NumBox.Text);
            fl.Price = Convert.ToInt32(PriceSlider.Value);
            fl.DepTime = Convert.ToDateTime(depPicker.Text);
            fl.DestinationTime = fl.DepTime.AddHours(Convert.ToInt32(HoursInFlight.Text));
            if (all_flights.Contains(fl))
            {
                MessageBox.Show("Такой рейс уже существует", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Information);
            }
            else
            {
                lastAdded = fl;
                lastAction = "add";
                all_flights.Add(fl);
                try
                {
                    _fos.SaveData(all_flights);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
        }

        private void deleteFlight_Click(object sender, RoutedEventArgs e)
        {
            if (numberToDelete.Text == null || numberToDelete.Text == "")
                return;
            var res = all_flights.Where(x => x.Num == Convert.ToInt32(numberToDelete.Text));
            Flight f = new Flight();
            foreach (var el in res)
            {
                f = res.First();
            }
            if (f.Num == Convert.ToInt32(numberToDelete.Text))
            {
                LastRemoved = f;
                lastAction = "del";
                all_flights.Remove(f);
            }
            else
            {
                MessageBox.Show("Рейс с таким номером отсутствует", "Что-то пошло не так", MessageBoxButton.OK, MessageBoxImage.Question);
            }
            try
            {
                _fos.SaveData(all_flights);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            dgResults.ItemsSource = all_flights;
        }

        private void Filter_Click(object sender, RoutedEventArgs e)
        {
            var res = all_flights
                .Where(x => (x.Price >= Convert.ToInt32(priceStart.Text)) && (x.Price <= Convert.ToInt32(priceEnd.Text)))
                .Where(x => x.DepartureCity == depFilter.Text)
                .Where(x => (x.DepTime >= Convert.ToDateTime(dPickerFrom.Text)) && (x.DepTime <= Convert.ToDateTime(dPickerTo.Text)));
            if (res.Count() > 0)
            {
                searchNsort.Clear();
                foreach (var el in res)
                {
                    searchNsort.Add(el);
                }
                dgResults.ItemsSource = searchNsort;
            }
            else
                MessageBox.Show("Рейсы для ваших параметров отсутствуют :(", "Что-то пошло не так", MessageBoxButton.OK, MessageBoxImage.Warning);
        }

        private void ENGbutton_Click(object sender, RoutedEventArgs e)
        {
            ResourceDictionary dict = new ResourceDictionary();
            dict.Source = new Uri("Dictionary-en.xaml", UriKind.RelativeOrAbsolute);
            this.Resources.MergedDictionaries.Clear();
            this.Resources.MergedDictionaries.Add(dict);
        }

        private void RUbtn_Click(object sender, RoutedEventArgs e)
        {
            ResourceDictionary dict = new ResourceDictionary();
            dict.Source = new Uri("Dictionary-ru.xaml", UriKind.RelativeOrAbsolute);
            this.Resources.MergedDictionaries.Clear();
            this.Resources.MergedDictionaries.Add(dict);
        }

        private void Night_Click(object sender, RoutedEventArgs e)
        {
            var uri = new Uri(@"NightMode.xaml", UriKind.Relative);
            ResourceDictionary resourceDict = Application.LoadComponent(uri) as ResourceDictionary;
            Application.Current.Resources.Clear();
            Application.Current.Resources.MergedDictionaries.Add(resourceDict);
        }

        private void Day_Click(object sender, RoutedEventArgs e)
        {
            var uri = new Uri(@"DayMode.xaml", UriKind.Relative);
            ResourceDictionary resourceDict = Application.LoadComponent(uri) as ResourceDictionary;
            Application.Current.Resources.Clear();
            Application.Current.Resources.MergedDictionaries.Add(resourceDict);

        }

        private void CommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            MessageBox.Show("Вы использовали кастомную команду для закрытия данного окна", "Внимание", MessageBoxButton.OK, MessageBoxImage.Information);
            Close();

        }

        private void CommandBinding_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void Undo_Click(object sender, RoutedEventArgs e)
        {
            //почти доведено до идеала. Добавить isEnabled, проверку на null/"" везде + обнуление действий и т.д
            if (lastAction == null || lastAction == "")
            {
                MessageBox.Show("Действие вызвало ошибку", "ERROR!", MessageBoxButton.OK, MessageBoxImage.Error);
                return;

            }
            if (lastAction == "del")
            {
                all_flights.Add(LastRemoved);
                lastAdded = LastRemoved;
                undoAction = "ADDED";
                lastAction = "";
            }
            else if (lastAction == "add")
            {
                all_flights.Remove(lastAdded);
                LastRemoved = lastAdded;
                undoAction = "REMOVED";
                lastAction = "";
            }
        }

        private void Redo_Click(object sender, RoutedEventArgs e)
        {
            if (undoAction == null || undoAction == "")
            {
                {
                    MessageBox.Show("Действие вызвало ошибку", "ERROR!", MessageBoxButton.OK, MessageBoxImage.Error);
                }
                return;
            }

            if (undoAction == "REMOVED")
            {
                all_flights.Add(LastRemoved);
                lastAdded = LastRemoved;
                undoAction = "";
                lastAction = "add";
            }
            else if (undoAction == "ADDED")
            {
                all_flights.Remove(lastAdded);
                LastRemoved = lastAdded;
                undoAction = "";
                lastAction = "del";
            }
        }
        private void CustomButton_Click(object sender, RoutedEventArgs e)
        {
            ParentGrid.Background = System.Windows.Media.Brushes.Azure;
        }
    }
}
