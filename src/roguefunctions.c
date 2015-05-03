/*************************filename here.c****************************
Student Name: Dominic Lee                    Student Number:  0823091
Date: 10/03/2014                         Course Name: CIS2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/


#include "rogue.h"
#include "roguefunctions.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <ncurses.h>
#include <time.h>


void Tokenizer(char *word, int room, int r,  struct rooms **roomNum)
{

    char *result;
    char delimsA[50] = {"X d"};
    int dEast; /* door in east wall */
    int dWest; /* door in west wall */
    int dSouth; /* door  in south wall */
    int dNorth; /* door in north wall */
    int num;
    int treasureX;
    int treasureY;
    long int monsterX;
    long int monsterY;
    int heroX;
    int heroY;
    int potionX;
    int potionY;
    int weaponX;
    int weaponY;
    int colM;
    int rowM;
    int colP;
    int rowP;
    int colW;
    int rowW;
    int colT;
    int rowT;
    int roomLength;
    int roomWidth;

    colM = 0;
    rowM = 0;
    colP = 0;
    rowP = 0;
    colW = 0;
    rowW = 0;
    colT = 0;
    rowT = 0;


    result = strtok(word,delimsA);

    roomLength = atoi(result);

    result = strtok(NULL,delimsA);

    roomWidth = atoi(result);


    while(result != NULL)
    {

      if(*result == 'e')
      {
         /*printf("The result is : %s ", result);*/
         num = atoi (&result[1]);
         dEast = num;


      }

      if(*result == 'w')
      {


          if(result[2] != ',')
          {


              if(result[2] == '\0')
              {

                  num = atoi (&result[1]);
                  dWest = num;

              }

              if(result[3] == '\0')
              {

                  num = atoi(&result[1]);
                  dWest = num;
              }

             else if(result[2] != '\0' && result[3] != '\0')
             {

                 weaponY = atoi(&result[1]); /*+ atoi(&result[2]));*/
                 roomNum[room]->weaponCoordinates[rowP][colP] = weaponY;
                 colW = colW + 1;

                 if(result[6] == '\0')
                 {
                     weaponX = atoi(&result[4]);
                     roomNum[room]->weaponCoordinates[rowW][colW] = weaponX;
                     rowW = rowW + 1;
                     colW = 0;
                 }
                 else
                 {
                    weaponX = atoi(&result[4]);
                    roomNum[room]->weaponCoordinates[rowW][colW] = weaponX;
                    rowW = rowW + 1;
                    colW = 0;

                 }
            }


         }
         else
         {

             weaponY = atoi (&result[1]);
             roomNum[room]->weaponCoordinates[rowW][colW] = weaponY;
             colW = colW + 1;
             if(result[5] == '\0')
             {

                 weaponX = atoi(&result[4]);
                 roomNum[room]->weaponCoordinates[rowW][colW] = weaponX;
                 rowW = rowW + 1;
                 colW = 0;

             }
             else
             {
                 weaponX = atoi(&result[3]);
                 roomNum[room]->weaponCoordinates[rowW][colW] = weaponX;
                 rowW = rowW + 1;
                 colW = 0;
             }
        }

     }

    if(*result == 's')
    {
        /* printf("The result is : %s ", result);*/
         num = atoi (&result[1]);
         dSouth = num;
    }

     if(*result == 'n')
     {
        /* printf("The result is : %s ", result);*/
         num = atoi (&result[1]);
         dNorth = num;

     }

     if(*result == 'g')
     {
        /* printf("The result is : %s ", result);*/

         if(result[2] != ',')
         {
             treasureY = atoi(&result[1]); /*+ atoi(&result[2]));*/
             roomNum[room]->treasureCoordinates[rowT][colT] = treasureY;
             colT = colT + 1;
             if(result[5] != '\0')
             {
                 treasureX = atoi(&result[4]);
                 roomNum[room]->treasureCoordinates[rowT][colT] = treasureX;
                 rowT = rowT + 1;
                 colT = 0;
             }
             else
             {
                treasureX = atoi(&result[4]);
                roomNum[room]->treasureCoordinates[rowT][colT] = treasureX;
                rowT = rowT + 1;
                colT = 0;

             }
         }
         else
         {
             treasureY = atoi (&result[1]);
             roomNum[room]->treasureCoordinates[rowT][colT] = treasureY;
             colT = colT + 1;
             if(result[4] != '\0')
             {

                 treasureX = atoi(&result[4]);
                 roomNum[room]->treasureCoordinates[rowT][colT] = treasureX;
                 rowT = rowT + 1;
                 colT = 0;

             }
             else
             {
                 treasureX = atoi(&result[3]);
                 roomNum[room]->treasureCoordinates[rowT][colT] = treasureX;
                 rowT = rowT + 1;
                 colT = 0;
             }
        }

     }

    if(*result == 'm')
    {


         if(result[2] != ',')
         {
             monsterY = atoi(&result[1]);
             roomNum[room]->monsterCoordinates[rowM][colM] = monsterY;
             colM = colM + 1;
             if(result[5] != '\0')
             {
                 monsterX = atoi(&result[4]);
                 roomNum[room]->monsterCoordinates[rowM][colM] = monsterX;
                 rowM = rowM + 1;
                 colM = 0;
             }
             else
             {
                monsterX = atoi(&result[4]);
                roomNum[room]->monsterCoordinates[rowM][colM] = monsterX;
                rowM = rowM + 1;
                colM = 0;

             }


         }
         else
         {

             monsterY = atoi (&result[1]);
             roomNum[room]->monsterCoordinates[rowM][colM] = monsterY;
             colM = colM + 1;
             if(result[4] != '\0')
             {

                 monsterX = atoi(&result[4]);
                 roomNum[room]->monsterCoordinates[rowM][colM] = monsterX;
                 rowM = rowM + 1;
                 colM = 0;

             }
             else
             {
                 monsterX = atoi(&result[3]);
                 roomNum[room]->monsterCoordinates[rowM][colM] = monsterX;
                 rowM = rowM + 1;
                 colM = 0;
             }
        }

     }

     /* mvprintw(10,110,"monster Y : %d",roomNum[4]->monsterCoordinates[3][0]);
      mvprintw(11,110,"monster X : %d",roomNum[4]->monsterCoordinates[3][1]);*/

     if(*result == 'p')
     {
        /* printf("The result is : %s ", result);*/

         if(result[2] != ',')
         {
             potionY = atoi(&result[1]); /*+ atoi(&result[2]));*/
             roomNum[room]->potionCoordinates[rowP][colP] = potionY;
             colP = colP + 1;
             if(result[5] != '\0')
             {
                 potionX = atoi(&result[4]);
                 roomNum[room]->potionCoordinates[rowP][colP] = potionX;
                 rowP = rowP + 1;
                 colP = 0;
             }
             else
             {
                potionX = atoi(&result[4]);
                roomNum[room]->potionCoordinates[rowP][colP] = potionX;
                rowP = rowP + 1;
                colP = 0;

             }


         }
         else
         {

             potionY = atoi (&result[1]);
             roomNum[room]->potionCoordinates[rowP][colP] = potionY;
             colP = colP + 1;
             if(result[4] != '\0')
             {

                 potionX = atoi(&result[4]);
                 roomNum[room]->potionCoordinates[rowP][colP] = potionX;
                 rowP = rowP + 1;
                 colP = 0;

             }
             else
             {
                 potionX = atoi(&result[3]);
                 roomNum[room]->potionCoordinates[rowP][colP] = potionX;
                 rowP = rowP + 1;
                 colP = 0;
             }
        }

     }


     if(*result == 'h')
     {
        /* printf("The result is : %s ", result);*/
         heroY = atoi (&result[1]);
         heroX = atoi (&result[3]);

     }



     result = strtok(NULL,delimsA);


   }


   drawBoard(roomLength,roomWidth,dEast, dWest, dSouth, dNorth,r, room, weaponX, weaponY, treasureX, treasureY, monsterX, monsterY, heroX, heroY, potionX, potionY, roomNum);/*roomFile,textLine,linePtr,roomCount);*/

}

