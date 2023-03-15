use UNIVER;

select NOTE, SUBJECT from PROGRESS
	where NOTE >=all (select NOTE from PROGRESS WHERE SUBJECT like 'О%')