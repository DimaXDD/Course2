import { connect } from 'react-redux';
import { Dispatch } from 'redux';
import { setVisibilityFilter } from '../actions';
import Link from '../components/Link';
import { RootState } from '../reducers/index';

interface OwnProps {
  filter: string;
}

interface StateProps {
  active: boolean;
}

interface DispatchProps {
  onClick: () => void;
}

const mapStateToProps = (state: RootState, ownProps: OwnProps): StateProps => ({
  active: ownProps.filter == state.visibilityFilter
});

const mapDispatchToProps = (dispatch: Dispatch, ownProps: OwnProps): DispatchProps => ({
  onClick: () => dispatch(setVisibilityFilter(ownProps.filter))
});

export default connect<StateProps, DispatchProps, OwnProps>(
  mapStateToProps,
  mapDispatchToProps
)(Link);