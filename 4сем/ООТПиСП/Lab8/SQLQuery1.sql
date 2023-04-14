select * from PersonalBill where FIO like 'Руинер%'
select * from Owner;

create procedure Find_bill_By_Surname @srnm nvarchar(15)
as
begin
set @srnm = @srnm + '%'
select PersonalBill.Id, PersonalBill.FIO,Owner.birthDate, Owner.wallet, PersonalBill.town from 
PersonalBill inner join Owner on PersonalBill.FIO = Owner.FIO
where  PersonalBill.FIO like @srnm;
end;

exec Find_bill_By_Surname @srnm='Руинер';