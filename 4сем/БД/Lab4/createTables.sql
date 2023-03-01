use UNIVER;

CREATE TABLE FACULTY
(
FACULTY				char(10) constraint  FACULTY_PK  primary key,  
FACULTY_NAME		nvarchar(50) default '???'
);

CREATE TABLE PROFESSION
(
PROFESSION			char(20) primary key not null,
FACULTY				char(10) not null  foreign key references FACULTY(FACULTY),
PROFESSION_NAME		nvarchar(100) null,
QUALIFICATION		nvarchar(50) null
);

CREATE TABLE PULPIT
(
PULPIT				char(20) primary key not null,
PULPIT_NAME			nvarchar(100) null,
FACULTY				char(10) not null  foreign key references FACULTY(FACULTY)
);

CREATE TABLE TEACHER
(
TEACHER				char(10) primary key not null,
TEACHER_NAME		nvarchar(100) null,
GENDER				char(1) default 'м' check (GENDER in ('м','ж')),
PULPIT				char(20) not null foreign key references PULPIT(PULPIT)
);

CREATE TABLE SUBJECT
(
SUBJECT				char(10) primary key not null,  
SUBJECT_NAME		nvarchar(100) null unique,
PULPIT				char(20) foreign key references PULPIT(PULPIT) not null
);

CREATE TABLE AUDITORIUM_TYPE
(
AUDITORIUM_TYPE		char(10) primary key not null,
AUDITORIUM_TYPENAME nvarchar(30) null
);

CREATE TABLE AUDITORIUM
(
AUDITORIUM			char(20) not null,
AUDITORIUM_TYPE		char(10) foreign key references AUDITORIUM_TYPE(AUDITORIUM_TYPE) not null,
AUDITORIUM_CAPACITY	int default 1 check (AUDITORIUM_CAPACITY between 1  and 300), 
AUDITORIUM_NAME		nvarchar(50) null
);

CREATE TABLE GROUPS
(
IDGROUP				int identity(1,1)  primary key not null,
FACULTY				char(10) foreign key references FACULTY(FACULTY) not null,
PROFESSION			char(20) foreign key references PROFESSION(PROFESSION) not null,
YEAR_FIRST			smallint check (YEAR_FIRST <= YEAR(GETDATE())),
COURSE				AS YEAR(GETDATE()) - YEAR_FIRST
);

CREATE TABLE STUDENT
(
IDSTUDENT			int primary key identity (1000,1),
IDGROUP				int foreign key references GROUPS(IDGROUP),
NAME				nvarchar(100),
BDAY				date,
STAMP				timestamp,
INFO				xml default null,
FOTO				varbinary(max) default null 
);

CREATE TABLE PROGRESS
(
SUBJECT				char(10) foreign key references SUBJECT(SUBJECT) not null,
IDSTUDENT			int foreign key references STUDENT(IDSTUDENT) not null,
PDATE				date,
NOTE				int check (NOTE between 1 and 10)
);


