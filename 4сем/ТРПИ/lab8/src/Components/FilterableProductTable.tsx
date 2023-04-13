import React, {FC, useState} from 'react';
import {FilterableProductTablePropsType, IProduct, ProductTableType, StateType} from "../types/types";
import SearchBar from "./SearchBar";
import ProductTable from "./ProductTable";


const FilterableProductTable  = (props: FilterableProductTablePropsType) => {
   const {products} = props;

    const [checked, setChecked] = useState(true);
    const [text, setText] = useState("");


    let state : StateType = {
       filterText: text,
       inStockOnly: checked,
       onFilterTextChange: (text:string) => setText(text),
       onInStockChange: (status : boolean) => setChecked(status)
   }

   return (
        <div>
            <SearchBar state={state}/>
            <ProductTable products={products} state={state}/>
        </div>
    );
};

export default FilterableProductTable;

/*
class FilterableProductTable extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      filterText: '',
      inStockOnly: false
    };

    this.handleFilterTextChange = this.handleFilterTextChange.bind(this);
    this.handleInStockChange = this.handleInStockChange.bind(this);
  }

  handleFilterTextChange(filterText) {
    this.setState({
      filterText: filterText
    });
  }

  handleInStockChange(inStockOnly) {
    this.setState({
      inStockOnly: inStockOnly
    })
  }

  render() {
    return (
      <div>
        <SearchBar
          filterText={this.state.filterText}
          inStockOnly={this.state.inStockOnly}
          onFilterTextChange={this.handleFilterTextChange}
          onInStockChange={this.handleInStockChange}
        />
        <ProductTable
          products={this.props.products}
          filterText={this.state.filterText}
          inStockOnly={this.state.inStockOnly}
        />
      </div>
    );
  }
}
 */