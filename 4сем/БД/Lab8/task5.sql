use UNIVER;

go
create view [Дисциплины]
as
select TOP 100 SUBJECT[Код], SUBJECT_NAME[Наименование дисциплины], PULPIT[Кафедра] 
from SUBJECT order by SUBJECT.SUBJECT_NAME

go
select * from [Дисциплины]

go
drop view [Дисциплины]
