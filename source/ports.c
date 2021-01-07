//===========================================================================
// File Name : ports.c
//
// Description: This file contains the Initialization for all port pins
//
// Author: Yuvini Velasquez
// Date: 9/11/19
// Compiler: Built with IAR Embedded Workbench Version: (7.12.4)
//===========================================================================

#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"
  
  
void Init_Ports(void){
  Init_Port1();                // Initializing pins in Port_1
  Init_Port2();                // Initializing pins in Port_2
  Init_Port3(USE_GPIO);        // Initializing pins in Port_3
  Init_Port4();                // Initializing pins in Port_4
  Init_Port5();                // Initializing pins in Port_5
  Init_Port6(1);                // Initializing pins in Port_6
//  Init_Port3(USE_GPIO);         // Initializing 3.4 to GPIO
}
//Selecting pin to low PxSEL0 &=~UNIQUE_NAME_1;
//Selecting pin to high PxSEL1 |= UNIQUE_NAME_1;

//EACH PORT PIN SHOULD HAVE 4 LINES
//PxSEL0    SELECTING PERIPHERAL TYPE
//PxSEL1    SELECTING PERIPHERAL TYPE
//PxOUT     SELECTING OUTPUT VALUE
//PxDIR     SELECTING DIRECTION (INPUT OR OUTPUT)
//INPUTS DON'R REQUIRE OUT VALUE?
void Init_Port1(void){
//------------------------------------------------------------------------------
// Port Configurations
//------------------------------------------------------------------------------
P1DIR = DIR_TO_OUTPUT;          // Set P1 direction to output aka  = 0xFF;
P1OUT = P_TO_LOW;               // P1 set Low aka = 0x00

P1SEL0 &= ~RED_LED;             // P1_0 GPIO operation
P1SEL1 &= ~RED_LED;             // P1_0 GPIO operation
P1OUT  |=  RED_LED;             // Set RED_LED Off [High]**
P1DIR  |=  RED_LED;              // Set direction to ??????


P1SEL0 |= A1_SEEED;             //A1_SEEED signal selection
P1SEL1 |= A1_SEEED;             //A1_SEEED signal selection
//P1OUT                           // Set out value ????
//P1DIR                           // Set direction to ??????

P1SEL0 |= V_DETECT_L;           //V_DETECT_L signal selection
P1SEL1 |= V_DETECT_L;           //V_DETECT_L signal selection
//P1OUT                           // Set out value ????
//P1DIR                           // Set direction to ??????

P1SEL0 |= V_DETECT_R;           //V_DETECT_R signal selection
P1SEL1 |= V_DETECT_R;           //V_DETECT_R signal selection
//P1OUT                           // Set out value ????
//P1DIR                           // Set direction to ??????

P1SEL0 |= V_BAT;                //V_BAT signal selection
P1SEL1 |= V_BAT;                //V_BAT signal selection
//P1OUT                           // Set out value ????
//P1DIR                           // Set direction to ??????

P1SEL0 |= V_THUMB;              //V_THUMB signal selection
P1SEL1 |= V_THUMB;              //V_THUMB signal selection
//P1OUT                           // Set out value ????
//P1DIR                           // Set direction to ??????

P1SEL0 |= UCA0RXD;              //UCA0RXD signal selection
P1SEL1 &= ~UCA0RXD;             //UCA0RXD signal selection
//PxOUT                           // Set out value ????
//P1DIR                           // Set direction to ??????

P1SEL0 |= UCA0TXD;              //UCA0TXD signal selection
P1SEL1 &= ~UCA0TXD;             //UCA0TXD signal selection
//PxOUT                           // Set out value ????
//P1DIR                           // Set direction to ??????

//------------------------------------------------------------------------------  
}
//SETTING PIN TO A "0" OR LOW
//PxSEL0 &= ~UNIQUE_NAME_1;
//SETTING PIN TO A "1" OR HIGH
//PxSEL0 |= UNIQUE_NAME_1;
void Init_Port2(void){
//------------------------------------------------------------------------------
// Port Configurations
//------------------------------------------------------------------------------
P2DIR = DIR_TO_OUTPUT;          // Set P1 direction to output aka  = 0xFF;
P2OUT = P_TO_LOW;                 // P1 set Low aka = 0x00
  
P2SEL0 &= ~P2_0;                // P2_0 GPIO operation
P2SEL1 &= ~P2_0;                // P2_0 GPIO operation
P2DIR &= ~P2_0;                 // Direction = input

P2SEL0 &= ~P2_1;                // P2_1 GPIO operation
P2SEL1 &= ~P2_1;                // P2_1 GPIO operation
P2DIR &= ~P2_1;                 // Direction = input

P2SEL0 &= ~P2_2;                // P2_2 GPIO operation
P2SEL1 &= ~P2_2;                // P2_2 GPIO operation
P2DIR &= ~P2_2;                 // Direction = input

P2SEL0 &= ~SW2;                 // SW2 Operation
P2SEL1 &= ~SW2;                 // SW2 Operation
P2DIR &= ~SW2;                  // Direction = input
P2OUT |= SW2;                   // Configure pullup resistor
P2REN |= SW2;                   // Enable pullup resistor
 P2IES |= SW2;                // P2.0 Hi/Lo edge interrupt
 P2IFG &= ~SW2;               // Clear all P2.6 interrupt flags
 P2IE |= SW2;                 // P2.6 interrupt enabled
//if(enable == 0){
//}else if(enable == 1){
//
//}

P2SEL0 &= ~P2_4;                // P2_4 GPIO operation
P2SEL1 &= ~P2_4;                // P2_4 GPIO operation
P2DIR &= ~P2_4;                 // Direction = input

P2SEL0 &= ~P2_5;                // P2_5 GPIO operation
P2SEL1 &= ~P2_5;                // P2_5 GPIO operation
P2DIR &= ~P2_5;                 // Direction = input

P2SEL0 &= ~LFXOUT;              // LFXOUT Clock operation
P2SEL1 |= LFXOUT;               // LFXOUT Clock operation

P2SEL0 &= ~LFXIN;               // LFXIN Clock operation
P2SEL1 |= LFXIN;                // LFXIN Clock operation
//------------------------------------------------------------------------------
}

