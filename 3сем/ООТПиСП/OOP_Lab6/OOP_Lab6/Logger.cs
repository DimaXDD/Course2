using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab6
{
    class Logger
    {
        private static readonly string Path = "log.txt";
        private DateTime ErrorTime;
        private DateTime EndTime;
        private string Message;
        private readonly DateTime StartTime;

        public Logger()
        {
            using StreamWriter LogFile = new(Path, false);
            StartTime = DateTime.Now;
            Message = ("Начало выполнения программы: " + StartTime.ToString());
            LogFile.WriteLine(Message);
        }

        public void WriteLine(string msg)
        {
            using StreamWriter LogFile = new(Path, true);
            LogFile.WriteLine(msg);
        }

        public void WriteError(string msg)
        {
            using StreamWriter LogFile = new(Path, true);
            ErrorTime = DateTime.Now;
            Message = msg;
            LogFile.WriteLine($"Error: {Message} -- at {ErrorTime}");
        }
        public void WriteEnd()
        {
            EndTime = DateTime.Now;
            this.WriteLine(EndTime.ToString());
        }
    }

}
