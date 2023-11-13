--use [DnD]

------------ Droppers ----------------------
drop table CharacterInventory
drop table CharacterAchievements
drop table CharacterAdventure
drop table NPCs
drop table Locations
drop table Quests
drop table Items
drop table Monsters
drop table Adventures
drop table Campaigns
drop table Characters
drop table Players

-- Create the Players table
CREATE TABLE Players (
    PlayerID INT PRIMARY KEY,
    PlayerName VARCHAR(255),
    ContactInfo VARCHAR(255),
    Notes TEXT
);

-- Create the Characters table
CREATE TABLE Characters (
    CharacterID INT PRIMARY KEY,
    PlayerID INT,
    CharacterName VARCHAR(255),
    Race VARCHAR(255),
    Class VARCHAR(255),
    Level INT,
    Attributes TEXT,
    FOREIGN KEY (PlayerID) REFERENCES Players(PlayerID) ON DELETE CASCADE
);

-- Create the Campaigns table
CREATE TABLE Campaigns (
    CampaignID INT PRIMARY KEY,
    CampaignName VARCHAR(255),
    StartDate DATE,
    EndDate DATE,
    Notes TEXT
);

-- Create the Adventures table
CREATE TABLE Adventures (
    AdventureID INT PRIMARY KEY,
    CampaignID INT,
    AdventureName VARCHAR(255),
    SessionDate DATE,
    Description TEXT,
    FOREIGN KEY (CampaignID) REFERENCES Campaigns(CampaignID) ON DELETE CASCADE
);

-- Create the Monsters table
CREATE TABLE Monsters (
    MonsterID INT PRIMARY KEY,
    MonsterName VARCHAR(255),
    Stats TEXT,
    Abilities TEXT
);


-- Create the Items table
CREATE TABLE Items (
    ItemID INT PRIMARY KEY,
    ItemName VARCHAR(255),
    ItemType VARCHAR(255),
    Description TEXT,
    Owner INT, -- Reference to CharacterID
    FOREIGN KEY (Owner) REFERENCES Characters(CharacterID) ON DELETE CASCADE
);

-- Create the Quests table
CREATE TABLE Quests (
    QuestID INT PRIMARY KEY,
    QuestName VARCHAR(255),
    Description TEXT,
    Reward VARCHAR(255)
);

-- Create the Locations table
CREATE TABLE Locations (
    LocationID INT PRIMARY KEY,
    LocationName VARCHAR(255),
    Description TEXT,
    NotableFeatures TEXT
	
);

-- Create the NPCs table
CREATE TABLE NPCs (
    NPCID INT PRIMARY KEY,
	LocationID INT,
    NPCName VARCHAR(255),
    Role VARCHAR(255),
	Level INT,
	FOREIGN KEY (LocationID) REFERENCES Locations(LocationID) ON DELETE CASCADE
);

CREATE TABLE CharacterAdventure (
    CharacterAdventureID INT PRIMARY KEY,
    CharacterID INT,
    AdventureID INT,
    FOREIGN KEY (CharacterID) REFERENCES Characters(CharacterID) ON DELETE CASCADE,
    FOREIGN KEY (AdventureID) REFERENCES Adventures(AdventureID) ON DELETE CASCADE
);

CREATE TABLE CharacterInventory (
    InventoryID INT PRIMARY KEY,
    CharacterID INT,
    ItemID INT,
    FOREIGN KEY (CharacterID) REFERENCES Characters(CharacterID) ON DELETE CASCADE,
    FOREIGN KEY (ItemID) REFERENCES Items(ItemID) 
);

CREATE TABLE CharacterAchievements (
    AchievementID INT PRIMARY KEY,
    CharacterID INT, -- primary key with both IDs 
    QuestID INT,
    FOREIGN KEY (CharacterID) REFERENCES Characters(CharacterID) ON DELETE CASCADE,
    FOREIGN KEY (QuestID) REFERENCES Quests(QuestID) ON DELETE CASCADE
);

----------- Inserting Data -----------------------