void Init_Port3(char smclk){
//------------------------------------------------------------------------------
// Port Configurations
//------------------------------------------------------------------------------
P3DIR = DIR_TO_OUTPUT;            // Set P1 direction to output aka  = 0xFF;
P3OUT = P_TO_LOW;                 // P1 set Low aka = 0x00

P3SEL0 &= ~TEST_PROBE;            //TEST_PROBE signal selection
P3SEL1 &= ~TEST_PROBE;            //TEST_PROBE signal selection
//P3OUT                           // Set out value ????
//P3DIR                           // Set direction to ??????

P3SEL0 |= OA2O;                  //OA2O signal selection
P3SEL1 |= OA2O;                  //OA2O signal selection
//P3OUT                          // Set out value ????
P3DIR &= ~OA2O;                  // Set direction to ??????

P3SEL0 |= OA2N;                   //OA2- signal selection
P3SEL1 |= OA2N;                   //OA2- signal selection
//P3OUT                           // Set out value ????
P3DIR &= ~OA2N;                            // Set direction to ??????

P3SEL0 |= OA2P;                   //OA2+ signal selection
P3SEL1 |= OA2P;                   //OA2+ signal selection
//P3OUT                           // Set out value ????
P3DIR &= ~OA2P;                           // Set direction to ??????

//3.4 HOMEWORK 5
// if ( smclk == USE_GPIO){
//    P3SEL0 &= ~SMCLK_OUT;            //SMCLK signal selection
//    P3SEL1 &= ~SMCLK_OUT;            //SMCLK signal selection    
//  }
//  else if (smclk == USE_SMCLK){
//    P3SEL0 |= SMCLK_OUT;             //SMCLK signal selection
//    P3SEL1 &= ~SMCLK_OUT;            //SMCLK signal selection
//  }

P3SEL0 |= SMCLK_OUT;             //SMCLK signal selection
P3SEL1 &= ~SMCLK_OUT;            //SMCLK signal selection
P3OUT |= SMCLK_OUT;              // Set out value ???? 9/27
//--P3DIR &= ~SMCLK;             // Set direction to ??????

P3SEL0 &= ~OA3O;                 //OA3O signal selection
P3SEL1 &= ~OA3O;                 //OA3O signal selection
//P3OUT                          // Set out value ????
P3DIR &= ~OA3O;                  // Set direction to ??????WHY?

P3SEL0 &= ~IOT_LINK;            //IOT_LINK signal selection
P3SEL1 &= ~IOT_LINK;            //IOT_LINK signal selection
//P3OUT                         // Set out value ????
//P3DIR                         // Set direction to ??????

P3SEL0 &= ~P3_7;                //P3_7 signal selection
P3SEL1 &= ~P3_7;                //P3_7 signal selection
//P3OUT                         // Set out value ????
P3DIR &= ~P3_7;                 // Set direction to INPUT,WHY?

//------------------------------------------------------------------------------  
}

