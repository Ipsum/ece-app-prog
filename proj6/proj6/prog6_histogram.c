/******************************************************************************
* 16.216 ECE Application Programming                                          *
* Instructor: M. Geiger                                                       *
* 09/09/12                                                                    *
* prog6_histogram.c: Using Arrays to Count Letters in Text                    *
*                                                                             *
* Author: David Tyler                                                         *
* SN: 00952042                                                                *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//protos
int * readText(int histo[], int *max);
void drawHist(int histo[], int max);

void main() 
{
    int histo[26] = {0};
    int *max = &histo[0];
    char cmd;

    while(1)
    {
        printf("\nEnter command (C, R, P, or Q): ");
        scanf(" %c",&cmd);
        cmd=tolower(cmd);

        switch(cmd) //state machine
        {
            case 'c':
                memset(histo,0,26*4); //set array to 0
                break;
            case 'r':
                max = readText(histo,max);
                break;
            case 'p':
                drawHist(histo,*max+1);
                break;
            case 'q':
                return;
            default:
                printf("Invalid command %c",cmd);
                break;
        }
    }
}

int * readText(int histo[], int *max)
{
    char inp;
    printf("ENTER A LINE OF TEXT:\n\n");
    getchar();
    while(1)
    {
        inp=getchar();
        if (inp=='\n')
            return max;
        inp = tolower((int)inp);
        inp-=97; //convert to array index values: a=97
        if (inp>=0 && inp<26)
        {
            histo[inp]=histo[inp]+1;
            if(histo[inp]>=*max) //move pointer to position of max value
                max=&histo[inp];

        }
    }
    return max;
}

void drawHist(int histo[], int max)
{
    int l;
    printf("LETTER FREQUENCIES IN TEXT: \n\n");
    for (;max>=0;max--) //height
    {
        for(l=0;l<26;l++) //width
        {
            if(histo[l]>max)
            {
                printf("|"); //if high enough
            }
            else
                printf(" "); //if not that high
            printf(" "); //pad
        }
        printf("\n");
    }
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n\n");
    return;
}