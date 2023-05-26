let nextTodoId : number = 0;

interface AddTodoAction {
  type: 'ADD_TODO';
  id: number;
  text: string;
}

interface SetVisibilityFilterAction {
  type: 'SET_VISIBILITY_FILTER';
  filter: string;
}

interface ToggleTodoAction {
  type: 'TOGGLE_TODO';
  id: number;
}

export const addTodo = (text: string): AddTodoAction => ({
  type: 'ADD_TODO',
  id: nextTodoId++,
  text,
});

export const setVisibilityFilter = (filter: string): SetVisibilityFilterAction => ({
  type: 'SET_VISIBILITY_FILTER',
  filter,
});

export const toggleTodo = (id: number): ToggleTodoAction => ({
  type: 'TOGGLE_TODO',
  id,
});

export const VisibilityFilters = {
  SHOW_ALL: 'SHOW_ALL',
  SHOW_COMPLETED: 'SHOW_COMPLETED',
  SHOW_ACTIVE: 'SHOW_ACTIVE',
  SHOW_NONE: 'SHOW_NONE',
} as const;