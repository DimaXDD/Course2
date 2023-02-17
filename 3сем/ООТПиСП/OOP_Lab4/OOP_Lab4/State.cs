using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab4
{
    partial class State : Continent
    {
        public override bool Equals(object Obj)
        {
            if (Obj == null)
                return false;
            State temp = (State)Obj;
            return temp.Square == Square;
        }
        public override int GetHashCode()
        {
            return 123 * Square;
        }

        public override string ToString()
        {
            return $"{GetType()} {Belt} {NameCont} {Square} {Soil} {Relief}";
        }

    }
}
