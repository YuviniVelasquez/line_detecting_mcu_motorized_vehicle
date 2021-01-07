//===========================================================================
// File Name : pwm_control.c
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

//void Init_LEDs(void){
////------------------------------------------------------------------------------
//// LED Configurations
////------------------------------------------------------------------------------
//// Turns on both LEDs
//// TB3.1 P6.0 R_FORWARD
//// TB3.2 P6.1 L_FORWARD
//// TB3.3 P6.2 R_REVERSE
//// TB3.4 P6.3 L_REVERSE
//  
//RIGHT_FORWARD_SPEED = WHEEL_OFF; // P6.0 Right Forward PWM OFF
//RIGHT_FORWARD_SPEED = [DESIRED ON AMOUNT]; // P6.0 Right Forward PWM ON amount
//
//LEFT_FORWARD_SPEED = WHEEL_OFF; // P6.1 Left Forward PWM OFF
//LEFT_FORWARD_SPEED = [DESIRED ON AMOUNT]; // P6.1 Left Forward PWM ON amount
//
//RIGHT_REVERSE_SPEED = WHEEL_OFF; // P6.2 Right Reverse PWM OFF
//RIGHT_REVERSE_SPEED = [DESIRED ON AMOUNT]; // P6.2 Right Reverse PWM ON amount
//
//LEFT_REVERSE_SPEED = WHEEL_OFF; // P6.3 Left Reverse PWM OFF
//LEFT_REVERSE_SPEED = [DESIRED ON AMOUNT]; // P6.3 Left Reverse PWM ON amount
////------------------------------------------------------------------------------
//}

void wheels_offpwm(void){
// TB3.1 P6.0 R_FORWARD
// TB3.2 P6.1 L_FORWARD
// TB3.3 P6.2 R_REVERSE
// TB3.4 P6.3 L_REVERSE
  
RIGHT_FORWARD_SPEED = WHEEL_OFF; // P6.0 Right Forward PWM OFF
LEFT_FORWARD_SPEED = WHEEL_OFF; // P6.1 Left Forward PWM OFF
RIGHT_REVERSE_SPEED = WHEEL_OFF; // P6.2 Right Reverse PWM OFF
LEFT_REVERSE_SPEED = WHEEL_OFF; // P6.3 Left Reverse PWM OFF
GREEN_LED_OFF;
RED_LED_OFF;
}

void wheels_forwardpwm(void){
// TB3.1 P6.0 R_FORWARD
// TB3.2 P6.1 L_FORWARD
// TB3.3 P6.2 R_REVERSE
// TB3.4 P6.3 L_REVERSE
RIGHT_REVERSE_SPEED = WHEEL_OFF; // P6.2 Right Reverse PWM OFF
LEFT_REVERSE_SPEED = WHEEL_OFF; // P6.3 Left Reverse PWM OFF
RIGHT_FORWARD_SPEED = WHEEL_FULL; // P6.0 Right Forward PWM ON          40000        
LEFT_FORWARD_SPEED = WHEEL_LEFT_FULL; // P6.1 Left Forward PWM ON       25000 MATCHES RIGHT
GREEN_LED_OFF;
RED_LED_ON;
}

void wheels_reversepwm(void){
// TB3.1 P6.0 R_FORWARD
// TB3.2 P6.1 L_FORWARD
// TB3.3 P6.2 R_REVERSE
// TB3.4 P6.3 L_REVERSE

RIGHT_FORWARD_SPEED = WHEEL_OFF; // P6.0 Right Forward PWM OFF
LEFT_FORWARD_SPEED = WHEEL_OFF; // P6.1 Left Forward PWM OFF
RIGHT_REVERSE_SPEED = WHEEL_FULL; // P6.2 Right Reverse PWM ON          40000
LEFT_REVERSE_SPEED = WHEEL_LEFT_BACK; // P6.3 Left Reverse PWM ON            30000
GREEN_LED_OFF;
RED_LED_ON;
}

void wheels_clkwise_pwm(void){
// TB3.1 P6.0 R_FORWARD
// TB3.2 P6.1 L_FORWARD
// TB3.3 P6.2 R_REVERSE
// TB3.4 P6.3 L_REVERSE

LEFT_REVERSE_SPEED = WHEEL_OFF; // P6.3 Left Reverse PWM ON
RIGHT_FORWARD_SPEED = WHEEL_OFF; // P6.0 Right Forward PWM OFF
RIGHT_REVERSE_SPEED = WHEEL_FULL; // P6.2 Right Reverse PWM ON          40000
LEFT_FORWARD_SPEED = WHEEL_LEFT_FULL; // P6.1 Left Forward PWM OFF      25000
GREEN_LED_OFF;
RED_LED_ON;
}

void wheels_ctrwise_pwm(void){
// TB3.1 P6.0 R_FORWARD
// TB3.2 P6.1 L_FORWARD
// TB3.3 P6.2 R_REVERSE
// TB3.4 P6.3 L_REVERSE
RIGHT_REVERSE_SPEED = WHEEL_OFF; // P6.2 Right Reverse PWM OFF          
LEFT_FORWARD_SPEED = WHEEL_OFF; // P6.1 Left Forward PWM OFF 
LEFT_REVERSE_SPEED = WHEEL_LEFT_FULL; // P6.3 Left Reverse PWM ON    25000
RIGHT_FORWARD_SPEED = WHEEL_FULL; // P6.0 Right Forward PWM ON      40000   
GREEN_LED_OFF;
RED_LED_ON;
}


void wheels_clkwiseslow_pwm(void){
// TB3.1 P6.0 R_FORWARD
// TB3.2 P6.1 L_FORWARD
// TB3.3 P6.2 R_REVERSE
// TB3.4 P6.3 L_REVERSE

LEFT_REVERSE_SPEED = WHEEL_OFF; // P6.3 Left Reverse PWM ON
RIGHT_FORWARD_SPEED = WHEEL_OFF; // P6.0 Right Forward PWM OFF
RIGHT_REVERSE_SPEED = WHEEL_VERY_SLOW; // P6.2 Right Reverse PWM ON
LEFT_FORWARD_SPEED =  WHEEL_LEFT_SLOW; // P6.1 Left Forward PWM OFF
GREEN_LED_OFF;
RED_LED_ON;
}