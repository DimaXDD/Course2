use UNIVER
go
create trigger TEACH_TRAN on TEACHER after insert, delete, update
as
declare @c int = (select COUNT(TEACHER) from TEACHER);
		if(@c > 10)
			begin
				raiserror('Учителей не может быть больше 10', 10, 1);
				rollback;
			end;
		return;


go
insert into TEACHER values ('ТЕСТ', 'Просто для теста', 'м', 'ИСиТ')
select * from TEACHER
select * from TR_AUDIT order by ID