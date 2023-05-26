import React, { useState } from 'react'
import './card.css'
import like from '../../ImageForComponents/Vector.png'
import likeGray from '../../ImageForComponents/like2.png'
import { useDispatch, useSelector } from "react-redux";
import { setObject } from "../../state/storeSlice/selectedItem";
import { setLikeState } from "../../state/storeSlice/massFavoriteCards"
import {setTag} from "../../state/storeSlice/tagsSlice"
import {Chip, Fab} from "@mui/material"
import FavoriteIcon from '@mui/icons-material/Favorite';

const Card = ({card}) =>{

    const dispatch = useDispatch();
    const tagsMass = useSelector((state) => state.tags.mode)
    return(
            <div className='containerCard' onClick={(e =>{
                dispatch(setObject(card))
            })}>
                <div className='imageCard'>
                    <img src={card.imageSrc}  alt='cardImage'/>
                </div>
                <div className='infoBlock'>
                    <p className='corporationName'>{card.corpName}</p>
                    <p className='jobName'>{card.jobName}</p>
                    <p className='countryName'>{card.counName}</p>
                    <div className='tagsMass'>
                        {card.tags.map((item,index) =>{
                            let variant = tagsMass.includes(item) ? "" : "outlined";
                            return  <Chip label={item} variant={variant} onClick={(event)=>{dispatch(setTag(item)); event.stopPropagation()}} />          
                        })}
                    </div>
                </div>
                <div className='dopFunc'>
                    <FavoriteIcon onClick={((event)=>{dispatch(setLikeState({id:card.id}));  event.stopPropagation()})} color={card.isLiked ? "" : "disabled"}/>
                    <div className='date'>{card.date}</div>
                </div>
            </div>
    )
}

export default Card