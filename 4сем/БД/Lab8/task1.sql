use UNIVER;

go
create view [Преподаватель]
as 
select 
GENDER[Пол], PULPIT[Кафедра], TEACHER[Код], TEACHER_NAME[Имя] from TEACHER;


UPDATE TEACHER
SET GENDER = 'м'
WHERE TEACHER_NAME = 'Рожков Леонид Николаевич';

delete from TEACHER
WHERE TEACHER_NAME = 'Рожков Леонид Николаевич';


go
select * from [Преподаватель]

go
drop view [Преподаватель]