use UNIVER;

select top 1
(select avg(NOTE) from PROGRESS where PROGRESS.SUBJECT like 'ОАиП') as 'ОАиП',
(select avg(NOTE) from PROGRESS where PROGRESS.SUBJECT like 'КГ') as 'КГ',
(select avg(NOTE) from PROGRESS where PROGRESS.SUBJECT like 'СУБД') as 'СУБД'
