using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace OOP_Lab12
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("Тест метода GetDiskInfo()");
                TDSDiskInfo.GetDiskInfo();
                Console.WriteLine("\n\nТест метода GetFileInfo()");
                TDSFileInfo.GetFileInfo("E:\\2_курс\\3сем\\ООТПиСП\\Условия\\12_Потоки_файловая система.pdf");
                Console.WriteLine("\n\nТест метода GetDirInfo()");
                TDSDirInfo.GetDirInfo("E:\\2_курс\\3сем\\ООТПиСП");
                Console.WriteLine("\n\nТест метода GetFilesAndFoulders()");
                TDSFileManager.GetFilesAndFoulders("..\\net6.0");
                Console.WriteLine("\n\nТест метода CreateCopyOfFile()");
                TDSFileManager.CreateCopyOfFile("..\\net6.0\\TDSInspect\\TDSdirinfo.txt");
                Console.WriteLine("\n\nТест метода Remove()");
                //TDSFileManager.Remove("..\\net6.0\\TDSInspect\\TDSdirinfo.txt\\copy_TDSdirinfo.txt");
                Console.WriteLine("\n\nСоздание директория TDSFiles");
                TDSFileManager.CreateDirectory("..\\net6.0", "TDSFiles");
                Console.WriteLine("\n\nКопирование файлов с расширением .dll и .exe в директорию TDSFiles");
                TDSFileManager.ReplaceTo("..\\net6.0", "TDSFiles", ".dll", ".exe");
                Console.WriteLine("\n\nУпаковка в zip-архив TDSFiles");
                TDSFileManager.CreateZip("TDSFiles");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}