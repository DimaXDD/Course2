use UNIVER;

select * from GROUPS


select a.FACULTY,
       G.PROFESSION,
	   G.IDGROUP,
	   --(2014 - g.YEAR_FIRST) [Курс],
       round(avg(cast(NOTE AS float(4))), 2) as [Средняя оценка]
from FACULTY a
         join GROUPS G on a.FACULTY = G.FACULTY
         join STUDENT S on G.IDGROUP = S.IDGROUP
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by a.FACULTY, G.PROFESSION, G.IDGROUP
--group by a.FACULTY, G.PROFESSION, G.YEAR_FIRST, G.IDGROUP, G.YEAR_FIRST
order by [Средняя оценка] desc