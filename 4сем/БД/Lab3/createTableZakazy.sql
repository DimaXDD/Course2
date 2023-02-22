use Lab3;
create table ЗАКАЗЫ
(
	ID_Заказа int primary key,
	Артикул_товара int foreign key references ТОВАРЫ(Артикул),
	Код_поставщика char(5) foreign key references ПОСТАВЩИКИ(Код_поставщика),
	Количество_заказанных int not null,
	Цена_товара money,
	Дата_заказа date,
	Примечание nvarchar(40)
);