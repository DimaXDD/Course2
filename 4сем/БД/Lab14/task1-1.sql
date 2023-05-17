use UNIVER;

go
create function COUNT_STUDENTS (@FACULTY varchar(20)) returns int
as
begin
		declare @COUNT int = (select count(*)
						  from STUDENT s
						  join GROUPS g on s.IDGROUP = g.IDGROUP
						  join FACULTY f on f.FACULTY = g.FACULTY
						  where g.FACULTY = @FACULTY)
	return @COUNT
end

go
select * from STUDENT s	join GROUPS g on s.IDGROUP = g.IDGROUP
						join FACULTY f on f.FACULTY = g.FACULTY
						where g.FACULTY = 'ТОВ'
						
go
declare @RES int = dbo.COUNT_STUDENTS('ТОВ')
print 'Количество студентов: ' + cast(@RES as varchar)

--drop function COUNT_STUDENTS