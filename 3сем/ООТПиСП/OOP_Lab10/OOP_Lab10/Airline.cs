using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab10
{
    class Airline
    {
        public string Destination { get; set; }
        public int FlightNumber { get; set; }
        public string AircraftType { get; set; }
        public int HourTime { get; set; }
        public int MinuteTime { get; set; }
        public string DayOfWeek { get; set; }
        public Airline(string destination, int flightNumber, string aircraftType, int hourTime, int minuteTime, string dayOfWeek)
        {
            Destination = destination;
            FlightNumber = flightNumber;
            AircraftType = aircraftType;
            HourTime = hourTime;
            MinuteTime = minuteTime;
            DayOfWeek = dayOfWeek;
        }
        public override string ToString()
        {
            return $"Destination: {Destination}, FlightNumber: {FlightNumber}, AircraftType: {AircraftType}, HourTime: {HourTime}, MinuteTime: {MinuteTime}, DayOfWeek: {DayOfWeek}";
        }
    }
}
