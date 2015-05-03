#include "rogue.h"
#include<stdio.h>
#include<ncurses.h>
#define totalD 25
#define totalM 10
#define totalP 10
#define totalT 3
#define totalW 10
#define maxDoors 24


/*Struct Name : 
  Purpose : 
  Parameters :   
*/


struct gameStats{

    int playerHP;
    int potions;
    int potionCount;
    int swords;
    int swordCount;
    int hammers;
    int hammerCount;
    int gold;
    int experiencePts;  
    int monsterCount; 
    int monsterKills;

};


/*Struct Name : 
  Purpose : 
  Parameters :   
*/
struct rooms{

int doorNorth[2];
int doorSouth[2];
int doorEast[2];
int doorWest[2];
int heroYX[2];
int doorCoordinates[totalD][2];
int monsterCoordinates[totalM][2];
int potionCoordinates[totalP][2];
int weaponCoordinates[totalW][2];
int treasureCoordinates[totalT][2];
int heroY;
int heroX;

}**roomNum;



/*Function Name : drawBoard
  Purpose : Takes room data and draws each room with the respective items and monsters.
  Parameters : Length of room, Width of room, east door,west door,south door,north door, 'r' which helps to decide room positions,
               'room' which is the index for each struct,x and y coordinates of a weapon, 
               x and y coordinates of treasure,x and y coordinates of monster,x and y coordinates of hero,
               x and y coordinates of potion and a room data structure.
  Return : void function.
  
*/
void drawBoard(int roomLength,int roomWidth, int dE, int dW, int dS, int dN, int r, int room, int wX, int wY, int tX, int tY, int mX, int mY, int hX, int hY, int pX, int pY, struct rooms **roomNum);


/*Function Name : Tokenizer
  Purpose : Takes a pointer tp the first line of the .txt file and parses it into its individual data elements, which 
             each room will be built from.
  Parameters : word - char pointer that points to the first character of the array that stores the first line in the .txt file
               room - index for each room struct, r- helps decide the position of each room,
               **roomNum is a room data structure.
               
  Return : Void function.
  
*/
void Tokenizer(char *word, int room, int r, struct rooms **roomNum);


/*Function Name : playRogue
  Purpose : Movement done in this function
  Parameters : none
  Return : Void function
  
*/
void playRogue(); 


/*Function Name : checkDoorY
  Purpose : checks if y coordinate of a door is approached
  Parameters : x and y coordinates of the hero
  Return : y coordinate
  
*/
int checkDoorY(int positionY, int positionX);


/*Function Name : checkDoorX
  Purpose : checks if x coordinate of a door is approached
  Parameters : x and y coordinates of the hero
  Return : x coordinate
  
*/
int checkDoorX(int positionY, int positionX);


/*Function Name : checkObject
  Purpose : checks if item/weapon is approached
  Parameters : x and y coordinates of hero
  Return : void function.
  
*/
void checkObject(int positionY, int positionX, int control, struct gameStats *stats);


/*Function Name : monsterCombat
  Purpose : Initiates monster combat window
  Parameters : 
  Return : 
  
*/
void monsterCombat(struct gameStats *stats);


/*Function Name : 
  Purpose : 
  Parameters : 
  Return : 
  
*/
WINDOW *reticleCursor(int height, int width, int positionY, int positionX);


/*Function Name : 
  Purpose : 
  Parameters : 
  Return : 
  
*/
void closeReticle(WINDOW *reticle);


/*Function Name : 
  Purpose : 
  Parameters : 
  Return : 
  
*/
void endStats(struct gameStats *stats);









