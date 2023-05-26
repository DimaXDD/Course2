import {func, stateType} from "../types";
import {connect} from "react-redux";
import {Header} from "../components/Header";
import {setVisibilityFilter} from "../actions";
import {VisibilityFilters} from "../actions";

const mapStateToProps = (state : stateType) => ({
    currentFilter: state.visibilityFilter.filter,
})
const mapDispatchToProps = (dispatch : func) => ({
    showAll: () => dispatch(setVisibilityFilter(VisibilityFilters.SHOW_ALL)),
    showFavorites: () => dispatch(setVisibilityFilter(VisibilityFilters.SHOW_FAVORITES)),
})

export default connect(mapStateToProps, mapDispatchToProps)(Header);