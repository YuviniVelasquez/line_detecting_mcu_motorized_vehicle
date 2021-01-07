//===========================================================================
// File Name : line_detect.c
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

extern unsigned int left_val;
extern unsigned int right_val;

extern volatile unsigned int line_state;
extern volatile unsigned int one_sec_count;
extern unsigned int enable_sec_count;
extern unsigned int counter_second;

void line_detect(void){
//------------------------------------------------------------------------------
// LED Configurations
//------------------------------------------------------------------------------
  
  if (line_state == LINE_STATE_1){
    one_sec_count = START_1SEC;  //wait for 1 second
    line_state = LINE_STATE_2 ;
  }
  if((line_state == LINE_STATE_2)&&(one_sec_count == ONE_SEC_COMPLETED)){   //once a second has passed and it's in state 2
    if ((left_val > DARK_VALUE_L1)||(right_val > DARK_VALUE_L1 )){    //check if there is a black like
        line_state=LINE_STATE_3;
        wheels_offpwm();
        one_sec_count = START_1SEC;
    }  
  }
  if((line_state == LINE_STATE_3)&&(one_sec_count == ONE_SEC_COMPLETED)){
        wheels_clkwiseslow_pwm();
        line_state = LINE_STATE_4;
      }
  if(line_state == LINE_STATE_4){
    if ((left_val > DARK_VALUE_L4 )&&(right_val < DARK_VALUE_L1_5  )){    //check if there is a white line
        line_state=LINE_STATE_5;
        wheels_offpwm();

    }
  }
  

  
//------------------------------------------------------------------------------
}