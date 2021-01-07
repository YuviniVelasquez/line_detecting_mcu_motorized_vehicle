//===========================================================================
// File Name : clockcount.c
//
// Description: This file divides the clock speed using counters to be used in different applications
//such as tires speed for figures,counters, etc
// Author: Yuvini Velasquez
// Date: 9/11/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================

#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

extern volatile unsigned int Time_Sequence;
//extern volatile unsigned int clockdiv_count = RESET_COUNTER;
//clockdiv_count = 0; // Reseting counter
volatile unsigned int state;
unsigned int time_follower = 0;
unsigned int delay_counter = 0;
extern volatile unsigned int circle_timer_count;// =0;


void fsm (int casefsm){
  if(casefsm == 0){
    //delay
//    state=0;
//    if(time_follower != Time_Sequence ){
//      time_follower = Time_Sequence;
//      delay_counter ++;
 
//    if (delay_counter >= 500){
//    state=1;
//    circle_timer_count =0;
//    }    
  if ( (!(P4IN & SW1))||(!(P2IN & SW2))) {                    //Project 4 SW enable 
      circle_timer_count =0;
      state = 1;
  }
  }else if(casefsm == 1){
    if ( (!(P4IN & SW1))||(!(P2IN & SW2))) {                    //Project 4 SW enable 
      state = 2;  
  }
  }else if(casefsm == 2){
  }else {
  }
  




}