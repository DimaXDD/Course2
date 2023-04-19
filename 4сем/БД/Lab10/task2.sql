create table #EX2
(
	TKEY int, 
    ID int identity(1, 1),
    TF varchar(100)
);

set nocount on;
declare @iter int = 0;
while @iter < 15000
begin
	INSERT #EX2(TKEY, TF) values(floor(30000 * RAND()), replicate('строка ', 10));
	set @iter += 1;
end

-- без индексов 0.159
select count(*)[Количество строк] from #EX2;
select * from #EX2

--создаем некластеризованный неуникальный составной индекс
CREATE index #EX2_NONCLU on #EX2(TKEY, ID)

checkpoint;  --фиксация БД
DBCC DROPCLEANBUFFERS;  --очистить буферный кэш

--Этот индекс не применяется оптимизатором ни при фильтрации, 
--ни при сортировке строк таблицы #EX2, в чем можно убедиться, посмотрев планы следующих запросов
SELECT * from  #EX2 where  TKEY > 1500 and ID < 4500;  
SELECT * from  #EX2 order by  TKEY, ID

-- однако, некласетризированный составной 
-- индекс подключается при фиксированном значении
-- (1,15 без индекса, 0,0067 с индексом)
select * from #EX2 where TKEY = 556 and ID > 3

drop index #EX2_NONCLU on #EX2
drop table #EX2