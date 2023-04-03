use UNIVER;

go
create view [Количество_кафедр]
as 
select FACULTY_NAME[Факультет], COUNT(PULPIT)[Количество кафедр]
		from FACULTY inner join PULPIT
		on FACULTY.FACULTY = PULPIT.FACULTY 
		group by FACULTY_NAME;


--task 6
go
ALTER VIEW [Количество_кафедр] with SCHEMABINDING
as select		fclt.FACULTY_NAME		[Факультет],
				count(plpt.PULPIT)		[Количество_кафедр]
				from dbo.FACULTY fclt inner join dbo.PULPIT plpt
				on fclt.FACULTY = plpt.FACULTY 
				group by FACULTY_NAME;


go
select * from [Количество_кафедр]

go
drop view [Количество_кафедр]
