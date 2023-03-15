use UNIVER;

select NOTE, SUBJECT from PROGRESS
	where NOTE >any (select NOTE from PROGRESS WHERE NOTE > 5)
	order by NOTE desc