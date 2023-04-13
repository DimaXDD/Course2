import React, {FC} from 'react';
import {IProduct} from "../types/types";

type ProductCategoryRowType = {
    category : string;
}

const ProductCategoryRow = (props : ProductCategoryRowType) => {
    const {category} = props;
    return (
        <tr>
            <th>
                {category}
            </th>
        </tr>
    );
};

export default ProductCategoryRow;
/*

class ProductCategoryRow extends React.Component {
  render() {
    const category = this.props.category;
    return (
      <tr>
        <th colSpan="2">
          {category}
        </th>
      </tr>
    );
  }
}

 */