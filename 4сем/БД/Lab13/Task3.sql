--ex.3
alter proc PSUBJECT @PULPIT varchar(20)
as 
begin
	select * from SUBJECT where SUBJECT.PULPIT != @PULPIT
end

create table #SUBJECTS
(
	Код varchar(10) primary key,
	Дисциплина varchar(50) not null,
	Кафедра varchar(10) not null
);
insert #SUBJECTS exec PSUBJECT @PULPIT = 'ИСиТ'
select * from #SUBJECTS

drop table #SUBJECTS
drop proc PSUBJECT