use UNIVER;

select * from PROGRESS

select *
from (select Case when PROGRESS.NOTE between 4 and 5 then '4-5'
					when PROGRESS.NOTE between 6 and 7 then '6-7'
					when PROGRESS.NOTE between 8 and 9 then '8-9'
					else '10'
					end[Оценки], count(*)[Кол-во]
from PROGRESS Group by Case 
					when PROGRESS.NOTE between 4 and 5 then '4-5'
					when PROGRESS.NOTE between 6 and 7 then '6-7'
					when PROGRESS.NOTE between 8 and 9 then '8-9'
					else '10'
					end) as T
order by case[Оценки]
				when '4-5' then 3
				when '6-7' then 2 
				when '8-9' then 1
				else 0
				end