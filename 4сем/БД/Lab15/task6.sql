--ex.6
use UNIVER
go
create trigger TR_TEACHER_DEL1 on TEACHER after delete
as declare @TEACHER char(10), @TEACHER_NAME varchar(100),
		   @GENDER char(1), @PULPIT char(20), @IN varchar(300)
print 'DELETE Trigger 1'
set @IN = 'Trigger Normal Priority'
insert into TR_AUDIT (STMT, TRNAME, CC) values ('DEL', 'TR_TEACHER_DEL1', @IN)

go
create trigger TR_TEACHER_DEL2 on TEACHER after delete
as declare @TEACHER char(10), @TEACHER_NAME varchar(100),
		   @GENDER char(1), @PULPIT char(20), @IN varchar(300)
print 'DELETE Trigger 2'
set @IN = 'Trigger Low Priority'
insert into TR_AUDIT (STMT, TRNAME, CC) values ('DEL', 'TR_TEACHER_DEL2', @IN)

go
create trigger TR_TEACHER_DEL3 on TEACHER after delete
as declare @TEACHER char(10), @TEACHER_NAME varchar(100),
		   @GENDER char(1), @PULPIT char(20), @IN varchar(300)
print 'DELETE Trigger 3'
set @IN = 'Trigger Highest Priority'
insert into TR_AUDIT (STMT, TRNAME, CC) values ('DEL', 'TR_TEACHER_DEL3', @IN)

go
select t.name, e.type_desc 
from sys.triggers t join  sys.trigger_events e  
on t.object_id = e.object_id  
where OBJECT_NAME(t.parent_id) = 'TEACHER' and e.type_desc = 'DELETE'

go
exec SP_SETTRIGGERORDER @triggername = 'TR_TEACHER_DEL3', @order = 'First', @stmttype = 'DELETE'
exec SP_SETTRIGGERORDER @triggername = 'TR_TEACHER_DEL2', @order = 'Last',  @stmttype = 'DELETE'

go
insert into TEACHER values ('ТРДС', 'Трубач Дмитрий Сергеевич', 'м', 'ИСиТ')
delete from TEACHER where TEACHER = 'ТРДС'
select * from TEACHER
select * from TR_AUDIT order by ID