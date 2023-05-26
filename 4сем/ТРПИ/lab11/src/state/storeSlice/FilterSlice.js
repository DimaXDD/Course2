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