//===========================================================================
// File Name : macros.h
//
// Description: This file contains the Initialization for all port pins
//
// Author: Yuvini Velasquez
// Date: 9/11/19
// Compiler: Built with IAR Embedded Workbench Version: V(7.12.4)
//===========================================================================

 

#define RED_LED_ON      (P1OUT |= RED_LED)
#define RED_LED_OFF    (P1OUT &= ~RED_LED)
#define GREEN_LED_ON    (P6OUT |= GRN_LED)
#define GREEN_LED_OFF  (P6OUT &= ~GRN_LED)
#define ALWAYS                         (1)
#define RESET_STATE                    (0)
#define RESET_INDEX                     (0)
#define RED_LED                     (0x01) // RED LED 0
#define GRN_LED                     (0x40) // GREEN LED 1
#define YES                             (1)
#define NO                              (0)
#define NO_2                            (2)
#define OFF                             (0)   
#define CLEAR_COMMAND                       (0)
#define CLEAR_COUNTER                   (0)
//Main Macros
#define CASE_250        (0xFA)  //Time_Sequence first case @250
#define CASE_200        (0xC8)  //Time_Sequence second case @200
#define CASE_150        (0x96)  //Time_Sequence third case @150
#define CASE_100        (0x64)  //Time_Sequence fourth case @100
#define CASE_50         (0x32)  //Time_Sequence fifth case @50
#define RESET_TIMER     (0x00)  //Setting value to zero
#define ONE_TIME_ZERO   (0x00)  //Setting one time value to zero
#define CHANGE_DISP     (0x01)  //Enabling to 1 the change to display
#define NUM_OF_ROWS         (0x04)
#define NUM_0F_COLS         (0x0B)
//Main and Init Macros
#define DISPLAY_L1      (0x00)  //Array selector for display_line
#define DISPLAY_L2      (0x01)  //Array selector for display_line
#define DISPLAY_L3      (0x02)  //Array selector for display_line
#define DISPLAY_L4      (0x03)  //Array selector for display_line
//Init Macros
#define END_OF_ARRAY    (0x0A)  //Last array element, 10
#define INIT_OF_ARRAY   (0x00)  //Beginning of array, element 0
//P3Selector Macros
#define USE_GPIO        (0x00)  //Enabling GPIO
#define USE_SMCLK       (0x01)  //Enabling SMCLK
//General Ports macros
#define DIR_TO_OUTPUT   (0xFF)    //Set PX direction to output
#define P_TO_LOW        (0x00)    // Use to set Px to Low    
//Clockdiv Macros
#define RESET_COUNTER   (0x00) // Reseting counter to zero
#define CSCTL4_MAX      (0x8000) //Frequency of CSCTL4, 2^15
//Figures macros
#define CL4_1_8         (0x1000) //Frequency division at every 4096Hz,(2^15)/8
#define CL4_2_8         (0x2000) //Frequency division at every 4096Hz,(2^15)/8
#define CL4_3_8         (0x3000) //Frequency division at every 4096Hz,(2^15)/8
#define CL4_4_8         (0x4000) //Frequency division at every 4096Hz,(2^15)/8
#define CL4_5_8         (0x5000) //Frequency division at every 4096Hz,(2^15)/8
#define CL4_6_8         (0x6000) //Frequency division at every 4096Hz,(2^15)/8
#define CL4_7_8         (0x7000) //Frequency division at every 4096Hz,(2^15)/8
#define CL4_8_8         (0x8000) //Frequency division at every 4096Hz,(2^15)/8

// Port 1 Pins
#define RED_LED         (0x01) // 0 RED LED 0
#define A1_SEEED        (0x02) // 1 A1_SEEED
#define V_DETECT_L      (0x04) // 2 V_DETECT_L
#define V_DETECT_R      (0x08) // 3 V_DETECT_R
#define V_BAT           (0x10) // 4 V_BAT
#define V_THUMB         (0x20) // 5 V_THUMB
#define UCA0RXD         (0x40) // 6 Back Channel UCA0RXD
#define UCA0TXD         (0x80) // 7 Back Channel UCA0TXD

// Port 2 Pins
#define P2_0            (0x01) // 0
#define P2_1            (0x02) // 1
#define P2_2            (0x04) // 2
#define SW2             (0x08) // 3 SW2
#define P2_4            (0x10) // 4
#define P2_5            (0x20) // 5
#define LFXOUT            (0x40) // XOUTR
#define LFXIN             (0x80) // XINR

