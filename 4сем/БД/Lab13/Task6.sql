--ex.6
use UNIVER
go
create proc PAUDITORIUM_INSERTX 
@AUD char(20), @NAME varchar(50), @CAPACITY int = 0, @AUD_TYPE char(10), @AUD_TYPENAME varchar(70)
as 
begin try
	set transaction isolation level SERIALIZABLE
	begin tran
		insert into AUDITORIUM_TYPE (AUDITORIUM_TYPE, AUDITORIUM_TYPENAME)
		values (@AUD_TYPE, @AUD_TYPENAME)
		exec PAUDITORIUM_INSERT @AUD, @NAME, @CAPACITY, @AUD_TYPE
	commit tran
end try
begin catch
	print 'Код ошибки:  ' + cast(ERROR_NUMBER() as varchar)
	print 'Серьёзность: ' + cast(ERROR_SEVERITY() as varchar)
	print 'Сообщение:   ' + cast(ERROR_MESSAGE() as varchar)
	if @@TRANCOUNT > 0 
		rollback tran
	return -1
end catch

go
exec PAUDITORIUM_INSERTX @AUD = '325-1', @NAME = '325-1', @CAPACITY = 50, @AUD_TYPE = 'ЛР-К', @AUD_TYPENAME = 'Лабораторный кабинет'

select * from AUDITORIUM
select * from AUDITORIUM_TYPE

--delete AUDITORIUM where AUDITORIUM = '325-1'
--delete AUDITORIUM_TYPE where AUDITORIUM_TYPE = 'ЛР-К'

drop proc PAUDITORIUM_INSERTX 