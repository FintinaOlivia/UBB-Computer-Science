-- CREATE DATABASE ASSIGNMENT4;
-- USE ASSIGNMENT4;

CREATE TABLE Players (
    PlayerID INT PRIMARY KEY,
    PlayerName VARCHAR(255)
);

CREATE TABLE Game(
    GameID INT PRIMARY KEY,
    PlayerID INT,
    FOREIGN KEY (PlayerID) REFERENCES Players(PlayerID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE GameCategories(
    CategoryID INT PRIMARY KEY,
    CategoryName VARCHAR(255)
);

CREATE TABLE Locations(
    LocationID INT PRIMARY KEY,
    LocationName VARCHAR(255)
);

CREATE TABLE NPCs(
    NPCID INT PRIMARY KEY,
    NPCName VARCHAR(255)
);

CREATE TABLE NPCsPerLocation(
    NPCID INT,
    LocationID INT,
    FOREIGN KEY (NPCID) REFERENCES NPCs(NPCID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (LocationID) REFERENCES Locations(LocationID) ON DELETE CASCADE ON UPDATE CASCADE
);

SELECT * FROM Players;
SELECT * FROM Game;
SELECT * FROM GameCategories;
SELECT * FROM Locations;
SELECT * FROM NPCs;
SELECT * FROM NPCsPerLocation;

DROP TABLE NPCsPerLocation;
DROP TABLE NPCs;
DROP TABLE Locations;
DROP TABLE GameCategories;
DROP TABLE Game;
DROP TABLE Players;


IF EXISTS (SELECT * FROM dbo.sysobjects WHERE id = object_id(N'[FK_TestRunTables_Tables]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestRunTables] DROP CONSTRAINT FK_TestRunTables_Tables
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestTables_Tables]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestTables] DROP CONSTRAINT FK_TestTables_Tables
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestRunTables_TestRuns]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestRunTables] DROP CONSTRAINT FK_TestRunTables_TestRuns
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestRunViews_TestRuns]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestRunViews] DROP CONSTRAINT FK_TestRunViews_TestRuns
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestTables_Tests]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestTables] DROP CONSTRAINT FK_TestTables_Tests
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestViews_Tests]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestViews] DROP CONSTRAINT FK_TestViews_Tests
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestRunViews_Views]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestRunViews] DROP CONSTRAINT FK_TestRunViews_Views
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestViews_Views]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [TestViews] DROP CONSTRAINT FK_TestViews_Views
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[Tables]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [Tables]
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[TestRunTables]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [TestRunTables]
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[TestRunViews]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [TestRunViews]
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[TestRuns]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [TestRuns]
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[TestTables]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [TestTables]
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[TestViews]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [TestViews]
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[Tests]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [Tests]
GO


if exists (select * from dbo.sysobjects where id = object_id(N'[Views]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [Views]
GO


CREATE TABLE [Tables] (
	[TableID] [int] IDENTITY (1, 1) NOT NULL ,
	[Name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL 
) ON [PRIMARY]
GO


CREATE TABLE [TestRunTables] (
	[TestRunID] [int] NOT NULL ,
	[TableID] [int] NOT NULL ,
	[StartAt] [datetime] NOT NULL ,
	[EndAt] [datetime] NOT NULL 
) ON [PRIMARY]
GO


CREATE TABLE [TestRunViews] (
	[TestRunID] [int] NOT NULL ,
	[ViewID] [int] NOT NULL ,
	[StartAt] [datetime] NOT NULL ,
	[EndAt] [datetime] NOT NULL 
) ON [PRIMARY]
GO


CREATE TABLE [TestRuns] (
	[TestRunID] [int] IDENTITY (1, 1) NOT NULL ,
	[Description] [nvarchar] (2000) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[StartAt] [datetime] NULL ,
	[EndAt] [datetime] NULL 
) ON [PRIMARY]
GO


CREATE TABLE [TestTables] (
	[TestID] [int] NOT NULL ,
	[TableID] [int] NOT NULL ,
	[NoOfRows] [int] NOT NULL ,
	[Position] [int] NOT NULL 
) ON [PRIMARY]
GO


CREATE TABLE [TestViews] (
	[TestID] [int] NOT NULL ,
	[ViewID] [int] NOT NULL 
) ON [PRIMARY]
GO


CREATE TABLE [Tests] (
	[TestID] [int] IDENTITY (1, 1) NOT NULL ,
	[Name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL 
) ON [PRIMARY]
GO


CREATE TABLE [Views] (
	[ViewID] [int] IDENTITY (1, 1) NOT NULL ,
	[Name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL 
) ON [PRIMARY]
GO


ALTER TABLE [Tables] WITH NOCHECK ADD 
	CONSTRAINT [PK_Tables] PRIMARY KEY  CLUSTERED 
	(
		[TableID]
	)  ON [PRIMARY] 
GO


ALTER TABLE [TestRunTables] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestRunTables] PRIMARY KEY  CLUSTERED 
	(
		[TestRunID],
		[TableID]
	)  ON [PRIMARY] 
GO


ALTER TABLE [TestRunViews] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestRunViews] PRIMARY KEY  CLUSTERED 
	(
		[TestRunID],
		[ViewID]
	)  ON [PRIMARY] 
GO


ALTER TABLE [TestRuns] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestRuns] PRIMARY KEY  CLUSTERED 
	(
		[TestRunID]
	)  ON [PRIMARY] 
GO


ALTER TABLE [TestTables] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestTables] PRIMARY KEY  CLUSTERED 
	(
		[TestID],
		[TableID]
	)  ON [PRIMARY] 
GO


ALTER TABLE [TestViews] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestViews] PRIMARY KEY  CLUSTERED 
	(
		[TestID],
		[ViewID]
	)  ON [PRIMARY] 
