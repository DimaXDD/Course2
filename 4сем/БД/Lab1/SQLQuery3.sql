﻿use ТрубачПРОДАЖИ
GO

SELECT  ТОВАРЫ.Наименование, ЗАКАЗЧИКИ.Наименование_фирмы
FROM      ЗАКАЗЧИКИ INNER JOIN
                   ЗАКАЗЫ ON ЗАКАЗЧИКИ.Наименование_фирмы = ЗАКАЗЫ.Заказчик INNER JOIN
                   ТОВАРЫ ON ЗАКАЗЫ.Наименование_товара = ТОВАРЫ.Наименование
WHERE   (ТОВАРЫ.Наименование = 'Принтер')
