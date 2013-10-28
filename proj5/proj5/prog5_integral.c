/******************************************************************************
* 16.216 ECE Application Programming                                          *
* Instructor: M. Geiger                                                       *
* 09/17/12                                                                    *
* prog5_integral.c: Integral Approximation with Functions                     *
*                                                                             *
* Author: David Tyler                                                         *
* SN: 00952042                                                                *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <math.h>

void cls(void); //deal with clearing scanf on bad input
double f(double);
double integrate(double, double, int);

//function main: init vars, read in input, manage state machine
void main()
{
    double a,b;
    int n,args;

    int state=0;
    while(1)
    {
        switch(state)
        {
            case 0: //get endpoints and check for errors
                printf("\nEnter endpoints of interval to be integrated (low hi): ");
                args = scanf("%lf%lf",&a,&b);
                if(a>=b) {
                    printf("Error: low must be < hi");
                    break; }
                if(args!=2) {
                    printf("Error: Improperly formatted input");
                    cls();
                    break; }
                state++;
                break;
            case 1: //get number trap and check errors
                printf("Enter number of trapezoids to be used: ");
                args=scanf("%d",&n);
                 if(args!=1) {
                    printf("Error: Improperly formatted input");
                    cls();
                    break; }
                 if(n<1) {
                     printf("Error: numT must be >=1");
                     break; }
                 state++;
                 break;
            case 2: //output result
                printf("Using %d trapezoids, integral between %lf and %lf is %lf\n",n,a,b,integrate(a,b,n));
                state++;
            case 3: //query for next state, check errors
                printf("Evaluate another interval (Y/N)? ");
                scanf(" %c",&args);
                if(args=='y' || args=='Y')
                    state=0;
                else if(args=='n' || args =='N')
                    return;
                else
                    printf("Error: must enter Y or N");
                break;
        }
    }
}

void cls() //clear input buffer
{
    char j;
    scanf("%c",&j);
    if(j=='\n')
        return;
    cls(); 
}

double f(double x) //calc y of given function from x
{
    return(sin(x)+(x*x)/10);
}

double integrate(double a, double b, int n) //integrate
{
    double interval;
    double y0,y1;
    double area;
    int i;

    interval = b-a;
    if (interval<0)
        interval*=-1; //find absolute value
    interval = interval/n; //height of traps
    area = 0;
    //area of trap: (b1+b2)/2*h or ((y0+y1)/2)*interval
    for(i=0;i<n;i++)
    {
        y0=f(a+interval*i); //side 1
        y1=f(a+interval*(i+1)); //side 2
        area+=(y0+y1)*.5*interval; //accumlate area
    }

    return area;
}

