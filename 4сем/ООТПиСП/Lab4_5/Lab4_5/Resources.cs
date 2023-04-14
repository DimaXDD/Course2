using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace Lab4_5
{
    public class Resources
    {
        private static ResourceDictionary _resources;

        static Resources()
        {
            _resources = new ResourceDictionary();
            _resources.Source = new Uri("Dictionary-en.xaml", UriKind.RelativeOrAbsolute);
        }

        public static string GetString(string key)
        {
            return _resources[key] as string;
        }

        public static void SetLanguage(CultureInfo culture)
        {
            string dictionaryName = $"Dictiontary-ru.xaml";
            var dictionary = new ResourceDictionary();
            dictionary.Source = new Uri(dictionaryName, UriKind.RelativeOrAbsolute);
            _resources = dictionary;
        }
    }
}