void Init_Port4(void){
//------------------------------------------------------------------------------
// Configure PORT 4
//------------------------------------------------------------------------------
P4DIR = DIR_TO_OUTPUT;           // Set P1 direction to output aka  = 0xFF;
P4OUT = P_TO_LOW;                // P1 set Low aka = 0x00

P4SEL0 &= ~RESET_LCD;            // RESET_LCD GPIO operation
P4SEL1 &= ~RESET_LCD;            // RESET_LCD GPIO operation
P4DIR |= RESET_LCD;              // Set RESET_LCD direction to output
P4OUT |= RESET_LCD;              // Set RESET_LCD Off [High]

P4SEL0 &= ~SW1;                  // SW1 GPIO operation
P4SEL1 &= ~SW1;                  // SW1 GPIO operation
P4DIR &= ~SW1;                   // Direction = input
P4OUT |= SW1;                    // Configure pullup resistor
P4REN |= SW1;                    // Enable pullup resistor
P4IES |= SW1;                 // P2.0 Hi/Lo edge interrupt
P4IFG &= ~SW1;                // Clear all P2.6 interrupt flags
P4IE |= SW1;                  // P2.6 interrupt enabled

P4SEL0 |= UCA1RXD;               // USCI_A1 UART operation
P4SEL1 &= ~UCA1RXD;              // USCI_A1 UART operation

P4SEL0 |= UCA1TXD;               // USCI_A1 UART operation
P4SEL1 &= ~UCA1TXD;              // USCI_A1 UART operation

P4SEL0 &= ~UCB1_CS_LCD;          // UCB1_CS_LCD GPIO operation
P4SEL1 &= ~UCB1_CS_LCD;          // UCB1_CS_LCD GPIO operation
P4DIR |= UCB1_CS_LCD;            // Set SPI_CS_LCD direction to output
P4OUT |= UCB1_CS_LCD;            // Set SPI_CS_LCD Off [High]

P4SEL0 |= UCB1SCLK;              // UCB1CLK SPI BUS operation
P4SEL1 &= ~UCB1SCLK;             // UCB1CLK SPI BUS operation

P4SEL0 |= UCB1SIMO;              // UCB1SIMO SPI BUS operation
P4SEL1 &= ~UCB1SIMO;             // UCB1SIMO SPI BUS operation

P4SEL0 |= UCB1SOMI;              // UCB1SOMI SPI BUS operation
P4SEL1 &= ~UCB1SOMI;             // UCB1SOMI SPI BUS operation
//------------------------------------------------------------------------------
}

void Init_Port5(void){
//------------------------------------------------------------------------------
// Port Configurations
//------------------------------------------------------------------------------
P5DIR = DIR_TO_OUTPUT;            // Set P1 direction to output aka  = 0xFF;
P5OUT = P_TO_LOW;                 // P1 set Low aka = 0x00

P5SEL0 &= ~IOT_RESET;             //IOT_RESET signal selection
P5SEL1 &= ~IOT_RESET;             //IOT_RESET signal selection
//P5OUT                           // Set out value ????
//P5DIR                           // Set direction to ??????
P5SEL0 &= ~IR_LED;                //IR_LED signal selection
P5SEL1 &= ~IR_LED;                //IR_LED signal selection
//P5OUT                           // Set out value ????
//P5DIR                           // Set direction to ??????


P5SEL0 &= ~IOT_PROGRAM_SELECT;    //IOT_PROGRAM_SELECT signal selection
P5SEL1 &= ~IOT_PROGRAM_SELECT;    //IOT_PROGRAM_SELECT signal selection
//P5OUT                           // Set out value ????
//P5DIR                           // Set direction to ??????


P5SEL0 &= ~IOT_PROGRAM_MODE;      //IOT_PROGRAM_MODE signal selection
P5SEL1 &= ~IOT_PROGRAM_MODE;      //IOT_PROGRAM_MODE signal selection
//P5OUT                           // Set out value ????
//P5DIR                           // Set direction to ??????

P5SEL0 &= ~CHECK_BAT;             //CHECK_BAT signal selection
P5SEL1 &= ~CHECK_BAT;             //CHECK_BAT signal selection
//P5OUT                           // Set out value ????
//P5DIR                           // Set direction to ??????
//------------------------------------------------------------------------------  

//------------------------------------------------------------------------------  
}

