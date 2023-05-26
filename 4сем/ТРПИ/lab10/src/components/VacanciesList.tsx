import {VacanciesListPropsType} from "../types";
import Vacancy from "./Vacancy";
//@ts-ignore
import styles from "../styles/VacanciesList.module.css"

const VacanciesList = ({ vacancies, toggleVacancy, selectVacancy } : VacanciesListPropsType) => {
    if(vacancies.length !== 0)
    {
        return (
            <ul className={styles.list}>
                {
                    vacancies.map((v) =>
                        <Vacancy key={v.id} OnClickSelect={() => selectVacancy(v.id)}
                                 OnClickFav={() => toggleVacancy(v.id)} info={v}/>)
                }
            </ul>
        );
    }
    else {
        return (
            <p className={styles.nothingFound}>Ничего не найдено</p>
        );
    }
}
export default VacanciesList;