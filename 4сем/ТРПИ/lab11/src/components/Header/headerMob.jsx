import React,{useState} from "react";
import logo from '../../ImageForComponents/FRONTEND JOB.svg'
import menu from "../../ImageForComponents/Group.svg"
import "./headerMob.css"
import { useSelector, useDispatch } from "react-redux";
import { toggleMode } from "../../state/storeSlice/storeSlice";
import { setObject } from "../../state/storeSlice/selectedItem";



const HeaderMob = () =>{
    const dispatch = useDispatch();
    const mode = useSelector((state) => state.searchMode.mode);
    const [active,setActive] = useState(false)
    const handleClick = (e,type) => {
        dispatch(setObject(""))
        dispatch(toggleMode(type));
        setActive(false)
    };

    let searchClass = ["itemHeader"]
    let favoriteClass = ["itemHeader"]
    if(mode === "Search")
        searchClass.push("active")
    else if(mode === "Favorite")
        favoriteClass.push("active")
    
    return(
        <div className="wrapperHeaderMob">
            <div className="containerMob">
            <div className='logoImage' >
                    <img src={logo} alt='logo' />
                </div>
                <button className="buttonMenu" onClick={() => setActive(!active)}><img src={menu}/></button>
                <div className="List" style={{display : active ? "block" : "none"}}>
                    <div className={searchClass.join(" ")} onClick={e =>  handleClick(e,dispatch(toggleMode("Search")))}>Поиск вакансий</div>
                    <div className={favoriteClass.join(" ")} onClick={e => handleClick(e,dispatch(toggleMode("Favorite")))}>Избранные вакансии</div>
                </div>
            </div>
           
        </div>
    )
}

export default HeaderMob