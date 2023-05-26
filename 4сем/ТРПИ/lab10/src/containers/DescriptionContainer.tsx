import {defaultFilters, FiltersType, func, stateType, VacancyInfo} from "../types";
import {connect} from "react-redux";
import {VacancyDescription} from "../components/VacancyDescription";
import {getVisibleVacancies} from "./VisibleVacanciesList";
import {cancelSelection, VisibilityFilters} from "../actions";


const getSelectedVacancy = (vacancies: VacancyInfo[], filter : string = VisibilityFilters.SHOW_ALL, values : FiltersType = defaultFilters) => {
    let result =  getVisibleVacancies(vacancies, filter, values).find(v => v.isSelected);
    return result === undefined ? null : result;
}

const mapStateToProps = (state : stateType) => ({
    vacancy: getSelectedVacancy(state.vacancies, state.visibilityFilter.filter, state.visibilityFilter.filterValues),
});
const mapDispatchToProps = (dispatch : func) => ( {
    cancelSelection: (id: number) => dispatch(cancelSelection(id)),
});

export default connect(mapStateToProps, mapDispatchToProps)(VacancyDescription);