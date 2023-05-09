--ex.4
use UNIVER
go
create proc PAUDITORIUM_INSERT @AUD char(20), @NAME varchar(50), @CAPACITY int = 0, @TYPE char(10)
as
begin
	begin try
		insert into AUDITORIUM (AUDITORIUM, AUDITORIUM_NAME, AUDITORIUM_CAPACITY, AUDITORIUM_TYPE)
		values (@AUD, @NAME, @CAPACITY, @TYPE)
		return 1
	end try
	begin catch
		print 'Номер ошибка:  ' + cast(ERROR_NUMBER() as varchar(6))
		print 'Уровень: ' + cast(ERROR_SEVERITY() as varchar(6))
		print 'Сообщение:   ' + ERROR_MESSAGE()
		return -1
	end catch
end

go
declare @RETURN int
exec @RETURN = PAUDITORIUM_INSERT @AUD = '500-1', @NAME = '500-1', @CAPACITY = 20, @TYPE = 'ЛК'
print 'Процедура завершилась с кодом ' + cast(@RETURN as varchar)

select * from AUDITORIUM
select * from AUDITORIUM_TYPE

delete AUDITORIUM where AUDITORIUM = '500-1'