// Port 3 Pins
#define TEST_PROBE      (0x01) // 0 TEST PROBE
#define OA2O            (0x02) // 1 Photodiode Circuit
#define OA2N            (0x04) // 2 Photodiode Circuit
#define OA2P            (0x08) // 3 Photodiode Circuit
#define SMCLK_OUT       (0x10) // 4 SMCLK
#define OA3O            (0x20) // 5
#define IOT_LINK        (0x40) // 6 IOT_LINK
#define P3_7            (0x80) // 7

// Port 4 Pins
#define RESET_LCD       (0x01) // 0 LCD Reset
#define SW1             (0x02) // 1 SW1
#define UCA1RXD         (0x04) // 2 Back Channel UCA1RXD
#define UCA1TXD         (0x08) // 3 Back Channel UCA1TXD
#define UCB1_CS_LCD     (0x10) // 4 Chip Select
#define UCB1SCLK        (0x20) // 5 SPI mode - clock output—UCB1CLK
#define UCB1SIMO        (0x40) // 6 UCB1SIMO
#define UCB1SOMI        (0x80) // 7 UCB1SOMI

//Port 5 Pins
#define IOT_RESET               (0x01) 
#define IR_LED                  (0x02)
#define IOT_PROGRAM_SELECT      (0x04)
#define IOT_PROGRAM_MODE        (0x08)
#define CHECK_BAT               (0x10)

//Port 6 Pins
#define R_FORWARD       (0x01) // RIght wheel fordward
#define L_FORWARD       (0x02) // Left wheel fordward
#define R_REVERSE       (0x04) // RIght wheel reverse
#define L_REVERSE       (0x08) // RIght wheel reverse
#define LCD_BACKLITE    (0x10)  
#define P6_5            (0x20)
#define GRN_LED            (0x40)


//Clock division Macro
#define DIVS            (0x0030)
#define DIVS_L          (0x0030)
#define DIVS0           (0x0010)
#define DIVS0_L         (0x0010)
#define DIVS1           (0x0020)
#define DIVS1_L         (0x0020)
#define DIVS_0          (0x0000) // /1
#define DIVS_1          (0x0010) // /2
#define DIVS_1_L        (0x0010)
#define DIVS_2          (0x0020) // /4
#define DIVS_2_L        (0x0020)
#define DIVS_3          (0x0030) // /8
#define DIVS_3_L        (0x0030)
#define DIVS__1         (0x0000) // /1
#define DIVS__2         (0x0010) // /2
#define DIVS__2_L       (0x0010)
#define DIVS__4         (0x0020) // /4
#define DIVS__4_L       (0x0020)
#define DIVS__8         (0x0030) // /8
#define DIVS__8_L       (0x0030)

//Switchcount Macros
#define WAIT            (0x4C4B40)

//FIGURE_CALL MACROS
#define fcircle           (1)
#define finfinity         (2)
#define ftriangle         (3)
#define circle_limit           (41)
#define infinity_limit         (73)
#define triangle_limit         (73)

//FIGURES MACROS
#define on_every_25              (25)
#define on_every_50              (50)

#define part1_inf               (8)
#define part2_inf               (25)
#define part3_inf               (44)
#define part4_inf               (61)
#define part5_inf               (70)

#define part1_tri               (3)
#define part2_tri               (7)
#define part3_tri               (14)
#define part4_tri               (18)
#define part5_tri               (26)
#define part6_tri               (31)
#define part7_tri               (38)
#define part8_tri               (42)
#define part9_tri               (50)
#define part10_tri               (54)
#define part11_tri               (61)
#define part12_tri               (65)

//Interrupt_timers macros
#define EVERY_10_MS              (2)
#define EVERY_200_MS             (40)
#define RUN_COUNTER_LIMIT       (60000)
#define SWITCH_4_PRESSED        (4)
#define SWITCH_2_PRESSED        (2)
#define SWITCH_PRESSED_RESET    (0)
#define ONE_S_AT_50MS           (20)
#define START_1SEC              (1)
#define ONE_SEC_COMPLETED       (2)

//Interrupt_ports macros
#define TB0CCR0_INTERVAL        (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB0CCR0_INTERVAL50      (25000)// 8,000,000 / 2 / 8 / (1 / 50msec)
#define TB0CCR1_INTERVAL50      (25000)// 8,000,000 / 2 / 8 / (1 / 50msec)  //not being used
#define TB0CCR2_INTERVAL2       (500)// 8,000,000 / 2 / 8 / (1 / 1 sec)  //Used for Time_Sequence

