import React from "react";
import Card from "../Card/card";
import "./cardList.css"
import { useSelector } from "react-redux";



const getFilterCard = (cards,filterState,tagsState) =>{
    let massCards = cards
    if(filterState.modeCountry){
        massCards = massCards.filter((item) => item.counName.toLowerCase().includes(filterState.modeCountry.toLowerCase()));
    }
    if(filterState.modeSchedule !== "Not"){
        massCards = massCards.filter((item) => item.shedule == filterState.modeSchedule)
    }
    if(filterState.modeEmployment !== "Not"){
        massCards = massCards.filter((item) => item.employment == filterState.modeEmployment)
    }
    if(filterState.modeBetween !== "Not"){
        massCards = massCards.filter((item) => item.between == filterState.modeBetween)
    }
    if(filterState.modeIncome){
        massCards = massCards.filter((item) => Number.parseInt(item.income) >= Number.parseInt(filterState.modeIncome))
    }
    if(!tagsState.length)
        return massCards
    return massCards.filter(
        (item) => item.tags.filter((tag) => tagsState.includes(tag)).length === tagsState.length
    )

}

const getCorrectCards = (cards,headerState,tagsState,filterState) =>{
        return getFilterCard(headerState === "Search" ? cards : cards.filter(item => item.isLiked === true),filterState, tagsState)
}

const CardList = () =>{
    const tagsState = useSelector((state) => state.tags.mode)
    const headerState = useSelector((state) => state.searchMode.mode);
    const massItems = useSelector((state) => state.setMassMode.mode);
    const filterState = useSelector((state) => state.filterMode)
    return(
    <div className="wrapperList">
        <div className="containerList">
            { getCorrectCards(massItems,headerState,tagsState,filterState).map((item,index)=>{
                return <Card  key={index} card={item}  />
            })}

            
        </div>
    </div>
    )
}
export default CardList