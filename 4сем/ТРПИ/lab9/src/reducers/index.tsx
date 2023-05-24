import { combineReducers } from 'redux';
import todos, { Todo } from './todos';
import visibilityFilter from './visibilityFilter';

export interface RootState {
  todos: Todo[];
  visibilityFilter: string;
}

const rootReducer = combineReducers({
  todos,
  visibilityFilter,
});

export default rootReducer;