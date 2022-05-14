#include "instruction.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




void print_instruction(Instruction* i){
 (i->opcode) ? printf("%s ", i->opcode) : printf("Error no line\n");
 (i->op_1) ? (i->op_2) ? printf("%s %s \n", i->op_1, i->op_2) : printf("%s \n", i->op_1) : printf("\n");
}

void create_instruction(char *str, Instruction* i){
  i->opcode= strtok(str, " ");
  i->op_1= strtok(NULL, ",");
  i->op_2= strtok(NULL, " ");
}

void *PROGRAM_MEMORY_START;
void *INST_MEM;
void *DATA;
void *HEAP;
void *STACK;
void *PROGRAM_MEMORY_END;


int main(){
  //  OBJECTIVE:
  //    Quick loop to try and write to instruction memory
  //      Instruction memory is an array of (max)128 instructions (INST_MEM)
  //              NOTE: We will have fixed sized INST_MEM, DATA + limited size of HEAP, STACK
  //      Do we need to create register file? (Only the ip is needed so far, might as well)
  //      
  //      Create parser at the same time
  //        Decoding instruction will happen for each instruction, so we just need to add simple
  //        checks for number of opcodes and such (We will consider what to do about labels there).
  //          
  //    CRUCIAL NOTE COPY SOMEWHERE ELSE LATER: The program instructions are assumed to start from 0x00
  unsigned sizeof_PRGM = (sizeof(Instruction) * 128) + (sizeof(int) * 24) + (sizeof(int) * 1028) + (sizeof(int)* 1028);
  PROGRAM_MEMORY_START = malloc(sizeof_PRGM);
  INST_MEM = PROGRAM_MEMORY_START;
  //Instruction *INST_MEM = INST_MEM;
  for(int i = 0; i < 33; i++){
  char str[24] = "jump LABEL";
    create_instruction(str, (INST_MEM+(i*sizeof(Instruction)))); 
  }
  
  for(int i = 0; i < 33; i++){
    print_instruction((INST_MEM+(i*sizeof(Instruction)))); 
  }
   

}







