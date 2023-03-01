use UNIVER;

select distinct PROGRESS.NOTE[Оценка], STUDENT.NAME[Имя студента],
		SUBJECT.SUBJECT[Дисциплина], PULPIT.PULPIT[Кафедра], FACULTY.FACULTY[Факультет],
		
Case
when (PROGRESS.NOTE = 6) then 'шесть'
when (PROGRESS.NOTE = 7) then 'семь'
when (PROGRESS.NOTE = 8) then 'восемь'
else 'не между 6 и 8'
end [Примечание]

from PROGRESS
inner join STUDENT on PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT
inner join SUBJECT on PROGRESS.SUBJECT = SUBJECT.SUBJECT
inner join PULPIT on SUBJECT.PULPIT = PULPIT.PULPIT
inner join FACULTY on FACULTY.FACULTY = PULPIT.FACULTY
inner join PROFESSION on PROFESSION.FACULTY = FACULTY.FACULTY

where PROGRESS.NOTE between 6 and 8
order by PROGRESS.NOTE desc;

select * from PROGRESS