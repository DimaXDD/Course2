import React from 'react'
import logo from '../../ImageForComponents/FRONTEND JOB.svg'
import './header.css'
import { useSelector, useDispatch } from "react-redux";
import { toggleMode } from "../../state/storeSlice/storeSlice";
import { setObject } from "../../state/storeSlice/selectedItem";
import {Button,ToggleButtonGroup,ToggleButton} from "@mui/material"

const Header = () =>{
    const dispatch = useDispatch();
    const mode = useSelector((state) => state.searchMode.mode);

    const handleClick = (type) => {
        dispatch(setObject(""))
        dispatch(toggleMode(type));
    };

    let searchClass = ["itemHeader"]
    let favoriteClass = ["itemHeader"]
    if(mode === "Search")
        searchClass.push("active")
    else if(mode === "Favorite")
        favoriteClass.push("active")
    return(
    <div className='wrapper'>
        <div className='header'>
            <div className='containerHeader'>
                <div className='logoImage' >
                    <img src={logo} alt='logo' />
                </div>
                <ToggleButtonGroup
                    color="primary"
                    exclusive
                    value={mode}
                    onChange={(event,value) => handleClick(value)}
                    aria-label="Platform"
                    >
                    <ToggleButton value="Search">Поиск вакансий</ToggleButton>
                    <ToggleButton value="Favorite">Избранные вакансии</ToggleButton>
                </ToggleButtonGroup>
                
            </div>
        </div>
    </div>)
}


export default Header;