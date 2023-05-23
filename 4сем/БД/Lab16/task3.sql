--ex.3
use UNIVER

declare @i int = 0,
	@xml varchar(2000) = '<?xml version="1.0" encoding="windows-1251" ?>
       <SUBJECTS> 
		<SUBJECT SUBJECT="ТПвИ" SUBJECT_NAME="Технология программирования в интернет"	PULPIT="ИСиТ" /> 
		<SUBJECT SUBJECT="ДПИ"	SUBJECT_NAME="Дизайн пользовательских интерфейсов"		PULPIT="ИСиТ" /> 
		<SUBJECT SUBJECT="РиАТ" SUBJECT_NAME="Разработка и анализ требований"			PULPIT="ИСиТ" /> 
       </SUBJECTS>'

exec sp_xml_preparedocument @i output, @xml
select * from openxml(@i, '/SUBJECTS/SUBJECT', 0)
with (
	[SUBJECT] char(10), 
	[SUBJECT_NAME] nvarchar(100), 
	[PULPIT] char(20)
)
select * from SUBJECT

insert into SUBJECT ([SUBJECT], [SUBJECT_NAME], [PULPIT])
select [SUBJECT], [SUBJECT_NAME], P.[PULPIT]
from openxml(@i, '/SUBJECTS/SUBJECT', 0)
with (
	[SUBJECT] char(10), 
	[SUBJECT_NAME] nvarchar(100), 
	[PULPIT] char(20)
) as s
JOIN PULPIT P ON S.[PULPIT] = P.[PULPIT]; -- Join with PULPIT table to ensure existence of PULPIT value
select * from SUBJECT

delete from SUBJECT where SUBJECT = 'ТПвИ'
delete from SUBJECT where SUBJECT = 'ДПИ'
delete from SUBJECT where SUBJECT = 'РиАТ'