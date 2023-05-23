--ex.1
use UNIVER

select t.TEACHER_NAME 'Преподаватель', RTRIM(LTRIM(t.PULPIT)) 'Кафедра' from TEACHER t 
join PULPIT p 
on t.PULPIT = p.PULPIT 
where t.PULPIT = 'ИСиТ'
for xml RAW('PULPUT'), root('Список_элементов'), elements

--select * from TEACHER
--select * from PULPIT