INSERT INTO Players (PlayerID, PlayerName, ContactInfo, Notes)
VALUES
  (1, 'John Doe', 'john@example.com', 'New player added'),
  (2, 'Alice Smith', 'alice@example.com', 'Experienced player'),
  (3, 'Bob Johnson', 'bob@example.com', 'Casual player'),
  (4, 'Eva White', 'eva@example.com', 'Role-playing enthusiast'),
  (5, 'David Brown', 'david@example.com', 'Newbie to DnD'),
  (6, 'Linda Davis', 'linda@example.com', 'Veteran gamer'),
  (7, 'Michael Wilson', 'michael@example.com', 'Game master'),
  (8, 'Sarah Lee', 'sarah@example.com', 'Adventure seeker'),
  (9, 'Richard Jones', 'richard@example.com', 'Strategic thinker'),
  (10, 'Laura Moore', 'laura@example.com', 'Role-play enthusiast'),
  (11, 'Fintina Olivia', 'olivia@example.com', 'Average bardic inspiration overuser'),
  (12, 'Florescu Daria', 'daria_verde@example.com', 'To dm or not to dm'),
  (13, 'Fenesan Daria', 'daria_rosu@example.com', 'Birb.'),
  (14, 'Geanovu Medeea', 'mede@example.com', 'Tragically in love with a paradimensional asshole'),
  (15, 'Gheorghe Octavian', 'octabro@example.com', 'Sharpening the Edge(tm) everyday');

INSERT INTO Characters (CharacterID, PlayerID, CharacterName, Race, Class, Level, Attributes)
VALUES
  (1, 1, 'Sir Aldric the Brave', 'Human', 'Warrior', 3, 'Strength: 12, Dexterity: 10, Constitution: 14, Intelligence: 8, Wisdom: 10, Charisma: 12'),
  (2, 1, 'Elowen Moonshadow', 'Elf', 'Wizard', 5, 'Strength: 8, Dexterity: 16, Constitution: 12, Intelligence: 18, Wisdom: 14, Charisma: 10'),
  (3, 2, 'Bromli Stonebeard', 'Dwarf', 'Rogue', 2, 'Strength: 14, Dexterity: 16, Constitution: 16, Intelligence: 10, Wisdom: 12, Charisma: 8'),
  (4, 1, 'Grommash Thundertusk', 'Half-Orc', 'Barbarian', 4, 'Strength: 18, Dexterity: 10, Constitution: 16, Intelligence: 8, Wisdom: 10, Charisma: 12'),
  (5, 4, 'Lilith Darkfire', 'Tiefling', 'Sorcerer', 1, 'Strength: 8, Dexterity: 10, Constitution: 12, Intelligence: 14, Wisdom: 10, Charisma: 15'),
  (6, 5, 'Fizzlewhip Sprocketgear', 'Gnome', 'Bard', 2, 'Strength: 8, Dexterity: 14, Constitution: 12, Intelligence: 14, Wisdom: 10, Charisma: 16'),
  (7, 6, 'Elandra Windrider', 'Half-Elf', 'Cleric', 5, 'Strength: 10, Dexterity: 12, Constitution: 12, Intelligence: 10, Wisdom: 17, Charisma: 15'),
  (8, 7, 'Drakar Flameforge', 'Dragonborn', 'Cleric', 3, 'Strength: 14, Dexterity: 10, Constitution: 14, Intelligence: 10, Wisdom: 12, Charisma: 10'),
  (9, 8, 'Wilbur Greenfoot', 'Halfling', 'Ranger', 4, 'Strength: 8, Dexterity: 16, Constitution: 12, Intelligence: 10, Wisdom: 15, Charisma: 12'),
  (10, 9, 'Seraphina Dawnbringer', 'Aasimar', 'Monk', 2, 'Strength: 10, Dexterity: 14, Constitution: 10, Intelligence: 12, Wisdom: 14, Charisma: 16');

