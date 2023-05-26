import { createSlice } from "@reduxjs/toolkit";
import Cards from "../../massCards";

const initialState = {
  mode: Cards,
};

const cardModeSlice = createSlice({
  name: "cardMode",
  initialState,
  reducers: {
    setLikeState(state,action){
        state.mode[action.payload.id].isLiked = !state.mode[action.payload.id].isLiked 
    }
  },
});

export const { setLikeState } = cardModeSlice.actions;
export default cardModeSlice.reducer;