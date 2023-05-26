import {defaultFilters, EmploymentType, FilterPropsType, FiltersType, Schedule, WorkingExperience} from "../types";
import {VisibilityFilters} from "../actions";
import {useEffect, useState} from "react";
//@ts-ignore
import styles from "../styles/Filter.module.css";

export const Filter = ({currentFilter, doFilter} : FilterPropsType) => {
    const [location, setLocation] = useState(defaultFilters.locationFilter);
    const [schedule, setSchedule] = useState(defaultFilters.scheduleFilter);
    const [employment, setEmployment] = useState(defaultFilters.employmentTypeFilter);
    const [experience, setExperience] = useState(defaultFilters.workingExperienceFilter);
    const [salary, setSalary] = useState(defaultFilters.salaryFilter);
    const [showExperienceFilter, setExpFilter]  = useState(false);
    const [showScheduleFilter, setScheduleFilter]  = useState(false);
    const [showEmploymentFilter, setEmploymentFilter]  = useState(false);
    const [showAllFilters, setAllFilters] = useState(false);

    if (currentFilter !== VisibilityFilters.SHOW_FAVORITES) {
        return (
            <nav>
                <div className={styles.containerDesktop}>
                    <div className={styles.filterContainers}>
                        <svg className={styles.locationIcon} width="20" height="20" viewBox="0 0 20 20" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <path d="M0.000110945 7.48668C-0.00264513 7.65559 0.046006 7.82135 0.139614 7.96199C0.233221 8.10262 0.367364 8.21148 0.524255 8.27413L8.52475 11.4747L11.7254 19.4759C11.7873 19.6306 11.8941 19.7633 12.0321 19.8567C12.1701 19.9502 12.3329 20.0001 12.4996 20H12.5129C12.6817 19.9973 12.8457 19.9435 12.9832 19.8456C13.1207 19.7477 13.2252 19.6103 13.2829 19.4517L19.9493 1.11961C20.0038 0.970477 20.0146 0.808854 19.9804 0.653777C19.9462 0.4987 19.8684 0.356627 19.7562 0.244291C19.6439 0.131955 19.5019 0.0540335 19.3468 0.0197035C19.1918 -0.0146265 19.0302 -0.00393511 18.881 0.0505182L0.548421 6.71673C0.389733 6.77459 0.252348 6.87926 0.15444 7.01689C0.0565329 7.15452 0.00271682 7.31863 0.000110945 7.48751V7.48668Z" fill="#0070FB"/>
                        </svg>
                        <input className={styles.locationInput} type={"text"} value={location}
                               onChange={(e) => setLocation(e.target.value)}/>
                    </div>
                    <div className={styles.filterContainers}>
                        <svg className={styles.titleIcon} width="20" height="20" viewBox="0 0 20 20" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <path d="M9.99 0C4.47 0 0 4.48 0 10C0 15.52 4.47 20 9.99 20C15.52 20 20 15.52 20 10C20 4.48 15.52 0 9.99 0ZM14 14C13.9075 14.0927 13.7976 14.1663 13.6766 14.2164C13.5557 14.2666 13.426 14.2924 13.295 14.2924C13.164 14.2924 13.0343 14.2666 12.9134 14.2164C12.7924 14.1663 12.6825 14.0927 12.59 14L9.3 10.71C9.20551 10.6174 9.13034 10.5069 9.07885 10.3851C9.02735 10.2632 9.00055 10.1323 9 10V6C9 5.45 9.45 5 10 5C10.55 5 11 5.45 11 6V9.59L14 12.59C14.39 12.98 14.39 13.61 14 14Z" fill="#0070FB"/>
                        </svg>
                        <p className={styles.filterCurrentOption} onClick={() => setScheduleFilter(!showScheduleFilter)}>{schedule}</p>
                        <ul className={styles.listOptions} style={{visibility: showScheduleFilter ? 'visible': 'hidden'}}>
                            <li>
                                <input checked={schedule === Schedule.FullTime} type={"radio"} id="schedule1"
                                       value={Schedule.FullTime}
                                       onChange={(e) => {
                                           setSchedule(e.target.value);
                                           setScheduleFilter(false);
                                       }
                                }/>
                                <label htmlFor="schedule1">{Schedule.FullTime}</label>
                            </li>
                            <li>
                                <input checked={schedule === Schedule.FlexibleHours} type={"radio"} id="schedule2"
                                       value={Schedule.FlexibleHours}
                                       onChange={(e) => {
                                           setSchedule(e.target.value);
                                           setScheduleFilter(false);
                                       }
                                }/>
                                <label htmlFor="schedule2">{Schedule.FlexibleHours}</label>
                            </li>
                            <li>
                                <input checked={schedule === Schedule.DistantWork}  type={"radio"} id="schedule3"
                                       value={Schedule.DistantWork}
                                       onChange={(e) => {
                                           setSchedule(e.target.value);
                                           setScheduleFilter(false);
                                       }
                                }/>
                                <label htmlFor="schedule3">{Schedule.DistantWork}</label>
                            </li>
                        </ul>
                    </div>
                    <div className={styles.filterContainers}>
                        <svg className={styles.titleIcon} width="20" height="19" viewBox="0 0 20 19" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <path d="M18 4H14V2C14 0.89 13.11 0 12 0H8C6.89 0 6 0.89 6 2V4H2C0.89 4 0.00999999 4.89 0.00999999 6L0 17C0 18.11 0.89 19 2 19H18C19.11 19 20 18.11 20 17V6C20 4.89 19.11 4 18 4ZM12 4H8V2H12V4Z" fill="#0070FB"/>
                        </svg>
                        <p className={styles.filterCurrentOption}
                           onClick={() => setEmploymentFilter(!showEmploymentFilter)}>{employment}</p>
                        <ul className={styles.listOptions} style={{visibility: showEmploymentFilter ? 'visible': 'hidden'}}>
                            <li>
                                <input checked={employment === EmploymentType.FullEmployment} type={"radio"}
                                       id="employment1" value={EmploymentType.FullEmployment}
                                       onChange={(e) => {
                                           setEmployment(e.target.value);
                                           setEmploymentFilter(false);
                                       }
                                }/>
                                <label htmlFor="employment1">{EmploymentType.FullEmployment}</label>
                            </li>
                            <li>
                                <input checked={employment === EmploymentType.PartTimeEmployment} type={"radio"}
                                       id="employment2" value={EmploymentType.PartTimeEmployment}
                                       onChange={(e) => {
                                           setEmployment(e.target.value);
                                           setEmploymentFilter(false);
                                       }
                                }/>
                                <label htmlFor="employment2">{EmploymentType.PartTimeEmployment}</label>
                            </li>
                            <li>
                                <input checked={employment === EmploymentType.ProjectWork} type={"radio"} id="employment3"
                                       value={EmploymentType.ProjectWork}
                                       onChange={(e) => {
                                           setEmployment(e.target.value);
                                           setEmploymentFilter(false);
                                       }
                                }/>
                                <label htmlFor="employment3">{EmploymentType.ProjectWork}</label>
                            </li>
                            <li>
                                <input checked={employment === EmploymentType.Internship} type={"radio"}
                                       id="employment4" value={EmploymentType.Internship}
                                       onChange={(e) => {
                                           setEmployment(e.target.value);
                                           setEmploymentFilter(false);
                                       }
                                }/>
                                <label htmlFor="employment4">{EmploymentType.Internship}</label>
                            </li>
                        </ul>
                    </div>
                    <div className={styles.filterContainers}>
                        <svg className={styles.titleIcon} width="20" height="21" viewBox="0 0 20 21" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <path d="M19.947 7.18097C19.8842 6.99583 19.7685 6.83316 19.6142 6.71303C19.46 6.5929 19.2739 6.52057 19.079 6.50497L13.378 6.05197L10.911 0.590968C10.8325 0.41508 10.7047 0.265689 10.5431 0.160825C10.3815 0.0559612 10.193 0.000105879 10.0004 1.50379e-07C9.80771 -0.000105578 9.61916 0.0555428 9.45745 0.160229C9.29574 0.264916 9.16779 0.414166 9.08903 0.589968L6.62203 6.05197L0.921026 6.50497C0.729482 6.52014 0.546364 6.59018 0.393581 6.7067C0.240798 6.82322 0.124819 6.98129 0.0595194 7.162C-0.00578038 7.34271 -0.0176359 7.5384 0.0253712 7.72567C0.0683784 7.91294 0.164427 8.08385 0.302026 8.21797L4.51503 12.325L3.02503 18.777C2.97978 18.9723 2.99428 19.1767 3.06665 19.3636C3.13901 19.5506 3.26589 19.7115 3.43083 19.8254C3.59577 19.9394 3.79115 20.0011 3.99161 20.0026C4.19208 20.0042 4.38837 19.9454 4.55503 19.834L10 16.204L15.445 19.834C15.6154 19.9471 15.8162 20.0053 16.0207 20.0008C16.2251 19.9963 16.4232 19.9293 16.5884 19.8089C16.7536 19.6884 16.878 19.5203 16.9448 19.327C17.0116 19.1338 17.0176 18.9247 16.962 18.728L15.133 12.328L19.669 8.24597C19.966 7.97797 20.075 7.55997 19.947 7.18097Z" fill="#0070FB"/>
                        </svg>
                        <p className={styles.filterCurrentOption} onClick={() => setExpFilter(!showExperienceFilter)}>{experience}</p>
                        <ul className={styles.listOptions} style={{visibility: showExperienceFilter ? 'visible': 'hidden'}}>
                            <li>
                                <input checked={experience === WorkingExperience.NoExperience} type={"radio"} id="experience1" value={WorkingExperience.NoExperience}
                                       onChange={(e) => {
                                           setExperience(e.target.value)
                                           setExpFilter(false);
                                       }
                                }/>
                                <label htmlFor="experience1">{WorkingExperience.NoExperience}</label>
                            </li>
                            <li>
                                <input checked={experience === WorkingExperience.From1To3} type={"radio"} id="experience2" value={WorkingExperience.From1To3}
                                       onChange={(e) => {
                                           setExperience(e.target.value)
                                           setExpFilter(false);
                                       }
                                }/>
                                <label htmlFor="experience2">{WorkingExperience.From1To3}</label>
                            </li>
                            <li>
                                <input checked={experience === WorkingExperience.From3To6}  type={"radio"} id="experience3" value={WorkingExperience.From3To6}
                                       onChange={(e) => {
                                           setExperience(e.target.value)
                                           setExpFilter(false);
                                       }
                                }/>
                                <label htmlFor="experience3">{WorkingExperience.From3To6}</label>
                            </li>
                            <li>
                                <input checked={experience === WorkingExperience.MoreThan6} type={"radio"} id="experience4" value={WorkingExperience.MoreThan6}
                                       onChange={(e) => {
                                           setExperience(e.target.value)
                                           setExpFilter(false);
                                       }
                                }/>
                                <label htmlFor="experience4">{WorkingExperience.MoreThan6}</label>
                            </li>
                        </ul>
                    </div>
                    <div className={styles.filterContainers}>
                        <svg className={styles.salaryIcon} width="20" height="20" viewBox="0 0 20 20" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <path d="M19.0439 0H11.3947C10.8695 0 10.1339 0.304691 9.76289 0.675675L0.279212 10.1593C0.100391 10.339 0 10.5822 0 10.8357C0 11.0891 0.100391 11.3323 0.279212 11.512L8.48803 19.7208C8.66769 19.8996 8.91085 20 9.16434 20C9.41782 20 9.66099 19.8996 9.84065 19.7208L19.3243 10.2371C19.6966 9.86485 20 9.13054 20 8.6053V0.956144C19.999 0.702869 19.8979 0.460255 19.7188 0.281161C19.5397 0.102067 19.2971 0.00100707 19.0439 0V0ZM14.2631 7.64915C14.0119 7.64907 13.7632 7.59951 13.5311 7.50329C13.2991 7.40708 13.0883 7.26611 12.9107 7.08842C12.7331 6.91073 12.5923 6.6998 12.4962 6.46768C12.4002 6.23556 12.3508 5.9868 12.3508 5.73559C12.3509 5.48438 12.4005 5.23565 12.4967 5.00359C12.5929 4.77154 12.7339 4.56071 12.9116 4.38313C13.0893 4.20556 13.3002 4.06473 13.5323 3.96867C13.7644 3.87261 14.0132 3.82322 14.2644 3.8233C14.7718 3.82347 15.2582 4.02517 15.6169 4.38403C15.9755 4.7429 16.1769 5.22952 16.1767 5.73686C16.1765 6.2442 15.9748 6.7307 15.616 7.08932C15.2571 7.44794 14.7705 7.64932 14.2631 7.64915Z" fill="#0070FB"/>
                        </svg>

                        <input className={styles.salaryInput} type={"number"} value={salary} onChange={(e) => setSalary(Number(e.target.value))}/>
                    </div>
                    <input className={styles.searchButton} type={"button"} value="Поиск" onClick={() => {
                        const filters : FiltersType = {
                            locationFilter: location,
                            scheduleFilter: schedule,
                            employmentTypeFilter: employment,
                            workingExperienceFilter: experience,
                            salaryFilter: salary
                        };
                        setScheduleFilter(false);
                        setEmploymentFilter(false);
                        setExpFilter(false);
                        doFilter(filters)
                    }
                    }/>
                </div>

                <div className={styles.containerTablet}>
                    <div className={styles.filterContainers}>
                        <svg className={styles.locationIcon} width="20" height="20" viewBox="0 0 20 20" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <path d="M0.000110945 7.48668C-0.00264513 7.65559 0.046006 7.82135 0.139614 7.96199C0.233221 8.10262 0.367364 8.21148 0.524255 8.27413L8.52475 11.4747L11.7254 19.4759C11.7873 19.6306 11.8941 19.7633 12.0321 19.8567C12.1701 19.9502 12.3329 20.0001 12.4996 20H12.5129C12.6817 19.9973 12.8457 19.9435 12.9832 19.8456C13.1207 19.7477 13.2252 19.6103 13.2829 19.4517L19.9493 1.11961C20.0038 0.970477 20.0146 0.808854 19.9804 0.653777C19.9462 0.4987 19.8684 0.356627 19.7562 0.244291C19.6439 0.131955 19.5019 0.0540335 19.3468 0.0197035C19.1918 -0.0146265 19.0302 -0.00393511 18.881 0.0505182L0.548421 6.71673C0.389733 6.77459 0.252348 6.87926 0.15444 7.01689C0.0565329 7.15452 0.00271682 7.31863 0.000110945 7.48751V7.48668Z" fill="#0070FB"/>
                        </svg>
                        <input className={styles.locationInput} type={"text"} value={location}
                           onChange={(e) => setLocation(e.target.value)}/>
                    </div>
                    <div className={styles.filterContainers}>
                        <svg className={styles.salaryIcon} width="20" height="20" viewBox="0 0 20 20" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <path d="M19.0439 0H11.3947C10.8695 0 10.1339 0.304691 9.76289 0.675675L0.279212 10.1593C0.100391 10.339 0 10.5822 0 10.8357C0 11.0891 0.100391 11.3323 0.279212 11.512L8.48803 19.7208C8.66769 19.8996 8.91085 20 9.16434 20C9.41782 20 9.66099 19.8996 9.84065 19.7208L19.3243 10.2371C19.6966 9.86485 20 9.13054 20 8.6053V0.956144C19.999 0.702869 19.8979 0.460255 19.7188 0.281161C19.5397 0.102067 19.2971 0.00100707 19.0439 0V0ZM14.2631 7.64915C14.0119 7.64907 13.7632 7.59951 13.5311 7.50329C13.2991 7.40708 13.0883 7.26611 12.9107 7.08842C12.7331 6.91073 12.5923 6.6998 12.4962 6.46768C12.4002 6.23556 12.3508 5.9868 12.3508 5.73559C12.3509 5.48438 12.4005 5.23565 12.4967 5.00359C12.5929 4.77154 12.7339 4.56071 12.9116 4.38313C13.0893 4.20556 13.3002 4.06473 13.5323 3.96867C13.7644 3.87261 14.0132 3.82322 14.2644 3.8233C14.7718 3.82347 15.2582 4.02517 15.6169 4.38403C15.9755 4.7429 16.1769 5.22952 16.1767 5.73686C16.1765 6.2442 15.9748 6.7307 15.616 7.08932C15.2571 7.44794 14.7705 7.64932 14.2631 7.64915Z" fill="#0070FB"/>
                        </svg>

                        <input className={styles.salaryInput} type={"number"} value={salary} onChange={(e) => setSalary(Number(e.target.value))}/>
                    </div>
                    <p className={styles.Title} onClick={() => setAllFilters(!showAllFilters)}>Фильтры</p>
                    <input className={styles.searchButton} type={"button"} value="Поиск" onClick={() => {
                        const filters : FiltersType = {
                            locationFilter: location,
                            scheduleFilter: schedule,
                            employmentTypeFilter: employment,
                            workingExperienceFilter: experience,
                            salaryFilter: salary
                        };
                        setAllFilters(false);
                        doFilter(filters)
                    }
                    }/>
                    <div className={styles.allFilters} style={{display: showAllFilters ? "block" : "none"}}>
                        <div className={styles.allFiltersContainer}>
                            <div>
                                <p className={styles.Title}>График работы</p>
                                <ul className={styles.listOptions}>
                                    <li>
                                        <input checked={schedule === Schedule.FullTime} type={"radio"} id="schedule1"
                                               value={Schedule.FullTime}
                                               onChange={(e) => setSchedule(e.target.value)}/>
                                        <label htmlFor="schedule1">{Schedule.FullTime}</label>
                                    </li>
                                    <li>
                                        <input checked={schedule === Schedule.FlexibleHours} type={"radio"} id="schedule2"
                                               value={Schedule.FlexibleHours}
                                               onChange={(e) => setScheduleFilter(false)}/>
                                        <label htmlFor="schedule2">{Schedule.FlexibleHours}</label>
                                    </li>
                                    <li>
                                        <input checked={schedule === Schedule.DistantWork}  type={"radio"} id="schedule3"
                                               value={Schedule.DistantWork}
                                               onChange={(e) => setSchedule(e.target.value)}/>
                                        <label htmlFor="schedule3">{Schedule.DistantWork}</label>
                                    </li>
                                </ul>
                            </div>
                            <div>
                                <p className={styles.Title}>Тип занятости</p>
                                <ul className={styles.listOptions}>
                                    <li>
                                        <input checked={employment === EmploymentType.FullEmployment} type={"radio"}
                                               id="employment1" value={EmploymentType.FullEmployment}
                                               onChange={(e) => setEmployment(e.target.value)}/>
                                        <label htmlFor="employment1">{EmploymentType.FullEmployment}</label>
                                    </li>
                                    <li>
                                        <input checked={employment === EmploymentType.PartTimeEmployment} type={"radio"}
                                               id="employment2" value={EmploymentType.PartTimeEmployment}
                                               onChange={(e) => setEmployment(e.target.value)}/>
                                        <label htmlFor="employment2">{EmploymentType.PartTimeEmployment}</label>
                                    </li>
                                    <li>
                                        <input checked={employment === EmploymentType.ProjectWork} type={"radio"} id="employment3"
                                               value={EmploymentType.ProjectWork}
                                               onChange={(e) =>  setEmployment(e.target.value)}/>
                                        <label htmlFor="employment3">{EmploymentType.ProjectWork}</label>
                                    </li>
                                    <li>
                                        <input checked={employment === EmploymentType.Internship} type={"radio"}
                                               id="employment4" value={EmploymentType.Internship}
                                               onChange={(e) => setEmployment(e.target.value)}/>
                                        <label htmlFor="employment4">{EmploymentType.Internship}</label>
                                    </li>
                                </ul>
                            </div>
                            <div>
                                <p className={styles.Title}>Опыт работы</p>
                                <ul className={styles.listOptions}>
                                    <li>
                                        <input checked={experience === WorkingExperience.NoExperience} type={"radio"} id="experience1" value={WorkingExperience.NoExperience}
                                               onChange={(e) => {
                                                   setExperience(e.target.value)
                                                   setExpFilter(false);
                                               }
                                               }/>
                                        <label htmlFor="experience1">{WorkingExperience.NoExperience}</label>
                                    </li>
                                    <li>
                                        <input checked={experience === WorkingExperience.From1To3} type={"radio"} id="experience2" value={WorkingExperience.From1To3}
                                               onChange={(e) => {
                                                   setExperience(e.target.value)
                                                   setExpFilter(false);
                                               }
                                               }/>
                                        <label htmlFor="experience2">{WorkingExperience.From1To3}</label>
                                    </li>
                                    <li>
                                        <input checked={experience === WorkingExperience.From3To6}  type={"radio"} id="experience3" value={WorkingExperience.From3To6}
                                               onChange={(e) => setExperience(e.target.value)}/>
                                        <label htmlFor="experience3">{WorkingExperience.From3To6}</label>
                                    </li>
                                    <li>
                                        <input checked={experience === WorkingExperience.MoreThan6} type={"radio"} id="experience4" value={WorkingExperience.MoreThan6}
                                               onChange={(e) => setExperience(e.target.value)}/>
                                        <label htmlFor="experience4">{WorkingExperience.MoreThan6}</label>
                                    </li>
                                </ul>
                            </div>
                        </div>
                    </div>
                </div>

                <div className={styles.containerMobile}>
                    <div className={styles.filterContainers}>
                        <svg className={styles.locationIcon} width="12" height="12" viewBox="0 0 20 20" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <path d="M0.000110945 7.48668C-0.00264513 7.65559 0.046006 7.82135 0.139614 7.96199C0.233221 8.10262 0.367364 8.21148 0.524255 8.27413L8.52475 11.4747L11.7254 19.4759C11.7873 19.6306 11.8941 19.7633 12.0321 19.8567C12.1701 19.9502 12.3329 20.0001 12.4996 20H12.5129C12.6817 19.9973 12.8457 19.9435 12.9832 19.8456C13.1207 19.7477 13.2252 19.6103 13.2829 19.4517L19.9493 1.11961C20.0038 0.970477 20.0146 0.808854 19.9804 0.653777C19.9462 0.4987 19.8684 0.356627 19.7562 0.244291C19.6439 0.131955 19.5019 0.0540335 19.3468 0.0197035C19.1918 -0.0146265 19.0302 -0.00393511 18.881 0.0505182L0.548421 6.71673C0.389733 6.77459 0.252348 6.87926 0.15444 7.01689C0.0565329 7.15452 0.00271682 7.31863 0.000110945 7.48751V7.48668Z" fill="#0070FB"/>
                        </svg>
                        <input className={styles.locationInput} type={"text"} value={location}
                               onChange={(e) => setLocation(e.target.value)}/>
                    </div>
                    <p className={styles.Title} onClick={() => setAllFilters(!showAllFilters)}>Фильтры</p>
                    <input className={styles.searchButton} type={"button"} value="Поиск" onClick={() => {
                        const filters : FiltersType = {
                            locationFilter: location,
                            scheduleFilter: schedule,
                            employmentTypeFilter: employment,
                            workingExperienceFilter: experience,
                            salaryFilter: salary
                        };
                        setAllFilters(false);
                        doFilter(filters)
                    }
                    }/>
                    <div className={styles.allFilters} style={{display: showAllFilters ? "block" : "none"}}>
                        <div className={styles.allFiltersContainer}>
                            <div>
                                <p className={styles.Title}>Доход</p>
                                <input className={styles.salaryInput} type={"number"} value={salary} onChange={(e) => setSalary(Number(e.target.value))}/>
                            </div>
                            <div>
                                <p className={styles.Title}>График работы</p>
                                <ul className={styles.listOptions}>
                                    <li>
                                        <input checked={schedule === Schedule.FullTime} type={"radio"} id="schedule1"
                                               value={Schedule.FullTime}
                                               onChange={(e) => setSchedule(e.target.value)}/>
                                        <label htmlFor="schedule1">{Schedule.FullTime}</label>
                                    </li>
                                    <li>
                                        <input checked={schedule === Schedule.FlexibleHours} type={"radio"} id="schedule2"
                                               value={Schedule.FlexibleHours}
                                               onChange={(e) => setScheduleFilter(false)}/>
                                        <label htmlFor="schedule2">{Schedule.FlexibleHours}</label>
                                    </li>
                                    <li>
                                        <input checked={schedule === Schedule.DistantWork}  type={"radio"} id="schedule3"
                                               value={Schedule.DistantWork}
                                               onChange={(e) => setSchedule(e.target.value)}/>
                                        <label htmlFor="schedule3">{Schedule.DistantWork}</label>
                                    </li>
                                </ul>
                            </div>
                            <div>
                                <p className={styles.Title}>Тип занятости</p>
                                <ul className={styles.listOptions}>
                                    <li>
                                        <input checked={employment === EmploymentType.FullEmployment} type={"radio"}
                                               id="employment1" value={EmploymentType.FullEmployment}
                                               onChange={(e) => setEmployment(e.target.value)}/>
                                        <label htmlFor="employment1">{EmploymentType.FullEmployment}</label>
                                    </li>
                                    <li>
                                        <input checked={employment === EmploymentType.PartTimeEmployment} type={"radio"}
                                               id="employment2" value={EmploymentType.PartTimeEmployment}
                                               onChange={(e) => setEmployment(e.target.value)}/>
                                        <label htmlFor="employment2">{EmploymentType.PartTimeEmployment}</label>
                                    </li>
                                    <li>
                                        <input checked={employment === EmploymentType.ProjectWork} type={"radio"} id="employment3"
                                               value={EmploymentType.ProjectWork}
                                               onChange={(e) =>  setEmployment(e.target.value)}/>
                                        <label htmlFor="employment3">{EmploymentType.ProjectWork}</label>
                                    </li>
                                    <li>
                                        <input checked={employment === EmploymentType.Internship} type={"radio"}
                                               id="employment4" value={EmploymentType.Internship}
                                               onChange={(e) => setEmployment(e.target.value)}/>
                                        <label htmlFor="employment4">{EmploymentType.Internship}</label>
                                    </li>
                                </ul>
                            </div>
                            <div>
                                <p className={styles.Title}>Опыт работы</p>
                                <ul className={styles.listOptions}>
                                    <li>
                                        <input checked={experience === WorkingExperience.NoExperience} type={"radio"} id="experience1" value={WorkingExperience.NoExperience}
                                               onChange={(e) => {
                                                   setExperience(e.target.value)
                                                   setExpFilter(false);
                                               }
                                               }/>
                                        <label htmlFor="experience1">{WorkingExperience.NoExperience}</label>
                                    </li>
                                    <li>
                                        <input checked={experience === WorkingExperience.From1To3} type={"radio"} id="experience2" value={WorkingExperience.From1To3}
                                               onChange={(e) => {
                                                   setExperience(e.target.value)
                                                   setExpFilter(false);
                                               }
                                               }/>
                                        <label htmlFor="experience2">{WorkingExperience.From1To3}</label>
                                    </li>
                                    <li>
                                        <input checked={experience === WorkingExperience.From3To6}  type={"radio"} id="experience3" value={WorkingExperience.From3To6}
                                               onChange={(e) => setExperience(e.target.value)}/>
                                        <label htmlFor="experience3">{WorkingExperience.From3To6}</label>
                                    </li>
                                    <li>
                                        <input checked={experience === WorkingExperience.MoreThan6} type={"radio"} id="experience4" value={WorkingExperience.MoreThan6}
                                               onChange={(e) => setExperience(e.target.value)}/>
                                        <label htmlFor="experience4">{WorkingExperience.MoreThan6}</label>
                                    </li>
                                </ul>
                            </div>
                        </div>
                    </div>
                </div>
            </nav>
        );
    }
    else {
        return (
            <></>
        )
    }
}