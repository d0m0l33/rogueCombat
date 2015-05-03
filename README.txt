Name : Dominic Lee
Student ID : 0823091
Course : CIS2500


About Program ---->

This is a rouge like game. The program runs from a terminal window. This program reads the game data from a textfile 'nameOfFile.txt'.


How to compile program ---->

On terminal, in 'rogueCombat' root directory, type 'make'. The executable file generated will be in the 'bin' subdirectory.


How to run program ---->

After compilation, type 'bin/rogue nameOfFile.txt'. If 'nameOfFile.txt' isn't typed, program will state that an argument is missing. 
If file doesn't exist, program will return an error statement.
This folder already comes with a default data file : "data.txt"


Limitations ---->

If textfile has errors such as identical coordinates for items, items will be overwritten. Similarly, if item coodrinates are similar
to that of the room walls, items will end up in the walls. 


Enhancements ----->

Monster Combat : 

When a monster is approached, a combat window is shown on the right with the rogue player and the monster being fought. 
The player may choose between 1 of 4 options to use during the combat sequence. Items picked up before the combat window 
can be used as one of the options, such as a sword or a potion. These items are not unlimited. Each time a player attacks,
the monster will simultaneously attack, and the players life points will decrease. Player beats monster by decreasing monster life
points to 0 before the his/her life points hits 0.


Items to collect :

Items can be collected and used in monster combat. Gold collected increases player experience points.

Different Monsters :

There are 1 of 3 monsters to battle in this game. Each monster has a different level of life points as well as attack damage. Monsters
are randomly distributed throughout each room. 
