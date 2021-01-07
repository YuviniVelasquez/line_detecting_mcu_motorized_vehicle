//------------------------------------------------------------------------------
//  File Name : main.c
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Yuvini Velasquez
//  Jan 2018
//  Built with IAR Embedded Workbench Version: V(7.12.4)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

// Global Variables
volatile char slow_input_down;
extern char display_line[NUM_OF_ROWS][NUM_0F_COLS];
extern char test_command[STRING_SIZE_10];
char message_keeper[STRING_SIZE_10];
char message_keeper1[STRING_SIZE_10];
extern char adc_char[STRING_SIZE_10];
char display_keeper[STRING_SIZE_11];
extern char *display[NUM_OF_ROWS];
unsigned char display_mode;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;
extern volatile unsigned int Time_Sequence;
extern volatile char one_time;
extern volatile unsigned int clockdiv_count;
volatile unsigned int circle_timer_count;
extern unsigned int figure;
volatile unsigned int onoff;
volatile unsigned int line_state;
extern unsigned int UCA0_index;
extern volatile unsigned int p4_counter ;
extern volatile unsigned int p2_counter ;
extern unsigned int display_menu_state;
extern unsigned int once;
unsigned int once_arr;
int i;
int read;
volatile int store_once;
volatile unsigned display_putty;
extern volatile int check_command_once;

extern volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
extern volatile unsigned int usb_rx_ring_wr;
extern volatile unsigned int usb_rx_ring_rd;
extern volatile unsigned int seriarport_ON_OFF;
extern volatile unsigned int clear_array;
extern volatile int check_value_once;
volatile char command_keeper[11];
volatile unsigned int low_once;

extern unsigned int ADC_Channel;
extern unsigned int ADC_Left_Detect;
extern unsigned int ADC_Right_Detect;
extern unsigned int ADC_Thumb;
unsigned int enable_200ms_counter;
//extern unsigned int ADC_Channel;
//extern unsigned int ADC_Left_Detect;
//extern unsigned int ADC_Right_Detect;
//extern unsigned int ADC_Thumb;
// Function Prototypes
void main(void);
extern volatile unsigned int enable_setup_commands;
extern volatile unsigned int enable_iot_port_number;
extern volatile unsigned int clear_iot_command;
unsigned int record_command;
volatile char command_stack[3][30];
unsigned int stack_row;
volatile unsigned int command_start_end;
extern volatile unsigned int clear_command_stack;
volatile unsigned int ready_to_read_stack;
extern unsigned int number_of_commands;
//[rows][cols]
extern volatile unsigned int command_library1;
extern volatile unsigned int command_library2;
extern volatile unsigned int command_library3;
extern volatile unsigned int command_library_state;


