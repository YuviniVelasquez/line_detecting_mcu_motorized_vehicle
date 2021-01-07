//===========================================================================
// File Name : figures.c
//
// Description: This file will control the speed for the tires to make specific figures
//
// Author: Yuvini Velasquez
// Date: 9/29/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================

#include  "functions.h" 
#include  "msp430.h"
#include <string.h>
#include "macros.h"

volatile unsigned int clockdiv_count = RESET_COUNTER;
extern volatile unsigned int Time_Sequence;
extern volatile unsigned int circle_timer_count;


void stop_wheels(void){
//------------------------------------------------------------------------------
// Circle speed stopped
//------------------------------------------------------------------------------
    P6OUT &= ~R_FORWARD;              //Right wheel off 
    P6OUT &= ~L_FORWARD;              //Left wheel off
}

void circle(void){
//------------------------------------------------------------------------------
// Circle speed configuration // one half of other
//------------------------------------------------------------------------------
  if(Time_Sequence % on_every_25){
    P6OUT |= R_FORWARD;              //Right wheel on 
    P6OUT &= ~L_FORWARD;              //Left wheel on
    GREEN_LED_ON;
    RED_LED_OFF;
    
  }else{
    P6OUT |= R_FORWARD;              //Right wheel on 
    P6OUT |= L_FORWARD;              //Left wheel on
    GREEN_LED_ON;
    RED_LED_ON;
  }
 //------------------------------------------------------------------------------
}
void circle_left(void){
//------------------------------------------------------------------------------
// Circle speed configuration // one half of other
//------------------------------------------------------------------------------
  if(Time_Sequence % on_every_50){
    P6OUT |= R_FORWARD;              //Right wheel on 
    P6OUT &= ~L_FORWARD;              //Left wheel on
    GREEN_LED_OFF;
    RED_LED_OFF;
    
  }else{
    P6OUT |= R_FORWARD;              //Right wheel on 
    P6OUT |= L_FORWARD;              //Left wheel on
    GREEN_LED_ON;
    RED_LED_ON;
  }

 //------------------------------------------------------------------------------
}
void circle_right(void){
//------------------------------------------------------------------------------
// Circle speed configuration // one half of other
//------------------------------------------------------------------------------
  if(Time_Sequence % on_every_50){
    P6OUT &= ~R_FORWARD;              //Right wheel on 
    P6OUT |= L_FORWARD;              //Left wheel on
    GREEN_LED_ON;
    RED_LED_ON;
    
  }else{
    P6OUT |= R_FORWARD;              //Right wheel on 
    P6OUT |= L_FORWARD;              //Left wheel on
    GREEN_LED_ON;
    RED_LED_ON;
  }

 //------------------------------------------------------------------------------
}

void straight_line(void){
//------------------------------------------------------------------------------
// Circle speed stopped
//------------------------------------------------------------------------------
    P6OUT |= R_FORWARD;              //Right wheel on 
    P6OUT |= L_FORWARD;              //Left wheel on

}


void infinity (void){
  //------------------------------------------------------------------------------
// Figure 8
//------------------------------------------------------------------------------
  if (circle_timer_count <= part1_inf){
    circle_left();
  }else if( circle_timer_count <= part2_inf) {
    circle_right();
  }else if( circle_timer_count <= part3_inf) {
    circle_left();
  }else if( circle_timer_count <= part4_inf) {
    circle_right();
  }else if( circle_timer_count <= part5_inf) {
    circle_left();
  }else{
    stop_wheels();
    }
}

void triangle (void){
// //------------------------------------------------------------------------------
  // Triangle figure
  // //------------------------------------------------------------------------------
  if (circle_timer_count <= part1_tri){
    circle_left();
  }else if( circle_timer_count <= part2_tri) {
    straight_line();
  }else if( circle_timer_count <= part3_tri) {
    circle_left();
  }else if( circle_timer_count <= part4_tri) {
    straight_line();
  }else if( circle_timer_count <= part5_tri) {
    circle_left();
  }else if( circle_timer_count <= part6_tri) {
    straight_line();
  }else if( circle_timer_count <= part7_tri) {
    circle_left();
  }else if( circle_timer_count <= part8_tri) {
    straight_line();
  }else if( circle_timer_count <= part9_tri) {
    circle_left();
  }else if( circle_timer_count <= part10_tri) {
    straight_line();
  }else if( circle_timer_count <= part11_tri) {
    circle_left();
  }else if( circle_timer_count <= part12_tri) {
    straight_line();   
  }else{
    stop_wheels();
    }
  
}