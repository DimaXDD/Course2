use master;
CREATE database UNIVER on primary
(
	name = N'UNIVER_mdf', filename = N'E:\2_курс\4сем\БД\Lab4\UNIVER_mdf.mdf',
	size = 1024Kb, maxsize=UNLIMITED, filegrowth = 1024Kb
),
(
	name = N'UNIVER_ndf', filename = N'E:\2_курс\4сем\БД\Lab4\UNIVER_ndf.mdf',
	size = 1024Kb, maxsize=UNLIMITED, filegrowth = 25%
)
log on
(
	name = N'UNIVER_log', filename = N'E:\2_курс\4сем\БД\Lab4\UNIVER_log.ldf',
	size = 1024Kb, maxsize = 2048Gb, filegrowth = 10%
)
go