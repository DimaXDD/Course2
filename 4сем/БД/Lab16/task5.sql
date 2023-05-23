--ex.5
use UNIVER

--drop xml schema collection Student
--drop table STUDENT_TEST

create xml schema collection Student as 
N'<?xml version="1.0" encoding="utf-16" ?>
<xs:schema attributeFormDefault="unqualified" elementFormDefault="qualified" xmlns:xs="http://www.w3.org/2001/XMLSchema">
	<xs:element name="STUDENT">  
		<xs:complexType>
			<xs:sequence>
				<xs:element name="PASSPORT" maxOccurs="1" minOccurs="1">
					<xs:complexType>
						<xs:attribute name="SERIES" type="xs:string" use="required" />
						<xs:attribute name="NUMBER" type="xs:unsignedInt" use="required"/>
						<xs:attribute name="DATE"  use="required" >  
							<xs:simpleType> 
								<xs:restriction base ="xs:string">
									<xs:pattern value="[0-9]{2}.[0-9]{2}.[0-9]{4}"/>
								</xs:restriction>
							</xs:simpleType>
						</xs:attribute>
					</xs:complexType> 
				</xs:element>
				<xs:element maxOccurs="3" name="PHONE" type="xs:unsignedInt"/>
				<xs:element name="ADRESS">
					<xs:complexType>
						<xs:sequence>
							<xs:element name="COUNTRY" type="xs:string" />
							<xs:element name="CITY" type="xs:string" />
							<xs:element name="STREET" type="xs:string" />
							<xs:element name="HOUSE" type="xs:string" />
							<xs:element name="APPARTEMENT" type="xs:string" />
						</xs:sequence>
					</xs:complexType>
				</xs:element>
			</xs:sequence>
		</xs:complexType>
	</xs:element>
</xs:schema>'


create table STUDENT_TEST 
(    
	IDSTUDENT integer  identity(1000,1)  primary key,
    IDGROUP integer  foreign key  references GROUPS(IDGROUP),        
    NAME nvarchar(100), 
    BDAY  date,
    STAMP timestamp,
    INFO   xml(Student),    -- типизированный столбец XML-типа
    FOTO  varbinary
);

-- Добавляем схему к колонке INFO
alter table STUDENT_TEST alter column INFO xml(Student)

delete from STUDENT_TEST where NAME = 'Трубач Дмитрий Сергеевич'

-- тест 1, должен пройти
insert STUDENT_TEST (IDGROUP, NAME, BDAY, INFO) values
(5, 'Трубач Дмитрий Сергеевич', '2004-01-10', 
'<STUDENT>
	<PASSPORT SERIES="MC" NUMBER="1234567" DATE="10.05.2018" />
	<PHONE>123456789</PHONE>
	<ADRESS>
		<COUNTRY>Беларусь</COUNTRY>
		<CITY>Минск</CITY>
		<STREET>Белорусская</STREET>
		<HOUSE>21</HOUSE>
		<APPARTEMENT>76</APPARTEMENT>
	</ADRESS>
</STUDENT>')

--тест 2, не должен, нет паспорта
insert STUDENT_TEST (IDGROUP, NAME, BDAY, INFO) values
(5, 'Трубач Дмитрий Сергеевич', '2004-01-10', 
'<STUDENT>
	<PASSPORT SERIES="MC" NUMBER="1234567" DATE="10.05.2018" />
	<PHONE>123456789</PHONE>
	<ADRESS>
		<COUNTRY>Беларусь</COUNTRY>
		<CITY>Минск</CITY>
		<STREET>Белорусская</STREET>
		<HOUSE>21</HOUSE>
		<APPARTEMENT>76</APPARTEMENT>
	</ADRESS>
</STUDENT>')

--тест 3, не должен, ошибка в дате
insert STUDENT_TEST(IDGROUP, NAME, BDAY, INFO) values
(5, 'Трубач Дмитрий Сергеевич', '2004-01-10', 
'<STUDENT>
	<PASSPORT SERIES="MC" NUMBER="1234567" DATE="2018-01-10" />
	<PHONE>123456789</PHONE>
	<ADRESS>
		<COUNTRY>Беларусь</COUNTRY>
		<CITY>Минск</CITY>
		<STREET>Белорусская</STREET>
		<HOUSE>21</HOUSE>
		<APPARTEMENT>76</APPARTEMENT>
	</ADRESS>
</STUDENT>')

-- тест 4, не должен, ошибка в номере
insert STUDENT_TEST (IDGROUP, NAME, BDAY, INFO) values
(5, 'Трубач Дмитрий Сергеевич', '2004-01-10', 
'<STUDENT>
	<PASSPORT SERIES="MC" NUMBER="1234567" DATE="10.05.2018" />
	<PHONE>123456789123456789</PHONE>
	<ADRESS>
		<COUNTRY>Беларусь</COUNTRY>
		<CITY>Минск</CITY>
		<STREET>Белорусская</STREET>
		<HOUSE>21</HOUSE>
		<APPARTEMENT>76</APPARTEMENT>
	</ADRESS>
</STUDENT>')

--тест 5, не должен, еще одно насчет номера
insert STUDENT_TEST (IDGROUP, NAME, BDAY, INFO) values
(5, 'Трубач Дмитрий Сергеевич', '2004-01-10', 
'<STUDENT>
	<PASSPORT SERIES="MC" NUMBER="1234567" DATE="10.05.2018" />
	<PHONE>123456789</PHONE>
	<PHONE>987654321</PHONE>
	<PHONE>123546789</PHONE>
	<PHONE>123656689</PHONE>
	<ADRESS>
		<COUNTRY>Беларусь</COUNTRY>
		<CITY>Минск</CITY>
		<STREET>Белорусская</STREET>
		<HOUSE>21</HOUSE>
		<APPARTEMENT>76</APPARTEMENT>
	</ADRESS>
</STUDENT>')
