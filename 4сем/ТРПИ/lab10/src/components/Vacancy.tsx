import {VacancyPropsType} from "../types";
// @ts-ignore
import styles from '../styles/Vacancy.module.css';

const Vacancy = ({OnClickSelect, OnClickFav, info} : VacancyPropsType) => {
    return (
        <section className={styles.sectionStyle} style={{background: info.isSelected ? '#0070FB' : 'white'}}
                 onClick={OnClickSelect}>
            <div className={styles.container}>
                <div className={styles.headContainer}>
                    <img className={styles.logo} srcSet={info.logo} alt="logo"/>
                    <div className={styles.mainContainer}>
                        <p className={styles.companyName}>{info.companyName}</p>
                        <p className={styles.jobHeader}>{info.jobName}</p>
                        <p className={styles.location}>{info.city}</p>
                        <div className={styles.tagsContainer}>
                        {
                            info.tags.map(tag => (
                                <div className={styles.tag}><span style={{margin: 0}}>{tag}</span></div>
                            ))
                        }
                        </div>
                    </div>
                </div>
                <div className={styles.sideContainer}>
                    <svg width="20" height="19" viewBox="0 0 20 19" fill="none" xmlns="http://www.w3.org/2000/svg"
                         onClick={(event) => {
                             event.stopPropagation();
                             OnClickFav();
                         }}>
                        <path fill-rule="evenodd" clip-rule="evenodd" d="M10 1.66446C15.5477 -4.11405 29.418 5.99771 10
                        19C-9.41803 5.99898 4.45235 -4.11405 10 1.66446Z" style={
                            {fill: info.isFavorite ? "#DD5E5E" : "#E1E1E1"}}/>
                    </svg>
                        <p className={styles.date}>{info.dateAdded}</p>
                </div>
            </div>
        </section>
    );
}
export default Vacancy;