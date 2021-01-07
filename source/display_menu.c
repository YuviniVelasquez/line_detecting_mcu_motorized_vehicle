//===========================================================================
// File Name : display_menu.c
//
// Description: This file contains the different menu options seen in LED
//
// Author: Yuvini Velasquez
// Date: 9/11/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================

#include  "functions.h" 
#include  "msp430.h"
#include <string.h>
#include "macros.h"


extern volatile unsigned int p4_counter ;
extern volatile unsigned int p2_counter ;
extern volatile unsigned int circle_timer_count;
unsigned int display_menu_state;

extern char display_line[NUM_OF_ROWS][NUM_0F_COLS];
extern char adc_char[10];
extern char *display[NUM_OF_ROWS];
extern char display_keeper[11];
extern char message_keeper[10];


extern unsigned char display_mode;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;
extern volatile unsigned int p4_counter ;
extern volatile unsigned int p2_counter ;
extern volatile unsigned int clear_array;


unsigned int figure;
unsigned int display_counter;
unsigned int once;
extern volatile int store_once;
extern volatile unsigned int five_sec_count;
extern volatile char command_keeper[11];
extern volatile unsigned int UCA0_index;
extern volatile unsigned int UCA1_index;
extern volatile unsigned int enable_circle_timer;               //enables circuit timer

extern volatile unsigned display_putty;
extern volatile int check_command_once;
extern volatile unsigned int line_state;
char arrived_state[2];
volatile unsigned int arrived_state_int;

void display_menu(void){
//------------------------------------------------------------------------------
// LED Menu fsm
//------------------------------------------------------------------------------
  if (display_menu_state == STATE_0){
  
    strcpy(display_line[DISPLAY_L1], "   NCSU   ");
    update_string(display_line[DISPLAY_L1], DISPLAY_L1);   
    strcpy(display_line[DISPLAY_L2], "   WOLF   ");
    update_string(display_line[DISPLAY_L2], DISPLAY_L2);
    strcpy(display_line[DISPLAY_L3], " PROJECT  ");
    update_string(display_line[DISPLAY_L3], DISPLAY_L3);
    strcpy(display_line[DISPLAY_L4], "    10    ");
    update_string(display_line[DISPLAY_L4], DISPLAY_L4);  
    display_changed = YES;
    if(once == YES){
      five_sec_count = ENABLE_COUT;
      once = NO;
    }
    if(five_sec_count == COUNT_COMPLETE){
        display_menu_state =STATE_1;
        five_sec_count = DISABLE_COUNT;
        arrived_state_int = 0;
    }
  
  }else if (display_menu_state == STATE_1){     //state 1 is IOT module
    arrived_state[0] = ASCI_CONVERTER + arrived_state_int;
    strcpy(display_line[DISPLAY_L1], "ARRIVED  ");
    display_line[DISPLAY_L1][DISPLAY_CHAR9] =  arrived_state[0];
    update_string(display_line[DISPLAY_L1], DISPLAY_L1);   
    strcpy(display_line[DISPLAY_L2], "  IP 10   ");
    update_string(display_line[DISPLAY_L2], DISPLAY_L2);
    strcpy(display_line[DISPLAY_L3], "153.62.91 ");
    update_string(display_line[DISPLAY_L3], DISPLAY_L3);
    strcpy(display_line[DISPLAY_L4], "SECS  ");
    update_string(display_line[DISPLAY_L4], DISPLAY_L4);  
    enable_display_update();
    display_changed = YES;
    enable_circle_timer =1;
  }else if (display_menu_state == STATE_2){     //state 2 is BLACK LINE

    strcpy(display_line[DISPLAY_L1], "ARRIVED  ");
    update_string(display_line[DISPLAY_L1], DISPLAY_L1);   
    strcpy(display_line[DISPLAY_L2], "  IP 10   ");
    update_string(display_line[DISPLAY_L2], DISPLAY_L2);
    strcpy(display_line[DISPLAY_L3], "153.62.91 ");
    update_string(display_line[DISPLAY_L3], DISPLAY_L3);
    switch(line_state){
      case LINE_STATE_1:
        strcpy(display_line[DISPLAY_L4], " WAITING  ");
        break;
      case LINE_STATE_2:
        strcpy(display_line[DISPLAY_L4], "INTERCEPT ");
        break;
      case LINE_STATE_3:
        strcpy(display_line[DISPLAY_L4], " WAITING  ");
        break;
      case LINE_STATE_4:
        strcpy(display_line[DISPLAY_L4], " TURNING  ");
        break;
      case LINE_STATE_5:
        strcpy(display_line[DISPLAY_L4], " CIRCLING ");
        break;
      case LINE_STATE_6:
        strcpy(display_line[DISPLAY_L4], " TURNING  ");
        break;
      case LINE_STATE_7:
        strcpy(display_line[DISPLAY_L4], "  CENTER  ");
        break;
      case LINE_STATE_10:
        strcpy(display_line[DISPLAY_L4], "   DONE   ");
        break;
        default: strcpy(display_line[DISPLAY_L4], "          "); break;
     }
    update_string(display_line[DISPLAY_L4], DISPLAY_L4);  
    enable_display_update();
    display_changed = YES;
  }

//------------------------------------------------------------------------------
}

