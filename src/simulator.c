#include "instruction.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
Instruction I_0;
char inst[] = "ADD";
char op1[] = "AL";
char op2[] = "AL";
I_0.opcode = inst;
I_0.op_1 = op1;
I_0.op_2 = op2;
printf("Size of Instruction %lu\n", sizeof(I_0)); 
}






