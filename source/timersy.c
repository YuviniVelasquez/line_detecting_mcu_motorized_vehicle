//===========================================================================
// File Name : timersy.c
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

//------------------------------------------------------------------------------
// Timer B0 initialization sets up both B0_0, B0_1-B0_2 and overflow
void Init_Timer_B0(void) {
  TB0CTL = TBSSEL__SMCLK; // SMCLK source
  TB0CTL |= TBCLR; // Resets TB0R, clock divider, count direction
  TB0CTL |= MC__CONTINOUS; // Continuous up
  TB0CTL |= ID__2; // Divide clock by 2
  TB0EX0 = TBIDEX__8; // Divide clock by an additional 8
  TB0CCR0 = TB0CCR0_INTERVAL; // CCR0
  TB0CCTL0 |= CCIE; // CCR0 enable interrupt
// TB0CCR1 = TB0CCR1_INTERVAL; // CCR1
// TB0CCTL1 |= CCIE; // CCR1 enable interrupt
// TB0CCR2 = TB0CCR2_INTERVAL; // CCR2
// TB0CCTL2 |= CCIE; // CCR2 enable interrupt
  TB0CTL &= ~TBIE; // Disable Overflow Interrupt
  TB0CTL &= ~TBIFG; // Clear Overflow Interrupt flag
}
//------------------------------------------------------------------------------

#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer0_B0_ISR(void){
//------------------------------------------------------------------------------
// TimerB0 0 Interrupt handler
//----------------------------------------------------------------------------
...... Add What you need happen in the interrupt ......
TB0CCR0 += TB0CCR0_INTERVAL; // Add Offset to TBCCR0
//----------------------------------------------------------------------------
}
#pragma vector=TIMER0_B1_VECTOR
__interrupt void TIMER0_B1_ISR(void){
//----------------------------------------------------------------------------
// TimerB0 1-2, Overflow Interrupt Vector (TBIV) handler
//----------------------------------------------------------------------------
switch(__even_in_range(TB0IV,14)){
case 0: break; // No interrupt
case 2: // CCR1 not used
...... Add What you need happen in the interrupt ......
TB0CCR1 += TB0CCR1_INTERVAL; // Add Offset to TBCCR1
break;
case 4: // CCR2 not used
...... Add What you need happen in the interrupt ......
TB0CCR2 += TB0CCR2_INTERVAL; // Add Offset to TBCCR2
break;
case 14: // overflow
...... Add What you need happen in the interrupt ......
break;
default: break;
}
//----------------------------------------------------------------------------
}
