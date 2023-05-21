--ex.9
use UNIVER
go
create trigger TR_TEACHER_DDL on database 
for DDL_DATABASE_LEVEL_EVENTS  as   
declare @EVENT_TYPE varchar(50) = EVENTDATA().value('(/EVENT_INSTANCE/EventType)[1]', 'varchar(50)')
declare @OBJ_NAME varchar(50) = EVENTDATA().value('(/EVENT_INSTANCE/ObjectName)[1]', 'varchar(50)')
declare @OBJ_TYPE varchar(50) = EVENTDATA().value('(/EVENT_INSTANCE/ObjectType)[1]', 'varchar(50)')
if @OBJ_NAME = 'TEACHER' 
begin
	print 'Тип события: ' + cast(@EVENT_TYPE as varchar)
	print 'Имя объекта: ' + cast(@OBJ_NAME as varchar)
	print 'Тип объекта: ' + cast(@OBJ_TYPE as varchar)
	raiserror('Операции с таблицей TEACHER запрещены.', 16, 1)
	rollback  
end

go
alter table TEACHER drop column TEACHER_NAME