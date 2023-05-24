import React, { useRef } from 'react';
import { connect, ConnectedProps } from 'react-redux';
import { RootState } from '../reducers';
import { addTodo } from '../actions';

interface OwnProps {}

interface DispatchProps {
  addTodo: (text: string) => void;
}

type Props = OwnProps & ConnectedProps<typeof connector> & DispatchProps;

const AddTodo = ({ addTodo }: Props) => {
  const inputRef = useRef<HTMLInputElement>(null);

  const handleSubmit = (e: React.FormEvent<HTMLFormElement>) => {
    e.preventDefault();
    if (inputRef.current && inputRef.current.value.trim()) {
      addTodo(inputRef.current.value);
      inputRef.current.value = '';
    }
  };

  return (
    <div>
      <form onSubmit={handleSubmit}>
        <input ref={inputRef} />
        <button type="submit">Add Todo</button>
      </form>
    </div>
  );
};

const mapStateToProps = (state: RootState) => ({});

const mapDispatchToProps = { addTodo };

const connector = connect(mapStateToProps, mapDispatchToProps);

export default connector(AddTodo);