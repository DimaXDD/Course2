import {defaultFilters, filtersStateType, visibilityFilterActionType} from "../types";
import {VisibilityFilters} from "../actions";

const defaultState : filtersStateType = {
    filter: VisibilityFilters.SHOW_ALL,
    filterValues: defaultFilters
}

const visibilityFilter = (state : filtersStateType = defaultState, action : visibilityFilterActionType) => {
    switch (action.type) {
        case 'SET_VISIBILITY_FILTER':
            return {filter: action.filter, filterValues: action.filterValues};
        default:
            return state;
    }
}
export default visibilityFilter;