//===========================================================================
// File Name : switchcount.c
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

extern volatile int emitter_enable;
extern volatile unsigned int p4_counter ;

void emitter_control(void){
//------------------------------------------------------------------------------
// Emitter control to turn on/off
//------------------------------------------------------------------------------
  if((emitter_enable ==1) && (p4_counter == 1)){
          P5OUT |= IR_LED;
          emitter_enable = 0;
  }
//------------------------------------------------------------------------------
}