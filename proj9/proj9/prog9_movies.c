#include <stdio.h>
#include <string.h>

#define CMP(s) !(strcmp(cmd,(s)))

void stripnl(char * s);

typedef struct {
    int number;
    char name[40];
    char rating[5];
    int length;
    char times[20];
} movie;

int main() {
    FILE * fp;
    char * clr;
    int check=1;
    int i;
    movie movies[10]={0};

    fp = fopen("schedule.txt","r");
    if(!fp)
    {
        printf("Error: Input file not found\n");
        return 1;
    }
    for(i=0;i<10;i++)
    {
        movie m={0,{'\0'},{'\0'},0,{'\0'}};

        fscanf(fp,"%d",&m.number);
        fscanf(fp,"[^\n]",m.name);
        fscanf(fp,"%c",&clr);
        m.name[strlen(m.name)]='\0';
        //stripnl(m.name);
        fscanf(fp,"[^\n]",m.rating);
        //stripnl(m.rating);
        fscanf(fp,"%d",&m.length);
        fscanf(fp,"[^\n]",m.times);
        //stripnl(m.times);
        if(!m.number)
            i=11;
        else
            movies[i]=m;
    }

    while(1)
    {
        char cmd[10]={0};
        printf("\nEnter command: ");
        scanf(" %s",&cmd);
    
        if( !(strcmp(cmd,"all")) )
        {
            i=0;
            printf("\nTheater Movie (Rating)\n");
            while(movies[i].number>0)
            {
                printf(" %-5d %s (%s)\n",movies[i].number,movies[i].name,movies[i].rating);
                i++;
            }
        }
        else if( !(strcmp(cmd,"number")) )
        {}

        else if( !(strcmp(cmd,"name")) )
        {}
        else if( !(strcmp(cmd,"exit")) )
        {
            return 0;
        }
        else
        {
            printf("The command is invalid");
        }
    }
}

void stripnl(char * s)
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]=='\n')
        {
            s[i]='\0';
            return;
        }
        i++;
    }
    return;
}

            
