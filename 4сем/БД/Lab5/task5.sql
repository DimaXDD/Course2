use UNIVER;

select FACULTY_NAME from FACULTY
	where not exists (select * from PULPIT
			where PULPIT.FACULTY = FACULTY.FACULTY)