void drawBoard(int roomLength,int roomWidth,int dE, int dW, int dS, int dN, int r, int room, int wX, int wY, int tX, int tY, int mX, int mY, int hX, int hY, int pX, int pY, struct rooms **roomNum)/* FILE *roomFile, char textLine[100], char* linePtr, int roomCount)*/
{

    int length;
    int width;
    int i;
    int j;
    int L;
    int W;
    int rowD;
    int colD;
    int k;

    length = roomLength;
    width = roomWidth;

    k = 0;

     rowD = 0;
     colD = 0;

    if(r == 0)
    {
        W = 15 + r;
        L = 10 + r;
    }

    if(r > 9)
    {

        L = 10; /*60 - r;*/
        W = 30 + r;
    }

    if(r > 19)
    {
        L = 10;
        W = 60 + r;
    }

    if(r > 29)
    {
         L = 25;
         W = (60 + (r - 10));
    }

    if(r > 39)
    {
         L = 25;
         W = 30 + (r - 30);
    }
    if(r>49)
    {

        L = 25;
        W = 14;

    }

   initscr();

   noecho();

   /*mvprintw(5,14,"^*WELCOME TO ROGUE*^");

   mvprintw(5,70," To play game, use the h,j,k,l");
   mvprintw(6,70," keys to move the character '@' ");
   mvprintw(8, 70," Hit 'e' twice to generate another room");
   mvprintw(9, 70,"Hit 'e' a third time to QUIT game.");
   mvprintw(11, 70,"M - monster, P - Potion, * - Treasure"); */



   /*refresh();*/

	 for( i = 0; i < length; i++)
	   {


		   for( j = 0; j < width; j++)
		   {
		       mvaddch((i + L),(j + W),'.');

			  if(i == 0)

				  mvaddch((i + L),(j + W),'-');/*width of top*/

			 if(j == (width - 1))
				  mvaddch((i + L),(width + W),'|');/*length of right side*/

			  if( i == (length - 1))


				 mvaddch((i + L),(j + W),'-');/*width of base*/

			}

			mvaddch((i + L),W,'|');/*length of left side*/

		}
       mvaddch((L + dE),(width + W),'+');  /* East Door */
   	   roomNum[room]->doorCoordinates[rowD][colD] = (L + dE);
   	   colD = colD + 1;
   	   roomNum[room]->doorCoordinates[rowD][colD] = (width + W);
   	   rowD = rowD + 1;
   	   colD = 0;
   	   roomNum[room]->doorEast[0] = (L + dE);
   	   roomNum[room]->doorEast[1] = (width + W);

       mvaddch((L + dW),W,'+');  /* West Door */
       roomNum[room]->doorCoordinates[rowD][colD] = (L + dW);
   	   colD = colD + 1;
   	   roomNum[room]->doorCoordinates[rowD][colD] = (W);
   	   rowD = rowD + 1;
   	   colD = 0;
   	   roomNum[room]->doorWest[0] = (L + dW);
   	   roomNum[room]->doorWest[1] = W;

       mvaddch(L,(W + dN), '+');  /* North Door */
       roomNum[room]->doorCoordinates[rowD][colD] = (L);
   	   colD = colD + 1;
   	   roomNum[room]->doorCoordinates[rowD][colD] = (W + dN);
   	   rowD = rowD + 1;
   	   colD = 0;
   	   roomNum[room]->doorNorth[0] = L;
   	   roomNum[room]->doorNorth[1] = (W + dN);

       mvaddch((L + (length - 1)),(W + dS), '+'); /* South Door */
       roomNum[room]->doorCoordinates[rowD][colD] = (L + (length - 1));
   	   colD = colD + 1;
   	   roomNum[room]->doorCoordinates[rowD][colD] = (W + dS);
   	   rowD = rowD + 1;
   	   colD = 0;
   	   roomNum[room]->doorSouth[0] = (L + (length -1));
   	   roomNum[room]->doorSouth[1] = (W + dS);



      i = 0;
      j = 0;
      k = 0;

       while(roomNum[room]->monsterCoordinates[i][j] != 0)
       {


           mvaddch((L + roomNum[room]->monsterCoordinates[i][0]),(W + roomNum[room]->monsterCoordinates[i][1]), 'M');
           i = i + 1;

       }

       i = 0;
       j = 0;
       k = 0;

       while(roomNum[room]->weaponCoordinates[i][j] != 0)
       {


           mvaddch((L + roomNum[room]->weaponCoordinates[i][0]),(W + roomNum[room]->weaponCoordinates[i][1]), ')');
           i = i + 1;

       }


       i = 0;
       j = 0;
       k = 0;

       while(roomNum[room]->potionCoordinates[i][j] != 0)
       {


           mvaddch((L + roomNum[room]->potionCoordinates[i][0]),(W + roomNum[room]->potionCoordinates[i][1]), '!');
           i = i + 1;

       }

       i = 0;
       j = 0;
       k = 0;

       while(roomNum[room]->treasureCoordinates[i][j] != 0)
       {


           mvaddch((L + roomNum[room]->treasureCoordinates[i][0]),(W + roomNum[room]->treasureCoordinates[i][1]), '*');
           i = i + 1;

       }


       /* mvaddch((L + tY),(W + tX), '*');*/


       /*for(i=0;i<4;i++)
       {

            mvprintw(k,30," doorY = %d ",roomNum[room]->doorCoordinates[i][0]);
            k = k + 1;
            mvprintw(k,30," doorX = %d ",roomNum[room]->doorCoordinates[i][1]);
            k = k + 1;


       }*/


    if(room ==0)
    {
        roomNum[room]->heroYX[0] = (L + 2);
        roomNum[room]->heroYX[1] = (W + 2);
    }
    else
    {

        roomNum[room]->heroYX[0] = (L + hY);
        roomNum[room]->heroYX[1] = (W + hX);
    }




    refresh();



   /*playRogue(r,L,W,hY,hX);*/


    /* mvprintw(6,5,"WeaponY : %d",roomNum[0]->weaponCoordinates[0][0]);*/


}

