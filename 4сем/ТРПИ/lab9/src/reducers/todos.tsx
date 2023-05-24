export interface Todo {
  id: number;
  text: string;
  completed: boolean;
}

export type Action =
  | { type: 'ADD_TODO'; id: number; text: string }
  | { type: 'TOGGLE_TODO'; id: number };

const todos = (state: Todo[] = [], action: Action): Todo[] => {
  switch (action.type) {
    case 'ADD_TODO':
      return [
        ...state,
        {
          id: action.id,
          text: action.text,
          completed: false,
        },
      ];
    case 'TOGGLE_TODO':
      return state.map((todo) =>
        todo.id === action.id ? { ...todo, completed: !todo.completed } : todo
      );
    default:
      return state;
  }
};

export default todos;