INSERT INTO Items (ItemID, ItemName, ItemType, Description, Owner)
VALUES
  (1, 'Sword of Valor', 'Weapon', 'A legendary sword with a history of heroism', 1),
  (2, 'Wizard s Robe', 'Armor', 'Magical robes that enhance spellcasting', 2),
  (3, 'Lockpick Set', 'Tool', 'High-quality lockpicking tools', 3),
  (4, 'Orcish Battle Axe', 'Weapon', 'A brutal orcish battle axe', 4),
  (5, 'Amulet of the Elements', 'Accessory', 'Enhances elemental magic', 5),
  (6, 'Bard s Lute', 'Instrument', 'A beautifully crafted musical instrument', 6),
  (7, 'Cleric s Holy Symbol', 'Accessory', 'Symbol of divine power', 7),
  (8, 'Dragon Scale Armor', 'Armor', 'Crafted from the scales of a slain dragon', 8),
  (9, 'Ranger s Bow', 'Weapon', 'A finely crafted bow for long-range attacks', 9),
  (10, 'Monk s Meditation Beads', 'Accessory', 'Aids in meditation and concentration', 10),
  (11, 'Potion of Healing', 'Consumable', 'Restores a small amount of health', NULL),
  (12, 'Scroll of Fireball', 'Scroll', 'Unleashes a powerful fire spell when read', NULL),
  (13, 'Plate Mail', 'Armor', 'Heavy armor for maximum protection', NULL),
  (14, 'Ring of Invisibility', 'Ring', 'Grants the wearer invisibility', NULL),
  (15, 'Staff of the Magi', 'Weapon', 'A powerful staff with various magical abilities', NULL),
  (16, 'Amulet of Strength', 'Accessory', 'Enhances the wearer s physical strength', NULL),
  (17, 'Dagger of Venom', 'Weapon', 'A dagger coated with deadly poison', NULL),
  (18, 'Wand of Lightning Bolts', 'Wand', 'Casts powerful lightning spells', NULL),
  (19, 'Boots of Speed', 'Footwear', 'Increases the wearer s movement speed', NULL),
  (20, 'Elixir of Wisdom', 'Consumable', 'Enhances the consumer s wisdom', NULL),
  (21, 'Longbow of Accuracy', 'Weapon', 'Increases the accuracy of long-range attacks', NULL),
  (22, 'Helmet of Intellect', 'Headgear', 'Enhances the wearer s intelligence', NULL),
  (23, 'Ring of Regeneration', 'Ring', 'Slowly regenerates the wearer s health', NULL),
  (24, 'Scythe of Souls', 'Weapon', 'Steals the souls of defeated enemies', NULL),
  (25, 'Robe of the Archmage', 'Armor', 'Worn by legendary spellcasters', NULL),
  (26, 'Shield of Resilience', 'Shield', 'Provides high resistance to damage', NULL),
  (27, 'Gloves of Dexterity', 'Gloves', 'Enhances the wearer s dexterity', NULL),
  (28, 'Amulet of Protection', 'Accessory', 'Increases the wearer s defensive capabilities', NULL),
  (29, 'Sword of Vengeance', 'Weapon', 'Inflicts more damage with each enemy struck', NULL),
  (30, 'Cloak of Invisibility', 'Cloak', 'Renders the wearer invisible when hooded', NULL),
  (31, 'Hammer of Thunderbolts', 'Weapon', 'Channels the power of thunder and lightning', NULL),
  (32, 'Gauntlets of Ogre Strength', 'Gloves', 'Increases the wearer s strength to superhuman levels', NULL),
  (33, 'Helm of Telepathy', 'Headgear', 'Grants the ability to read thoughts', NULL),
  (34, 'Ring of Teleportation', 'Ring', 'Allows the wearer to teleport to known locations', NULL),
  (35, 'Bow of Venom', 'Weapon', 'Arrows are tipped with deadly poison', NULL),
  (36, 'Cloak of Elvenkind', 'Cloak', 'Grants the wearer stealth in natural surroundings', NULL),
  (37, 'Gloves of the Thief', 'Gloves', 'Enhances lockpicking and pickpocketing skills', NULL),
  (38, 'Crown of Charisma', 'Headgear', 'Enhances the wearer s charisma and social skills', NULL),
  (39, 'Necklace of Fire Resistance', 'Accessory', 'Provides immunity to fire-based attacks', NULL),
  (40, 'Sword of Excalibur', 'Weapon', 'A legendary sword of great power', NULL),
  (41, 'Robe of Elemental Protection', 'Armor', 'Resists the elements (fire, ice, lightning, etc.)', NULL),
  (42, 'Ring of Time Travel', 'Ring', 'Allows the wearer to briefly travel through time', NULL),
  (43, 'Staff of the Ice Mage', 'Weapon', 'Casts powerful ice spells', NULL),
  (44, 'Amulet of Luck', 'Accessory', 'Enhances the wearers luck and fortune', NULL),
  (45, 'Dagger of Shadows', 'Weapon', 'Allows the user to step into the shadow realm', NULL),
  (46, 'Shield of the Paladin', 'Shield', 'Blessed shield that provides divine protection', NULL),
  (47, 'Boots of Feather Fall', 'Footwear', 'Prevents fall damage by slowing descent', NULL),
  (48, 'Hood of Illusions', 'Headgear', 'Creates illusory duplicates of the wearer', NULL),
  (49, 'Bow of Storms', 'Weapon', 'Arrows summon storms and lightning strikes', NULL),
  (50, 'Cloak of the Wind', 'Cloak', 'Grants the wearer the ability to fly for short distances', NULL);

