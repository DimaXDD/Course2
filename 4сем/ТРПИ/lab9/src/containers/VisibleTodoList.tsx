import { connect } from 'react-redux';
import { toggleTodo } from '../actions';
import TodoList from '../components/TodoList';
import { VisibilityFilters } from '../actions';
import { RootState } from '../reducers';
import { Todo } from '../reducers/todos';

interface StateProps {
  todos: Todo[];
}

interface DispatchProps {
  toggleTodo: (id: number) => void;
}

interface OwnProps {}

const getVisibleTodos = (todos: Todo[], filter: string): Todo[] => {
  switch (filter) {
    case VisibilityFilters.SHOW_ALL:
      return todos;
    case VisibilityFilters.SHOW_COMPLETED:
      return todos.filter((t) => t.completed);
    case VisibilityFilters.SHOW_ACTIVE:
      return todos.filter((t) => !t.completed);
    case VisibilityFilters.SHOW_NONE:
      return [];
    default:
      throw new Error('Unknown filter: ' + filter);
  }
};

const mapStateToProps = (state: RootState, ownProps: OwnProps): StateProps => ({
  todos: getVisibleTodos(state.todos, state.visibilityFilter),
});

const mapDispatchToProps: DispatchProps = {
  toggleTodo,
};

export default connect<StateProps, DispatchProps, OwnProps, RootState>(
  mapStateToProps,
  mapDispatchToProps
)(TodoList);