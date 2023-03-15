use UNIVER;

select distinct PULPIT_NAME[Кафедра]--, PROFESSION_NAME
from FACULTY, PULPIT, PROFESSION
where PULPIT.FACULTY = FACULTY.FACULTY
 and FACULTY.FACULTY in (select PROFESSION.FACULTY
                         from PROFESSION
                         where PROFESSION_NAME like ('%технология%')
                            or PROFESSION_NAME like ('%технологии%'))