GO


ALTER TABLE [Tests] WITH NOCHECK ADD 
	CONSTRAINT [PK_Tests] PRIMARY KEY  CLUSTERED 
	(
		[TestID]
	)  ON [PRIMARY] 
GO


ALTER TABLE [Views] WITH NOCHECK ADD 
	CONSTRAINT [PK_Views] PRIMARY KEY  CLUSTERED 
	(
		[ViewID]
	)  ON [PRIMARY] 
GO


ALTER TABLE [TestRunTables] ADD 
	CONSTRAINT [FK_TestRunTables_Tables] FOREIGN KEY 
	(
		[TableID]
	) REFERENCES [Tables] (
		[TableID]
	) ON DELETE CASCADE  ON UPDATE CASCADE ,
	CONSTRAINT [FK_TestRunTables_TestRuns] FOREIGN KEY 
	(
		[TestRunID]
	) REFERENCES [TestRuns] (
		[TestRunID]
	) ON DELETE CASCADE  ON UPDATE CASCADE 
GO


ALTER TABLE [TestRunViews] ADD 
	CONSTRAINT [FK_TestRunViews_TestRuns] FOREIGN KEY 
	(
		[TestRunID]
	) REFERENCES [TestRuns] (
		[TestRunID]
	) ON DELETE CASCADE  ON UPDATE CASCADE ,
	CONSTRAINT [FK_TestRunViews_Views] FOREIGN KEY 
	(
		[ViewID]
	) REFERENCES [Views] (
		[ViewID]
	) ON DELETE CASCADE  ON UPDATE CASCADE 
GO


ALTER TABLE [TestTables] ADD 
	CONSTRAINT [FK_TestTables_Tables] FOREIGN KEY 
	(
		[TableID]
	) REFERENCES [Tables] (
		[TableID]
	) ON DELETE CASCADE  ON UPDATE CASCADE ,
	CONSTRAINT [FK_TestTables_Tests] FOREIGN KEY 
	(
		[TestID]
	) REFERENCES [Tests] (
		[TestID]
	) ON DELETE CASCADE  ON UPDATE CASCADE 
GO


ALTER TABLE [TestViews] ADD 
CONSTRAINT [FK_TestViews_Tests] FOREIGN KEY 
	(
		[TestID]
	) REFERENCES [Tests] (
		[TestID]
	),

	CONSTRAINT [FK_TestViews_Views] FOREIGN KEY 
	(
		[ViewID]
	) REFERENCES [Views] (
		[ViewID]
	)
GO


------------------PROCEDURES---------------------------

create or alter procedure addToTables (@tableName varchar(50)) as
    if @tableName in (select Name from Tables) begin
        print 'Table already present in Tables'
        return
    end
    if @tableName not in (select TABLE_NAME from INFORMATION_SCHEMA.TABLES) begin
        print 'Table not present in the database'
        return
    end
    insert into Tables (Name) values (@tableName)
GO

create or alter procedure addToViews (@viewName varchar(50)) as
    if @viewName in (select Name from Views) begin
        print 'View already present in Views'
        return
    end
    if @viewName not in (select TABLE_NAME from INFORMATION_SCHEMA.VIEWS) begin
        print 'View not present in the database'
        return
    end
    insert into Views (Name) values (@viewName)
GO

