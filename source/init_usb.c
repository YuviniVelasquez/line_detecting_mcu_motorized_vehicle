//===========================================================================
// File Name : init_usb.c
//
// Description: This file contains the different menu options seen in LED
//
// Author: Yuvini Velasquez
// Date: 11/01/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================

#include  "functions.h" 
#include  "msp430.h"
#include <string.h>
#include "macros.h"

volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
volatile char USB_Char_Tx[SMALL_RING_SIZE] ;
volatile unsigned int usb_rx_ring_wr;
volatile unsigned int usb_rx_ring_rd;
volatile unsigned int usb_tx_ring_wr;
volatile unsigned int usb_tx_ring_rd;
volatile unsigned int seriarport_ON_OFF;
//----------------------------------------------------
void Init_Serial_UCA0(void){
  int i;
  for(i =START_COUNTER; i <SMALL_RING_SIZE; i++){
   USB_Char_Rx[i] = USB_START_BUFF; // USB Rx Buffer
  }
  usb_rx_ring_wr = BEGINNING;
  usb_rx_ring_rd = BEGINNING;
for(i =START_COUNTER; i <LARGE_RING_SIZE; i ++){ // May not use this
  USB_Char_Tx[i] = USB_START_BUFF; // USB Tx Buffer
  
}
  usb_tx_ring_wr = BEGINNING;
  usb_tx_ring_rd = BEGINNING;
// Configure UART 0
  UCA0CTLW0 = WORD_REGISTER; // Use word register
  UCA0CTLW0 |= UCSWRST; // Set Software reset enable
  UCA0CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as f BRCLK

// BRCLK Baudrate UCOS16 UCBRx UCFx UCSx neg pos neg pos
// 8000000 115200 1       4     5   0x55 0.08 0.04 0.10 0.14
UCA0BRW = BAUD_115k ;// 115,200 Baud
// UCA0MCTLW = UCSx concatenate UCFx concatenate UCOS16;
// UCA0MCTLW = 0x49 concatenate 1 concatenate 1;
UCA0MCTLW = BAUDCONC_115k ;
UCA0CTLW0 &= ~ UCSWRST; // Set Software reset enable
UCA0IE |= UCRXIE; // Enable RX interrupt
}  
//------------------------------------------------------------


//----------------------------------------------------
void Init_Serial_UCA1(void){
  int i;
  for(i =START_COUNTER; i <SMALL_RING_SIZE; i++){
   USB_Char_Rx[i] = USB_START_BUFF; // USB Rx Buffer
  }
  usb_rx_ring_wr = BEGINNING;
  usb_rx_ring_rd = BEGINNING;
for(i =START_COUNTER; i <LARGE_RING_SIZE; i ++){ // May not use this
  USB_Char_Tx[i] = USB_START_BUFF; // USB Tx Buffer
}
  usb_tx_ring_wr = BEGINNING;
  usb_tx_ring_rd = BEGINNING;
// Configure UART 0
  UCA1CTLW0 = WORD_REGISTER; // Use word register
  UCA1CTLW0 |= UCSWRST; // Set Software reset enable
  UCA1CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as f BRCLK
//No parity  Page 539
//  UCA1CTLW0 &= ~ UCPEN ;
// 8 bits
//  UCA1CTLW0 &=~ UC7BIT ;
//UC7BIT = 0;
//  UCA1CTLW0 &=~ UCSPB;
//1 stop bit
seriarport_ON_OFF = 0;
UCA1BRW = BAUD_115k ;//115,200 Baud
// UCA0MCTLW = UCSx concatenate UCFx concatenate UCOS16;
// UCA0MCTLW = 0x49 concatenate 1 concatenate 1;
UCA1MCTLW = BAUDCONC_115k ;
UCA1CTLW0 &= ~ UCSWRST; // Set Software reset enable
UCA1IE |= UCRXIE; // Enable RX interrupt
}  
//------------------------------------------------------------


  
  
  
