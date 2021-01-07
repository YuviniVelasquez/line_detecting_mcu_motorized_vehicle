//===========================================================================
// File Name : interrupt_serial_com.c
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

// global variables
extern volatile unsigned int usb_rx_ring_rd;
extern volatile unsigned int usb_rx_ring_wr;
extern volatile unsigned int usb_tx_ring_wr;
extern volatile unsigned int usb_tx_ring_rd;
extern volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
volatile unsigned int UCA0_index;
volatile unsigned int UCA1_index;
char test_command[STRING_SIZE_10];
extern char display_keeper[STRING_SIZE_11];
extern char message_keeper[STRING_SIZE_10];
extern char message_keeper1[STRING_SIZE_10];
extern volatile int p1_pressed;
char temp_value;
char temp_value2;
extern volatile unsigned int seriarport_ON_OFF;
volatile int check_value_once;
volatile int check_command_once;
extern  char iot_commands [STRING_SIZE_30];
volatile char command_viewer [STRING_SIZE_30];
volatile unsigned int clear_iot_command;
volatile unsigned int clear_command_stack;
unsigned int number_of_commands;



extern char display_line[NUM_OF_ROWS][NUM_0F_COLS];
//The eUSCI_A has only one interrupt vector that is shared for
//transmission and for reception.
//-------------------------------------------------------------

#pragma vector = EUSCI_A0_VECTOR
__interrupt void eUSCI_A0_ISR(void){
  unsigned int temp;
  switch(__even_in_range(UCA0IV,SIZE_8)){
  case CASE_0:                                                // Vector 0 no interrupt              
    
    break;
  case CASE_2:                                                //Vector 2 - RXIFG
    temp = usb_rx_ring_wr++;
    USB_Char_Rx[temp] = UCA0RXBUF;                       // RX -> USB_Char_Rx character
     temp_value2 = UCA0RXBUF;                           //GETS VALUE FROM IOT
     UCA1TXBUF = temp_value2;                           //TRANSMITS IOT VALUES RECEIVED TO UCA1 AKA USB THAT GOES TO TERMITE
    if (usb_rx_ring_wr >= (sizeof(USB_Char_Rx))){
      usb_rx_ring_wr = BEGINNING;                       // Circular buffer back to beginning
    }
    if( temp_value2 == ESC_CHAR){//counts the escapes in a command
           clear_command_stack ++;
       }
        if( temp_value2 == UP_ARROW_CHAR){//counts the ^ in a command
           number_of_commands ++;
       }
    break;
  case CASE_4:                                               // Vector 4 � TXIFG
      //CODE FOR TRANSMIT
      switch(UCA0_index++){
        case CASE_0: 
        case CASE_1: 
        case CASE_2: 
        case CASE_3: 
        case CASE_4: 
        case CASE_5: 
        case CASE_6: 
        case CASE_7: 
        case CASE_8:
        case CASE_9:
        case CASE_10:
        case CASE_11:
        case CASE_12:
        case CASE_13:
        case CASE_14:
        case CASE_15:
        case CASE_16:
        case CASE_17:
        case CASE_18:
        case CASE_19:
        case CASE_20:          
        case CASE_21:
        case CASE_22:
        case CASE_23:
        case CASE_24:
        case CASE_25:          
        case CASE_26:
        case CASE_27:
          UCA0TXBUF = iot_commands[UCA0_index];
//          command_viewer[UCA0_index] = UCA0TXBUF;
          break;
        case CASE_28: //
          UCA0TXBUF = RETURN;
          break;
        case CASE_29: // Vector 0 - no interrupt
          UCA0TXBUF = LINEFEED;
          break;
        default:
          UCA0IE &= ~UCTXIE; // Disable TX interrupt
          clear_iot_command = YES;

          break;
      }break;
    default:break;
  } 
}
//--------------------------------------------------------
//The eUSCI_A has only one interrupt vector that is shared for
//transmission and for reception.
//-------------------------------------------------------------

#pragma vector = EUSCI_A1_VECTOR
__interrupt void eUSCI_A1_ISR(void){
  //unsigned int temp;
  switch(__even_in_range(UCA1IV,SIZE_8)){
  case CASE_0:                                                // Vector 0 no interrupt              
    break;
  case CASE_2:                                                //Vector 2 - RXIFG
    //CODE TO RECEIVE
    //temp = usb_rx_ring_wr++;
    //USB_Char_Rx[temp] = UCA1RXBUF;                       // RX -> USB_Char_Rx character

    temp_value=UCA1RXBUF;
    UCA0TXBUF=temp_value;
    //seriarport_ON_OFF=1;
   // UCA0TXBUF=temp_value;
    //UCA1TXBUF=temp_value;     Sends Directly without IOT
    //if (usb_rx_ring_wr >= (sizeof(USB_Char_Rx))){
    //  usb_rx_ring_wr = BEGINNING;                       // Circular buffer back to beginning
   // }
    break;
  case CASE_4:                                               // Vector 4 � TXIFG
      //CODE FOR TRANSMIT
      switch(UCA1_index++){
        case CASE_0: 
        case CASE_1: 
        case CASE_2: 
        case CASE_3: 
        case CASE_4: 
        case CASE_5: 
        case CASE_6: 
        case CASE_7: 
        case CASE_8: 
                // UCA1TXBUF = temp_value2;// UCA1TXBUF = message_keeper[UCA1_index];
          break;
        case CASE_9: //
          UCA1TXBUF = SIZE_13;
          break;
        case CASE_10: // Vector 0 - no interrupt
          UCA1TXBUF = SIZE_10;
          break;
        default:
          UCA1IE &= ~UCTXIE; // Disable TX interrupt

          break;
      }break;
    default:break;
  } 
}
//--------------------------------------------------------