create or alter procedure addToTests (@testName varchar(50)) as
    if @testName in (select Name from Tests) begin
        print 'Test already present in Tests'
        return
    end
    insert into Tests (Name) values (@testName)
GO

create or alter procedure connectTableToTest (@tableName varchar(50), @testName varchar(50), @rows int, @pos int) as
    if @tableName not in (select Name from Tables) begin
        print 'Table not present in Tables'
        return
    end
    if @testName not in (select Name from Tests) begin
        print 'Tests not present in Tests'
        return
    end
    if exists(
        select *
        from TestTables T1 join Tests T2 on T1.TestID = T2.TestID
        where T2.Name=@testName and Position=@pos
        ) begin
        print 'Position provided conflicts with previous positions'
        return
    end
    insert into TestTables (TestID, TableID, NoOfRows, Position) values (
        (select Tests.TestID from Tests where Name=@testName),
        (select Tables.TableID from Tables where Name=@tableName),
        @rows,
        @pos
    )
GO

create or alter procedure connectViewToTest (@viewName varchar(50), @testName varchar(50)) as
    if @viewName not in (select Name from Views) begin
        print 'View not present in Views'
        return
    end
    if @testName not in (select Name from Tests) begin
        print 'Tests not present in Tests'
        return
    end
    insert into TestViews (TestID, ViewID) values (
        (select Tests.TestID from Tests where Name=@testName),
        (select Views.ViewID from Views where Name=@viewName)
    )
GO

create or alter procedure runTest (@testName varchar(50)) as
    if @testName not in (select Name from Tests) begin
        print 'test not in Tests'
        return
    end
    declare @command varchar(100)
    declare @testStartTime datetime2
    declare @startTime datetime2
    declare @endTime datetime2
    declare @table varchar(50)
    declare @rows int
    declare @pos int
    declare @view varchar(50)
    declare @testId int
    select @testId=TestID from Tests where Name=@testName
    declare @testRunId int
    set @testRunId = (select max(TestRunID)+1 from TestRuns)
    if @testRunId is null
        set @testRunId = 0
    declare tableCursor cursor scroll for
        select T1.Name, T2.NoOfRows, T2.Position
        from Tables T1 join TestTables T2 on T1.TableID = T2.TableID
        where T2.TestID = @testId
        order by T2.Position
    declare viewCursor cursor for
        select V.Name
        from Views V join TestViews TV on V.ViewID = TV.ViewID
        where TV.TestID = @testId

    set @testStartTime = sysdatetime()
    open tableCursor
    fetch last from tableCursor into @table, @rows, @pos
    while @@FETCH_STATUS = 0 begin
        exec ('delete from '+ @table)
        fetch prior from tableCursor into @table, @rows, @pos
    end
    close tableCursor

    open tableCursor
    SET IDENTITY_INSERT TestRuns ON
    insert into TestRuns (TestRunID, Description, StartAt)values (@testRunId, 'Tests results for: ' + @testName, @testStartTime)
    SET IDENTITY_INSERT TestRuns OFF
    fetch tableCursor into @table, @rows, @pos
    while @@FETCH_STATUS = 0 begin
        set @command = 'populateTable' + @table
        if @command not in (select ROUTINE_NAME from INFORMATION_SCHEMA.ROUTINES) begin
            print @command + 'does not exist'
            return
        end
        set @startTime = sysdatetime()
        exec @command @rows
        set @endTime = sysdatetime()
        insert into TestRunTables (TestRunID, TableId, StartAt, EndAt) values (@testRunId, (select TableID from Tables where Name=@table), @startTime, @endTime)
        fetch tableCursor into @table, @rows, @pos
    end
    close tableCursor
    deallocate tableCursor

    open viewCursor
    fetch viewCursor into @view
    while @@FETCH_STATUS = 0 begin
        set @command = 'select * from ' + @view
        set @startTime = sysdatetime()
        exec (@command)
        set @endTime = sysdatetime()
        insert into TestRunViews (TestRunID, ViewID, StartAt, EndAt) values (@testRunId, (select ViewID from Views where Name=@view), @startTime, @endTime)
        fetch viewCursor into @view
    end
    close viewCursor
    deallocate viewCursor

    update TestRuns
    set EndAt=sysdatetime()
    where TestRunID = @testRunId
GO

-- Test 1 -- 
--a table with a single-column primary key and no foreign keys;

-- Select statement operating on one table
CREATE VIEW GameCategoriesView AS
    SELECT * FROM GameCategories
GO


