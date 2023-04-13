import React, {useEffect, useState} from 'react';
import s from "./App.module.css"
import ProductTable from "./Components/ProductTable";
import {PRODUCTS} from "./state";
import FilterableProductTable from "./Components/FilterableProductTable";

function App() {

  return (
      <div className={s.body}>
          <FilterableProductTable products={PRODUCTS}/>
      </div>
  );
}

export default App;
