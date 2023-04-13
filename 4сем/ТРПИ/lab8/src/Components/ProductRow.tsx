import React from 'react';
import {IProduct} from "../types/types";

type ProductRowType = {
    product : IProduct
}

const ProductRow = (props : ProductRowType) => {
    const {product} = props;
    const name = product.stocked ?
        product.name : <span style={{color: 'red'}}> {product.name} </span>

    return (
        <tr>
            <td>{name}</td>
            <td>{product.price}</td>
        </tr>
    );
};

export default ProductRow;
/*
class ProductRow extends React.Component {
  render() {
    const product = this.props.product;
    const name = product.stocked ?
      product.name :
      <span style={{color: 'red'}}>
        {product.name}
      </span>;

    return (
      <tr>
        <td>{name}</td>
        <td>{product.price}</td>
      </tr>
    );
  }
}
*/