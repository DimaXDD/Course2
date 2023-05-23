--ex.2
use UNIVER

select [AUDITORIUM].AUDITORIUM_NAME [Название_аудитории],
		RTRIM(LTRIM([AUDITORIUM].AUDITORIUM_TYPE)) [Тип_аудитории],
		[AUDITORIUM].AUDITORIUM_CAPACITY [Вместимость]
from AUDITORIUM
join AUDITORIUM_TYPE 
on AUDITORIUM_TYPE.AUDITORIUM_TYPE = AUDITORIUM.AUDITORIUM_TYPE
where AUDITORIUM_TYPE.AUDITORIUM_TYPENAME like '%лекци%'
for xml auto, type, root('Список_аудиторий')

--select * from AUDITORIUM
--select * from AUDITORIUM_TYPE