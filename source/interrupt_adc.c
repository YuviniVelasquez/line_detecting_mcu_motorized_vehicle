//===========================================================================
// File Name : interrupt_adc.c
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

unsigned int ADC_Channel;
unsigned int ADC_Left_Detect;
unsigned int ADC_Right_Detect;
unsigned int ADC_Thumb;
unsigned int adc_line;

#pragma vector=ADC_VECTOR
__interrupt void ADC_ISR(void){
switch(__even_in_range(ADCIV,ADCIV_ADCIFG)){
  case ADCIV_NONE:
    break;
  case ADCIV_ADCOVIFG: // When a conversion result is written to the ADCMEM0
  // before its previous conversion result was read.
    break;
  case ADCIV_ADCTOVIFG: // ADC conversion-time overflow
    break;
  case ADCIV_ADCHIIFG: // Window comparator interrupt flags
    break;
  case ADCIV_ADCLOIFG: // Window comparator interrupt flag
    break;
  case ADCIV_ADCINIFG: // Window comparator interrupt flag
    break;
  case ADCIV_ADCIFG: // ADCMEM0 memory register with the conversion result
    ADCCTL0 &= ~ADCENC;         //Disables ENC bit.
    switch (ADC_Channel++){
      case THUMB_CASE: // Channel A2 Interrupt
        ADCMCTL0 &= ~ADCINCH_5; // Disable Last channel A2
        ADCMCTL0 |= ADCINCH_2; // Enable Next channel A3
        ADC_Thumb = ADCMEM0; // Move result into Global
        ADC_Thumb = ADC_Thumb >> DIVIDE_4; // Divide the result by 4
        adc_line=ADC_LINE1;             //Line where it will be displayed on the menu
        HEXtoBCD(ADC_Thumb); // Convert result to String
        ADCCTL0 |= ADCENC; // Enable Conversions
       ADCCTL0 |= ADCSC; // Start next sample
        break;
      case LEFT_DETECT_CASE: // Channel A3 Interrupt   Left_Detect
        ADCMCTL0 &= ~ADCINCH_2; // Disable Last channel A3
        ADCMCTL0 |= ADCINCH_3; // Enable Next channel A5
        ADC_Left_Detect = ADCMEM0; // Move result into Global
        ADC_Left_Detect = ADC_Left_Detect >> DIVIDE_4; // Divide the result by 4
        adc_line=ADC_LINE2;             //Line where it will be displayed on the menu    
        HEXtoBCD(ADC_Left_Detect); // Convert result to String
       ADCCTL0 |= ADCENC; // Enable Conversions
       ADCCTL0 |= ADCSC; // Start next sample
        break;
      case RIGHT_DETECT_CASE: // Channel A2 Interrupt
        ADCMCTL0 &= ~ADCINCH_3; // Disable Last channel A5
        ADCMCTL0 |= ADCINCH_5; // Enable Next channel A2
        ADC_Right_Detect = ADCMEM0; // Move result into Global
        ADC_Right_Detect = ADC_Right_Detect >> DIVIDE_4; // Divide the result by 4
        adc_line=ADC_LINE3;             //Line where it will be displayed on the menu        
        HEXtoBCD(ADC_Right_Detect); // Convert result to String
        ADC_Channel=RESET_STATE;
        break;
      default:
        break;
    }

  break;
default:
  break;
}
}