//Timmers macros
#define RIGHT_FORWARD_SPEED      (TB3CCR1)
#define LEFT_FORWARD_SPEED       (TB3CCR2)
#define RIGHT_REVERSE_SPEED      (TB3CCR3)
#define LEFT_REVERSE_SPEED       (TB3CCR4)
#define WHEEL_PERIOD             (40000)
#define WHEEL_OFF                (0)

//PWM_CONTROL MACROS
#define WHEEL_FULL               (40000)
#define WHEEL_VERY_SLOW          (20000)

#define WHEEL_LEFT_FULL          (25000)
#define WHEEL_LEFT_BACK          (30000)
#define WHEEL_LEFT_SLOW          (15000)
#define WHEEL_LEFT_SSLOW         (13000)
#define WHEEL_LEFT_VSLOW         (10000)
#define WHEEL_LEFT_VVSLOW        (8000)
#define WHEEL_LEFT_CUSTOM        (5000)

#define WHEEL_RIGHT_MSLOW        (25000)
#define WHEEL_RIGHT_SLOW         (15000)
#define WHEEL_RIGHT_VSLOW        (10000)
#define WHEEL_RIGHT_VVSLOW        (8000)
#define WHEEL_RIGHT_CUSTOM        (18000)
#define WHEEL_SHARP_CLK_R       (1000)
#define WHEEL_SHARP_CLK_L       (10000)

#define WHEEL_SHARP_CTR_R       (15000)
#define WHEEL_SHARP_CTR_L       (12000)

//forward_reverse_p5
#define STATE_0                 (0)
#define STATE_1                 (1)
#define STATE_2                 (2)
#define STATE_3                 (3)
#define STATE_4                 (4)
#define STATE_5                 (5)
#define STATE_6                 (6)

#define TIME_1                  (220)
#define TIME_2                  (440)        
#define TIME_3                  (880)        
#define TIME_4                  (1100)
#define TIME_5                  (1320)
#define TIME_6                  (1540)
#define TIME_7                  (2200)
#define TIME_8                  (2640)
#define TIME_9                  (3300)

//Interrupt adc macros  
#define THUMB_CASE              (0x00)
#define LEFT_DETECT_CASE        (0x01)
#define RIGHT_DETECT_CASE        (0x02)

#define DIVIDE_4                (2)
#define ADC_LINE1               (1)
#define ADC_LINE2               (2)
#define ADC_LINE3               (3)
#define ADC_CHAR0               (0)
#define ADC_CHAR1               (1)
#define ADC_CHAR2               (2)
#define ADC_CHAR3               (3)
#define ADC_CHAR4               (4)
#define DISPLAY_CHAR6           (6)
#define DISPLAY_CHAR7           (7)
#define DISPLAY_CHAR8           (8)
#define DISPLAY_CHAR9           (9)

//Line_detect macros
#define LINE_STATE_1            (1)
#define LINE_STATE_2            (2)
#define LINE_STATE_3            (3)
#define LINE_STATE_4            (4)
#define LINE_STATE_5            (5)
#define LINE_STATE_6            (6)
#define LINE_STATE_7            (7)
#define LINE_STATE_10           (10)
#define DARK_VALUE_L1           (150)   //gray
#define DARK_VALUE_L1_5         (200)
#define DARK_VALUE_L2           (300)
#define DARK_VALUE_L3           (450)
#define DARK_VALUE_L4           (600)
#define DARK_VALUE_L5           (750)   //dark gray

//Hex_BCD
#define LINE_LENGHT             (10)
#define RESET_INT               (0)
#define THOUSAND_LIMIT          (999)
#define THOUSAND_CONVERTER      (1000)
#define HUNDRED_LIMIT           (99)
#define HUNDRED_CONVERTER       (100)
#define TENTHS_LIMIT            (9)
#define TENTHS_CONVERTER        (10)
#define VALUE_COUNTER           (1)
#define ASCI_CONVERTER          (0x30)
#define ASCI_ZERO               (0x00)        
#define P4PRESSED_1             (1)

//USB initializing
#define BEGINNING               (0)
#define SMALL_RING_SIZE         (16)
#define LARGE_RING_SIZE         (16)

//baud rate 115,200
#define BAUD_115k               (4)
#define BAUDCONC_115k           (0x5551)

//baud rate  460800
#define BAUD_460k               (1)
#define BAUDCONC_460k           (0x0411)


