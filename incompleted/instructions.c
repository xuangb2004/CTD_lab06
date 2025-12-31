/* instructions.c */
#include <stdio.h>
#include "instructions.h"

void printInstruction(Instruction* instr) {
  switch (instr->op) {
  case OP_LA: printf("LA %d,%d", instr->p, instr->q); break;
  case OP_LV: printf("LV %d,%d", instr->p, instr->q); break;
  case OP_LC: printf("LC %d", instr->q); break;
  case OP_LI: printf("LI"); break;
  case OP_INT: printf("INT %d", instr->q); break;
  case OP_DCT: printf("DCT %d", instr->q); break;
  case OP_J: printf("J %d", instr->q); break;
  case OP_FJ: printf("FJ %d", instr->q); break;
  case OP_HL: printf("HL"); break;
  case OP_ST: printf("ST"); break;
  case OP_CALL: printf("CALL %d,%d", instr->p, instr->q); break;
  case OP_EP: printf("EP"); break;
  case OP_EF: printf("EF"); break;
  case OP_RC: printf("RC"); break;
  case OP_RI: printf("RI"); break;
  case OP_WRC: printf("WRC"); break;
  case OP_WRI: printf("WRI"); break;
  case OP_WLN: printf("WLN"); break;
  case OP_AD: printf("AD"); break;
  case OP_SB: printf("SB"); break;
  case OP_ML: printf("ML"); break;
  case OP_DV: printf("DV"); break;
  case OP_NEG: printf("NEG"); break;
  case OP_CV: printf("CV"); break;
  case OP_EQ: printf("EQ"); break;
  case OP_NE: printf("NE"); break;
  case OP_GT: printf("GT"); break;
  case OP_LT: printf("LT"); break;
  case OP_GE: printf("GE"); break;
  case OP_LE: printf("LE"); break;
  case OP_BP: printf("BP"); break;
  default: break;
  }
}