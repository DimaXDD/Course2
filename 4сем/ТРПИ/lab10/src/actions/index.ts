import {
    defaultFilters,
    FiltersType,
    vacancyActionType,
    visibilityFilterActionType,
} from "../types";

export const setVisibilityFilter = (filter : string, filterValues : FiltersType = defaultFilters) : visibilityFilterActionType => ({
    type: 'SET_VISIBILITY_FILTER',
    filter,
    filterValues,
});

export const toggleVacancy = (id : number) : vacancyActionType => ({
    type: 'TOGGLE_VACANCY',
    id,
});
export const selectVacancy = (id : number) : vacancyActionType => ({
    type: 'SELECT_VACANCY',
    id,
});
export const cancelSelection = (id : number) : vacancyActionType => ({
    type: 'CANCEL_SELECTION',
    id,
});
export const VisibilityFilters = {
    SHOW_ALL: 'SHOW_ALL',
    SHOW_FAVORITES: 'SHOW_FAVORITES',
    SHOW_FILTERS: 'SHOW_FILTERS',
};