/******************************************************************************
* 16.216 ECE Application Programming                                          *
* Instructor: M. Geiger                                                       *
* 09/17/12                                                                    *
* prog2_io.c: Basic I/O and Operations                                        *
*                                                                             *
* Author: David Tyler                                                         *
* SN: 00952042                                                                *
*                                                                             *
* $fortune -o                                                                 *
* "Dear Dad, you are getting quite old;                                       *
* Your assets, I think, should be sold,                                       *
* And given to me,                                                            *
* So that you can be free,                                                    *
* To live out those years they call gold."                                    *
******************************************************************************/
#include <stdio.h>

#define pi 3.141592653589793238462643383279502884197169399375105820974944592307
#define sqr(x) ((x)*(x)) //shortcut to square

//function main: init vars, read in input, calculate&output dimensions
void main()
{
	double rsph; //sphere radius
	double rcyl,hcyl; //cylinder radius,height
	double lpri,wpri,hpri; //prism length,width,height

	//get input values
	printf("Enter radius of sphere (cm): ");
	scanf("%lf",&rsph);

	printf("Enter radius and height of cylinder (cm): ");
	scanf("%lf%lf",&rcyl,&hcyl);

	printf("Enter length, width, and height of prism (cm): ");
	scanf("%lf%lf%lf",&lpri,&wpri,&hpri);

	//calculate dimensions and print for each shape
	printf("\nSPHERE\n");
	printf("Radius: %lf cm\n",rsph);
	printf("Surface area: %lf square cm\n",4*pi*sqr(rsph));
	printf("Volume: %lf cubic cm\n",4.0/3.0*pi*(sqr(rsph)*rsph));

	printf("\nCYLINDER\n");
	printf("Radius: %lf cm\n",rcyl);
	printf("Height: %lf cm\n",hcyl);
	printf("Surface area: %lf square cm\n",(2*pi*sqr(rcyl))+(2*pi*rcyl*hcyl));
	printf("Volume: %lf cubic cm\n",pi*sqr(rcyl)*hcyl);

	printf("\nRECTANGULAR PRISM\n");
	printf("Length: %lf cm\n",lpri);
	printf("Width: %lf cm\n",wpri);
	printf("Height: %lf cm\n",hpri);
	printf("Surface area: %lf square cm\n",(2*lpri*wpri)+(2*wpri*hpri)+(2*lpri*hpri));
	printf("Volume: %lf cubic cm\n",lpri*wpri*hpri);
}