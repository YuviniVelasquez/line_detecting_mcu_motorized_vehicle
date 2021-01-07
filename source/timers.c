//===========================================================================
// File Name : timers.c
//
// Description: This file contains timers
//
// Author: Yuvini Velasquez
// Date: 9/11/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================

#include "functions.h"
#include "msp430.h"
#include <string.h>
#include "macros.h"

void Init_Timers(void)
{
  Init_Timer_B0(); // Initializing Timers in B_0
  Init_Timer_B3(); // Initializing Timers in B_3
}
//------------------------------------------------------------------------------
// Timer B0 initialization sets up both B0_0, B0_1-B0_2 and overflow
void Init_Timer_B0(void)
{
  //Definition of timers
  TB0CTL = TBSSEL__SMCLK;  // SMCLK source
  TB0CTL |= TBCLR;         // Resets TB0R, clock divider, count direction
  TB0CTL |= MC__CONTINOUS; // Continuous up
  TB0CTL |= ID__2;         // Divide clock by 2
  TB0EX0 = TBIDEX__8;      // Divide clock by an additional 8

  //When intervals are going to happen
  //Set CCR to interval, you assume it starts at zero and count to that interval
  TB0CCR0 = TB0CCR0_INTERVAL; // CCR0
  TB0CCTL0 |= CCIE;           // CCR0 enable interrupt, and as soon as it hits the value
  // this interrupt  will happen
  TB0CCR1 = TB0CCR1_INTERVAL50; // CCR1
  TB0CCTL1 |= CCIE;             // CCR1 enable interrupt
  //TB0CCR2 = TB0CCR2_INTERVAL2; // CCR2
  //TB0CCTL2 |= CCIE; // CCR2 enable interrupt,
  // By defautl enable overflow interrupt comes enable
  TB0CTL &= ~TBIE; // Disable Overflow Interrupt

  TB0CTL &= ~TBIFG; // Clear Overflow Interrupt flag
  //so no interrupt will happen
}
//------------------------------------------------------------------------------

void Init_Timer_B3(void)
{
  //------------------------------------------------------------------------------
  // SMCLK source, up count mode, PWM Right Side
  // TB3.1 P6.0 R_FORWARD
  // TB3.2 P6.1 L_FORWARD
  // TB3.3 P6.2 R_REVERSE
  // TB3.4 P6.3 L_REVERSE
  //------------------------------------------------------------------------------
  TB3CTL = TBSSEL__SMCLK;          // SMCLK
  TB3CTL |= MC__UP;                // Up Mode
  TB3CTL |= TBCLR;                 // Clear TAR
  TB3CCR0 = WHEEL_PERIOD;          // PWM Period
  TB3CCTL1 = OUTMOD_7;             // CCR1 reset/set
  RIGHT_FORWARD_SPEED = WHEEL_OFF; // P6.0 Right Forward PWM duty cycle
  TB3CCTL2 = OUTMOD_7;             // CCR2 reset/set
  LEFT_FORWARD_SPEED = WHEEL_OFF;  // P6.1 Left Forward PWM duty cycle
  TB3CCTL3 = OUTMOD_7;             // CCR3 reset/set
  RIGHT_REVERSE_SPEED = WHEEL_OFF; // P6.2 Right Reverse PWM duty cycle
  TB3CCTL4 = OUTMOD_7;             // CCR4 reset/set
  LEFT_REVERSE_SPEED = WHEEL_OFF;  // P6.3 Left Reverse PWM duty cycle
  //------------------------------------------------------------------------------
}