INSERT INTO Locations (LocationID, LocationName, Description, NotableFeatures)
VALUES
  (1, 'The Forgotten Caverns', 'A dark and hidden network of underground caves', 'Glowing mushrooms, secret chambers'),
  (2, 'Dragon s Lair', 'A desolate landscape with a looming dragon presence', 'Scorched earth, smoking ruins'),
  (3, 'Haunted Mansion', 'An eerie mansion with a ghostly reputation', 'Creaking floors, spectral apparitions'),
  (4, 'Orc Stronghold', 'A fortified encampment of fierce orcs', 'Spiked defenses, war banners'),
  (5, 'Enchanted Forest', 'A mystical forest where magic flows through the trees', 'Talking animals, ancient spells'),
  (6, 'Thieves Guild Hideout', 'A secretive hideout for the city\s underground', 'Hidden entrances, secret tunnels'),
  (7, 'Bandit Camp', 'A camp of bandits hiding stolen treasures', 'Stolen loot, wanted posters'),
  (8, 'Ancient Tomb', 'A long-forgotten tomb of an ancient king', 'Intricate carvings, cryptic inscriptions'),
  (9, 'Spiritual Nexus', 'A serene place for connecting with spirits', 'Meditation circles, ancient blessings'),
  (10, 'Temporal Anomaly', 'A rift in space-time with unpredictable consequences', 'Fluctuating realities, time portals');
 
INSERT INTO Monsters (MonsterID, MonsterName, Stats, Abilities)
VALUES
  (1, 'Goblin', 'Strength: 10, Dexterity: 14, Constitution: 12, ...', 'Stealth, Cunning, Poisonous Arrows'),
  (2, 'Dragon', 'Strength: 20, Dexterity: 10, Constitution: 18, ...', 'Fire Breath, Flight, Fearful Roar'),
  (3, 'Zombie', 'Strength: 12, Dexterity: 6, Constitution: 16, ...', 'Undead Resilience, Infectious Bite'),
  (4, 'Orc', 'Strength: 16, Dexterity: 10, Constitution: 14, ...', 'Brutal Strike, Aggression, Intimidation'),
  (5, 'Beholder', 'Strength: 12, Dexterity: 8, Constitution: 18, ...', 'Eye Rays, Anti-Magic Field, Levitation'),
  (6, 'Wight', 'Strength: 14, Dexterity: 12, Constitution: 14, ...', 'Life Drain, Fear Aura, Undead Resilience'),
  (7, 'Wyvern', 'Strength: 18, Dexterity: 14, Constitution: 16, ...', 'Poison Sting, Flight, Deadly Bite'),
  (8, 'Mimic', 'Strength: 16, Dexterity: 12, Constitution: 14, ...', 'Shape-shifting, Adhesive Grasp, Surprise Attack'),
  (9, 'Succubus', 'Strength: 10, Dexterity: 16, Constitution: 12, ...', 'Charm, Seduction, Telepathy'),
  (10, 'Lich', 'Strength: 12, Dexterity: 10, Constitution: 18, ...', 'Spellcasting, Immortality, Phylactery');


INSERT INTO NPCs (NPCID, LocationID, NPCName, Role, Level)
VALUES
  (1, 1, 'Grom the Goblin', 'Cunning Guide',2),
  (2, 2, 'Drakar the Dragon', 'Ancient Guardian',7),
  (3, 3, 'Eleanor the Ghost', 'Restless Spirit',4),
  (4, 4, 'Goruk the Orc Chieftain', 'Fearsome Leader',4),
  (5, 5, 'Eldara the Forest Enchantress', 'Mystical Protector',6),
  (6, 2, 'Silas the Master Thief', 'Underworld Boss',7),
  (7, 7, 'Roderick the Bandit King', 'Robber Baron',1),
  (8, 8, 'Arthus the Undying', 'Cursed Lich',3),
  (9, 5, 'Isolde the Spirit Medium', 'Peaceful Guide',2),
  (10, 5, 'Temporal Paradox Entity', 'Time Anomaly',7);