-- populating the table with a large enough dataset
CREATE PROCEDURE populateTableGameCategories(@rows INT) AS
    DECLARE @i INT
    SET @i = 0
    WHILE @i < @rows BEGIN
        INSERT INTO GameCategories VALUES(@i, 'GameCategory' + CAST(@i AS VARCHAR(255)))
        SET @i = @i + 1
    END
GO

EXEC addToTables 'GameCategories'
EXEC addToViews 'GameCategoriesView'
EXEC addToTests 'Test1'
EXEC connectTableToTest 'GameCategories', 'Test1', 1000, 1
EXEC connectViewToTest 'GameCategoriesView', 'Test1'
EXEC runTest 'Test1'
GO


-- Test 2 --

-- a table with a single-column primary key and a single-column foreign key;

-- a view with a SELECT statement that operates on at least 2 different tables 
-- and contains at least one JOIN operator;
CREATE OR ALTER VIEW GameView AS
    SELECT GameID as 'Game ID', PlayerName as 'Player Name'
    FROM Game G INNER JOIN Players P ON G.PlayerID = P.PlayerID
GO

SELECT * FROM GameView
GO

-- populating the tables with a large enough dataset
CREATE OR ALTER PROCEDURE populateTablePlayers(@rows INT) AS
    DECLARE @i INT
    SET @i = 0
    WHILE @i < @rows BEGIN
        INSERT INTO Players VALUES(@i, 'Player' + CAST(@i AS VARCHAR(255)))
        SET @i = @i + 1
    END
GO

DELETE FROM Players
EXEC populateTablePlayers 15
SELECT * FROM Players
GO

CREATE OR ALTER PROCEDURE populateTableGame(@rows INT) AS
    DELETE FROM Game
    DECLARE @i INT
    SET @i = 0
    WHILE @i < @rows BEGIN
        INSERT INTO Game VALUES(@i, @i)
        SET @i = @i + 1
    END
GO

EXEC populateTableGame 15
SELECT * FROM Game

EXEC addToTests 'Test2'

EXEC addToTables 'Players'
EXEC addToTables 'Game'

EXEC addToViews 'GameView'

EXEC connectTableToTest 'Players', 'Test2', 1000, 2
EXEC connectTableToTest 'Game', 'Test2', 1000, 3

EXEC connectViewToTest 'GameView', 'Test2'

EXEC runTest 'Test2'
GO

----------- Test 3 -------------

-- a table with a multi-column primary key and no foreign keys;

-- a view with a SELECT statement that operates on at least 2 different tables
-- contains at least one JOIN operator and a GROUP BY operator;

CREATE VIEW NPCsPerLocationView AS
	SELECT LocationName as 'Location Name', COUNT(NPCID) as 'Number of NPCs'
	FROM NPCsPerLocation NPL INNER JOIN Locations L ON NPL.LocationID = L.LocationID
	GROUP BY LocationName
GO

-- populating the tables with a large enough dataset
CREATE OR ALTER PROCEDURE populateTableLocations(@rows INT) AS
	DECLARE @i INT
	SET @i = 0
	WHILE @i < @rows BEGIN
		INSERT INTO Locations VALUES(@i, 'Location' + CAST(@i AS VARCHAR(255)))
		SET @i = @i + 1
	END
GO

CREATE OR ALTER PROCEDURE populateTableNPCs(@rows INT) AS
	DECLARE @i INT
	SET @i = 0
	WHILE @i < @rows BEGIN
		INSERT INTO NPCs VALUES(@i, 'NPC' + CAST(@i AS VARCHAR(255)))
		SET @i = @i + 1
	END
GO

CREATE OR ALTER PROCEDURE populateTableNPCsPerLocation(@rows INT) AS
	DECLARE @i INT
	SET @i = 0
	WHILE @i < @rows BEGIN
		INSERT INTO NPCsPerLocation VALUES(@i, @i)
		SET @i = @i + 1
	END
GO

EXEC addToTables 'Locations'
EXEC addToTables 'NPCs'
EXEC addToTables 'NPCsPerLocation'

EXEC addToViews 'NPCsPerLocationView'

EXEC addToTests 'Test3'

EXEC connectTableToTest 'Locations', 'Test3', 1000, 4
EXEC connectTableToTest 'NPCs', 'Test3', 1000, 5
EXEC connectTableToTest 'NPCsPerLocation', 'Test3', 1000, 6

EXEC connectViewToTest 'NPCsPerLocationView', 'Test3'

EXEC runTest 'Test3'

SELECT * FROM TestRuns
SELECT * FROM TestRunTables
SELECT * FROM TestRunViews