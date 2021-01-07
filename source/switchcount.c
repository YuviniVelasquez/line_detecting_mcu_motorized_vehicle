//===========================================================================
// File Name : switchcount.c
//
// Description: This file contains the Initialization for all port pins
//
// Author: Yuvini Velasquez
// Date: 9/11/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================

#include "functions.h"
#include "msp430.h"
#include <string.h>
#include "macros.h"

unsigned int p4_counter;
unsigned int p2_counter;
extern volatile unsigned int circle_timer_count;
extern volatile unsigned int Time_Sequence;

void switch_func(void)
{

  if (!(P4IN & SW1))
  {
    p4_counter++;
    __delay_cycles(WAIT);
    circle_timer_count = RESET_STATE;
    Time_Sequence = RESET_STATE;
  }
  if (!(P2IN & SW2))
  {
    p2_counter++;
    __delay_cycles(WAIT);
  }
}