INSERT INTO Quests (QuestID, QuestName, Description, Reward)
VALUES
  (1, 'The Ancient Legacy', 'Retrieve the ancient artifact from the cave', 'Gold coins and magical items'),
  (2, 'The Gobling King', 'Slay the goblin king and rescue the villagers', 'Silver coins and a powerful weapon'),
  (3, 'Library of Alexandria', 'Solve the riddles of the ancient library', 'Knowledge and rare spell scrolls'),
  (4, 'The Orcs Are coming', 'Defend the town from the orc horde', 'Fame and land ownership'),
  (5, 'Mystery Is In The Air', 'Investigate the mysterious disappearances in the forest', 'Mystical artifacts and gems'),
  (6, 'Fedora and a Trenchoat', 'Infiltrate the thieves guild and expose their plans', 'Influence and a secret ally'),
  (7, 'The Crown is Mine!', 'Recover the stolen royal crown from the bandits', 'Gold coins and royal favor'),
  (8, 'The Lost Tomb', 'Explore the lost tomb of an ancient king', 'Ancient treasures and cursed artifacts'),
  (9, 'Preaches from a Lost Sister', 'Help the lost spirits find peace', 'Spiritual guidance and insight'),
  (10, 'Doctor Strange', 'Repair the rifts in the space-time continuum', 'Temporal knowledge and unique time-based artifacts');

INSERT INTO Campaigns (CampaignID, CampaignName, StartDate, EndDate, Notes)
VALUES
  (1, 'Campaign 1', '2023-01-01', '2023-12-31', 'A new campaign with adventures'),
  (2, 'Campaign 2', '2023-02-15', '2023-11-30', 'An epic quest awaits'),
  (3, 'Campaign 3', '2023-04-10', '2023-09-15', 'Mysteries of the unknown'),
  (4, 'Campaign 4', '2023-03-20', '2023-10-20', 'Dangerous encounters in the wilderness'),
  (5, 'Campaign 5', '2023-05-05', NULL, 'Intrigue and politics in the city'),
  (6, 'Campaign 6', '2023-06-15', NULL, 'Dark forces threatening the world'),
  (7, 'Campaign 7', '2023-07-01', NULL, 'Reclaiming lost relics'),
  (8, 'Campaign 8', '2023-08-10', NULL, 'Exploration and adventure in uncharted lands'),
  (9, 'Campaign 9', '2023-09-10', NULL, 'A journey into the abyss'),
  (10, 'Campaign 10', '2023-10-05', NULL, 'Time-traveling escapades');

INSERT INTO Adventures (AdventureID, CampaignID, AdventureName, SessionDate, Description)
VALUES
  (1, 1, 'Adventure 1', '2023-02-15', 'First adventure in Campaign 1'),
  (2, 1, 'Adventure 2', '2023-03-10', 'The quest for the lost relic'),
  (3, 2, 'Adventure 3', '2023-04-20', 'Battle against the ancient dragon'),
  (4, 2, 'Adventure 4', '2023-05-15', 'Investigating the haunted mansion'),
  (5, 3, 'Adventure 5', '2023-06-25', 'Survival in the wilderness'),
  (6, 2, 'Adventure 6', '2023-07-30', 'City under siege'),
  (7, 2, 'Adventure 7', '2023-08-10', 'Confronting the dark sorcerer'),
  (8, 7, 'Adventure 8', '2023-09-05', 'Recovering the stolen artifacts'),
  (9, 8, 'Adventure 1', '2023-10-15', 'Exploring the mysterious islands'),
  (10, 1, 'Adventure 10', '2023-11-20', 'The final showdown');

INSERT INTO CharacterAdventure (CharacterAdventureID, CharacterID, AdventureID)
VALUES
  -- the range of adventures is 1-10
  -- the range of characters is 1-10
  (1,1,6),
  (2,5,2),
  (3,5,6),
  (4,2,4),
  (5,5,9),
  (6,4,6),
  (7,3,7),
  (8,5,8),
  (9,2,7),
  (10,1,10);

