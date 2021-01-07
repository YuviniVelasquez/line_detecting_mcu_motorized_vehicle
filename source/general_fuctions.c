//===========================================================================
// File Name : general_functions.c
//
// Description: This file contains a variety of functions that help initialize IOT 
//
// Author: Yuvini Velasquez
// Date: 9/11/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================

#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"
extern volatile unsigned int enable_setup_commands;
volatile unsigned int enable_iot_port_number;
char iot_commands [STRING_SIZE_30];
extern volatile unsigned int UCA0_index;
extern volatile unsigned int UCA1_index;
extern volatile char command_viewer [STRING_SIZE_30];
extern volatile unsigned int clear_iot_command;
extern volatile char command_stack[STACK_SIZE][STRING_SIZE_30];
volatile unsigned int command_library1;
volatile unsigned int command_library2;
volatile unsigned int command_library3;
extern volatile unsigned int ready_to_read_stack;
extern unsigned int stack_row;
volatile unsigned int command_library_state;
extern volatile unsigned int command_call;


void dissasemby_setup(void){
  if (enable_setup_commands == YES){
    enable_setup_commands = NO_2;
    strcpy(iot_commands," AT+WSYNCINTRL=60000");
    iot_commands[DISSASEMBLY_RETURN]= '\r';
    UCA0_index = RESET_INDEX;
    UCA0IE |= UCTXIE; // Enable TX interrupt
    UCA0TXBUF= iot_commands[UCA0_index];
    //command_viewer[UCA0_index] = iot_commands[UCA0_index];
    enable_iot_port_number = YES;
  }
}

void iot_port_setup(void){
  if (enable_iot_port_number == YES){
    enable_iot_port_number = NO_2;
    strcpy(iot_commands,"AT+NSTCP=34765,1");
    iot_commands[IOT_RETURN]= '\r';
    UCA0_index = RESET_INDEX;
    UCA0IE |= UCTXIE; // Enable TX interrupt
    UCA0TXBUF= iot_commands[UCA0_index];

  }
}

void clear_iot_command_array(void){
  if (clear_iot_command == YES){
    clear_iot_command = NO;
    strcpy(iot_commands,"                            ");
    iot_commands[RETURN_COM_LOCATION]= '\r';
    iot_commands[NULL_COM_LOCATION]= '\n';
  }
}
void clear_stack(void){
  int m;
  int n;
  for(m= FIRST_COMMAND; m <=  THIRD_COMMAND; m++){
    for(n=BEG_COMMAND_CHAR;n<= LAST_COMMAND_CHAR; n++){
        command_stack[m][n] = '\0';
        if(n == RETURN_COM_LOCATION){
          command_stack[m][n] = '\r';
        }else if (n == NULL_COM_LOCATION){
          command_stack[m][n] = '\n';
        }
    } 
  }
}

void command_stack_process(void){

  if(ready_to_read_stack == YES){
    if(stack_row > AT_LEAST_1_COMMAND){
    command_library1 = command_stack[FIRST_COMMAND][FIRST_COMMAND_CHAR];
    }
    if (stack_row >AT_LEAST_2_COMMAND){
        command_library2 = command_stack[SECOND_COMMAND][SECOND_COMMAND_CHAR];
    }
    if(stack_row >AT_LEAST_3_COMMAND){
        command_library3 = command_stack[THIRD_COMMAND][THIRD_COMMAND_CHAR];
    }
   ready_to_read_stack=NO;
  command_library_state = CASE_1; 
  }

  
}

//F forward 2 secs
//B backward 1 sec
//R right 90 degrees
//L left 45 degrees

 void command_library (void){
    switch(command_library_state){
      
      case CASE_0:    
        break;
      case CASE_1:                  
          if(command_library1 == FORWARD_2_SECS ){
            command_call = FORWARD_2_SECS; command_library_state = CASE_2;
          }else if(command_library1 == BACK_1_SEC ){
            command_call = BACK_1_SEC; command_library_state = CASE_2;
          }else if(command_library1 == RIGHT_45_DEGREES ){
            command_call = RIGHT_45_DEGREES; command_library_state = CASE_2;
          }else if(command_library1 == LEFT_45_DEGREES ){
            command_call = LEFT_45_DEGREES;  command_library_state = CASE_2;
          }else if(command_library1 == RIGHT_10_DEGREES ){
            command_call = RIGHT_10_DEGREES;  command_library_state = CASE_2;
          }else if(command_library1 == LEFT_10_DEGREES ){
            command_call = LEFT_10_DEGREES;  command_library_state = CASE_2;
          }else if(command_library1 == FORWARD_5_SECS ){
            command_call = FORWARD_5_SECS;  command_library_state = CASE_2;
          }else if(command_library1 == RIGHT_180_D ){
            command_call = RIGHT_180_D;  command_library_state = CASE_2;
          }else if(command_library1 == CHANGE_ARRIVED_STATE ){
            command_call = CHANGE_ARRIVED_STATE;  command_library_state = CASE_2;
          }else{ break; }
        break;
      case CASE_2:
        break;
      case CASE_3:
          if(command_library2 == FORWARD_2_SECS ){
            command_call = FORWARD_2_SECS; command_library_state = CASE_4;
          }else if(command_library2 == BACK_1_SEC ){
            command_call = BACK_1_SEC; command_library_state = CASE_4;
          }else if(command_library2 == RIGHT_45_DEGREES ){
            command_call = RIGHT_45_DEGREES; command_library_state = CASE_4;
          }else if(command_library2 == LEFT_45_DEGREES ){
            command_call = LEFT_45_DEGREES; command_library_state = CASE_4;
          }else break; 
        break;
      case CASE_4:
        break;
      case CASE_5:
          if(command_library3 == FORWARD_2_SECS ){
            command_call = FORWARD_2_SECS; command_library_state = CASE_6;
          }else if(command_library3 == BACK_1_SEC ){
            command_call = BACK_1_SEC; command_library_state = CASE_6;
          }else if(command_library3 == RIGHT_45_DEGREES ){
            command_call = RIGHT_45_DEGREES; command_library_state = CASE_6;
          }else if(command_library3 == LEFT_45_DEGREES ){
            command_call = LEFT_45_DEGREES; command_library_state = CASE_6;
          }else break; 
        break;                        //
      default: break;
      }
  
  
}
 









