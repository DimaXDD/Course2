use UNIVER;

go
create view [Дисциплины]
as
select TOP 100 SUBJECT[Код], SUBJECT_NAME[Наименование дисциплины], PULPIT[Кафедра] 
from SUBJECT order by SUBJECT.SUBJECT_NAME

insert Дисциплины values('БД1', 'Не бд1', 'ИСиТ')

go	
select * from [Дисциплины]

go
drop view [Дисциплины]
