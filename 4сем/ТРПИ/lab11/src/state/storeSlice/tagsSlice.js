import { createSlice } from "@reduxjs/toolkit";

const initialState = {
    mode: [],
  };
const TagsSlice = createSlice({
  name: "tags",
  initialState,
  reducers: {
    setTag: (state, action) => {
        if(state.mode.includes(action.payload)){
            state.mode = state.mode.filter((item) => item != action.payload)
        }
        else{
            state.mode.push(action.payload)
        }
    }
  },
});

export const { setTag } = TagsSlice.actions;

export default TagsSlice.reducer;


// В данном коде определен слайс (slice) для управления состоянием тегов в 
// Redux с использованием функции createSlice из библиотеки "@reduxjs/toolkit".

// Первоначальное состояние (initialState) содержит одно поле mode, которое 
// представляет собой массив тегов.

// Затем создается слайс (slice) с именем "tags" при помощи функции createSlice. 
// Внутри этого слайса определен редьюсер и экшены для изменения состояния тегов.

// Один редьюсер внутри reducers объекта называется setTag. Этот редьюсер обновляет 
// состояние путем добавления или удаления тега в зависимости от того, есть ли уже такой 
// тег в массиве mode. Если тег уже присутствует в массиве, то он удаляется при помощи метода 
// filter. Если тег отсутствует в массиве, то он добавляется при помощи метода push.

// В конце файла экспортируется экшен setTag и редьюсер, которые будут использоваться в 
// других частях приложения для обновления и чтения состояния тегов.