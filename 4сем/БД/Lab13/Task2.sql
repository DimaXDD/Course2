--ex.2
-- Смотреть файл Lab13_2(не поможет), он создается автоматически после
-- выбора бд UNIVER -> программирование -> хранимые процедуры -> PSUBJECT -> Изменить
declare @k int = 0, @r int = 0, @p varchar(20);
exec @k = PSUBJECT @p = 'ИСиТ', @c = @r output;
print 'Кол-во дисциплин всего: ' + cast(@k as varchar(3))
print 'Кол-во дисциплин на кафедре ' + cast(@p as varchar(3)) + ' = ' + cast(@r as varchar(3))
--drop proc PSUBJECT