void playRogue()/*(int r, int L, int W, int hY, int hX)*/
{

    int ch;
    int positionY;
    int positionX;

    int roomCount;
    int control;
    int newPosY;
    int newPosX;

    int rowM;
    int colM;
    int i;

    roomCount = 2;

    positionY = 12;
    positionX = 18;

    rowM = 0;
    colM = 0;

    struct gameStats *stats;

    stats = malloc(sizeof(struct gameStats));

    stats->playerHP = 1000;
    stats->potionCount = 0;
    stats->swordCount = 0;
    stats->hammerCount = 0;
    stats->potions = 0;
    stats->monsterCount = 0;
    stats->experiencePts = 0;

    for(i=0;i<6;i++)
    {

        while(roomNum[i]->monsterCoordinates[rowM][colM]!= 0)
        {
            stats->monsterCount = stats->monsterCount + 1;
            colM = colM + 1;
            rowM = rowM + 1;
            colM = 0;


        }
        rowM = 0;
        colM = 0;
    }


    mvprintw(46,50,"Room1 monster X : %d ",roomNum[0]->monsterCoordinates[2][1]);

    chtype character;

    mvprintw(4,58," Experience Points : %d ",stats->experiencePts);
    mvprintw(47,13,"[w,a,s,d] - Move hero");
    move(positionY,positionX);
    mvaddch(positionY,positionX,'@');


    curs_set(0);



    while(/*((ch = getch()) != 'q') ||*/ stats->playerHP > 0 /*stats->monsterKills == stats->monsterCount*/)
    {
        ch = getch();

        switch (ch)
		{
		    case 'w':

		        control = 1;



                getsyx(positionY,positionX);
                character = mvinch((positionY-1),(positionX - 1));
                if(character == '-')
                {
                    mvprintw(positionY,(positionX - 1),"@");
                    break;


                }
                if(character == '+')
                {



                    newPosY = checkDoorY((positionY - 1),(positionX - 1));
                    newPosX = checkDoorX((positionY - 1),(positionX - 1));
                    mvaddch(positionY,(positionX - 1),' ');
                    positionY = newPosY;
                    positionX = newPosX;
                    mvaddch(positionY,(positionX - 1),'@');


                    break;



                }
                checkObject(positionY,positionX,control,stats);

		        mvaddch(positionY,(positionX - 1),'.');
		        mvprintw((positionY - 1),(positionX - 1),"@");

		        refresh();


		        break;



			case 'a':

			    control = 2;



			    getsyx(positionY,positionX);
			    character = mvinch(positionY,(positionX - 2));
                if(character == '|')
                {
                    mvprintw(positionY,(positionX-1),"@");
                    break;


                }
                if(character == '+')
                {

                    newPosY = checkDoorY(positionY,(positionX - 2));
                    newPosX = checkDoorX(positionY,(positionX - 2));
                    mvaddch(positionY,(positionX - 1),' ');
                    positionY = newPosY;
                    positionX = newPosX;
                    mvaddch(positionY,(positionX - 1),'@');


                    break;



                }
                checkObject(positionY,positionX,control,stats);


                 mvaddch(positionY,(positionX - 1),'.');
                 mvprintw(positionY,(positionX - 2),"@");




                 refresh();


                 break;



			case 's':

			    control = 3;



                getsyx(positionY,positionX);
                character = mvinch((positionY+1),(positionX -1));
                if(character == '-')
                {
                    mvprintw(positionY,(positionX-1),"@");

                    break;

                }
                if(character == '+')
                {

                    newPosY = checkDoorY((positionY +1),(positionX - 1));
                    newPosX = checkDoorX((positionY + 1),(positionX - 1));

                    mvaddch(positionY,(positionX - 1),' ');
                    positionY = newPosY;
                    positionX = newPosX;
                    mvaddch(positionY,(positionX - 1),'@');


                    break;



                }
                checkObject(positionY,positionX,control,stats);


		         mvaddch(positionY,(positionX - 1),'.');
			     mvprintw((positionY + 1),(positionX - 1),"@");



			     refresh();




                 break;



            case 'd':

                control = 4;



                getsyx(positionY,positionX);
                character = mvinch(positionY,positionX);
                if(character == '|')
                {
                    mvprintw(positionY,(positionX -1),"@");

                    break;


                }
                if(character == '+')
                {

                    newPosY = checkDoorY(positionY,positionX);
                    newPosX = checkDoorX(positionY,positionX);
                    mvaddch(positionY,(positionX - 1),' ');
                    positionY = newPosY;
                    positionX = newPosX;
                    mvaddch(positionY,(positionX - 1),'@');


                    break;
                }
                checkObject(positionY,positionX,control,stats);
                mvaddch(positionY,(positionX - 1),'.');
                mvprintw(positionY,(positionX),"@");




                refresh();

                break;

           case 'q':

               stats->playerHP = 0;

               break;

			getch();

		}




    }
    getsyx(positionY,positionX);
    mvaddch(positionY,(positionX - 1),' ');

    endStats(stats);



    refresh();


    endwin();




}

