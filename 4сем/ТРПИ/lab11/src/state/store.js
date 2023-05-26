import { configureStore } from "@reduxjs/toolkit";
import searchModeReducer from "./storeSlice/storeSlice";
import objectReducer from "./storeSlice/selectedItem";
import massCard from "./storeSlice/massFavoriteCards" 
import tagsSlice from "./storeSlice/tagsSlice"
import serchSclice from "./storeSlice/FilterSlice"


const store = configureStore({
  reducer: {
    searchMode: searchModeReducer,
    changeMode: objectReducer,
    setMassMode: massCard,
    tags: tagsSlice,
    filterMode:serchSclice
  },
});

export default store;

