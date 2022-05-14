#include "instruction.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *PROGRAM_MEMORY_START;
void *INST_MEM;
void *DATA;
void *HEAP;
void *STACK;
void *PROGRAM_MEMORY_END;



void print_instruction(Instruction* i){
 (i->opcode) ? printf("%s ", i->opcode) : printf("error");
 (i->op_1) ? 
   (i->op_2) ? 
      printf("%s %s \n", i->op_1, i->op_2) 
    : printf("%s \n", i->op_1) 
   : printf("\n");
}

void create_instruction(char *str, Instruction* i){
  i->opcode= strtok(str, " ");
  i->op_1= strtok(NULL, ",");
  i->op_2= strtok(NULL, " ");
}

void print_program(){
  int i = 0;
  while(INST_MEM+(i*sizeof(Instruction))){
    print_instruction(INST_MEM+(i*sizeof(Instruction))); 
  }
}

void load_program(char * filename){
  //int store_label[1028];
  FILE *fp;
  fp = fopen(filename,"r");
  if(fp == NULL){
    printf("Seems like no program was loaded in\n");
    return;
  }
  char buffer[100];
  int i = 0;
  while(1){
    if(fgets(buffer, 100, fp) == NULL){
      break;
    }else{
      create_instruction(buffer, INST_MEM+(i*sizeof(Instruction)));
      printf("%s is buffer\n", buffer);
      i++;
    }
  }
}



int main(int argc, char **argv){
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
  unsigned sizeof_PRGM = (sizeof(Instruction) * 256) + (sizeof(void*) * 24) + (sizeof(void*) * 1028) + (sizeof(void*)* 1028);
  PROGRAM_MEMORY_START = malloc(sizeof_PRGM);
  INST_MEM = PROGRAM_MEMORY_START;
  
  FILE *fp;
  fp = fopen(argv[1],"r");
  if(fp == NULL){
    printf("Seems like no program was loaded in\n");
  }
  char buffer[100];
  int i = 0;
  while(1){
    if(fgets(buffer, 100, fp) == NULL){
      break;
    }else{
      create_instruction(buffer, INST_MEM+(i*sizeof(Instruction)));
      printf("%s is buffer\n", buffer);
      i++;
    }
  }


  //load_program(argv[1]);
  //print_program();

  

}