int checkDoorY(int positionY, int positionX)
{

    int i;
    int j;
    int valid = 0;
    int newY = 0;
    int roomNumber;

    /* for(i=0;i<4;i++)
       {

            mvprintw(k,50," doorY = %d ",roomNum[0]->doorCoordinates[i][0]);
            k = k + 1;
            mvprintw(k,50," doorX = %d ",roomNum[0]->doorCoordinates[i][1]);
            k = k + 1;


       }*/


    for(i = 0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(positionY == roomNum[i]->doorCoordinates[j][0])
            {
                if(positionX == roomNum[i]->doorCoordinates[j][1])
                {
                    if((roomNum[i]->doorCoordinates[j][0] == roomNum[i]->doorEast[0]) && (roomNum[i]->doorCoordinates[j][1] == roomNum[i]->doorEast[1]))
                    {
                        roomNumber = i;
                        valid = valid + 1;
                    }
                    if((roomNum[i]->doorCoordinates[j][0] == roomNum[i]->doorWest[0]) && (roomNum[i]->doorCoordinates[j][1] == roomNum[i]->doorWest[1]))
                    {
                        roomNumber = i;
                        valid = valid + 2;
                    }
                    if((roomNum[i]->doorCoordinates[j][0] == roomNum[i]->doorNorth[0]) && (roomNum[i]->doorCoordinates[j][1] == roomNum[i]->doorNorth[1]))
                    {
                        roomNumber = i;
                        valid = valid + 3;
                    }
                    if((roomNum[i]->doorCoordinates[j][0] == roomNum[i]->doorSouth[0]) && (roomNum[i]->doorCoordinates[j][1] == roomNum[i]->doorSouth[1]))
                    {
                        roomNumber = i;
                        valid = valid + 4;
                    }
                }
            }
        }
    }

    if(roomNumber == 0 && valid == 1)
    {
        newY = roomNum[1]->heroYX[0];
    }
    if(roomNumber == 1 && valid == 2)
    {
        newY = roomNum[0]->heroYX[0];
    }
    if(roomNumber == 1 && valid == 1)
    {
        newY = roomNum[2]->heroYX[0];
    }
    if(roomNumber == 1 && valid == 4)
    {
        newY = roomNum[4]->heroYX[0];
    }
    if(roomNumber == 2 && valid == 2)
    {
        newY = roomNum[1]->heroYX[0];
    }
    if(roomNumber == 2 && valid == 4)
    {
        newY = roomNum[3]->heroYX[0];
    }
    if(roomNumber == 3 && valid == 2)
    {
        newY = roomNum[4]->heroYX[0];
    }
    if(roomNumber == 3 && valid == 3)
    {
        newY = roomNum[2]->heroYX[0];
    }
    if(roomNumber == 4 && valid == 1)
    {
        newY = roomNum[3]->heroYX[0];

    }
    if(roomNumber == 4 && valid == 3)
    {
        newY = roomNum[1]->heroYX[0];
    }
    if(roomNumber == 4 && valid == 2)
    {
        newY = roomNum[5]->heroYX[0];
    }
    if(roomNumber == 5 && valid == 1)
    {
        newY = roomNum[4]->heroYX[0];
    }

    return(newY);

}

