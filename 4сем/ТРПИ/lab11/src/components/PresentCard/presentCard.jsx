import React from "react";
import "./presentCard.css"
import { useDispatch, useSelector } from "react-redux";
import { setNull } from "../../state/storeSlice/selectedItem";
import imageClose from "../../ImageForComponents/close.svg"

const PresentCard = ({flagClose}) =>{
    const card = useSelector((state) => state.changeMode.mode);
    const dispatch = useDispatch();
    if(card){
        return(
            <div className="wrapperPresent">
                <div className="containerPresent">
                    <div className="selectItemHeader">
                        <div className="selectedImage">
                            <img src={card.imageSrc} alt="icon"/>
                        </div>
                        <div className="selectedHeaderInfo">
                            <p className="textMain">{card.jobName}</p>
                            <p className="textDop">{card.corpName} | {card.counName}</p>
                        </div>
                    </div>
                    <div className="middle">
                        <p className="cost">{card.cost}</p>
                            {card.text.map((item,index) =>{
                                return <p key={index} className="itemSelected">{item}</p>
                            })}
                    </div>
                    <button className="buttonStyle" onClick={()=> dispatch(setNull())} style={{display : flagClose ? "block" : "none"}} >
                        <img src={imageClose}/>
                    </button>
                </div>
            </div>
        )
    }
    else{
        return(
            <div className="secondContainer">
                <p>Вы ничего не выбрали</p>
            </div>
        )
    }
    
}
export default PresentCard