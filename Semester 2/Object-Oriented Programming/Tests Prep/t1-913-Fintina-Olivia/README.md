# Lab Test 1


**EHF Top Scorer List Manager**

The European Handball Federation (EHF) needs an application to manage the list of Top Scorer players in the Women's EHF Champions League competition. Each player has a name, a nationality, a team for which she plays and the number of goals scored in this season. The name of the player and the name of the team can be composed by more words separated by an underscore. The nationality is a 3-letter abbreviation of a country's name. See below some examples of players (the attributes name, nationality, team and goals are separated by the | separator):

Nora_Mork | NOR | Larvik | 83 \
Isabelle_Gullden | SWE | CSM Bucurest | 80 \
Cristina_Neagu | ROU | Buducnost | 63 \
Allison_Pineau | FRA | HCM_Baia Mare | 82 \
Ilina_Ekaterina | RUS | Rostov-Don | 80 \
Nerea Pena | ESP | FTC-Rail_Cargo_Hungaria | 59

Write a top scorer list manager application with a console-based user interface which allows the following operations:
1. Add a new player. A message will be shown if the player was successfully added (1.5p). If a player already exists with the same name, the application should not add the player, and it should display a corresponding message (1.5p).
2. Show all the players, with all their information (name, nationality, team, goals). (1p).
3. Show all the players who play for a given team (1p), sorted by the number of goals (1p) and the total number of goals scored by that team (1p).
   Input at least 5 players to your initial list of players (from the source code).
   Write specifications and white-box tests for the following functions:
   Function which adds a player to the player list (the repository/service function). (0.5- specification, 0.5-test)
   Function which retrieves all players for a given team sorted by the number of goals (0.5 -specification, 0.5-test)
   The application must use layered architecture in order for functionalities to be graded.
   1p-of.
   Time: 60 minutes


Solve the provided problem, using object oriented programming and C++.

Input at least 5 entities in your repository.

The application must use layered architecture in order for functionalities to be graded.

Do not forget to add the required tests and specifications.

Using existing code is forbidden, you must start your application from scratch.

For function documentation you may use:
- https://en.cppreference.com/w/
- https://www.cplusplus.com/

Time: 60 minutes.


