/* instructions.h */
#ifndef __INSTRUCTIONS_H__
#define __INSTRUCTIONS_H__

typedef enum {
  OP_LA, OP_LV, OP_LC, OP_LI, OP_INT, OP_DCT, OP_J, OP_FJ, OP_HL, OP_ST,
  OP_CALL, OP_EP, OP_EF, OP_RC, OP_RI, OP_WRC, OP_WRI, OP_WLN,
  OP_AD, OP_SB, OP_ML, OP_DV, OP_NEG, OP_CV,
  OP_EQ, OP_NE, OP_GT, OP_LT, OP_GE, OP_LE, OP_BP
} OpCode;

typedef struct {
  OpCode op;
  int p;
  int q;
} Instruction;

void printInstruction(Instruction* instr);

#endif