--ex.3
use UNIVER
drop trigger TR_TEACHER_UPD
go
create trigger TR_TEACHER_UPD on TEACHER after update
as 
declare @TEACHER char(10), @TEACHER_NAME varchar(100),
		   @GENDER char(1), @PULPIT char(20), @IN varchar(300)
print 'Выполнена операция UPDATE'

set @TEACHER = (select TEACHER from DELETED where TEACHER is not null)
set @TEACHER_NAME = (select TEACHER_NAME from DELETED where TEACHER_NAME is not null)
set @GENDER = (select GENDER from DELETED where GENDER is not null)
set @PULPIT = (select PULPIT from DELETED where PULPIT is not null)
set @IN = ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
		  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT)) + ' -> '

set @TEACHER = (select TEACHER from INSERTED where TEACHER is not null)
set @TEACHER_NAME = (select TEACHER_NAME from INSERTED where TEACHER_NAME is not null)
set @GENDER = (select GENDER from INSERTED where GENDER is not null)
set @PULPIT = (select PULPIT from INSERTED where PULPIT is not null)
set @IN = @IN + ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
		  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT))

insert into TR_AUDIT (STMT, TRNAME, CC) values ('UPD', 'TR_TEACHER_UPD', @IN)
return;

go
update TEACHER set GENDER = 'м' where TEACHER='РЖК'
select * from TEACHER
select * from TR_AUDIT;
