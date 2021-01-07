//===========================================================================
// File Name : p3_switch.c
//
// Description: This will change port 3.4 from GP I/O to SMCLK
//
// Author: Yuvini Velasquez
// Date: 9/27/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================
#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

void Init_Port3(int p3_4selector){
//------------------------------------------------------------------------------
// PORT Configurations
//------------------------------------------------------------------------------
// Turns on both LEDs
  if (p3_4selector == USE_GPIO){
    P3SEL0 &= ~SMCLK_OUT;             //SMCLK signal selection
    P3SEL1 &= ~SMCLK_OUT;            //SMCLK signal selection
    
  }
  else if (p3_4selector == USE_SMCLK){
    P3SEL0 |= SMCLK_OUT;             //SMCLK signal selection
    P3SEL1 &= ~SMCLK_OUT;            //SMCLK signal selection
  }
  else{
    P3SEL0 &= ~SMCLK_OUT;             //SMCLK signal selection
    P3SEL1 &= ~SMCLK_OUT;            //SMCLK signal selection
  }
//------------------------------------------------------------------------------
}