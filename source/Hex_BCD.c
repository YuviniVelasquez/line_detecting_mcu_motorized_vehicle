// File Name : Hex_BCD.c
//
// Description: This file contains the function that converts the input 
// to a hex
//
// Author: Yuvini Velasquez
// Date: 10/18/19
// Compiler: Built with IAR Embedded Workbench Version: V (7.12.4)
//===========================================================================


#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

extern unsigned int adc_line;
extern volatile unsigned char display_changed;
extern char display_line[NUM_OF_ROWS][NUM_0F_COLS];
extern char adc_char[LINE_LENGHT];
extern volatile unsigned int p4_counter ;

unsigned int left_val;
unsigned int right_val;
extern volatile unsigned int rotation_timer;
unsigned int counter_char;
extern unsigned int circle_timer;       //overall timer
extern unsigned int enable_circle_timer;               //enables circuit timer

//------------------------------------------------------------------------------
//******************************************************************************
// Hex to BCD Conversion
// Convert a Hex number to a BCD for display on an LCD or monitor
//
//------------------------------------------------------------------------------

char adc_char[LINE_LENGHT];

void HEXtoBCD(int hex_value){
 // hex_value = rotation_timer;
  if(adc_line==ADC_LINE2){
        left_val = hex_value;

  }else if (adc_line ==ADC_LINE3){
        right_val = hex_value; 
  }
    counter_char = circle_timer;
  
int value=RESET_INT;
while (counter_char > THOUSAND_LIMIT){
counter_char = counter_char - THOUSAND_CONVERTER;
value = value + VALUE_COUNTER;
}
adc_char[ADC_CHAR0] = ASCI_CONVERTER + value;
if (adc_char[ADC_CHAR0] == ASCI_ZERO){
  adc_char[ADC_CHAR0] = '0';
}
    display_changed = YES;
value = RESET_INT;
while (counter_char > HUNDRED_LIMIT){
counter_char = counter_char - HUNDRED_CONVERTER;
value = value + VALUE_COUNTER;
}
adc_char[ADC_CHAR1] = ASCI_CONVERTER + value;
if (adc_char[ADC_CHAR1] == ASCI_ZERO){
  adc_char[ADC_CHAR1] = '0';
}
display_changed = YES;

value = RESET_INT;
while (counter_char > TENTHS_LIMIT){
counter_char = counter_char - TENTHS_CONVERTER;
value = value + VALUE_COUNTER;
}
adc_char[ADC_CHAR2] = ASCI_CONVERTER + value;
if (adc_char[ADC_CHAR2] == ASCI_ZERO){
  adc_char[ADC_CHAR2] = '0';
}

  adc_char[ADC_CHAR3] = ASCI_CONVERTER + counter_char;

      display_line[DISPLAY_L4][DISPLAY_CHAR6] = adc_char[ADC_CHAR0];
      display_line[DISPLAY_L4][DISPLAY_CHAR7] = adc_char[ADC_CHAR1];
      display_line[DISPLAY_L4][DISPLAY_CHAR8] = adc_char[ADC_CHAR2];
      display_line[DISPLAY_L4][DISPLAY_CHAR9] = adc_char[ADC_CHAR3];


}
//******************************************************************************
//------------------------------------------------------------------------------




void screen_counter(void){
  if(enable_circle_timer){
    counter_char = circle_timer;
  
int value=RESET_INT;
while (counter_char > THOUSAND_LIMIT){
counter_char = counter_char - THOUSAND_CONVERTER;
value = value + VALUE_COUNTER;
}
adc_char[ADC_CHAR0] = ASCI_CONVERTER + value;
if (adc_char[ADC_CHAR0] == ASCI_ZERO){
  adc_char[ADC_CHAR0] = '0';
}
    display_changed = YES;
value = RESET_INT;
while (counter_char > HUNDRED_LIMIT){
counter_char = counter_char - HUNDRED_CONVERTER;
value = value + VALUE_COUNTER;
}
adc_char[ADC_CHAR1] = ASCI_CONVERTER + value;
if (adc_char[ADC_CHAR1] == ASCI_ZERO){
  adc_char[ADC_CHAR1] = '0';
}
display_changed = YES;

value = RESET_INT;
while (counter_char > TENTHS_LIMIT){
counter_char = counter_char - TENTHS_CONVERTER;
value = value + VALUE_COUNTER;
}
adc_char[ADC_CHAR2] = ASCI_CONVERTER + value;
if (adc_char[ADC_CHAR2] == ASCI_ZERO){
  adc_char[ADC_CHAR2] = '0';
}

  adc_char[ADC_CHAR3] = ASCI_CONVERTER + counter_char;

      display_line[DISPLAY_L4][DISPLAY_CHAR6] = adc_char[ADC_CHAR0];
      display_line[DISPLAY_L4][DISPLAY_CHAR7] = adc_char[ADC_CHAR1];
      display_line[DISPLAY_L4][DISPLAY_CHAR8] = adc_char[ADC_CHAR2];
      display_line[DISPLAY_L4][DISPLAY_CHAR9] = adc_char[ADC_CHAR3];
}

}
//******************************************************************************
//------------------------------------------------------------------------------