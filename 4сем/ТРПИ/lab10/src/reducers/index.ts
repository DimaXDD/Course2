import {combineReducers} from "redux";
import visibilityFilter from "./visibilityFilter";
import vacancies from "./vacancies";

export default combineReducers({
    vacancies,
    visibilityFilter,
});