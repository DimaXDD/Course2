--ex.1
use UNIVER
go
create table TR_AUDIT
(
	ID int identity(1, 1),										-- номер
	STMT varchar(20) check (STMT in ('INS', 'DEL', 'UPD')),		-- DML название оператора
	TRNAME varchar(50),											-- имя триггера
	CC varchar(300)												-- комментарий
)

go
create trigger TR_TEACHER_INS on TEACHER after insert
as 
declare @TEACHER char(10), @TEACHER_NAME varchar(100),
		   @GENDER char(1), @PULPIT char(20), @IN varchar(300)
print 'Выполнена операция INSERT'
set @TEACHER = (select TEACHER from INSERTED)
set @TEACHER_NAME = (select TEACHER_NAME from INSERTED)
set @GENDER = (select GENDER from INSERTED)
set @PULPIT = (select PULPIT from INSERTED)
set @IN = ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
		  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT))
insert into TR_AUDIT (STMT, TRNAME, CC) values ('INS', 'TR_TEACHER_INS', @IN)
return;

go
insert into TEACHER values ('ИВНВ', 'Иванов Иван Иванович', 'м', 'ИСиТ')
select * from TEACHER
select * from TR_AUDIT order by ID