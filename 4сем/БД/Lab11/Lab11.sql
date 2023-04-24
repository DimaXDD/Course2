use UNIVER;

--ex.1
declare discpiplineCursor cursor for select SUBJECT_NAME from SUBJECT where SUBJECT.PULPIT like 'ИСиТ';
declare @subject char(35), @subjects char(500) = '';

OPEN discpiplineCursor;
FETCH discpiplineCursor into @subject;
print 'Дисциплины кафедры ИСиТ:';
while @@FETCH_STATUS = 0
	begin
		set @subjects = RTRIM(@subject) + char(10) +  @subjects;
		FETCH  discpiplineCursor into @subject;
	end;
	print @subjects;
CLOSE discpiplineCursor;
deallocate  discpiplineCursor;

--ex.2
------------------- Курсор локальный -------------------------------
declare StudentsL CURSOR LOCAL for SELECT NAME, IDGROUP from STUDENT;
declare @name nvarchar(50), @group int;      
	OPEN StudentsL;	  
	fetch StudentsL into @name, @group; 	
    print '1. '+ @name + ', группа: ' + cast(@group as varchar(6));   
go
declare @name nvarchar(50), @group int;     	
	fetch StudentsL into @name, @group; 	
    print '2. '+ @name+ ', группа: '  + cast(@group as varchar(6));  
go 
------------------- Курсор глобальный -------------------------------
declare StudentsG CURSOR GLOBAL for select NAME, IDGROUP from STUDENT;
declare @name nvarchar(50), @group int;      
	OPEN StudentsG;	  
	fetch StudentsG into @name, @group; 	
      print '1. '+ @name + ', группа: ' + cast(@group as varchar(6));   
      go
declare @name nvarchar(50), @group int;     	
	fetch StudentsG into @name, @group; 	
    print '2. '+ @name + ', группа: '+ cast(@group as varchar(6));  
CLOSE StudentsG;
DEALLOCATE StudentsG;

--ex.3
------------------- Курсор статический -------------------------------
declare progStatic cursor local static for SELECT SUBJECT, PDATE, NOTE FROM PROGRESS where SUBJECT = 'КГ';
declare @tid char(10), @tnm char(40), @tgn char(1);

open progStatic
print   'Количество строк : ' + cast(@@CURSOR_ROWS as varchar(5)); 
UPDATE PROGRESS set NOTE = 5 where IDSTUDENT = '1020';
delete PROGRESS where IDSTUDENT = '1079';
insert PROGRESS (SUBJECT, IDSTUDENT, PDATE, NOTE) 
                 values ('КГ', 1079, '2013-01-10', 10); 
FETCH progStatic into @tid, @tnm, @tgn;     
while @@fetch_status = 0                                    
     begin 
         print @tid + ' '+ @tnm + ' '+ @tgn;      
         fetch progStatic into @tid, @tnm, @tgn; 
      end;          
CLOSE progStatic;
------------------- Курсор динамический -------------------------------
go
declare progDynamic cursor local dynamic for SELECT SUBJECT, PDATE, NOTE FROM PROGRESS where SUBJECT = 'КГ';
declare @tid char(10), @tnm char(40), @tgn char(1);

open progDynamic
print   'Количество строк : ' + cast(@@CURSOR_ROWS as varchar(5)); 
UPDATE PROGRESS set NOTE = 5 where IDSTUDENT = '1020';
delete PROGRESS where IDSTUDENT = '1079';
insert PROGRESS (SUBJECT, IDSTUDENT, PDATE, NOTE) 
                 values ('КГ', 1079, '2013-01-10', 10); 
FETCH progDynamic into @tid, @tnm, @tgn;     
while @@fetch_status = 0                                    
     begin 
         print @tid + ' '+ @tnm + ' '+ @tgn;      
         fetch progDynamic into @tid, @tnm, @tgn; 
      end;          
CLOSE progDynamic;

--ex.4
declare progScroll cursor local dynamic scroll
	for select ROW_NUMBER() over (order by IDSTUDENT) Номер,
	* from PROGRESS;
declare @number varchar(100), @sub varchar(10), @idstudent varchar(6), @pdate varchar (11), @note varchar (2)

OPEN progScroll
FETCH progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Первая выбранная строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);

FETCH LAST from progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Последняя строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);

FETCH RELATIVE -1  from progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Первая до предыдущей строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);

FETCH ABSOLUTE 2  from progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Вторая с начала строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);

FETCH RELATIVE 1  from progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Первая после предыдущей строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);

FETCH ABSOLUTE -2  from progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Вторая с конца строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);
close progScroll

--ex.5
use tempdb;
CREATE TABLE #EXAMPLE
(
	ID int identity(1,1),
	WORD varchar(100)
);
INSERT INTO #EXAMPLE values ('Яблоко'),('Груша'),('Апельсин'),('Мандарин'),('Вишня'),('Клубника'),('Клюква');

select * from #EXAMPLE

declare cursorCurrentOf cursor local dynamic for select * from #EXAMPLE FOR UPDATE;
declare @id varchar(10), @word varchar(100);

OPEN cursorCurrentOf
fetch cursorCurrentOf into @id, @word;
print @id + '-' + @word;
DELETE #EXAMPLE where CURRENT OF cursorCurrentOf;
fetch  cursorCurrentOf into @id,@word;
UPDATE #EXAMPLE set WORD += ' - updated' where CURRENT OF cursorCurrentOf;
print @id + '-' + @word;
close cursorCurrentOf;

OPEN cursorCurrentOf
while(@@FETCH_STATUS = 0)
	begin
		fetch cursorCurrentOf into @id,@word;
		print @id + '-' + @word;
	end;
close cursorCurrentOf;

DROP TABLE #EXAMPLE;

--ex.6
----------------------- 6.1 -------------------------
go
use UNIVER;
--select * from PROGRESS
--INSERT INTO PROGRESS (SUBJECT, IDSTUDENT, PDATE, NOTE) values ('КГ', 1025,  '06.05.2013', 3);
--delete PROGRESS where IDSTUDENT = 1025

declare ProgStud cursor local dynamic for
	SELECT p.IDSTUDENT, s.NAME, p.NOTE FROM PROGRESS p
	JOIN STUDENT s ON s.IDSTUDENT = p.IDSTUDENT
	WHERE p.NOTE < 4
		FOR UPDATE
declare @id varchar(5), @nm varchar(50), @nt int

OPEN ProgStud
FETCH ProgStud INTO @id, @nm, @nt
print @id + ': ' + @nm + ' (оценка ' + cast(@nt as varchar) + ')'
DELETE PROGRESS WHERE CURRENT OF ProgStud
CLOSE ProgStud


----------------------- 6.2 -------------------------
go
select * from PROGRESS
declare Prog CURSOR LOCAL DYNAMIC FOR
	SELECT p.IDSTUDENT, s.NAME, p.NOTE FROM PROGRESS p
	JOIN STUDENT s ON s.IDSTUDENT = p.IDSTUDENT
	WHERE p.IDSTUDENT = 1021
		FOR UPDATE
declare @id varchar(5), @nm varchar(50), @nt int

OPEN Prog
FETCH Prog INTO @id, @nm, @nt
UPDATE PROGRESS SET NOTE = NOTE - 1 WHERE CURRENT OF Prog
print @id + ': ' + @nm + ' (была оценка ' + cast(@nt as varchar) + ')'
CLOSE Prog
select * from PROGRESS