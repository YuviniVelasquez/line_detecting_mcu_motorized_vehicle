//===========================================================================
// File Name : led.c
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


unsigned int p4_counter ;
unsigned int p2_counter ;

void switch_func(void){
   
  if(!(P4IN & SW1)){
    p4_counter ++;
  }
  if(!(P2IN & SW2)){
    p2_counter ++;
  }
  
  if (p4 == 1 ){
    circle();
    if(circle_timer_count >= 22){
          stop_wheels();
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
}