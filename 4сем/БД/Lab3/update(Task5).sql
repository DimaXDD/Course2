﻿UPDATE ТОВАРЫ set Количество_на_складе = Количество_на_складе + 10 Where Название_детали = 'Двигатель внутреннего сгорания';

SELECT Название_детали, Количество_на_складе FROM ТОВАРЫ;