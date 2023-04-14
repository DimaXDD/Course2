using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4_5
{
    public abstract class Command
    {
        public abstract void Execute();
        public abstract void Undo();
    }

    public class AddCommand : Command
    {
        private readonly ObservableCollection<Flight> _collection;
        private readonly Flight _item;

        public AddCommand(ObservableCollection<Flight> collection, Flight item)
        {
            _collection = collection;
            _item = item;
        }

        public override void Execute()
        {
            _collection.Add(_item);
        }

        public override void Undo()
        {
            _collection.Remove(_item);
        }
    }
}
