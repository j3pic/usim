#ifndef USIM_LCADMC_H
#define USIM_LCADMC_H

// See SYS:LCADR;LCADMC LISP canonical version.

// IR FIELDS
#define CONS_IR_OP 05302
#define   CONS_OP_ALU 00	// ASSUMED 0 AND OMITTED IN MANY PLACES FOR BREVITY
#define   CONS_OP_JUMP 01
#define   CONS_OP_DISPATCH 02
#define   CONS_OP_BYTE 03
#define CONS_IR_POPJ 05201
#define CONS_IR_ILONG 05501
#define CONS_IR_STAT_BIT 05601
#define CONS_IR_SPARE_BIT 05701
#define CONS_IR_PARITY_BIT 06001	// Not normally read but returnned by CC-READ-C-MEM-WITH-PARITY.
#define CONS_IR_A_SRC 04012
#define CONS_IR_M_SRC 03206
#define  CONS_FUNC_SRC_INDICATOR 040	// ADD IN FOR FUNCTIONAL SOURCES
#define  CONS_M_SRC_DISP_CONST 040
#define  CONS_M_SRC_MICRO_STACK 041	// USP BITS 28-24, SPCn BITS 18-0
#define  CONS_M_SRC_PDL_BUFFER_POINTER 042
#define  CONS_M_SRC_PDL_BUFFER_INDEX 043
#define  CONS_M_SRC_C_PDL_BUFFER_INDEX 045
#define  CONS_M_SRC_OPC 046
#define  CONS_M_SRC_Q 047
#define  CONS_M_SRC_VMA 050
#define  CONS_M_SRC_MAP 051	// ADDRESSED BY MD, NOT VMA
#define    CONS_MAP_LEVEL_1_BYTE 03005
#define    CONS_MAP_LEVEL_2_BYTE 00030
#define    CONS_MAP_PFR_BIT (01 << 30)
#define    CONS_MAP_PFW_BIT (01 << 31)
#define  CONS_M_SRC_MD 052
#define  CONS_M_SRC_LC 053
#define  CONS_M_SRC_MICRO_STACK_POP 054	// SAME AS MICRO-STACK, BUT ALSO POPS USP
#define    CONS_US_POINTER_BYTE 03005
#define    CONS_US_DATA_BYTE 00023
#define  CONS_M_SRC_C_PDL_BUFFER_POINTER_POP 064
#define  CONS_M_SRC_C_PDL_BUFFER_POINTER 065
#define CONS_IR_A_MEM_DEST 01614
#define   CONS_A_MEM_DEST_INDICATOR 04000	// ADD THIS TO A MEM ADDRESS
#define   CONS_A_MEM_DEST_1777 05777
#define CONS_IR_M_MEM_DEST 01605
#define CONS_IR_FUNC_DEST 02305
#define  CONS_FUNC_DEST_LC 01
#define  CONS_FUNC_DEST_INT_CNTRL 02
#define  CONS_FUNC_DEST_C_PP 010
#define  CONS_FUNC_DEST_PDL_BUFFER_PUSH 011
#define  CONS_FUNC_DEST_C_PI 012
#define  CONS_FUNC_DEST_PDL_BUFFER_INDEX 013
#define  CONS_FUNC_DEST_PDL_BUFFER_POINTER 014
#define  CONS_FUNC_DEST_MICRO_STACK_PUSH 015
#define  CONS_FUNC_DEST_OA_LOW 016
#define  CONS_FUNC_DEST_OA_HIGH 017
#define  CONS_FUNC_DEST_VMA 020
#define    CONS_VMA_LEVEL_1_BYTE 01513
#define    CONS_VMA_LEVEL_2_BYTE 01005
#define  CONS_FUNC_DEST_VMA_START_READ 021
#define  CONS_FUNC_DEST_VMA_START_WRITE 022
#define  CONS_FUNC_DEST_VMA_WRITE_MAP 023
#define    CONS_MAP_LEVEL_1_BYTE_FOR_WRITING 03305	// NOT IDENTICAL TO CONS-MAP-LEVEL-1-BYTE
#define    CONS_VMA_WRITE_LEVEL_1_MAP_BIT (01 << 26)
#define    CONS_VMA_WRITE_LEVEL_2_MAP_BIT (01 << 25)
#define  CONS_FUNC_DEST_MD 030
#define  CONS_FUNC_DEST_MD_START_READ 031
#define  CONS_FUNC_DEST_MD_START_WRITE 032
#define  CONS_FUNC_DEST_MD_WRITE_MAP 033
#define CONS_IR_OB 01402
#define  CONS_OB_MSK 00		// DEPENDS ON THIS =0 FOR BREVITY
#define  CONS_OB_ALU 01
#define  CONS_OB_ALU_RIGHT_1 02
#define  CONS_OB_ALU_LEFT_1 03
#define CONS_IR_MF 01202	// MISCELLANEOUS FUNCTION
#define  CONS_MF_HALT 01
#define CONS_IR_ALUF 00207	// INCLUDING CARRY
#define  CONS_ALU_SETZ (00 << 01)
#define  CONS_ALU_AND (01 << 01)
#define  CONS_ALU_SETM (03 << 01)
#define  CONS_ALU_SETA (05 << 01)
#define  CONS_ALU_XOR (06 << 01)
#define  CONS_ALU_IOR (07 << 01)
#define  CONS_ALU_SETO (017 << 01)
#define  CONS_ALU_SUB 055	// includes ALU-CARRY-IN-ONE
#define  CONS_ALU_ADD (031 << 01)
#define  CONS_ALU_MPM (037 << 01)
#define  CONS_ALU_MPMP1 077
#define  CONS_ALU_MP1 071
#define  CONS_ALU_MSTEP 0100
#define  CONS_ALU_DSTEP 0102
#define  CONS_ALU_RSTEP 0112
#define  CONS_ALU_DFSTEP 0122
#define CONS_IR_Q 00002
#define  CONS_Q_LEFT 01
#define  CONS_Q_RIGHT 02
#define  CONS_Q_LOAD 03
#define CONS_IR_DISP_LPC 03101
#define CONS_IR_DISP_ADVANCE_INSTRUCTION_STREAM 03001
#define CONS_IR_DISP_CONST 04012
#define CONS_IR_DISP_ADDR 01413
#define CONS_IR_BYTL_1 00505
#define CONS_IR_DISP_BYTL 00503
#define CONS_IR_MROT 00005
#define CONS_IR_JUMP_ADDR 01416
#define CONS_IR_JUMP_COND 00007
#define  CONS_JUMP_COND_M_LT_A 041
#define  CONS_JUMP_COND_M_LE_A 042
#define  CONS_JUMP_COND_M_EQ_A 043
#define  CONS_JUMP_COND_PAGE_FAULT 044
#define  CONS_JUMP_COND_PAGE_FAULT_OR_INTERRUPT 045
#define  CONS_JUMP_COND_PAGE_FAULT_OR_INTERRUPT_OR_SEQUENCE_BREAK 046
#define  CONS_JUMP_COND_UNC 047
#define  CONS_JUMP_COND_M_GE_A 0141
#define  CONS_JUMP_COND_M_GT_A 0142
#define  CONS_JUMP_COND_M_NEQ_A 0143
#define  CONS_JUMP_COND_NO_PAGE_FAULT 0144
#define CONS_IR_R 01101
#define CONS_IR_P 01001
#define CONS_IR_N 00701
#define CONS_IR_BYTE_FUNC 01402
#define  CONS_BYTE_FUNC_LDB 01
#define  CONS_BYTE_FUNC_SELECTIVE_DEPOSIT 02
#define  CONS_BYTE_FUNC_DPB 03

// DISPATCH MEMORY BITS
#define CONS_DISP_R_BIT 02001
#define CONS_DISP_P_BIT 01701
#define CONS_DISP_N_BIT 01601
#define CONS_DISP_RPN_BITS 01603
#define CONS_DISP_PARITY_BIT 02101

#define WRITE 1

#define cc_execute(executor, ir)					\
	(executor == WRITE) ? cc_execute_w(ir) : cc_execute_r(ir)

#endif
