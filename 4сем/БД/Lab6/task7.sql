use UNIVER;

select * from PROGRESS

select PROGRESS.[SUBJECT], 
	   count(PROGRESS.NOTE) as [Количество 8, 9]
from PROGRESS 

group by PROGRESS.[SUBJECT], PROGRESS.NOTE
having PROGRESS.NOTE in (8,9)