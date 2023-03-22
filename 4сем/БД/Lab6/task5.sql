use UNIVER;

select * from GROUPS

select a.FACULTY,
       G.PROFESSION,
	   G.IDGROUP,
	   P.SUBJECT,
	   --(2014 - g.YEAR_FIRST) [Курс]
       round(avg(cast(NOTE AS float(4))), 2) as [Средняя оценка]
from FACULTY a
         join GROUPS G on a.FACULTY = G.FACULTY
         join STUDENT S on G.IDGROUP = S.IDGROUP
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
		where P.SUBJECT like 'СУБД' or P.SUBJECT like 'ОАиП'
group by a.FACULTY, G.PROFESSION, P.SUBJECT, G.IDGROUP
--group by a.FACULTY, G.PROFESSION, P.SUBJECT, G.IDGROUP, G.YEAR_FIRST
order by [Средняя оценка] desc