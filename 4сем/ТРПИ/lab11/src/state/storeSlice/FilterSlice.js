import { createSlice } from "@reduxjs/toolkit";

const initialState = {
  modeCountry: "",
  modeSchedule: "Not",
  modeEmployment: "Not",
  modeBetween: "Not",
  modeIncome: ""
};

const FilterSlice = createSlice({
  name: "SearchMode",
  initialState,
  reducers: {
    setCountry(state,action){
        state.modeCountry = action.payload
    },
    setSchedule(state,action){
        state.modeSchedule = action.payload
        console.log("1")
    },
    setEmployment(state,action){
        state.modeEmployment = action.payload
    },
    setBetween(state,action){
        state.modeBetween = action.payload
    },
    setIncome(state,action){
        state.modeIncome = action.payload
    }
  },
});

export const { setCountry,setBetween,setEmployment,setIncome,setSchedule } = FilterSlice.actions;
export default FilterSlice.reducer;


// Здесь определен слайс (slice) для управления состоянием фильтра в Redux с использованием функции 
// createSlice из библиотеки "@reduxjs/toolkit".

// Первоначальное состояние (initialState) содержит следующие поля:

// modeCountry: Строка, представляющая выбранную страну.
// modeSchedule: Строка, представляющая выбранный режим графика работы.
// modeEmployment: Строка, представляющая выбранный тип занятости.
// modeBetween: Строка, представляющая выбранный интервал.
// modeIncome: Строка, представляющая выбранный доход.
// Затем создается слайс (slice) с именем "SearchMode" при помощи функции createSlice. 
// Внутри этого слайса определены редьюсеры и экшены для изменения состояния фильтра.

// Каждый редьюсер внутри reducers объекта отвечает за обновление соответствующего поля в состоянии фильтра 
// при вызове соответствующего экшена. Например, setCountry редьюсер обновляет значение поля modeCountry в 
// состоянии на значение, переданное в action.payload.

// В конце файла экспортируются экшены (setCountry, setBetween, setEmployment, setIncome, setSchedule) и 
// редьюсеры, которые будут использоваться в других частях приложения для обновления и чтения состояния фильтра.