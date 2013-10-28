/******************************************************************************
* 16.216 ECE Application Programming                                          *
* Instructor: M. Geiger                                                       *
* 09/28/12                                                                    *
* prog3_decode.c: Instruction Decoding                                        *
*                                                                             *
* Author: David Tyler                                                         *
* SN: 00952042                                                                *
*                                                                             *
* Two bytes meet.  The first byte asks, “Are you ill?”                        *
* The second byte replies, “No, just feeling a bit off.”                      *
******************************************************************************/

#include <stdio.h>

int main(void)
{
	int R [4]; //array of register values
	unsigned int cmd; //encoded instruction
	unsigned int opcode,d,s1,s2; //opcode=(opcode), d=(destination)
								 //s1=(source 1), s2=(source 2)

	//take input from the user
	printf("Enter values for 4 integer registers: ");
	scanf("%d%d%d%d",&R[0],&R[1],&R[2],&R[3]);
	printf("Enter single byte for instruction (in hex): ");
	scanf("%x",&cmd);

	//do some bitwise math to breakup instruction
	opcode=cmd>>6;
	s1=(cmd>>2)&(0x03);
	s2=(cmd)&(0x03);
	d =(cmd>>4)&(0x03);

	switch(opcode) //switch on opcode to do correct math
	{
	case 0: //Add
		printf("R%d = R%d + R%d",d,s1,s2);
		printf("\n   = %d + %d = %d\n",R[s1],R[s2],R[s1]+R[s2]);
		break;
	case 1: //Subtract
		printf("R%d = R%d - R%d",d,s1,s2);
		printf("\n   = %d - %d = %d\n",R[s1],R[s2],R[s1]-R[s2]);
		break;
	case 2: //Multiply
		printf("R%d = R%d * R%d",d,s1,s2);
		printf("\n   = %d * %d = %d\n",R[s1],R[s2],R[s1]*R[s2]);
		break;
	case 3: //Divide
		printf("R%d = R%d / R%d",d,s1,s2);
		printf("\n   = %d / %d = %d\n",R[s1],R[s2],R[s1]/R[s2]);
		break;
	default:
		printf("\nInvalid Opcode!");
	}

	return 0;
}
