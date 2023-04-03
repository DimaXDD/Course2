use UNIVER;

go
create view [Преподаватель]
as 
select 
GENDER[Пол], PULPIT[Кафедра], TEACHER[Код], TEACHER_NAME[Имя] from TEACHER;

go
select * from [Преподаватель]

go
drop view [Преподаватель]