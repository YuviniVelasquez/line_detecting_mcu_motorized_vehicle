//===========================================================================
// File Name : interrupts_timers.c
//
// Description: This file contains timers
//
// Author: Yuvini Velasquez
// Date: 9/11/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================

#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

volatile char one_time;
unsigned int LCD_COUNTER;
unsigned int TIME_SEQUENCE_COUNTER;
unsigned int LCD_BACKLITE_COUNTER;
volatile unsigned int p4_counter ;
volatile unsigned int p2_counter ;
volatile unsigned int enable_counter1;
volatile unsigned int enable_counter2;
volatile unsigned int enable_counter10;
volatile unsigned int enable_counter20;
volatile unsigned int run_complete;    //p5
volatile unsigned int pause_complete;      //p5
extern volatile unsigned int time_run;         //p5
extern volatile unsigned int time_pause;       //p5
volatile unsigned int DEBOUNCER_COUNTER1;
volatile unsigned int DEBOUNCER_COUNTER2;
volatile unsigned int run_counter;
volatile unsigned int pause_counter;
volatile unsigned int Time_Sequence;
extern volatile unsigned char update_display;
extern volatile unsigned char display_changed;
extern volatile unsigned int circle_timer_count;
extern volatile unsigned int Time_Sequence;
extern volatile unsigned int one_s_passed_port;
extern volatile int switch_pressed;
unsigned int local_time_run;
unsigned int local_time_pause;
extern unsigned int called_off;
extern unsigned int state_demo ;
unsigned int update_display_counter;
volatile unsigned int one_sec_count;
unsigned int enable_sec_count;
unsigned int counter_second;
unsigned int one_sec_clear_array;
unsigned volatile int clear_array;
extern unsigned int display_menu_state;
volatile unsigned int five_sec_count;
extern volatile int p2_pressed;
volatile extern unsigned int UCA0_index;
extern char test_command[10];
extern char message_keeper[10];
int state;
extern unsigned int enable_200ms_counter;
int counter_200ms;
extern volatile unsigned int low_once;
volatile unsigned int enable_setup_commands;
volatile unsigned int enable_command_counter; 
extern volatile unsigned int command_time_counter;
unsigned int enable_adc;
unsigned int adc_counter;
unsigned int circle_timer;                      //overall timer
volatile unsigned int enable_circle_timer;               //enables circuit timer
unsigned int circle_timer_interrupt_counter;    //counts every 5 ms

#pragma vector = TIMER0_B0_VECTOR// TIMERB0_CCR0, DEFINITION GIVEN BY SPECS//CURRENTLY STOPPING EVERY 5 MS
__interrupt void Timer0_B0_ISR(void){
//------------------------------------------------------------------------------
// TimerB0 0 Interrupt handler
//----------------------------------------------------------------------------
//...... Add What you need happen in the interrupt ......//current interrupt 5ms

//Time_Sequence counter, case enabler, reset
  TIME_SEQUENCE_COUNTER++;
  update_display_counter++;
  
  if(enable_command_counter ==1){
    command_time_counter++;
  }
  if(enable_200ms_counter ==1){
  counter_200ms++;
  }
  if(counter_200ms>=40){
  low_once = 2; 
  enable_200ms_counter =0;
  counter_200ms =0;
  }
    if(low_once == 2){
      P5SEL0 |= IOT_RESET;             //IOT_RESET signal selection
      P5SEL1 |= IOT_RESET;             //IOT_RESET signal selection
      low_once =3;

    }
  if(TIME_SEQUENCE_COUNTER == EVERY_10_MS){       //Every 10 ms
      Time_Sequence++;
      TIME_SEQUENCE_COUNTER = RESET_COUNTER;
      one_time = YES;
  }
  if(update_display_counter > EVERY_200_MS){
      update_display = YES;
      update_display_counter = RESET_COUNTER;    
  }
  if(enable_adc){
  adc_counter++;
  }
  if(adc_counter >= EVERY_10_MS){
   ADCCTL0 |= ADCENC; // Enable Conversions
   ADCCTL0 |= ADCSC; // Start next sample
   adc_counter=RESET_COUNTER;
  }
  if(enable_circle_timer){
      circle_timer_interrupt_counter++;
  }
  if(circle_timer_interrupt_counter >= 210){      //every second
    circle_timer++;
    circle_timer_interrupt_counter =0;
  }
  
  //five sec counter
  if(five_sec_count == 1){
      enable_sec_count = 1;
  }
  if(enable_sec_count){
    counter_second++;
  }
  if(counter_second > 1000 ){
      enable_sec_count = 0;
      five_sec_count = 2;        //done sec
      counter_second =0;
      enable_setup_commands = 1;        //enables dissasemby and port number
  } 

TB0CCR0 += TB0CCR0_INTERVAL; // Add Offset to TBCCR0
//----------------------------------------------------------------------------
}
#pragma vector=TIMER0_B1_VECTOR //Timer b0 ccr1 and others
__interrupt void TIMER0_B1_ISR(void){
//----------------------------------------------------------------------------
// TimerB0 1-2, Overflow Interrupt Vector (TBIV) handler
//----------------------------------------------------------------------------
switch(__even_in_range(TB0IV,14)){
case 0: break; // No interrupt
case 2: // CCR1 not used
//...... Add What you need happen in the interrupt ......
  //if sw1 var is is  
  //count up debounce time
  //if debounce count is met
  //enable switch interrupt again
  //turn off timer as long as sw2 is not also being debounced
  if(switch_pressed == SWITCH_4_PRESSED){
      enable_counter1 = YES;
      switch_pressed = SWITCH_PRESSED_RESET;
  }else if(switch_pressed == SWITCH_2_PRESSED){
      enable_counter2 = YES;
      switch_pressed = SWITCH_PRESSED_RESET;        
  }
  
  if(enable_counter1){
    DEBOUNCER_COUNTER1++;
  }
  if(enable_counter2){
    DEBOUNCER_COUNTER2++;
  }
  
      if(DEBOUNCER_COUNTER2 >= ONE_S_AT_50MS ){
        P2IE |= SW2;                  // P2.6 interrupt enable
        DEBOUNCER_COUNTER2 = RESET_COUNTER;
        enable_counter2 = NO;
        p2_counter++;
        one_s_passed_port = YES;
      }

      if(DEBOUNCER_COUNTER1 >= ONE_S_AT_50MS){
        P4IE |= SW1;                  // P2.6 interrupt enable
        DEBOUNCER_COUNTER1 = RESET_COUNTER;
        enable_counter1 = NO;
        p4_counter++;
        one_s_passed_port = YES;
        //wheels_forwardpwm();
      }
  
TB0CCR1 += TB0CCR1_INTERVAL50; // Add Offset to TBCCR1
break;
case 4: // CCR2 not used
//...... Add What you need happen in the interrupt ......
//LCD counter and display
  
TB0CCR2 += TB0CCR2_INTERVAL2; // Add Offset to TBCCR2
break;
case 14: // overflow
//...... Add What you need happen in the interrupt ......
break;
default: break;
}
//----------------------------------------------------------------------------
}