INSERT INTO CharacterAchievements (AchievementID, CharacterID, QuestID)
VALUES
  (1,2,1),
  (2,5,2),
  (3,5,3),
  (4,2,4),
  (5,6,5),
  (6,4,6),
  (7,3,7),
  (8,9,8),
  (9,2,9),
  (10,1,10);

----------- Delete Statements --------------------
DELETE from Players
DELETE from Characters
DELETE from CharacterAchievements
DELETE from CharacterAdventure
DELETE from CharacterInventory
DELETE from Items
DELETE from Locations
DELETE from Monsters
DELETE from NPCs
DELETE from Quests
DELETE from Adventures
DELETE from Campaigns


----------- Select all Statements ---------------
SELECT * from Players
SELECT * from Characters
SELECT * from CharacterAchievements
SELECT * from CharacterAdventure
SELECT * from CharacterInventory
SELECT * from Items
SELECT * from Locations
SELECT * from Monsters
SELECT * from NPCs
SELECT * from Quests
SELECT * from Campaigns
SELECT * FROM Adventures

SELECT DISTINCT PlayerName FROM Players
SELECT DISTINCT CharacterName FROM Characters
SELECT DISTINCT AdventureName FROM Adventures

--------- update data – for at least 3 tables; ---------

UPDATE Players
SET PlayerName = 'Johnny Test'
WHERE PlayerID = 1;

UPDATE Characters
SET CharacterName = 'Sir Aldric the Brave'
WHERE CharacterID >= 9;

UPDATE Items
SET [Owner] = 1
WHERE ItemID BETWEEN 20 AND 30;

-------- delete data – for at least 2 tables ---------
DELETE FROM Campaigns
WHERE EndDate IS NULL;

DELETE FROM Adventures
WHERE SessionDate < '2023-07-01';

DELETE FROM Items
WHERE Owner IS not NULL;

-------- a. 2 queries with the union operation; use UNION [ALL] and OR; ---------
SELECT * FROM Characters
WHERE CharacterID < 5
UNION ALL
SELECT * FROM Characters
WHERE CharacterID > 5 and CharacterID < 8;

SELECT * FROM Items
WHERE(ItemType = 'Weapon' OR ItemType = 'Armor')



-------- b. 2 queries with the intersection operation; use INTERSECT and IN; ---------
SELECT * FROM Characters
WHERE CharacterID IN (
  SELECT CharacterID FROM CharacterAdventure WHERE AdventureID = 6);


SELECT 
  Characters.PlayerID
FROM Characters
INTERSECT
SELECT 
  Players.PlayerID
FROM Players
  


-------- c. 2 queries with the difference operation; use EXCEPT and NOT IN; ---------
SELECT * FROM Characters
WHERE CharacterID NOT IN (SELECT CharacterID FROM CharacterAdventure);

SELECT PlayerName
FROM Players
EXCEPT
SELECT PlayerName
FROM Players
WHERE PlayerID > 5;


-------- d. 4 queries with INNER JOIN, LEFT JOIN, RIGHT JOIN, and FULL JOIN 
--- (one query per operator); 
--- one query will join at least 3 table
--- one will join at least two many-to-many relationships;

SELECT 
  Characters.CharacterName,
  Characters.CharacterID,
  Adventures.AdventureName,
  CharacterAdventure.AdventureID
FROM Characters
INNER JOIN CharacterAdventure ON Characters.CharacterID = CharacterAdventure.CharacterID
INNER JOIN Adventures ON CharacterAdventure.AdventureID = Adventures.AdventureID
INNER JOIN CharacterAchievements ON Characters.CharacterID = CharacterAchievements.CharacterID

SELECT * FROM Adventures
LEFT JOIN Campaigns ON Adventures.CampaignID = Campaigns.CampaignID

SELECT * FROM NPCs
RIGHT JOIN Locations ON NPCs.LocationID = Locations.LocationID

SELECT * FROM Items
FULL JOIN Characters ON Items.Owner = Characters.CharacterID


-------- e. 2 queries with the IN operator and a subquery in the WHERE clause; 
--- in at least one case, the subquery must include a subquery in its own WHERE clause;

