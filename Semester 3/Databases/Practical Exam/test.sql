-- CREATE DATABASE Test
-- USE [Test]


drop table Services
drop table DentistTreatmentPlan
drop table Dentists
drop table Appointments
drop table Patients
drop table TreatmentPlans


create table Patients(
    PatientName varchar(255) unique not null,
    Phone int,
    Email varchar(255),
    Addr varchar(255),
    primary key(PatientName)
);

create table TreatmentPlans(
    TName varchar(255) unique not null,
    Duration int,
    Fee  int,
    primary key(TName)
);

create table Services(
    ServiceName varchar(255) unique not null,
    Price int,
    TreatmentPlan varchar(255) foreign key references TreatmentPlans(TName),
    primary key(ServiceName)
);

create table Appointments(
    AppID int not null primary key,
    PatientName varchar(255) not null,
    TName varchar(255) not null,
    AYear varchar(255),
    AMonth varchar(255),
    ADay varchar(255),
    foreign key(PatientName) references Patients(PatientName),
    foreign key(TName) references TreatmentPlans(TName)
);


create table Dentists(
    DentistName varchar(255) unique not null,
    Phone int,
    Email varchar(255),
    primary key(DentistName),
    AppID int foreign key references Appointments(AppID) on delete cascade 
);

create table DentistTreatmentPlan(
    DTPid int IDENTITY(1,1) not null primary key,
    DentistName varchar(255) not null,
    TName varchar(255) not null,
    foreign key(DentistName) references Dentists(DentistName),
    foreign key(TName) references TreatmentPlans(TName)
);


-- Implement a stored procedure that receives the details of a patient and
--  adds the patient in the database. If there is already a patient with the 
--  same name, the procedure should return an error message and it
--  should not add the patient in the database.
GO
create or alter procedure spAddPatient
    @PatientName varchar(255),
    @Phone int,
    @Email varchar(255),
    @Addr varchar(255)
as
begin
    if exists (select * from Patients where PatientName = @PatientName)
    begin
        raiserror('Patient already exists', 16, 1)
    end
    else
    begin
        insert into Patients values (@PatientName, @Phone, @Email, @Addr)
    end
end
GO

exec spAddPatient 'Patient1', 123456789, 'a@b.c', 'addr1'
select * from Patients

-- create a view that displays the name of the patients that have appointments
-- scheduled for february 2024
GO
create or alter view vPatientsWithAppointments
as
select PatientName
from Appointments
where AYear = '2024' and AMonth = 'February'
GO

insert into Patients values ('Patient2', 123456789, 'a@b.c', 'addr1')
insert into TreatmentPlans values ('T1', 1, 1)
insert into Appointments values (1, 'Patient2', 'T1', '2024', 'February', '1')

select * from vPatientsWithAppointments
select * from Patients


-- implement a function that returns the dentist with the highest number of treatment plans
-- prescribed during appointments within a time period. The period of time is represented by a
-- start time and end time, which are function parameters. 
GO
CREATE OR ALTER FUNCTION fnGetDentistWithHighestNumberOfTreatmentPlans
    (@StartYear VARCHAR(255), @StartMonth VARCHAR(255), @StartDay VARCHAR(255),
    @EndYear VARCHAR(255), @EndMonth VARCHAR(255), @EndDay VARCHAR(255))
RETURNS VARCHAR(255)
AS
BEGIN
    DECLARE @DentistName VARCHAR(255)
    SELECT TOP 1 @DentistName = d.DentistName
    FROM Dentists d
    JOIN DentistTreatmentPlan dt ON d.DentistName = dt.DentistName
    JOIN TreatmentPlans tp ON dt.TName = tp.TName
    JOIN Appointments a ON tp.TName = a.TName
    WHERE a.AYear >= @StartYear AND a.AMonth >= @StartMonth AND a.ADay >= @StartDay
        AND a.AYear <= @EndYear AND a.AMonth <= @EndMonth AND a.ADay <= @EndDay
    GROUP BY d.DentistName
    ORDER BY COUNT(*) DESC
    RETURN @DentistName
END
GO


insert into TreatmentPlans values ('T2', 1, 1)
insert into Appointments values (2, 'Patient1', 'T2', '2024', 'February', '1')
insert into Dentists values ('Dentist1', 123456789, 'a@b.c', 2)
insert into DentistTreatmentPlan values ('Dentist1', 'T2')

insert into TreatmentPlans values ('T3', 1, 1)
insert into Appointments values (3, 'Patient1', 'T3', '2024', 'February', '1')
insert into DentistTreatmentPlan values ('Dentist1', 'T3')

insert into TreatmentPlans values ('T4', 1, 1)
insert into Appointments values (4, 'Patient1', 'T4', '2024', 'February', '1')
insert into Dentists values ('Dentist3', 123456789, 'a@b.c', 1)
insert into DentistTreatmentPlan values ('Dentist3', 'T4')

select * from Dentists
select dbo.fnGetDentistWithHighestNumberOfTreatmentPlans('2024', 'February', '1', '2024', 'February', '1')