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