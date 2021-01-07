//===========================================================================
// File Name : figure_call.c
//
// Description: This file will call which figure to start, how much time and when to stop
//
// Author: Yuvini Velasquez
// Date: 10/2/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================

#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

extern unsigned int figure;
extern volatile unsigned int circle_timer_count;
volatile unsigned int command_call;
extern volatile unsigned int enable_command_counter;
volatile unsigned int command_time_counter;
extern volatile unsigned int command_library_state;
extern volatile unsigned int command_library1;
extern volatile unsigned int command_library2;
extern volatile unsigned int command_library3;
unsigned int commands_completed;
extern unsigned int stack_row;
extern volatile unsigned int arrived_state_int;
extern volatile unsigned char display_changed;


void figure_call(void){
//------------------------------------------------------------------------------
// Calling figures, executing time, stopping
//------------------------------------------------------------------------------
     if(figure == fcircle){
        circle();
          if(circle_timer_count >= circle_limit){
            stop_wheels();     
          }
     }else if (figure == finfinity){
        infinity();
          if(circle_timer_count >= infinity_limit){
            stop_wheels();
          }
      }else if (figure == ftriangle){
        triangle();
          if(circle_timer_count >= triangle_limit){
            stop_wheels();
          }
      }    
//------------------------------------------------------------------------------
}

void command_call_timed(void){
//------------------------------------------------------------------------------
// Calling figures, executing time, stopping
//------------------------------------------------------------------------------
     if(command_call == FORWARD_2_SECS){
        wheels_forwardpwm();
        enable_command_counter =YES;
          if(command_time_counter >= TWO_SECS_LIMIT){
            wheels_offpwm();
            command_call = ONE_SEC_DEBOUNCER;
            command_time_counter = RESET_COUNTER;
            enable_command_counter =NO;
            commands_completed++;
          }
     }else if (command_call == BACK_1_SEC){
        wheels_reversepwm();
        enable_command_counter =YES;
          if(command_time_counter >= ONE_SEC_LIMIT){
            wheels_offpwm();
            command_call = ONE_SEC_DEBOUNCER;
            command_time_counter = RESET_COUNTER;
            enable_command_counter =NO;
            commands_completed++;
          }
      }else if (command_call == RIGHT_45_DEGREES){
       wheels_clkwise_pwm();
       enable_command_counter =YES;  
          if(command_time_counter >= FOURTY_FIVE_D_LIMIT){
            wheels_offpwm();
            command_call = ONE_SEC_DEBOUNCER;
            command_time_counter = RESET_COUNTER;
            enable_command_counter =NO;
            commands_completed++;
          }
      }else if (command_call == LEFT_45_DEGREES){
        wheels_ctrwise_pwm();
        enable_command_counter =YES;
          if(command_time_counter >= FOURTY_FIVE_D_LIMIT_LEFT){
            wheels_offpwm(); 
            command_call = ONE_SEC_DEBOUNCER;
            command_time_counter = RESET_COUNTER;
            enable_command_counter =NO;
            commands_completed++;
          }
      }else if (command_call == RIGHT_10_DEGREES){
      wheels_clkwise_pwm();
        enable_command_counter =YES;
          if(command_time_counter >= TEN_D_LIMIT){
            wheels_offpwm(); 
            command_call = ONE_SEC_DEBOUNCER;
            command_time_counter = RESET_COUNTER;
            enable_command_counter =NO;
            commands_completed++;
          }
      }else if (command_call == LEFT_10_DEGREES){
       wheels_ctrwise_pwm();
        enable_command_counter =YES;
          if(command_time_counter >= TEN_D_LIMIT){
            wheels_offpwm(); 
            command_call = ONE_SEC_DEBOUNCER;
            command_time_counter = RESET_COUNTER;
            enable_command_counter =NO;
            commands_completed++;
          }
      }else if (command_call ==FORWARD_5_SECS){
        wheels_forwardpwm();
        enable_command_counter =YES;
          if(command_time_counter >=FIVE_SECS_LIMIT ){
            wheels_offpwm(); 
            command_call = ONE_SEC_DEBOUNCER;
            command_time_counter = RESET_COUNTER;
            enable_command_counter =NO;
            commands_completed++;
          }
      }else if (command_call == RIGHT_180_D){
        wheels_ctrwise_pwm(); 
        enable_command_counter =YES;
          if(command_time_counter >= ONE_EIGHTY_LIMIT ){
            wheels_offpwm(); 
            command_call = ONE_SEC_DEBOUNCER;
            command_time_counter = RESET_COUNTER;
            enable_command_counter =NO;
            commands_completed++;
          }
      }else if (command_call == CHANGE_ARRIVED_STATE){
            wheels_offpwm(); 
            GREEN_LED_OFF;
            RED_LED_ON;
            arrived_state_int ++;
            command_call = ONE_SEC_DEBOUNCER;
            command_time_counter = RESET_COUNTER;
            commands_completed++;
            enable_display_update();
            display_changed = YES;
          
      }

     if(command_call == ONE_SEC_DEBOUNCER){
        enable_command_counter =YES;
        if(command_time_counter >= HALF_SEC_LIMIT){     //USED TO BE ONE_SEC_LIMIT
                     // command_library_state++;
                      command_call = OFF;
                      command_time_counter = RESET_COUNTER;
                      enable_command_counter =NO;          
                      if( commands_completed == stack_row){
                            commands_completed =CLEAR_COUNTER;
                            command_library1=CLEAR_COMMAND;
                            command_library2=CLEAR_COMMAND;
                            command_library3=CLEAR_COMMAND;
                            stack_row=CLEAR_COUNTER;
                            GREEN_LED_ON;
                            RED_LED_OFF;
                      }
        }
      }    
//------------------------------------------------------------------------------
}


