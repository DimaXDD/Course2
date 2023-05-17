use UNIVER

go
create function FCTEACHER (@PULPIT varchar(20)) returns int
as begin
	declare @COUNT int = (select count(*)
						  from   TEACHER t
						  where  t.PULPIT = isnull(@PULPIT, t.PULPIT))
	return @COUNT
end

-- drop function FCTEACHER

go
print 'Кол-во преподавателей всего: ' + cast(dbo.FCTEACHER(null) as varchar)
print 'Кол-во преподавателей ИСиТ:  ' + cast(dbo.FCTEACHER('ИСиТ') as varchar)
select PULPIT Кафедра, dbo.FCTEACHER(PULPIT) [Кол-во преподавателей]
from   PULPIT