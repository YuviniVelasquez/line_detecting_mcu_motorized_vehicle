//===========================================================================
// File Name : init.c
//
// Description: This file contains the Initialization for all port pins
//
// Author: Yuvini Velasquez
// Date: 9/11/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================

#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"
//variables
extern char display_line[NUM_OF_ROWS][NUM_0F_COLS];
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;
extern char *display[NUM_OF_ROWS];

void Init_Conditions(void){
//------------------------------------------------------------------------------
  int i;

  for(i=START_COUNTER;i<NUM_0F_COLS ;i++){
    display_line[DISPLAY_L1][i] = RESET_STATE;
    display_line[DISPLAY_L2][i] = RESET_STATE;
    display_line[DISPLAY_L3][i] = RESET_STATE;
    display_line[DISPLAY_L4][i] = RESET_STATE;
  }
  display_line[DISPLAY_L1][END_OF_ARRAY] = RESET_STATE;
  display_line[DISPLAY_L2][END_OF_ARRAY] = RESET_STATE;
  display_line[DISPLAY_L3][END_OF_ARRAY] = RESET_STATE;
  display_line[DISPLAY_L4][END_OF_ARRAY] = RESET_STATE;

  display[DISPLAY_L1] = &display_line[DISPLAY_L1][INIT_OF_ARRAY];
  display[DISPLAY_L2] = &display_line[DISPLAY_L2][INIT_OF_ARRAY];
  display[DISPLAY_L3] = &display_line[DISPLAY_L3][INIT_OF_ARRAY];
  display[DISPLAY_L4] = &display_line[DISPLAY_L4][INIT_OF_ARRAY];
  update_display = NO;
  update_display_count = NO;
// Interrupts are disabled by default, enable them.
  enable_interrupts();
//------------------------------------------------------------------------------
}
