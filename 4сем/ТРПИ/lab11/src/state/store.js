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


// Данный код является конфигурацией хранилища Redux с использованием библиотеки "@reduxjs/toolkit". 
// Внутри configureStore функции происходит создание Redux-хранилища с заданными редьюсерами.

// Здесь определено пять редьюсеров:

// searchModeReducer - это редьюсер для управления режимом поиска.
// objectReducer - это редьюсер для управления выбранным элементом.
// massCard - это редьюсер для управления массивом избранных карточек.
// tagsSlice - это редьюсер для управления тегами.
// serchSclice - это редьюсер для управления режимом фильтрации.
// В объекте reducer передаются эти редьюсеры, где каждый редьюсер имеет свое уникальное имя, 
// которое будет использоваться для доступа к его состоянию в Redux-хранилище.
