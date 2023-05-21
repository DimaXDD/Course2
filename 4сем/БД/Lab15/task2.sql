--ex.2
use UNIVER
go
create trigger TR_TEACHER_DEL on TEACHER after delete
as 
declare @TEACHER char(10), @TEACHER_NAME varchar(100),
		   @GENDER char(1), @PULPIT char(20), @IN varchar(300)
print 'Выполнена операция DELETE'
set @TEACHER = (select TEACHER from DELETED)
set @TEACHER_NAME = (select TEACHER_NAME from DELETED)
set @GENDER = (select GENDER from DELETED)
set @PULPIT = (select PULPIT from DELETED)
set @IN = ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
		  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT))
insert into TR_AUDIT (STMT, TRNAME, CC) values ('DEL', 'TR_TEACHER_DEL', @IN)
return;

go
delete from TEACHER where TEACHER = 'ИВНВ'
select * from TEACHER
select * from TR_AUDIT order by ID
