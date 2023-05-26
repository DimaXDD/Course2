import Header from "./components/Header/header";
import { useEffect, useState } from "react";
import CardList from "./components/CardList/cardList";
import Cards from "./massCards";
import PresentCard from "./components/PresentCard/presentCard";
import SearchBar from "./components/SearchBar/searchBar";
import React from 'react';
import "./App.css"
import { useSelector, useDispatch } from "react-redux";
import HeaderMob from "./components/Header/headerMob";

function App() {  
  let checkItem = useSelector((state) =>state.changeMode.mode)
  const [width,setWidth] = useState(window.innerWidth)

  useEffect(()=>{
    window.addEventListener("resize",() => setWidth(window.innerWidth))
  },[])
  if(width < 960){
    return (
      <div>
        {width < 600 ? <HeaderMob/> : <Header/>}
       <SearchBar />
       <div className="middleMainBlock">
        { checkItem ? <PresentCard flagClose = {true}/> : <CardList /> }
       </div>
      </div>
    );
  }
  return (
    <div >
     <Header/>
     <SearchBar />
     <div className="middleMainBlock">
        <CardList />
        <PresentCard flagClose = {false} />
     </div>
    </div>
  );
}

export default App;
