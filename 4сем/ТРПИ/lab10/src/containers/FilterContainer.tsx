import {FiltersType, func, stateType} from "../types";
import {setVisibilityFilter, VisibilityFilters} from "../actions";
import {connect} from "react-redux";
import {Filter} from "../components/Filter";

const mapStateToProps = (state: stateType) => ({
    currentFilter: state.visibilityFilter.filter,
})

const mapDispatchToProps = (dispatch : func) => ({
    doFilter: (filters : FiltersType) => dispatch(setVisibilityFilter(VisibilityFilters.SHOW_FILTERS, filters))
})

export default connect(mapStateToProps, mapDispatchToProps)(Filter)