int checkDoorX(int positionY, int positionX)
{

    int i;
    int j;
    int valid = 0;
    int newX = 0;
    int roomNumber;


    /* for(i=0;i<4;i++)
       {

            mvprintw(k,50," doorY = %d ",roomNum[0]->doorCoordinates[i][0]);
            k = k + 1;
            mvprintw(k,50," doorX = %d ",roomNum[0]->doorCoordinates[i][1]);
            k = k + 1;


       }

       mvprintw(k,50," East doorY = %d ",roomNum[0]->doorEast[0]);

       mvprintw((k + 1),50," East doorX = %d ",roomNum[0]->doorEast[1]); */


    for(i = 0;i<6;i++)
    {
        for(j=0;j<12;j++)
        {
            if(positionY == roomNum[i]->doorCoordinates[j][0])
            {
                if(positionX == roomNum[i]->doorCoordinates[j][1])
                {
                    if((roomNum[i]->doorCoordinates[j][0] == roomNum[i]->doorEast[0]) && (roomNum[i]->doorCoordinates[j][1] == roomNum[i]->doorEast[1]))
                    {
	                    roomNumber = i;
	                    valid = valid + 1;
	                }
                    if((roomNum[i]->doorCoordinates[j][0] == roomNum[i]->doorWest[0]) && (roomNum[i]->doorCoordinates[j][1] == roomNum[i]->doorWest[1]))
                    {
	                    roomNumber = i;
	                    valid = valid + 2;
                    }
					if((roomNum[i]->doorCoordinates[j][0] == roomNum[i]->doorNorth[0]) && (roomNum[i]->doorCoordinates[j][1] == roomNum[i]->doorNorth[1]))
					{
						roomNumber = i;
						valid = valid + 3;
					}
					if((roomNum[i]->doorCoordinates[j][0] == roomNum[i]->doorSouth[0]) && (roomNum[i]->doorCoordinates[j][1] == roomNum[i]->doorSouth[1]))
					{
						roomNumber = i;
						valid = valid + 4;
					}
				}
			}
		}
	}

    if(roomNumber == 0 && valid == 1)
	{
	    newX = roomNum[1]->heroYX[1];
	}
	if(roomNumber == 1 && valid == 2)
	{
	    newX = roomNum[0]->heroYX[1];
	}
	if(roomNumber == 1 && valid == 1)
	{
	    newX = roomNum[2]->heroYX[1];
	}
	if(roomNumber == 1 && valid == 4)
	{
	    newX = roomNum[4]->heroYX[1];
	}
	if(roomNumber == 2 && valid == 2)
	{
	    newX = roomNum[1]->heroYX[1];
	}
	if(roomNumber == 2 && valid == 4)
	{
	    newX = roomNum[3]->heroYX[1];
	}
	if(roomNumber == 3 && valid == 2)
	{
	    newX = roomNum[4]->heroYX[1];
	}
	if(roomNumber == 3 && valid == 3)
	{
	    newX = roomNum[2]->heroYX[1];
	}
	if(roomNumber == 4 && valid == 1)
	{
	    newX = roomNum[3]->heroYX[1];
	}
	if(roomNumber == 4 && valid == 3)
	{
	    newX = roomNum[1]->heroYX[1];
	}
	if(roomNumber == 4 && valid == 2)
	{
	    newX = roomNum[5]->heroYX[1];
	}
	if(roomNumber == 5 && valid == 1)
	{
	    newX = roomNum[4]->heroYX[1];
	}

    return(newX);

}

