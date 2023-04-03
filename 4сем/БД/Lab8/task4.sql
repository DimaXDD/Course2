use UNIVER;

go
create view [Аудитории]
as
select AUDITORIUM_NAME[Код], AUDITORIUM_TYPE[Тип] from AUDITORIUM
where AUDITORIUM.AUDITORIUM_TYPE like 'ЛК%' with check option

go
select * from [Аудитории]

go
drop view [Аудитории]

select * from AUDITORIUM