void main(void){
//------------------------------------------------------------------------------
// Main Program
// This is the main routine for the program. Execution of code starts here.
// The operating system is Back Ground Fore Ground.
//
//------------------------------------------------------------------------------
// Disable the GPIO power-on default high-impedance mode to activate
// previously configured port settings
  PM5CTL0 &= ~LOCKLPM5;
  Init_Ports();                        // Initialize Ports
  Init_Clocks();                       // Initialize Clock System
  Init_Conditions();                   // Initialize Variables and Initial Conditions
  Init_Timers();                       // Initialize Timers
  Init_LCD();                          // Initialize LCD
  //Init_ADC();                          //Initializing ADC 
  Init_Serial_UCA0();
  Init_Serial_UCA1();
   
  
// Place the contents of what you want on the display, in between the quotes
// Limited to 10 characters per line
//Funtion Reference: void update_string(char *string_data, int string);
  strcpy(display_line[DISPLAY_L1], "   NCSU   ");
  update_string(display_line[DISPLAY_L1], DISPLAY_L1);
  strcpy(display_line[DISPLAY_L2], " WOLFPACK ");
  update_string(display_line[DISPLAY_L2], DISPLAY_L2);
  strcpy(display_line[DISPLAY_L3], "  ECE306  ");
  update_string(display_line[DISPLAY_L4], DISPLAY_L4);
  enable_display_update();

 // strcpy(test_command, "NCSU  #1  ");
 
  display_changed = YES; 
  P6OUT &= ~LCD_BACKLITE;
once =1;
low_once=1;
enable_setup_commands=0;
enable_iot_port_number = 0;

//  Display_Update(3,1,0,0);
//    P6OUT |= R_FORWARD;              //TESTING 
//    P6OUT |= L_FORWARD;              //TESTING
//hw5 stuff
//  clockdiv_count = RESET_COUNTER;       //Reset counter
//  figure = 0;
//  circle_timer_count = 0;
//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
  while(ALWAYS) {                      // Can the Operating system run
    
    if(low_once == YES){
      Init_LEDs();
      clear_stack();
      P5SEL0 &= ~IOT_RESET;             //IOT_RESET signal selection
      P5SEL1 &= ~IOT_RESET;             //IOT_RESET signal selection
      enable_200ms_counter = YES;
      low_once=NO;
    }

      switch(Time_Sequence){
      case CASE_250:                        //
        if(one_time){
          //Init_LEDs();
          //lcd_BIG_mid();
          display_changed = CHANGE_DISP;
          one_time = ONE_TIME_ZERO;
          //screen_counter();
        }
        Time_Sequence = RESET_TIMER;             //
        break;
      case CASE_200:                        //
        if(one_time){
 //         GREEN_LED_ON;            // Change State of LED 5
          one_time = ONE_TIME_ZERO;
               display_menu();
        }
        break;
      case CASE_150:                         //
        if(one_time){
 //         RED_LED_ON;            // Change State of LED 4
 //         GREEN_LED_OFF;           // Change State of LED 5
          one_time = ONE_TIME_ZERO;
          clear_iot_command_array();

        }
        break;
      case CASE_100:                         //
        if(one_time){
          //lcd_4line();
//          GREEN_LED_ON;            // Change State of LED 5
          display_changed = CHANGE_DISP;
          one_time = ONE_TIME_ZERO;
          iot_port_setup();     //ADD PORT SETUP HERE
          display_menu();
        }
        break;
      case  CASE_50:                        //
        if(one_time){
//          RED_LED_OFF;           // Change State of LED 4
//          GREEN_LED_OFF;           // Change State of LED 5
          one_time = ONE_TIME_ZERO;
          dissasemby_setup();    //ADD DISASSOCIATION THING HERE
          
        }
        break;                         //
      default: break;
      }
   if(clear_command_stack == CLEAR_COMMAND_S1){
      clear_stack();              //the stack will reset
      stack_row=RESET_INDEX;
      clear_command_stack++;            //adds one to stop clear_stack
    }
    if(clear_command_stack >=CLEAR_COMMAND_S3){  //from the last part of input
    clear_command_stack = NO;            //gets ready for next string
    ready_to_read_stack = YES;
    }

      if(usb_rx_ring_rd != usb_rx_ring_wr){
       //if(USB_Char_Rx[usb_rx_ring_rd] == 1B){//counts the escapes in a command
       //    command_start_end ++;
       //}
        if(USB_Char_Rx[usb_rx_ring_rd] == '^' ){
            record_command = YES;
            i=RESET_COUNTER;
            stack_row++;
        }
        if(stack_row > STACK_SIZE){              //Command stack can hold up to 3 commands
            stack_row =RESET_COUNTER;               //if there is more
            clear_stack();              //the stack will reset
        }
        if (i>LAST_COMMAND_CHAR){                      //string command cannot be more than 30 chars
          i=RESET_COUNTER;
        }
        if(record_command == YES){        //record is enabled when there is a ^
          command_stack[stack_row - ADJUSTMENT_FOR_ARRAY][i] = USB_Char_Rx[usb_rx_ring_rd];
              if(USB_Char_Rx[usb_rx_ring_rd] == '\r'){
              record_command = NO;     //record is disable when there is a \r
              }
        }
        usb_rx_ring_rd++;       //increment ring pointer
        i++;                    //increment command pointer
        if(usb_rx_ring_rd > RING_BUFF_SIZE){    //if ring reaches limit
            usb_rx_ring_rd = RESET_COUNTER;     // reset
          }   
      }
    
    if((number_of_commands == stack_row)&&(record_command ==NO)){
        command_stack_process();
        number_of_commands=RESET_COUNTER;
        clear_stack(); 
    }
    

     // display_menu();
      command_library();
      command_call_timed();
      
      screen_counter();
      //carlson's commands
       Display_Process();

//      Switches_Process();                // Check for switch state change 
//      line_detect();
//      switch_func();
//      figure_call();
//      forward_rev();
  }
  
//    Wheels();

  }
//------------------------------------------------------------------------------