void checkObject(int positionY, int positionX, int control, struct gameStats *stats )
{
    chtype character;
    srand(time(NULL));

    int weapon;

    weapon = rand()%2;

    /*mvprintw(44,10,"weapon num : %d ",weapon);*/


    if(control == 1)
    {
       character = mvinch((positionY - 1),(positionX - 1));
       if(character == 'M')
       {
           monsterCombat(stats);
       }
       if(character == '!')
        {
            stats->potions = stats->potions + 1;
            stats->potionCount = stats->potionCount + 1;
            mvprintw(5,16,"Potion Found[%d] !",stats->potions);
        }
        if(character == ')')
        {

            if(weapon == 1)
            {
                stats->swords = stats->swords + 1;
                stats->swordCount = stats->swordCount;
                mvprintw(5,36,"Sword Found[%d] !",stats->swords);
            }
            if(weapon == 0)
            {
                stats->hammers = stats->hammers + 1;
                stats->hammerCount = stats->hammerCount + 1;
                mvprintw(6,16,"Hammer Found[%d] !",stats->hammers);

            }

        }
        if(character == '*')
        {
            stats->experiencePts = stats->experiencePts + 25;
            stats->gold = stats->gold + 1;
            mvprintw(6,36,"Gold Found[%d] !",stats->gold);
        }


    }

    if(control == 2)
    {
        character = mvinch(positionY,(positionX - 2));
       if(character == 'M')
       {
           monsterCombat(stats);
       }
       if(character == '!')
        {
            stats->potions = stats->potions + 1;
            stats->potionCount = stats->potionCount + 1;
            mvprintw(5,16,"Potion Found[%d] !",stats->potions);
        }
        if(character == ')')
        {

            if(weapon == 1)
            {
                stats->swords = stats->swords + 1;
                stats->swordCount = stats->swordCount;
                mvprintw(5,36,"Sword Found[%d] !",stats->swords);
            }
            if(weapon == 0)
            {
                stats->hammers = stats->hammers + 1;
                stats->hammerCount = stats->hammerCount + 1;
                mvprintw(6,16,"Hammer Found[%d] !",stats->hammers);

            }

        }
        if(character == '*')
        {
            stats->experiencePts = stats->experiencePts + 25;
            stats->gold = stats->gold + 1;
            mvprintw(6,36,"Gold Found[%d] !",stats->gold);
        }


    }

    if(control == 3)
    {
       character = mvinch((positionY+1),(positionX -1));
       if(character == 'M')
       {
           monsterCombat(stats);
       }
       if(character == '!')
        {
            stats->potions = stats->potions + 1;
            stats->potionCount = stats->potionCount + 1;
            mvprintw(5,16,"Potion Found[%d] !",stats->potions);
        }
        if(character == ')')
        {

            if(weapon == 1)
            {
                stats->swords = stats->swords + 1;
                stats->swordCount = stats->swordCount;
                mvprintw(5,36,"Sword Found[%d] !",stats->swords);
            }
            if(weapon == 0)
            {
                stats->hammers = stats->hammers + 1;
                stats->hammerCount = stats->hammerCount + 1;
                mvprintw(6,16,"Hammer Found[%d] !",stats->hammers);

            }

        }
        if(character == '*')
        {
            stats->experiencePts = stats->experiencePts + 25;
            stats->gold = stats->gold + 1;
            mvprintw(6,36,"Gold Found[%d] !",stats->gold);
        }

    }

    if(control == 4)
    {
        character = mvinch(positionY,positionX);
        if(character == 'M')
       {
           monsterCombat(stats);
       }
       if(character == '!')
        {
            stats->potions = stats->potions + 1;
            stats->potionCount = stats->potionCount + 1;
            mvprintw(5,16,"Potion Found[%d] !",stats->potions);
        }
        if(character == ')')
        {

            if(weapon == 1)
            {
                stats->swords = stats->swords + 1;
                stats->swordCount = stats->swordCount;
                mvprintw(5,36,"Sword Found[%d] !",stats->swords);
            }
            if(weapon == 0)
            {
                stats->hammers = stats->hammers + 1;
                stats->hammerCount = stats->hammerCount + 1;
                mvprintw(6,16,"Hammer Found[%d] !",stats->hammers);

            }

        }
        if(character == '*')
        {
            stats->experiencePts = stats->experiencePts + 25;
            stats->gold = stats->gold + 1;
            mvprintw(6,36,"Gold Found[%d] !",stats->gold);
        }



    }
    mvprintw(4,58," Experience Points : %d ",stats->experiencePts);

}

