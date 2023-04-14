using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4_5
{
    public class CommandManager
    {
        private readonly Stack<Command> _undoStack = new Stack<Command>();
        private readonly Stack<Command> _redoStack = new Stack<Command>();

        public void Execute(Command command)
        {
            command.Execute();
            _undoStack.Push(command);
            _redoStack.Clear();
        }

        public void Undo()
        {
            if (_undoStack.Count > 0)
            {
                Command command = _undoStack.Pop();
                command.Undo();
                _redoStack.Push(command);
            }
        }

        public void Redo()
        {
            if (_redoStack.Count > 0)
            {
                Command command = _redoStack.Pop();
                command.Execute();
                _undoStack.Push(command);
            }
        }

        public bool CanUndo()
        {
            return _undoStack.Count > 0;
        }

        public bool CanRedo()
        {
            return _redoStack.Count > 0;
        }
    }
}
