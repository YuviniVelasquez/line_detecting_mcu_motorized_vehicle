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

extern volatile unsigned int one_s_passed_port;
unsigned int state_demo ;
volatile unsigned int time_run;
volatile unsigned int time_pause;
extern volatile unsigned int run_complete;    //p5
extern volatile unsigned int pause_complete;      //p5
extern volatile unsigned int run_counter;
unsigned int display_menu_state;
unsigned int called_off;
unsigned int one_time_state;
void forward_rev(void){
//------------------------------------------------------------------------------
// Fordward Reverse demo Configurations
//------------------------------------------------------------------------------
//Checking if function has been called
  if(one_s_passed_port){
    one_s_passed_port = NO;
    state_demo = STATE_1; 
    one_time_state = YES;
    
  }
  if((state_demo == STATE_1)&&(one_time_state)){
        one_time_state = NO;
        display_menu_state = YES;       //forward
        display_menu();
        wheels_forwardpwm();
  }else if(run_counter == TIME_1){
        display_menu_state = STATE_2;       //off
        display_menu();
        wheels_offpwm();
  }else if(run_counter == TIME_2){
        display_menu_state = STATE_3;       //reverse
        display_menu();
        wheels_reversepwm();
  }else if(run_counter == TIME_3){
        display_menu_state = STATE_2;       //off
        display_menu();
        wheels_offpwm();
  }else if(run_counter == TIME_4){
        display_menu_state = STATE_1;       //forward
        display_menu();
        wheels_forwardpwm();
  }else if(run_counter == TIME_5){
        display_menu_state = STATE_2;       //off
        display_menu();
        wheels_offpwm();
  }else if(run_counter == TIME_6){
        display_menu_state = STATE_4;       //clock-wise
        display_menu();
        wheels_clkwise_pwm();
  }else if(run_counter == TIME_7){
        display_menu_state = STATE_2;       //off
        display_menu();        
        wheels_offpwm();
  }else if(run_counter == TIME_8){
        display_menu_state = STATE_5;       //ctr-clockwise
        display_menu();
        wheels_ctrclkwise_pwm();
  }else if(run_counter == TIME_9){
        display_menu_state = STATE_2;       //off
        display_menu();
        wheels_offpwm();
  }
  

//------------------------------------------------------------------------------
}