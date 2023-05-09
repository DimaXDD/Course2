--ex.1
use UNIVER
go
create procedure PSUBJECT	
as
begin
	set nocount on;
	declare @count int = (select count(*) from SUBJECT)
	select s.SUBJECT Код, s.SUBJECT_NAME Дисциплина, s.PULPIT Кафедра from SUBJECT s
	return @count
end

go
declare @COUNT_OUTPUT int = 0
exec @COUNT_OUTPUT = PSUBJECT
print 'Количество дисциплин: ' + cast(@COUNT_OUTPUT as varchar(10))

--drop proc PSUBJECT