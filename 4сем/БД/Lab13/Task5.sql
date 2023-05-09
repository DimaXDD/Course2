--ex.5
create proc SUBJECT_REPORT @PULPIT varchar(20)
as
begin try
	declare @SUBJ_OUT varchar(200) = ''
	declare @SUBJ_ONE varchar(20) = ''
	declare @ROWCOUNT int = 0
	declare cur cursor local static for (select SUBJECT from SUBJECT where SUBJECT.PULPIT = @PULPIT)
	if not exists (select SUBJECT from SUBJECT where SUBJECT.PULPIT = @PULPIT)
		raiserror('Ошибка! ', 11, 1)
	else
	open cur
		fetch cur into @SUBJ_ONE
		while @@FETCH_STATUS = 0
		begin
			set @SUBJ_OUT += rtrim(@SUBJ_ONE) + ', '
			set @ROWCOUNT = @ROWCOUNT + 1
			fetch cur into @SUBJ_ONE
		end
	print @SUBJ_OUT
	close cur
	return @ROWCOUNT
end try
begin catch
	print 'Ошибка в параметрах!'
	print 'Сообщение: ' + cast(ERROR_MESSAGE() as varchar(max))
	print 'Номер строки: ' + cast(@ROWCOUNT as varchar) 
end catch


drop proc SUBJECT_REPORT

declare @COUNT int = 0
exec @COUNT = SUBJECT_REPORT @PULPIT = 'ИСиТ'
print 'Количество дисциплин: ' + cast(@COUNT as varchar)