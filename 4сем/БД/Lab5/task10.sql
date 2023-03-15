use UNIVER;

select  Name, BDAY from STUDENT a
where BDAY in ( select BDAY from STUDENT where a.NAME != STUDENT.NAME)
order by BDAY