void display_line_copier(void){


  display_line[DISPLAY_L2][DISP_CHAR_0] = command_keeper[STR_CHAR_0];
display_line[DISPLAY_L2][DISP_CHAR_1] = command_keeper[STR_CHAR_1];
display_line[DISPLAY_L2][DISP_CHAR_2] = command_keeper[STR_CHAR_2];
display_line[DISPLAY_L2][DISP_CHAR_3] = command_keeper[STR_CHAR_3];
display_line[DISPLAY_L2][DISP_CHAR_4] = command_keeper[STR_CHAR_4];
display_line[DISPLAY_L2][DISP_CHAR_5] = command_keeper[STR_CHAR_5];
display_line[DISPLAY_L2][DISP_CHAR_6] = command_keeper[STR_CHAR_6];
display_line[DISPLAY_L2][DISP_CHAR_7] = command_keeper[STR_CHAR_7];
display_line[DISPLAY_L2][DISP_CHAR_8] = command_keeper[STR_CHAR_8];
display_line[DISPLAY_L2][DISP_CHAR_9] = command_keeper[STR_CHAR_9];

// if(display_keeper[STR_CHAR_0] != ' '){
//    message_keeper[STR_CHAR_0]=display_keeper[STR_CHAR_0];
//    message_keeper[STR_CHAR_1]=display_keeper[STR_CHAR_1];
//    message_keeper[STR_CHAR_2]=display_keeper[STR_CHAR_2];
//    message_keeper[STR_CHAR_3]=display_keeper[STR_CHAR_3];
//    message_keeper[STR_CHAR_4]=display_keeper[STR_CHAR_4];
//    message_keeper[STR_CHAR_5]=display_keeper[STR_CHAR_5];
//    message_keeper[STR_CHAR_6]=display_keeper[STR_CHAR_6];
//    message_keeper[STR_CHAR_7]=display_keeper[STR_CHAR_7];
//    message_keeper[STR_CHAR_8]=display_keeper[STR_CHAR_8];
//    message_keeper[STR_CHAR_9]='\0';
//   // store_once =0;
//  }
  
}

void display_line_clear(void){

//  int j;
//  for(j=0;display_keeper[j] != '\r';j++){
//        command_keeper[j]=display_keeper[j];
//    } else{
//    display_keeper[j]=display_keeper[j];
//    }
  }



void display_putty_state(void){

  switch(display_putty) {
   case 1  : //UCA1TXBUF = '\n';
          
           strcpy( message_keeper, "I'm here ");
           strcpy(display_line[DISPLAY_L3], "I'm here  ");
           update_string(display_line[DISPLAY_L3], DISPLAY_L3);
          UCA1_index=0;
          //UCA1IE |= UCTXIE;
          //UCA1TXBUF = message_keeper[0];
                 display_putty=0;


      break; 
   case 2  : // UCA1TXBUF = '\n';
          strcpy( message_keeper, "115,200  ");
          strcpy(display_line[DISPLAY_L3], "115,200   ");
          update_string(display_line[DISPLAY_L3], DISPLAY_L3);
          //UCA1IE |= UCTXIE;
          UCA1_index=0;
         // UCA1IE |= UCTXIE;
          //UCA1TXBUF = message_keeper[0];
          display_putty=0;      

      break; 
  
   /* you can have any number of case statements */
   default : break;
  }



}

void command_array_clear(void){
int j;
for(j=0;j<10;j++){
  command_keeper[j]=' ';

}
 command_keeper[10]='\n';
}

void command_array_copier(void){
int j;
  for(j=0;display_keeper[j] != '\r';j++){
        command_keeper[j]=display_keeper[j];

  }
       check_command_once = 1;
}
