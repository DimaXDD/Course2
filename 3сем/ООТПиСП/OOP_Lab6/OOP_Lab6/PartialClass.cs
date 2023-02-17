using System;
using System.Collections.Generic;
using System.Text;

namespace OOP_Lab6
{
    partial class State : Continent
    {
        public string NameState { get; set; }
        public string President { get; set; }
        public int Population { get; set; }
        public State(string state, string president, int population, string cont, int square)
        {
            NameState = state;
            President = president;
            Population = population;
            NameCont = cont;
            Square = square;
        }
    }
}