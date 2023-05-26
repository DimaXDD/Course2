import React from 'react';
import ReactDOM from 'react-dom/client';
// @ts-ignore
import './styles/index.module.css';
import App from './components/App';
import rootReducer from './reducers';
import {createStore} from "redux";
import {Provider} from "react-redux";


const store = createStore(rootReducer);

const root = ReactDOM.createRoot(
  document.getElementById('root') as HTMLElement
);
root.render(
  <React.StrictMode>
      <Provider store={store}>
        <App />
      </Provider>
  </React.StrictMode>
);

