--create database Lab9_Java

use Lab9_Java
create table Users
(
	ID int identity(1, 1) PRIMARY KEY,
	UserName nvarchar(50) NOT NULL,
	UserPassword nvarchar(50) NOT NULL,
	UserRole nvarchar(10) NOT NULL
)
insert into Users (UserName, UserPassword, UserRole) values ('admin', 'admin', 'admin');
insert into Users (UserName, UserPassword, UserRole) values ('user1', 'user1', 'user');