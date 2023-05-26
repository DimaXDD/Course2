import { createSlice } from "@reduxjs/toolkit";

const initialState = {
  mode: "Search",
};

const searchModeSlice = createSlice({
  name: "searchMode",
  initialState,
  reducers: {
    toggleMode: (state,actions) => {
        if(actions.payload === "Search" || actions.payload === "Favorite")
      state.mode = actions.payload
    },
  },
});

export const { toggleMode } = searchModeSlice.actions;
export default searchModeSlice.reducer;