//main 
#define STRING_SIZE             (9)
#define RING_BUFF_SIZE          (15)
#define STR_CHAR_0           (0)
#define STR_CHAR_1           (1)
#define STR_CHAR_2           (2)
#define STR_CHAR_3           (3)
#define STR_CHAR_4           (4)
#define STR_CHAR_5           (5)
#define STR_CHAR_6           (6)
#define STR_CHAR_7           (7)
#define STR_CHAR_8           (8)
#define STR_CHAR_9           (9)
#define DISP_CHAR_0           (0)
#define DISP_CHAR_1           (1)
#define DISP_CHAR_2           (2)
#define DISP_CHAR_3           (3)
#define DISP_CHAR_4           (4)
#define DISP_CHAR_5           (5)
#define DISP_CHAR_6           (6)
#define DISP_CHAR_7           (7)
#define DISP_CHAR_8           (8)
#define DISP_CHAR_9           (9)

//DISPLAY_MENU
#define ENABLE_COUT             (1)
#define COUNT_COMPLETE          (2)
#define DISABLE_COUNT           (0)



//INTERRUPT SERIAL COM
#define CASE_0          (0)
#define CASE_1          (1)
#define CASE_2          (2)
#define CASE_3          (3)
#define CASE_4          (4)
#define CASE_5          (5)
#define CASE_6          (6)
#define CASE_7          (7)
#define CASE_8          (8)
#define CASE_9          (9)
#define CASE_10         (10)
#define CASE_11         (11)
#define CASE_12         (12)
#define CASE_13         (13)
#define CASE_14         (14)
#define CASE_15         (15)
#define CASE_16         (16)
#define CASE_17         (17)
#define CASE_18         (18)
#define CASE_19         (19)
#define CASE_20         (20)          
#define CASE_21         (21)
#define CASE_22         (22)
#define CASE_23         (23)
#define CASE_24         (24)
#define CASE_25         (25)          
#define CASE_26         (26)
#define CASE_27         (27)
#define CASE_28         (28)
#define CASE_29         (29)
#define SIZE_13         (0x0D)
#define SIZE_10         (0x0A)
#define RETURN         (0x0D)
#define LINEFEED       (0x0A)
#define SIZE_8         (0x08)
#define STRING_SIZE_10  (10)
#define STRING_SIZE_11  (11)
#define ESC_CHAR        (27)
#define UP_ARROW_CHAR   (94)
#define STRING_SIZE_30  (30)

//INIT_USB
#define WORD_REGISTER   (0)
#define START_COUNTER   (0)
#define USB_START_BUFF  (0x00)

//geeral function macros
#define FORWARD_2_SECS          (0x41)  //A
#define BACK_1_SEC              (0x42)  //B
#define RIGHT_45_DEGREES        (0x43)  //C
#define LEFT_45_DEGREES         (0x44)  //D
#define ONE_SEC_DEBOUNCER       (0x45)  //E
#define TWO_SEC_DEBOUNCER       (0x46)  //F
#define RIGHT_10_DEGREES        (0x47)  //G
#define LEFT_10_DEGREES         (0x48)  //H
#define FORWARD_5_SECS          (0x49)  //I
#define RIGHT_180_D             (0x4A)  //J
#define CHANGE_ARRIVED_STATE    (0x4B)  //K


#define TWO_SECS_LIMIT          (400)
#define FIVE_SECS_LIMIT         (1000)
#define ONE_SEC_LIMIT           (200)
#define HALF_SEC_LIMIT           (100)
#define NINETY_D_LIMIT          (130)
#define ONE_EIGHTY_LIMIT          (260)
#define FOURTY_FIVE_D_LIMIT     (50)  
#define FOURTY_FIVE_D_LIMIT_LEFT (80) 
#define TEN_D_LIMIT             (20) 
#define AT_LEAST_1_COMMAND      (0)
#define AT_LEAST_2_COMMAND      (1)
#define AT_LEAST_3_COMMAND      (2)
#define FIRST_COMMAND           (0)
#define FIRST_COMMAND_CHAR      (1)
#define SECOND_COMMAND          (1)
#define SECOND_COMMAND_CHAR     (1)
#define THIRD_COMMAND           (2)
#define THIRD_COMMAND_CHAR      (1)
#define BEG_COMMAND_CHAR        (0)
#define LAST_COMMAND_CHAR       (29)
#define RETURN_COM_LOCATION     (28)
#define NULL_COM_LOCATION       (29)
#define DISSASEMBLY_RETURN      (20)
#define IOT_RETURN              (16)
#define STACK_SIZE              (3)

//MAIN 
#define CLEAR_COMMAND_S1        (1)
#define CLEAR_COMMAND_S3        (3)
#define ADJUSTMENT_FOR_ARRAY    (1)        




