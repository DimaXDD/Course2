USE [UNIVER]
GO
/****** Object:  StoredProcedure [dbo].[PSUBJECT]    Script Date: 08.05.2023 22:14:10 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER procedure [dbo].[PSUBJECT] @p varchar(20), @c int output
as
begin
	set nocount on;
	select s.SUBJECT Код, s.SUBJECT_NAME Дисциплина, s.PULPIT Кафедра from SUBJECT s
	set @c = (select count(*) from SUBJECT where SUBJECT.PULPIT = @p);

	print 'параметры: @p = ' + @p + ',@c = ' + cast(@c as varchar(3));
	declare @k int = (select count(*) from SUBJECT);
	return @k ;
end