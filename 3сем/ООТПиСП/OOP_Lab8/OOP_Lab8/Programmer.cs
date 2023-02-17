using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace OOP_Lab8
{
   /* Создать класс Программист с событиями Переименовать и
    Новое свойство.В main создать некоторое количество объектов
    (языков программирования). Подпишите объекты на события
    произвольным образом.Реакция на события может быть
    следующая: изменение имени/версии, добавление новых операций,
    технологий или понятий.Проверить результаты изменения
    состояния объектов после наступления событий, возможно не
    однократном*/
    class Programmer
    {
        #region Events

        delegate void RenameEventHandler(string name);

        public event EventHandler Rename; //событие стандартного типа
        public event EventHandler NewProperty;
        #endregion

        #region Fields
        private string _name;
        #endregion

        #region Constructors
        public Programmer(string name)
        {
            _name = name;
        }
        #endregion

        #region Methods
        public void CommandAddOperation()
        {
            NewProperty?.Invoke(this, null);
        }

        public void CommandRenaneOperation()
        {
            Rename?.Invoke(this, null);
        }
        #endregion

    }
}
