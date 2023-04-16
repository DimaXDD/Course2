create table #EX4
(
	TKEY int, 
    ID int identity(1, 1),
    TF varchar(50)
);

set nocount on;
declare @iter int = 0;
while @iter < 15000
begin
	INSERT #EX4(TKEY, TF) values(floor(30000 * RAND()), replicate('строка ', 5));
	set @iter += 1;
end

-- некластеризированный фильтруемный индекс используется
-- при фильтрации в секции where (без индекса везде 0,1)
select TKEY from #EX4 where TKEY between 5000 and 19999 
select TKEY from #EX4 where TKEY > 15000 and  TKEY < 20000  
select TKEY from #EX4 where TKEY = 17000

-- фильтруемый индекс (стало 0.005):
create index #EX4_WHERE on #EX4 (TKEY) where (TKEY > 15000 and TKEY < 20000)

drop index #EX4_WHERE on #EX4
drop table #EX4