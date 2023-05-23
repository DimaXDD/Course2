--ex.4
use UNIVER
delete from STUDENT where NAME = 'Трубач Дмитрий Сергеевич'
select * from STUDENT

insert STUDENT (IDGROUP, NAME, BDAY, INFO) values
(5, 'Трубач Дмитрий Сергеевич', '2004-01-10', 
'<STUDENT>
	<PASSPORT SERIES="MC" NUMBER="1234567" DATE="10.05.2018" />
	<PHONE>442184582</PHONE>
	<ADRESS>
		<COUNTRY>Беларусь</COUNTRY>
		<CITY>Минск</CITY>
		<STREET>Белорусская</STREET>
		<HOUSE>21</HOUSE>
		<APPARTEMENT>76</APPARTEMENT>
	</ADRESS>
</STUDENT>')

update STUDENT set INFO = 
'<STUDENT>
	<PASSPORT SERIES="KH" NUMBER="2982505" DATE="21.01.2016" />
	<PHONE>442184582</PHONE>
	<ADRESS>
		<COUNTRY>Беларусь</COUNTRY>
		<CITY>Гродно</CITY>
		<STREET>Малая Троицкая</STREET>
		<HOUSE>42</HOUSE>
		<APPARTEMENT>706</APPARTEMENT>
	</ADRESS>
</STUDENT>'
where INFO.value('(/STUDENT/ADRESS/APPARTEMENT)[1]', 'varchar(10)') = 76 -- ???

select  NAME [ФИО],
		INFO.value('(/STUDENT/PASSPORT/@SERIES)[1]', 'varchar(10)') Серия,
		INFO.value('(/STUDENT/PASSPORT/@NUMBER)[1]', 'varchar(10)') Номер,
		INFO.query('/STUDENT/ADRESS') Адрес
from STUDENT
where NAME = 'Трубач Дмитрий Сергеевич'