void Init_Port6(int onoff){
//------------------------------------------------------------------------------
// Port Configurations
//------------------------------------------------------------------------------
P6DIR = DIR_TO_OUTPUT;            // Set P1 direction to output
P6OUT = P_TO_LOW;                 // P1 set Low

P6SEL0 |= R_FORWARD;             //R_FORWARD signal selection
P6SEL1 &= ~R_FORWARD;             //R_FORWARD signal selection
//P6OUT &= ~R_FORWARD;              // Set out value ????
P6DIR |= R_FORWARD;               // Set direction to ??????

P6SEL0 |= L_FORWARD;             //L_FORWARD signal selection
P6SEL1 &= ~L_FORWARD;             //L_FORWARD signal selection
//P6OUT &= ~L_FORWARD;              // Set out value ????
P6DIR |= L_FORWARD;               // Set direction to ??????

P6SEL0 |= R_REVERSE;             //R_REVERSE signal selection
P6SEL1 &= ~R_REVERSE;             //R_REVERSE signal selection
//P6OUT &= ~R_REVERSE;              // Set out value ????
P6DIR |= R_REVERSE;               // Set direction to ??????

P6SEL0 |= L_REVERSE;              //L_REVERSE signal selection
P6SEL1 &= ~L_REVERSE;             //L_REVERSE signal selection
//P6OUT &= ~L_REVERSE;              // Set out value ????
P6DIR |= L_REVERSE;               // Set direction to ??????

//P6SEL0 &= ~LCD_BACKLITE;          //LCD_BACKLITE signal selection
//P6SEL1 &= ~LCD_BACKLITE;          //LCD_BACKLITE selection
//P6OUT |= LCD_BACKLITE;            // Set out value ON **ONLY ONE AT A TIME
////P6OUT &= ~LCD_BACKLITE;         // Set out value OFF **ONLY ONE AT A TIME
//P6DIR |= LCD_BACKLITE;

//if(onoff == 0){
//P6SEL0 &= ~LCD_BACKLITE;          //LCD_BACKLITE signal selection
//P6SEL1 &= ~LCD_BACKLITE;          //LCD_BACKLITE selection
//P6OUT |= LCD_BACKLITE;            // Set out value ON **ONLY ONE AT A TIME
//P6OUT &= ~LCD_BACKLITE;         // Set out value OFF **ONLY ONE AT A TIME
//P6DIR |= LCD_BACKLITE;
//}else{
  P6SEL0 &= ~LCD_BACKLITE;          //LCD_BACKLITE signal selection
  P6SEL1 &= ~LCD_BACKLITE;          //LCD_BACKLITE selection
  P6OUT |= LCD_BACKLITE;            // Set out value ON **ONLY ONE AT A TIME
//  P6OUT &= ~LCD_BACKLITE;         // Set out value OFF **ONLY ONE AT A TIME
  P6DIR |= LCD_BACKLITE;
//}


P6SEL0 |= P6_5;                   //P6_5 signal selection
P6SEL1 &= ~P6_5;                  //P6_5 signal selection
//P6OUT                           // Set out value ????
P6DIR &= ~P6_5;                   // Set direction to INPUT

P6SEL0 &= ~GRN_LED;               //P6_6 signal selection
P6SEL1 &= ~GRN_LED;               //P6_6 signal selection
P6OUT  |= GRN_LED;                // Set RED_LED Off [High]**
P6DIR |= GRN_LED;                 // Set direction to INPUT




//------------------------------------------------------------------------------  
}
