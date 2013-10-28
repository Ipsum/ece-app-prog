/******************************************************************************
* 16.216 ECE Application Programming                                          *
* Instructor: M. Geiger                                                       *
* 11/12/12                                                                    *
* prog8_files.c: Instruction Decoding and File I/O                            *
*                                                                             *
* Author: David Tyler                                                         *
* SN: 00952042                                                                *
*                                                                             *
* I am going to win it big tonight and have an extra $4!                      *
******************************************************************************/

#include <stdio.h>

//function main: init vars, open files, read files, write files, do math
int main() {
    FILE * fp; //file pointers
    FILE * fp2;
    int regs[32];
    int check; //check to term program on eof
    unsigned int inst;
    unsigned int opcode;
    unsigned int dest;
    unsigned int src1,src2;
    unsigned int shamt;
    char fname[50];  //file name
    char fname2[50]; //other file name

    //Lets open all of our files
    printf("Enter register file name: ");
    scanf("%s",&fname);
    fp = fopen(fname,"rb");
    if(!fp) //on null pointer, print error and exit
    {
        printf("Error: invalid register file name %s\nProgram will now exit\n",fname);
        return 1;
    }
    fread(regs,16,32,fp); //if file opened correctly, read
    fclose(fp); //done with this, so we close

    printf("Enter program file name: ");
    scanf("%s",&fname);
    printf("Enter output file name: ");
    scanf("%s",&fname2);

    fp = fopen(fname,"r");
    if(!fp)
    {
        printf("Error: invalid program file name %s\nProgram will now exit\n",fname);
        return 1;
    }

    fp2 = fopen(fname2,"w");
    if(!fp2)
    {
        printf("Error: invalid output file name %s\nProgram will now exit\n",fname2);
        return 1;
    }

    while(1) {
       check=fscanf(fp,"%x",&inst);
       if(check<=0) //on these return values from fscanf we are at eof, close files and exit
       {
           fclose(fp);
           fclose(fp2);
           return 0; //EOF
       }
       opcode = (inst & 0xFC000000) >> 26;		// Opcode = upper 6 bits (31-26)
	   dest = (inst & 0x03E00000) >> 21;		// Dest = bits 25-21
	   src1 = (inst & 0x001F0000) >> 16;		// src1 = bits 20-16
	   src2 = (inst & 0x0000F800) >> 11;		// src2 = bits 15-11
	   shamt = (inst & 0x000007C0) >> 6;		// Shift amount = bits 10-6

       switch(opcode) {
       case 1: //add
           fprintf(fp2,"INSTRUCTION %d: %#0.8x\nR%d = R%d + R%d\n   = %d + %d = %d\n\n",
               opcode-1,inst,dest,src1,src2,regs[src1],regs[src2],regs[src1]+regs[src2]);
           regs[dest]=regs[src1]+regs[src2];
           break;
       case 2: //sub
           fprintf(fp2,"INSTRUCTION %d: %#0.8x\nR%d = R%d - R%d\n   = %d - %d = %d\n\n",
               opcode-1,inst,dest,src1,src2,regs[src1],regs[src2],regs[src1]-regs[src2]);
           regs[dest]=regs[src1]-regs[src2];
           break;
       case 3: //multi
           fprintf(fp2,"INSTRUCTION %d: %#0.8x\nR%d = R%d * R%d\n   = %d * %d = %d\n\n",
               opcode-1,inst,dest,src1,src2,regs[src1],regs[src2],regs[src1]*regs[src2]);
           regs[dest]=regs[src1]*regs[src2];
           break;
       case 4: //div
           fprintf(fp2,"INSTRUCTION %d: %#0.8x\nR%d = R%d / R%d\n   = %d / %d = %d\n\n",
               opcode-1,inst,dest,src1,src2,regs[src1],regs[src2],regs[src1]/regs[src2]);
           regs[dest]=regs[src1]/regs[src2];
           break;
       case 5: //lshift
           fprintf(fp2,"INSTRUCTION %d: %#0.8x\nR%d = R%d << %d\n   = %d << %d = %d\n\n",
               opcode-1,inst,dest,src1,shamt,regs[src1],shamt,regs[src1]<<shamt);
           regs[dest]=regs[src1]<<shamt;
           break;
       case 6: //rshift
           fprintf(fp2,"INSTRUCTION %d: %#0.8x\nR%d = R%d >> %d\n   = %d >> %d = %d\n\n",
               opcode-1,inst,dest,src1,shamt,regs[src1],shamt,regs[src1]>>shamt);
           regs[dest]=regs[src1]>>shamt;
           break;
       case 7: //and
           fprintf(fp2,"INSTRUCTION %d: %#0.8x\nR%d = R%d & R%d\n   = %d & %d = %d\n\n",
               opcode-1,inst,dest,src1,src2,regs[src1],regs[src2],regs[src1]&regs[src2]);
           regs[dest]=regs[src1]&regs[src2];
           break;
       case 8: //or
           fprintf(fp2,"INSTRUCTION %d: %#0.8x\nR%d = R%d | R%d\n   = %d | %d = %d\n\n",
               opcode-1,inst,dest,src1,src2,regs[src1],regs[src2],regs[src1]|regs[src2]);
           regs[dest]=regs[src1]|regs[src2];
           break;
       case 9: //xor
           fprintf(fp2,"INSTRUCTION %d: %#0.8x\nR%d = R%d ^ R%d\n   = %d ^ %d = %d\n\n",
               opcode-1,inst,dest,src1,src2,regs[src1],regs[src2],regs[src1]^regs[src2]);
           regs[dest]=regs[src1]^regs[src2];
           break;
       default:
           printf("\n\nOh god something terrible happened");
       }
    }
    return 1;
}
