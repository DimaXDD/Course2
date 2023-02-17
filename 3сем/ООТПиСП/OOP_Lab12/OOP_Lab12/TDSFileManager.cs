using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
using System.IO.Compression;

namespace OOP_Lab12
{
    static class TDSFileManager
    {
        public static void GetFilesAndFoulders(string path)
        {
            /*. Прочитать список файлов и папок заданного диска. Создать
            директорий XXXInspect, создать текстовый файл
            xxxdirinfo.txt и сохранить туда информацию. Создать
            копию файла и переименовать его. Удалить
            первоначальный файл.*/
            DirectoryInfo dir = new(path);
            var files = dir.GetFiles();
            var folders = dir.GetDirectories();

            dir.CreateSubdirectory("TDSInspect");
            dir = new(path + "\\TDSInspect");

            string path_dirInfo = "TDSdirinfo.txt";
            using StreamWriter sw = new(dir.FullName + "\\" + path_dirInfo);
            sw.WriteLine("Файлы:");
            foreach (var file in files)
            {
                sw.WriteLine(file.Name);
            }
            sw.WriteLine("\n");
            sw.WriteLine("Папки:");
            foreach (var folder in folders)
            {
                sw.WriteLine(folder.Name);
            }
        }

        public static void CreateCopyOfFile(string path)
        {
            /*b. Создать еще один директорий XXXFiles. Скопировать в
            него все файлы с заданным расширением из заданного
            пользователем директория. Переместить XXXFiles в
            XXXInspect.*/
            FileInfo file = new(path);
            DirectoryInfo dir = file.Directory ??
                          throw new ArgumentNullException("Directory is not found");
            string fullNameOfCopy = $"{dir.FullName}\\copy_{file.Name}";
            Remove(fullNameOfCopy);
            file.CopyTo(fullNameOfCopy);
        }
        public static void Remove(string path)
        {
            if (path is null)
            {
                throw new ArgumentNullException(nameof(path));
            }

            FileInfo file = new(path);
            file.Delete();

            TDSLog.WriteToFile(MethodBase.GetCurrentMethod().Name, MethodBase.GetCurrentMethod().DeclaringType.Name);
        }

        public static void CreateDirectory(string path, string name)
        {
            /*Сделайте архив из файлов директория XXXFiles.
            Разархивируйте его в другой директорий.*/
            if (path is null)
            {
                throw new ArgumentNullException(nameof(path));
            }
            if (name is null)
            {
                throw new ArgumentNullException(nameof(name));
            }

            DirectoryInfo dir = new(path);
            dir.CreateSubdirectory(name);

            TDSLog.WriteToFile(MethodBase.GetCurrentMethod().Name, MethodBase.GetCurrentMethod().DeclaringType.Name);
        }

        public static void ReplaceTo(string pathFrom, string pathTo, params string[] extens)
        {
            DirectoryInfo dirFrom = new(pathFrom);
            DirectoryInfo dirTo = new(pathTo);

            var files = dirFrom.GetFiles();

            foreach (var file in files)
            {
                if (extens.Length == 0 ||
                    extens.Contains(file.Extension))
                {
                    Remove(dirTo.FullName + "\\" + file.Name);
                    file.MoveTo(dirTo.FullName + "\\" + file.Name);
                }
            }
            TDSLog.WriteToFile(MethodBase.GetCurrentMethod().Name, MethodBase.GetCurrentMethod().DeclaringType.Name);
        }

        public static void CreateZip(string path)
        {
            DirectoryInfo dir = new(path);
            string zipPath = $"{dir.FullName}\\{dir.Name}.zip";
            ZipFile.CreateFromDirectory(dir.FullName, zipPath);
            TDSLog.WriteToFile(MethodBase.GetCurrentMethod().Name, MethodBase.GetCurrentMethod().DeclaringType.Name);
        }
    }
}