void monsterCombat(struct gameStats *stats)
{

    int positionY;
    int positionX;
    int height;
    int width;
    int ch;
    int monsterHP;
    int randMonster;
    int monsterDamage;

    height = 3;
    width = 3;

    positionY = 41;
    positionX = 108;

    WINDOW *combat;
    WINDOW *reticleWin;
    cbreak();

    combat = newwin(35,65,10,105);

    box(combat,0,0);

    wrefresh(combat);

    randMonster = rand()%3;




    mvprintw(35,144,"Rogue Player");
    mvprintw(38,111,"PUNCH - 10HP");
    mvprintw(38,132,"Sword - 20HP[%d]",stats->swords);
    mvprintw(42,132,"Potion - ^50HP[%d]",stats->potions);
    mvprintw(42,111,"Hammer - 50HP[%d]",stats->hammers);
    mvprintw(46,108,"w,a,s,d - Move reticle");
    mvprintw(46,135,"[SPACEBAR] - Attack/choose Potion");
    mvprintw(4,126,"//\\COMBAT MODE//\\");
	mvprintw(5,126,"\\//           \\//");



    mvprintw(27,110,"  ,-------.");
    mvprintw(28,110,"  |,-----.|");
    mvprintw(29,110," (,'-----'.)");
    mvprintw(30,110,"{_{(') (')}_}");
    mvprintw(31,110," `.   _   .'");
    mvprintw(32,110,"   '-___-'");
    mvprintw(33,111, "|         |");
    mvprintw(34,110,"(_)_______(_)");


    if(randMonster == 2)
    {

        mvprintw(15,115,"Goblin King(!)");
        mvprintw(14,135," ^    ^    ^    ^");
        mvprintw(15,135,"(( ** ))  _( |_| )_");
        mvprintw(16,135,"| _||_ | < #_   _# >");
        mvprintw(17,135,"[______]   |0   0|");
        mvprintw(18,135,"  _[]_   _(_  ^  _)_");
        mvprintw(19,135," ( () )(`(|V' ' 'V|)`)");
        mvprintw(20,135,"   {}   (  )_____(  )");
        mvprintw(21,135,"   ()   (   )==(   )");
        mvprintw(22,135,"   {}  (  _=^^^^^=_ )");
        monsterHP = 80;
        monsterDamage = 20;


    }

    if(randMonster == 1)
    {

         mvprintw(15,115,"Dungeon Skeleton(!)");
         mvprintw(14,135,"     .-""-.  ");
         mvprintw(15,135,"   [ _  _ ] ");
         mvprintw(16,135,"   |(X)(X)| ");
         mvprintw(17,135,"   (_  ^ _) ");
         mvprintw(18,135,"    |wwww|  ");
         mvprintw(19,135,"    '-..-'  ");
         mvprintw(18,135,"      ||  ");
         mvprintw(19,135,"    '-..-'  ");
         monsterHP = 50;
         monsterDamage = 10;

     }

    if(randMonster == 0)
    {

         mvprintw(15,115,"Ice Dragon (!)");
	     mvprintw(15,129,"              *___                            ");
	     mvprintw(16,129,"          .'` .) {} -._______                  ");
	     mvprintw(17,129,"          <    _ `""`  ```  `,        _ _      ");
	     mvprintw(18,129,"         <    ( `.~v~v~v~v~v'  _  -- *     *   ");
	     mvprintw(19,129,"         | .    `. `.  __-  ~ -  +   ~   +     ");
	     mvprintw(20,129,"         | :  `----`. `.  -~ _  _ ~ *  +   +   ");
	     mvprintw(21,129,"         <:_     X  `. `.  - *__ +  -    -     ");
	     mvprintw(22,129,"          `.`----X    `._;     +   --  _ *  - " );
	     mvprintw(23,129,"                 `,_    `                      ");
	     mvprintw(24,129,"                  X  `---':                    ");
	     mvprintw(25,129,"                 X        ;                    ");
	     monsterHP = 150;
	     monsterDamage = 50;

    }

    reticleWin = reticleCursor(height, width, positionY, positionX);

    while(monsterHP > 0 && stats->playerHP > 0)
	{



    ch = getch();


	switch(ch)
		{	case 'a':

		        if(positionX < 110)
		        {
		            closeReticle(reticleWin);
		            reticleWin = reticleCursor(height, width, positionY, positionX);
		            break;


		        }

                closeReticle(reticleWin);
				reticleWin = reticleCursor(height, width, positionY, positionX = (positionX - 21));




				break;

		   case 'd':

		        if(positionX > 120)
		        {
		            closeReticle(reticleWin);
		            reticleWin = reticleCursor(height, width, positionY, positionX);
		            break;


		        }
				closeReticle(reticleWin);
				reticleWin = reticleCursor(height, width, positionY,positionX = (positionX + 21));

				break;

			case 'w':


			    if(positionY < 38)
		        {
		            closeReticle(reticleWin);
		            reticleWin = reticleCursor(height, width, positionY, positionX);
		            break;


		        }

				closeReticle(reticleWin);
				reticleWin = reticleCursor(height, width, positionY = (positionY - 4),positionX);


				break;

			case 's':

			    if(positionY > 40)
		        {
		            closeReticle(reticleWin);
		            reticleWin = reticleCursor(height, width, positionY, positionX);
		            break;


		        }

				closeReticle(reticleWin);
				reticleWin = reticleCursor(height, width, positionY = (positionY + 4),positionX);


				break;

			case ' ':

			   /*getsyx(positionY,positionX);*/
	           if(positionY == 41 && positionX == 108)
	           {
	               if(stats->hammers != 0)
	               {
	                   stats->hammers = stats->hammers - 1;
	                   mvprintw(42,111,"Hammer - 50HP[%d]",stats->hammers);
	                   monsterHP = monsterHP - 50;
	                   stats->playerHP = stats->playerHP - monsterDamage;

	                   break;
	               }

	               break;

	           }
	           if(positionY == 37 && positionX == 129)
	           {
	               if(stats->swords != 0)
	               {
	                   stats->swords = stats->swords - 1;
	                   mvprintw(38,132,"Sword - 20HP[%d]",stats->swords);
	                   monsterHP = monsterHP - 20;
	                   stats->playerHP = stats->playerHP - monsterDamage;

	                   break;
	               }

	               break;

	           }


	           if(positionY == 41 && positionX == 129)
	           {
	               if(stats->potions != 0)
	               {

	                   stats->playerHP = stats->playerHP + 50;
	                   stats->potions = stats->potions - 1;
	                   mvprintw(42,132,"Potion - ^50HP[%d]",stats->potions);

	                   break;
	               }

	               break;

	           }
               monsterHP = monsterHP - 10;
               stats->playerHP = stats->playerHP - monsterDamage;
               break;
        }


	   /* mvprintw(46,115,"X = %d, Y = %d",positionX,positionY);*/


        mvprintw(12,115,"[Monster HP : %d]",monsterHP);
	    mvprintw(34,142," [Rogue Player HP : %d] ",stats->playerHP);

    }

    if(monsterHP <= 0)
    {
        stats->monsterKills = stats->monsterKills + 1;
        if(randMonster == 0)
        {
            stats->experiencePts = stats->experiencePts + 200;
        }
        if(randMonster == 1)
        {
            stats->experiencePts = stats->experiencePts + 100;
        }
        if(randMonster == 2)
        {
            stats->experiencePts = stats->experiencePts + 50;
        }

    }

    mvprintw(4,58," Experience Points : %d ",stats->experiencePts);
    mvprintw(4,126,"//\\ Rogue MODE //\\");
	mvprintw(5,126,"\\//            \\//");
    delwin(combat);

    refresh();

}

