import {vacancyActionType, VacancyInfo} from "../types";
import {defaultState} from "./state";


const vacancies = (state: VacancyInfo[] = defaultState, action : vacancyActionType) => {
    switch (action.type) {
        case 'TOGGLE_VACANCY':
            return state.map(v => v.id === action.id ? {...v, isFavorite: !v.isFavorite} : v);
        case 'SELECT_VACANCY':
            return state.map(v => v.id === action.id ? {...v, isSelected: true} : {...v, isSelected: false});
        case 'CANCEL_SELECTION':
            return state.map(v => v.id === action.id ? {...v, isSelected: false} : v);
        default:
            return state;
    }
}
export default vacancies;