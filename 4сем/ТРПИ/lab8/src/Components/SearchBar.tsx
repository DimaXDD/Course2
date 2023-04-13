import React, {ChangeEvent, useState} from 'react';
import {StateType} from "../types/types";

type SearchBarType = {
    state : StateType
}

const SearchBar = (props: SearchBarType) => {

    let {state} = props;

    return (
        <form>
            <input
                type="text"
                placeholder="Search..."
                value={state.filterText}
                onChange= {(e) =>{state.onFilterTextChange(e.target.value)}}
            />
            <p>
                <input
                    type="checkbox"
                    checked={state.inStockOnly}
                    onChange={(e) =>{state.onInStockChange(e.target.checked)}}
                />
                {' '}
                Only show products in stock

            </p>
        </form>
    );
};

export default SearchBar;

/*
class SearchBar extends React.Component {
  constructor(props) {
    super(props);
    this.handleFilterTextChange = this.handleFilterTextChange.bind(this);
    this.handleInStockChange = this.handleInStockChange.bind(this);
  }

  handleFilterTextChange(e) {
    this.props.onFilterTextChange(e.target.value);
  }

  handleInStockChange(e) {
    this.props.onInStockChange(e.target.checked);
  }

  render() {
    return (
      <form>
        <input
          type="text"
          placeholder="Search..."
          value={this.props.filterText}
          onChange={this.handleFilterTextChange}
        />
        <p>
          <input
            type="checkbox"
            checked={this.props.inStockOnly}
            onChange={this.handleInStockChange}
          />
          {' '}
          Only show products in stock
        </p>
      </form>
    );
  }
}
*/