WINDOW *reticleCursor(int height, int width, int positionY, int positionX)
{


    WINDOW *reticle;

	reticle = newwin(height, width, positionY, positionX);
	box(reticle, 1 , 1);		/* 1, 1 gives reticle shape */


	wrefresh(reticle);

	return reticle;
}

void closeReticle(WINDOW *reticle)
{
	/* box(reticle, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners
	 * and so an ugly remnant of window.
	 */
	wborder(reticle, ' ', ' ', ' ',' ',' ',' ',' ',' '); /* borders */

	wrefresh(reticle);
	delwin(reticle);
}

void endStats(struct gameStats *stats)
{
    int ch;

    clear();

    mvprintw(3,15,"//\\//\\Game Stats//\\//\\");
    mvprintw(4,15,"\\//\\//          \\//\\//");
    mvprintw(7,15,"Gold Found ------------------()> %d",stats->gold);
    mvprintw(9,15,"Swords Found ----------------()> %d",stats->swordCount);
    mvprintw(11,15,"Hammers Found --------------()> %d",stats->hammerCount);
    mvprintw(13,15,"Potions Found --------------()> %d",stats->potionCount);
    mvprintw(15,15,"Monster Kills --------------()> %d",stats->monsterKills);
    mvprintw(17,15,"Experience Points --------------()> %d",stats->experiencePts);

    mvprintw(19,15,"(!)Hit 'space bar' to quit(!)");

    refresh();

    while((ch = getch()) != ' ')
    {


	    switch(ch)
		    {
		        case ' ':

		        break;
            }
        getch();

    }

}











