//===========================================================================
// File Name : interrupt_ports.c
//
// Description: This file contains the control of the interrupts
//
// Author: Yuvini Velasquez
// Date: 10/6/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================

#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

volatile int switch_pressed;             //sets an integer to a pressed switch
volatile int emitter_enable;
volatile unsigned int one_s_passed_port;  
extern volatile unsigned int DEBOUNCER_COUNTER1;
extern volatile unsigned int DEBOUNCER_COUNTER2;
extern volatile unsigned int enable_counter1;
extern volatile unsigned int enable_counter2;
extern volatile unsigned int p4_counter ;
extern volatile unsigned int p2_counter ;
extern volatile unsigned int line_state;
extern unsigned int display_menu_state;
volatile int p2_pressed;
volatile int p1_pressed;
extern char message_keeper[10];
extern volatile unsigned int UCA0_index;
extern volatile unsigned int UCA1_index;

//------------------------------------------------------------------------------
// Port 2 interrupt. For switches, they are disabled for the duration
// of the debounce timer. Flag is set that user space can check.
//Include #pragma vector = [Assigned Vector]
#pragma vector=PORT2_VECTOR
//Create Interrupt Service Routine Function with “__interrupt”
__interrupt void switchP2_interrupt(void) {
// Switch 2
  if (P2IFG & SW2) {
    P2IFG &= ~SW2; // IFG SW1 cleared
    // Set a variable to identify the switch has been pressed.
    switch_pressed = 2;
    
 
    // Set a variable to identify the switch is being debounced.
   
    //has 1 second passed?
    one_s_passed_port = 0;
     //DISABLE INTERRUPT PURT
    P2IE &= ~SW2;                  // P2.6 interrupt disable
    
    //SET TIMER TO TURN ITSELF BACK ON
  //  display_menu_state = 1;
    
    p2_pressed ++;
 
  }
// Use a Timer Value to control the debounce
}

//------------------------------------------------------------------------------
// Port 4 interrupt. For switches, they are disabled for the duration
// of the debounce timer. Flag is set that user space can check.
//Include #pragma vector = [Assigned Vector]
#pragma vector=PORT4_VECTOR
//Create Interrupt Service Routine Function with “__interrupt”
__interrupt void switchP4_interrupt(void) {
// Switch 1
  if (P4IFG & SW1) {
    P4IFG &= ~SW1; // IFG SW1 cleared
    // Set a variable to identify the switch has been pressed.
    switch_pressed = 4;
    
//    if(p4_counter < 4){
//      p4_counter++;
//    }
    emitter_enable = 1;
    line_state = 1;
        //has 1 second passed?
    one_s_passed_port = 0;
    
    //DISABLE INTERRUPT PURT
    P4IE &= ~SW1;                  // P2.6 interrupt disable

    //SET VARIABLE TO SHOW SWITCH PRESSED
    
 //display_menu_state = 2;
 //p1_pressed = 1;
     // UCA0_index=0;
      //UCA0IE |= UCTXIE;
     // UCA0TXBUF = message_keeper[0];
      
      //UCA1_index=0;
      //UCA1IE |= UCTXIE;
      //UCA1TXBUF = message_keeper[0];
 

 
 
  }
// Use a Timer Value to control the debounce
}
//------------------------------------------------------------------------------