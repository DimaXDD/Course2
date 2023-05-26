import React, {useEffect, useState} from 'react';
import VisibleVacanciesList from "../containers/VisibleVacanciesList";
import DescriptionContainer from "../containers/DescriptionContainer";
//@ts-ignore
import styles from "../styles/index.module.css";
import HeaderContainer from "../containers/HeaderContainer";
import FilterContainer from "../containers/FilterContainer";
function App() {
  return (
      <div>
        <HeaderContainer/>
        <div className={styles.header}></div>
        <FilterContainer/>
        <div className={styles.container}>
            <VisibleVacanciesList/>
            <DescriptionContainer/>
        </div>
      </div>
  );
}

export default App;
