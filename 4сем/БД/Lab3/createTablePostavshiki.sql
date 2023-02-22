use Lab3;
create table ПОСТАВЩИКИ
(
	Код_поставщика char(5) primary key,
	Имя_поставщика nvarchar(30) not null,
	Контактное_лицо nvarchar(40),
	Телефон nvarchar(20),
	Адрес nvarchar(60)
);