SELECT * FROM Characters
WHERE CharacterID IN (
  SELECT CharacterID FROM CharacterAdventure WHERE AdventureID IN (
    SELECT AdventureID FROM Adventures WHERE CampaignID IN (
      SELECT CampaignID FROM Campaigns WHERE CampaignName = 'Campaign 1')))

SELECT * FROM Items
WHERE Owner IN (
  SELECT CharacterID FROM Characters WHERE PlayerID IN (
    SELECT PlayerID FROM Players WHERE PlayerName = 'John Doe'))


--------- f. 2 queries with the EXISTS operator and a subquery in the WHERE clause;

SELECT * FROM Characters
WHERE EXISTS (
  SELECT * FROM CharacterAdventure WHERE 
    CharacterAdventure.CharacterID = Characters.CharacterID)

SELECT * FROM Items
WHERE EXISTS (
  SELECT * FROM Characters WHERE 
    Characters.CharacterID = Items.Owner
    AND Characters.PlayerID = 1)

--------- g. 2 queries with a subquery in the FROM clause;  

SELECT * FROM (
  SELECT * FROM Characters WHERE PlayerID = 1) AS PlayerCharacters
WHERE CharacterID IN (
  SELECT CharacterID FROM CharacterAdventure WHERE AdventureID < 5)


SELECT * FROM (
  SELECT * FROM Items WHERE Owner IS NOT NULL) AS OwnedItems
WHERE Owner IN (
  SELECT CharacterID FROM Characters WHERE PlayerID = 1)

-------- h. 4 queries with the GROUP BY clause, 
--- 3 of which also contain the HAVING clause; 
--- 2 of the latter will also have a subquery in the HAVING clause; 
--- use the aggregation operators: COUNT, SUM, AVG, MIN, MAX;

SELECT 
  COUNT(*) AS 'Number of High-Level Characters',
  Characters.Class
FROM Characters
WHERE Level > 1
GROUP BY Characters.Class
ORDER BY COUNT(*) DESC

SELECT 
  COUNT(*) AS 'Number of Characters',
  PlayerID
FROM Characters
GROUP BY PlayerID
HAVING COUNT(*) > 1

SELECT
  Locations.LocationName,
  LocID.NumberOfNPCs
FROM Locations
JOIN (
  SELECT 
    COUNT(*) AS NumberOfNPCs,
    LocationID
  FROM NPCs
  GROUP BY LocationID 
  HAVING (
    COUNT(*) < AVG(Level)
    AND COUNT(*) > 1
    AND LocationID IN (
      SELECT LocationID
      FROM NPCs
      WHERE Level > 3
    )
  )
) AS LocID ON Locations.LocationID = LocID.LocationID
ORDER BY LocID.NumberOfNPCs DESC;

SELECT
  ItemName
  ItemID
FROM Items
GROUP BY ItemID, ItemName
HAVING (
  ItemID IN (
    SELECT ItemID
    FROM Items
    WHERE ItemType = 'Weapon'
  GROUP BY ItemID
  )
)


-------- i. 4 queries using ANY and ALL to introduce a subquery in the WHERE clause 
--- (2 queries per operator); 
--- rewrite 2 of them with aggregation operators, 
--- and the other 2 with IN / [NOT] IN.


---- ANY
SELECT * FROM Characters
WHERE Level > ANY (
  SELECT Level FROM Characters WHERE PlayerID = 1)

SELECT * FROM Locations
WHERE LocationID = ANY (
  SELECT LocationID FROM NPCs WHERE Level > 3)


----- ALL
SELECT * FROM Items
Where ItemID > ALL (
  SELECT ItemID FROM Items WHERE Owner IS NOT NULL)

SELECT TOP(5) * FROM NPCs
WHERE Level > ALL (
  SELECT Level FROM NPCs WHERE LocationID = 1)


----- MIN/MAX/AVG/SUM
SELECT  * FROM Characters
WHERE Level > (
  SELECT MIN(Level) FROM Characters WHERE PlayerID = 1)

SELECT TOP(5) * FROM NPCs
WHERE Level > (SELECT MAX(Level) FROM NPCs WHERE LocationID = 1);



----- IN/NOT IN
SELECT *
FROM Locations
WHERE LocationID IN (
  SELECT LocationID
  FROM NPCs
  WHERE Level > 3
);

SELECT *
FROM Items
WHERE ItemID NOT IN (
  SELECT ItemID
  FROM Items
  WHERE Owner IS NOT NULL
);