/******************************************************************************
* 16.216 ECE Application Programming                                          *
* Instructor: M. Geiger                                                       *
* 10/17/12                                                                    *
* prog4_loops.c: Working with Loops                                           *
*                                                                             *
* Author: David Tyler                                                         *
* SN: 00952042                                                                *
*                                                                             *
* "I'm not a real programmer. I throw together things until it works then     *
* I move on. The real programmers will say 'Yeah it works but you're leaking  *
* memory everywhere. Perhaps we should fix that.' I’ll just restart Apache    *
* every 10 requests."                                                         *
* -Rasmus Lerdorf, creator of PHP                                             *
******************************************************************************/
#include <stdio.h>

//prototypes
int gcd(int num, int den);
double e(int n);
int fact(int x);

//function main: init vars, handle main input loop, call functions to calc
void main()
{
    char cmd; //user command
    int n,num,den,fgcd; //n=series length,num=numerator,
                        //den=denominator,fgcd=final gcd
    while(1) 
    {
        printf("Enter single character command <F | E | Q>: ");
        scanf(" %c",&cmd); //read in command ignoring whitespace

        switch(cmd)
        {
        case 'Q':
        case 'q':
            //if q or Q, exit program
            return;

        case 'F':
        case 'f':
            //get fraction and calculate gcd from that
            printf("Enter fraction numerator/denominator: ");
            scanf("%i/%i",&num,&den);

            if(den==0) //avoid dividing by 0
            {
                printf("Error: fraction cannot have denominator of 0\n\n");
            }
            else
            {
                num = num < 0 ? -num : num; //make sure we are dealing with pos
                den = den < 0 ? -den : den;
                fgcd = gcd(num,den); //calculate gcd and store result
                printf("%d/%d reduces to %d/%d (GCD = %d)\n\n",
                        num,den,num/fgcd,den/fgcd,fgcd);
            }
            break;

        case 'E':
        case 'e':
            //get number of iterations and compute e
            printf("Enter value for n (0 <= n <= 12): ");
            scanf("%d",&n);

            if(0<=n && n<=12) //check bounding
                printf("With n = %d, e is approximately %.9lf\n\n",n,e(n));
            else
                printf("Error: n must satisfy 0 <= n <= 12\n\n");
            break;

        default:
            //whoops the user didn't enter q f or e
            printf("Error: invalid command\n\n");
            break;
        }
    }
}

//function gcd: recursively compute gcd: den or num = 0 base case,
//take numerator and denominator, return gcd as an int
int gcd(int num, int den)
{
    if(den==0)
        return(num);
    if(num==0)
        return(den);

    return(gcd(den, num % den));
}

//function e: recursively calc e, base case n=0
//n = number of expansions, e is returned as a double on function completion
double e(int n)
{
    return( (n == 0) ? (1.0 / fact(n)) : e(n - 1) + (1.0 / fact(n)) );
}

//function fact: recurs calc the factorial of x, return result as int.
int fact(int x)
{
    return( (x >= 1) ? x * fact(x-1) : 1);
}