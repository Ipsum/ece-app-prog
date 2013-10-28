/******************************************************************************
* 16.216 ECE Application Programming                                          *
* Instructor: M. Geiger                                                       *
* 11/19/12                                                                    *
* prog7_raster.c: Simple Raster-Scan Graphics                                 *
*                                                                             *
* Author: David Tyler                                                         *
* SN: 00952042                                                                *
*                                                                             *
* I flew too close to the sun in persuit of rescuing memory                   *
******************************************************************************/
#define NCols 21
#define NRows 51

#include <math.h>
#include <stdio.h>
#include <string.h>

void reset(char [][NCols]);
void buildBox(char [][NCols],int,int,int,int);
void print(char [][NCols]);

void main()
{
    char boxes[NRows][NCols] = {{0}};
    char cmd[10]={0};
    int x,y,w,h;

    while(1)
    {
        printf("\nEnter command: ");
        scanf("%s",&cmd);

        if( !(strcmp(cmd,"add")) ) //add box command
        {
            printf("Enter X and Y coordinates for origin: ");
            scanf(" %d%d",&x,&y);
            printf("Enter width and height: ");
            scanf(" %d%d",&w,&h);
            buildBox(boxes,x,y,w,h);
        }
        else if( !(strcmp(cmd,"print")) )
        {
            print(boxes);
        }
        else if( !(strcmp(cmd,"reset")) )
        {
            for(x=0;x<NCols;x++)
            {
                for(y=0;y<=NRows;y++)
                {
                    boxes[NRows][NCols]=0;
                }
            }
        }
        else if( !(strcmp(cmd,"exit")) )
        {
            return;
        }
        else
            printf("Invalid Command");
    }
}

void buildBox(char boxes[][NCols],int x,int y,int w,int h)
{
    int i,j;

    for(i=x;i<(x+w);i++)
    {
        for(j=y;j<(y+h);j++)
        {
            if(!(i>=NRows || j>=NCols))
                boxes[i][j]='*';
        }
    }

    return;
}
void print(char boxes[][NCols])
{
    int i,j;
    for(i=NCols;i>=0;i--)
    {
        for(j=0;j<NRows;j++)
        {
            if (boxes[j][i]=='*')
                printf("*");
            else if(!(i%5)&&!(j%5))
                printf("+");
            else if(!(i%5))
                printf("-");
            else if(!(j%5))
                printf("|");
            else
                printf(" ");
        }
        if(!(i%5))
            printf("%d",i);
        printf("\n");
    }
    printf("0    5    10   15   20   25   30   35   40   45   50\n");
           
    return;
}