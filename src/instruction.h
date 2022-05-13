#ifndef INSTRUCTION_HEADER_GUARD
#define INSTRUCTION_HEADER_GUARD

struct InstructionTag;
typedef struct InstructionTag
{
 char *opcode;
 char *op_1;
 char *op_2; 
}Instruction;

#endif
