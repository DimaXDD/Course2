using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Lab4_5
{
    public class CustomCommands
    {
       public static readonly RoutedUICommand MyCustomCommand = new RoutedUICommand(
       "My Custom Command",
       "MyCustomCommand",
       typeof(CustomCommands),
       new InputGestureCollection()
       {
            new KeyGesture(Key.X, ModifierKeys.Control)
       }
   );
    }
}
