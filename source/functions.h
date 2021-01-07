//******************************************************************************
//
//  Description: This file contains the Function prototypes
//
//  Jim Carlson
//  Aug 2013
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************
// Functions

// Initialization
void Init_Conditions(void);

// Interrupts
void enable_interrupts(void);
__interrupt void Timer0_B0_ISR(void);
__interrupt void switch_interrupt(void);
//port selector
//void Init_Port3(int p3_4selector);

// Analog to Digital Converter

// Clocks
void Init_Clocks(void);

// LED Configurations
void Init_LEDs(void);
void IR_LED_control(char selection);
void Backlite_control(char selection);

  // LCD
void Display_Process(void);
void Display_Update(char p_L1,char p_L2,char p_L3,char p_L4);
void enable_display_update(void);
void update_string(char *string_data, int string);
void Init_LCD(void);
void lcd_clear(void);
void lcd_putc(char c);
void lcd_puts(char *s);

void lcd_power_on(void);
void lcd_write_line1(void);
void lcd_write_line2(void);
//void lcd_draw_time_page(void);
//void lcd_power_off(void);
void lcd_enter_sleep(void);
void lcd_exit_sleep(void);
//void lcd_write(unsigned char c);
//void out_lcd(unsigned char c);

void Write_LCD_Ins(char instruction);
void Write_LCD_Data(char data);
void ClrDisplay(void);
void ClrDisplay_Buffer_0(void);
void ClrDisplay_Buffer_1(void);
void ClrDisplay_Buffer_2(void);
void ClrDisplay_Buffer_3(void);

void SetPostion(char pos);
void DisplayOnOff(char data);
void lcd_BIG_mid(void);
void lcd_4line(void);
void lcd_out(char *s, char line, char position);
void lcd_rotate(char view);

//void lcd_write(char data, char command);
void lcd_write(unsigned char c);
void lcd_write_line1(void);
void lcd_write_line2(void);
void lcd_write_line3(void);

void lcd_command( char data);
void LCD_test(void);
void LCD_iot_meassage_print(int nema_index);

// Menu
void Menu_Process(void);

// Ports
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(char smclk);
void Init_Port4(void);
void Init_Port5(void);
void Init_Port6(int onoff);

// SPI
void Init_SPI_B1(void);
void SPI_B1_write(char byte);
void spi_rs_data(void);
void spi_rs_command(void);
void spi_LCD_idle(void);
void spi_LCD_active(void);
void SPI_test(void);
void WriteIns(char instruction);
void WriteData(char data);

// Switches
void Init_Switches(void);
void switch_control(void);
void enable_switch_SW1(void);
void enable_switch_SW2(void);
void disable_switch_SW1(void);
void disable_switch_SW2(void);
void Switches_Process(void);
void Init_Switch(void);
void Switch_Process(void);
void Switch1_Process(void);
void Switch2_Process(void);
void menu_act(void);
void menu_select(void);

// Timers
void Init_Timers(void);
void Init_Timer_B0(void);
void Init_Timer_B1(void);
void Init_Timer_B2(void);
void Init_Timer_B3(void);


void usleep(unsigned int usec);
void usleep10(unsigned int usec);
void five_msec_sleep(unsigned int msec);
void measure_delay(void);
void out_control_words(void);

//Clock Counters
void clock_cout(void);

//Figures
void circle(void);
void stop_wheels(void);
void infinity(void);
void circle_right(void);
void circle_left(void);
void straight_line(void);
void triangle(void);
                   

//clockcount
void couple_seconds_delay(void);
void fsm(int casefsm); 
void switch_func(void);
//menu display
void display_menu(void);
void display_line_copier(void);
void display_line_clear(void);
void display_putty_state(void);
void command_array_clear(void);
void command_array_copier(void);
//figure call
void figure_call(void);

//pwm 
void wheels_offpwm(void);
void wheels_forwardpwm(void);
void wheels_reversepwm(void);
void wheels_clkwise_pwm(void);
void wheels_ctrclkwise_pwm(void);
//forward_reverse_p5 functions
void forward_rev(void);
void wheels_clkwiseslow_pwm(void);
void wheels_ctrwise_pwm(void);

//HEX_BCD CONVERTER
void HEXtoBCD(int hex_value);
void screen_counter(void);
//interrupt_adc
int adc_line4(int disp_state);

//init_adc
void Init_ADC(void);

//Emitter control
void emitter_control(void);
//Line Detect
void line_detect(void);
//Initializing USB
void Init_Serial_UCA0(void); 
void Init_Serial_UCA1(void);

//General fucntions including iot setup
void dissasemby_setup(void);
void iot_port_setup(void);
void clear_iot_command_array(void);
void clear_stack(void);
void command_library (void);
void command_stack_process(void);
void command_call_timed(void);