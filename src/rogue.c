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
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<curses.h>


int main(int argc, char *argv[])
{

    FILE *filePtr;
    char mystring [100];
    char *roguePtr;
    int room;
    int i;
    int j;
    int r;


    room = 0;
    r = 0;


    filePtr = NULL;
    j = 0;

    roomNum = malloc(sizeof(struct rooms *)*6);
    for(i=0;i<6;i++)
    {
        roomNum[i] = malloc(sizeof(struct rooms));
    }

    if ( argc != 2 )
    {
        printf( "Error. Not Enough Arguments\n");
    }
    else
    {
        filePtr = fopen (argv[1], "r");
	    if (filePtr == NULL)
		    perror ("\n(!)Error opening file(!)");
	    else
	    {
            for(i=0;i<6;i++)
	        {
                fgets(mystring,100,filePtr);
                roguePtr = mystring;
                Tokenizer(roguePtr,room,r,roomNum);
                room = room + 1;
                r = r + 10;
            }

			fclose(filePtr);
            playRogue();
        }
    }
    return EXIT_SUCCESS;
}






