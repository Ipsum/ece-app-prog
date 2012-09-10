/******************************************************************************
* 16.216 ECE Application Programming                                          *
* Instructor: M. Geiger                                                       *
* 09/09/12                                                                    *
* prog1_simple.c: A Simple C Program to demostrate printf()                   *
*                                                                             *
* Author: David Tyler                                                         *
* SN: 00952042                                                                *
*                                                                             *
* NOTE: Professor I hope you don't mind if I had a little fun with this       *
******************************************************************************/

#include <stdio.h>

//create struct named student to hold output info
struct {
	char *name; //array of chars to make string
	char *major;
	char *year;
	char *classn;
} student;

//prototype functions
void addinfo();
void print();

//main: call funct to populate struct then call funct to print
void main()
{
	addinfo();
	print();
}
//addinfo: populate student struct
void addinfo()
{
	student.name = "David Tyler";
	student.major = "Computer Engineer";
	student.year = "Junior";
	student.classn = "16.216: ECE Application Programming (Fall 2012)";
}
//print: print out student struct contents
void print()
{
	printf("%s\n",student.name);
	printf("Major: %s\n",student.major);
	printf("Class: %s\n",student.year);
	printf("%s\n",student.classn);
}