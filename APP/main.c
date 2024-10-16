/*
 * EM_545.c
 *
 * Created: 8/17/2024 7:13:16 PM
 * Author : AMIT
 */ 
#include "../LIB/BIT_MATH.h" 
#include "../LIB/STD_TYPE.h" 
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/KEYPAD/KEYPAD_config.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#define  F_CPU 16000000UL 
#include <util/delay.h>

#include <stdbool.h>
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GI/GI_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/TIM0/TIM0_interface.h"
#include "../MCAL/TIM1/TIM1_interface.h"
#include "../HAL/DC_MOTOR/DC_MOTOR_interface.h"
#include "../MCAL/WDT/WDT_interface.h"
#include "../MCAL/WDT/WDT_reg.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/SPI/SPI_interface.h"




int main(void)
{
	SPI_Mastervoid_Init();
	
	while(1)
	{
		SPI_voidMasterSendData('F');
		_delay_ms(100);
	}
}













//////////////////////////////////////////////////////////////////Bluetooth module///////////////////////////////////////////////
//int main(void)
//{
	//
	//DIO_voidSetPinDir(DIO_PORTC,DIO_PIN2, OUTPUT);
	//DIO_voidSetPinDir(DIO_PORTD,DIO_PIN1, OUTPUT);
	//
	//UART_voidInit();
	//u8 recieve =0;
	//UART_voidTX("AB");
	//while(1)
	//{
		//recieve = UART_u8RX();
		//if(recieve == 'a')
		//{
			//
			//DIO_voidSetPinVal(DIO_PORTC,DIO_PIN2,HIGH);
		//}
		//else
			//DIO_voidSetPinVal(DIO_PORTC,DIO_PIN2,LOW);
			//
	//}
	//
//}
//
//






///////////////////////////////////////WDT///////////////////////////

//int main(void)
//{
	//
	//DIO_voidSetPinVal(DIO_PORTA,DIO_PIN0, OUTPUT);
	//
	//while(1)
	//{
		//WDT_voidStart(_65PRESCALER);
		//DIO_voidSetPinVal(DIO_PORTA,DIO_PIN0, HIGH);
		//_delay_ms(80);
		//DIO_voidSetPinVal(DIO_PORTA,DIO_PIN0, LOW);
		//_delay_ms(40); //total delays more than time of the WDT so it will reset
		//WDT_voidStop();		
		//
	//}
	//
	//
	//
//}



////////////////////////////////////////////////////////////////////////////////////////////////////////////


//volatile u16 ton=0 ;
//
//volatile u16 tp=0 ;
//
//void SW_ICU(void){
	//
	//static u8 count=0 ;
	//count++ ;
	//
	//if (count==1)
	//{
		//TIMER1_voidRest() ;
		//EXTI_voidInit(INT0_,FALLIN_EDGE) ;
	//}
	//if (count==2)
	//{
		//ton=TIMER1_u16ReadVal() ;
		//EXTI_voidInit(INT0_,RISING_EDGE) ;
	//}
	//if(count==3){
		//
		//tp=TIMER1_u16ReadVal() ;
		//count=0 ;
		//TIMER1_voidRest() ;
		//
	//}
	//
	//
	//
	//
	//
	//
	//
//}
//
//
//int main(void)
//{
	///* lcd init */
	//DIO_voidSetPortDir(DIO_PORTA,0xf0) ;
	//DIO_voidSetPortDir(DIO_PORTB,0x0f) ;
	//LCD_voidInit() ;
	//
	///* timers */
	//TIMER1_voidStart() ;
	///* EXT INTERRUPT */
	//GI_voidEnable()  ;
	//EXTI_voidInit(INT0_,RISING_EDGE) ;
	//EXTI0_voidEnable() ;
	//EXTI_voidSetCallBack(SW_ICU,INT0_) ;
	//
	//
	//
	//
	//while(1){
		//
		//TIM0_voidFastPWM(20) ;
		//
		//LCD_voidGoToXY(0,0) ;
		//LCD_SendNumber(ton,0,0) ;
		//LCD_voidGoToXY(0,1) ;
		//LCD_SendNumber(tp,0,1) ;
		//
		//
		//
	//}
//}
//
//
//
//





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//void main()
//{
	//
	//DIO_voidSetPinDir(DIO_PORTD, DIO_PIN5, OUTPUT);
	//TIMER1_voidFastPWMICR1();
	//
	//while(1)
	//{
		////for(u16 val = 5100; val > 1000;--val )
		////{
			//TIMER1_voidSetOCR1(5100);
			//_delay_ms(1);
				//TIMER1_voidSetOCR1(1000);
				//_delay_ms(1);
			//
		////}
	//}
//}

//void tim()
//{
		//static u16 count =0;
		//count ++;
		//if(count == 195)
		//{
			//DIO_voidTogglePinVal(DIO_PORTA,0);
			//count =0;
		//}
//}
//
//void main()
//{
	//
	////DIO_voidSetPinDir(DIO_PORTA,DIO_PIN0,OUTPUT);
	////GI_voidEnable();
	////TIM0_voidInit();
	////TIM0_voidCallBack(tim);
	////DIO_voidSetPinDir(DIO_PORTD, DIO_PIN4, OUTPUT);
	////DIO_voidSetPinDir(DIO_PORTD, DIO_PIN5, OUTPUT);
	////DIO_voidSetPinDir(DIO_PORTC, DIO_PIN0, OUTPUT);
	//u8 DC = 90;
	//DIO_voidSetPinDir(DIO_PORTC, DIO_PIN0, OUTPUT);
	//
	//while(1)
	//{
		////DC_MOTOR_CW(DC);
		//DIO_voidTogglePinVal(DIO_PORTC, DIO_PIN0);
		//_delay_ms(2000);
		////for(u8 i =0; i < 100 ; i++)
		////{
			////
			////TIMER1_voidFastPWM10BitRes(0,i);
				////_delay_ms(50);
			////TIMER1_voidFastPWM10BitRes(1,i);
			////_delay_ms(50);
		////}
	//}
//}
//



//void main()
//{
	//
	//DIO_voidSetPortDir(LCD_DPORT, 0xf0);
	//DIO_voidSetPortDir(LCD_CPORT, 0x0E); // Control pins
	//LCD_voidInit();
	//DIO_voidSetPortDir(DIO_PORTA, 0xFF);
	//
	//DIO_voidSetPinDir(DIO_PORTC,7, OUTPUT);
	//ADC_voidInit();
	//
	//f32 val =0;
	//f32 val1 = 0;
	//while(1)
	//{
		//val = ADC_u16ReadChannel(ADC1_);
		//val = 5 * (2 / 5);
		//val1 = (f32)val*5/1023;
		//
		////for(u8 i = 0; i < 5 ; i++)
		//LCD_SendNumber(val1, 0,1);
//
		//if(val1 > 3)
		//{
			//DIO_voidSetPinVal(DIO_PORTC, DIO_PIN7, HIGH);
			//
		//}
		//else
		//DIO_voidSetPinVal(DIO_PORTC, DIO_PIN7, LOW);
	//}
//}




//void led_function(void)
//{
//LED_voidToggle(DIO_PORTC, DIO_PIN2);
//
//}
//
//
//void main()
//{
		//DIO_voidSetPinDir(DIO_PORTA, DIO_PIN4, OUTPUT) ;
		//DIO_voidSetPinDir(DIO_PORTA, DIO_PIN5, OUTPUT) ;
		//DIO_voidSetPinDir(DIO_PORTA, DIO_PIN6, OUTPUT) ;
		//DIO_voidSetPinDir(DIO_PORTA, DIO_PIN7, OUTPUT) ;
	//
	//while(1)
	//
	//{
		//DIO_voidSetPinVal(DIO_PORTA, DIO_PIN4, LOW);
		//DIO_voidSetPinVal(DIO_PORTA, DIO_PIN5, HIGH);
		//DIO_voidSetPinVal(DIO_PORTA, DIO_PIN6, LOW);
		//DIO_voidSetPinVal(DIO_PORTA, DIO_PIN7, HIGH);
	//}
//
	//
//}

//void main()
//{
	//DIO_voidSetPinDir(DIO_PORTD,DIO_PIN2, INPUT);
	//DIO_voidSetPinDir(DIO_PORTD,DIO_PIN6, INPUT);
	//DIO_voidSetPinDir(DIO_PORTB,DIO_PIN0, INPUT);
	//DIO_voidSetPinDir(DIO_PORTC,DIO_PIN2, OUTPUT);
	//DIO_voidSetPinDir(DIO_PORTC,DIO_PIN7, OUTPUT);
	//DIO_voidSetPinDir(DIO_PORTD,DIO_PIN3, OUTPUT);
	//EXTI_voidInit(INT0_,  RISING_EDGE);
	//GI_voidEnable();
	//EXTI0_voidEnable();
	//callback(led_function, 0);
//
	//
	//while (1)
	//{
		//
	//}
//}
//
//ISR(INT_0)
//{
	//
//}







//// Object position and points collected
//u8 object_x = 0;
//u8 object_y = 0;
//u8 points_collected = 0;
//
//// Initialize the game
//void Start_login() {
	//LCD_voidClear(); // Clear the LCD screen
	//_delay_ms(500);
	//LCD_voidSendString("Game Start!");
	//_delay_ms(500);
	//LCD_voidClear(); // Clear the screen for a new game start
//}
//
//void display_message(char *message) {
	//LCD_voidClear();
	//_delay_ms(500);
	//LCD_voidSendString(message);
//}
//
//void object_creation(u8 pattern, u8 x, u8 y) {
	//u8 user[8] = {0x00, 0x1C, 0x10, 0x1C, 0x00, 0x00, 0x00, 0x00};
	//LCD_voidDrawData(pattern, user, x, y);
//}
//
//void horizontal_barrier_creation(u8 pattern, u8 x, u8 y, u8 blank) {
	//u8 barrier[8];
	//if (blank) {
		//u8 temp[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F};
		//memcpy(barrier, temp, 8 * sizeof(u8));
		//} else {
		//u8 temp[8] = {0x04, 0x0A, 0x04, 0x00, 0x00, 0x00, 0x1F, 0x1F};
		//memcpy(barrier, temp, 8 * sizeof(u8));
	//}
	//LCD_voidDrawData(pattern, barrier, x, y);
//}
//
//void vertical_barrier_creation(u8 pattern, u8 x, u8 y, u8 blank) {
	//u8 barrier[8] = {0}; // Correct initialization
//
	//if (blank) {
		//u8 temp[8] = {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01};
		//memcpy(barrier, temp, 8 * sizeof(u8));
		//} else {
		//u8 temp[8] = {0x01, 0x01, 0x01, 0x09, 0x15, 0x09, 0x01, 0x01};
		//memcpy(barrier, temp, 8 * sizeof(u8));
	//}
//
	//LCD_voidDrawData(pattern, barrier, x, y);
//}
//
//void points_creation(u8 pattern, u8 x, u8 y) {
	//u8 point[8] = {0x00, 0x00, 0x08, 0x14, 0x08, 0x00, 0x00, 0x00};
	//LCD_voidDrawData(pattern, point, x, y);
//}
//
//bool is_correct_path(u8 x, u8 y) {
	//// Redesign track positions
	//if ((x >= 0 && x <= 3 && y == 0) ||  // Moving right on bottom row
	//(x == 3 && y >= 0 && y <= 1) ||  // Moving up on column 3
	//(x >= 3 && x <= 7 && y == 1) ||  // Moving right on row 1
	//(x == 7 && y == 2) ||            // Moving down at column 7
	//(x >= 7 && x <= 15 && y == 2)) { // Moving right to the end
		//return true;
	//}
	//return false; // Incorrect path otherwise
//}
//
//void move_object(u8 new_x, u8 new_y) {
	//// Validate the movement
	//if (is_correct_path(new_x, new_y)) {
		//object_x = new_x;
		//object_y = new_y;
		//display_message("Good Move!");
		//_delay_ms(500);
		//update_voidGame();
//
		//// Check for points collection
		//if ((new_x == 5 && new_y == 0) || (new_x == 10 && new_y == 1)) {
			//points_collected++;
			//display_message("Point Collected!");
			//_delay_ms(500);
			//update_voidGame();
		//}
//
		//// Check if reached the end
		//if (new_x == 10 && new_y == 2) {
			//display_message("You Win!");
			//_delay_ms(500);
			//display_message("game ends");
		//}
		//} else {
		//display_message("Error: Wrong Path!");
		//_delay_ms(500);
		//update_voidGame();
	//}
//}
//
//void handle_button_press() {
	//if (DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN2)) { // Button 0: Move Up
		//if (object_y > 0) move_object(object_x, object_y - 1);
	//}
	//if (DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN6)) { // Button 1: Move Down
		//if (object_y < 2) move_object(object_x, object_y + 1);
	//}
	//if (DIO_u8ReadPinVal(DIO_PORTB, DIO_PIN0)) { // Button 2: Move Forward (Right)
		//if (object_x < 15) move_object(object_x + 1, object_y);
	//}
//}
//
//void Start_voidGame() {
	//Start_login(); // Show the login/start screen
//
	//// Set up barriers on the track
	//horizontal_barrier_creation(0, 1, 0, 0);
	//vertical_barrier_creation(2, 3, 0, 0);
	//horizontal_barrier_creation(3, 3, 1, 0);
	//vertical_barrier_creation(4, 7, 1, 0);
	//horizontal_barrier_creation(5, 8, 2, 0);
//
	//// Initialize object and points
	//object_creation(1, object_x, object_y);
	//points_creation(4, 5, 0); // Point at (5, 0)
	//points_creation(4, 10, 1); // Point at (10, 1)
//}
//
//void update_voidGame()
//{
	//LCD_voidClear();
	//_delay_ms(500);
	//// Set up barriers on the track
	//horizontal_barrier_creation(0, 1, 0, 0);
	//vertical_barrier_creation(2, 3, 0, 0);
	//horizontal_barrier_creation(3, 3, 1, 0);
	//vertical_barrier_creation(4, 7, 1, 0);
	//horizontal_barrier_creation(5, 8, 2, 0);
//
	//// Initialize object and points
	//object_creation(1, object_x, object_y);
	//points_creation(4, 5, 0); // Point at (5, 0)
	//points_creation(4, 10, 1); // Point at (10, 1)
//}
//
//int main(void) {
	//// LCD Initialization
	//DIO_voidSetPortDir(LCD_DPORT, 0xf0);
	//DIO_voidSetPortDir(LCD_CPORT, 0x0E); // Control pins
	//LCD_voidInit();
	//DIO_voidSetPinDir(DIO_PORTD, DIO_PIN2, INPUT);
	//DIO_voidSetPinDir(DIO_PORTD, DIO_PIN6, INPUT);
	//DIO_voidSetPinDir(DIO_PORTB, DIO_PIN0, INPUT);
//
	//Start_voidGame(); // Start the game
//
	//while (1) {
		//handle_button_press(); // Continuously check for button presses
		//_delay_ms(200); // Delay to debounce button and avoid rapid movement
	//}
//}
//


/*
 * Task 2: Password Checker
 * Conditions: Three chances to enter the right password (e.g., 1425). LED will be on if correct, else buzzer on.
 * Result: If successful, print "Welcome Home", else print "7aramy".
 */

//Bool Password_Checker(u16 entered_password) {
    //// Corrected the type to accept a multi-digit password
    //if (entered_password == 1425)
        //return T;
    //else
        //return F;
//}
//
//void Reset_Login() {
    //LCD_voidClear();
    //LCD_voidGoToXY(0, 0);
    //LCD_voidSendString("Enter Pass:");
//}
//
//int main(void) {
    ///* LCD INIT */
    //DIO_voidSetPortDir(LCD_DPORT, 0xf0); // 1111 0000
    //DIO_voidSetPortDir(LCD_CPORT, 0x0E); // 0000 0111
    //LCD_voidInit();
    //KEYPAD_voidInit();
//
    //u8 KEY = 0xFF;
    //u8 counter = 0;
    //u16 password_input = 0; // To store the entered password
    //Reset_Login();
//
    //while (1) {
        //password_input = 0; // Reset password input for each attempt
        //u8 holder = 12;
        //do {
            //KEY = KEYPAD_u8GetKey();
            //if (KEY == '=')
                //break;
            //if (KEY == 'C') {
                //holder = 0;
                //KEY = 0;
                //Reset_Login();
            //}
//
            //if (KEY == 'D') {
                //password_input /= 10; // Corrected deletion logic
                //LCD_voidGoToXY(holder, 0);
                //LCD_voidSendData(' ');
                //holder--;
            //} else if (KEY != 0xFF && KEY >= '0' && KEY <= '9') {
                //// Only handle numeric input
                //password_input = (password_input * 10) + (KEY - '0'); // Convert char to digit and accumulate
                //LCD_voidGoToXY(holder, 0);
                //LCD_voidSendData('*'); // Mask input with '*'
                //holder++;
                //_delay_ms(200);
            //}
        //} while (KEY != '=' && holder <= 16); // Exit if Enter ('=') is pressed or max length reached
//
        //Bool is_true = Password_Checker(password_input);
//
        //if (counter >= 3) {
            //// When attempts exceed, turn on the buzzer and display message
            //DIO_voidSetPortDir(DIO_PORTA, OUTPUT);
            //DIO_voidSetPinVal(DIO_PORTA, 3, HIGH);
            //u8 char_h[8] = {0x00, 0x00, 0x0C, 0x02, 0x1F, 0x00, 0x00, 0x00};
            //u8 char_r[8] = {0x00, 0x00, 0x00, 0x02, 0x01, 0x02, 0x0C, 0x00};
            //u8 char_a[8] = {0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00};
            //u8 char_m[8] = {0x00, 0x00, 0x00, 0x02, 0x1D, 0x02, 0x00, 0x00};
            //u8 char_y[8] = {0x00, 0x00, 0x00, 0x00, 0x03, 0x12, 0x1E, 0x0C};
            //LCD_voidClear();
            //LCD_voidDrawData(0, char_h, 4, 0);
            //LCD_voidDrawData(1, char_r, 3, 0);
            //LCD_voidDrawData(2, char_a, 2, 0);
            //LCD_voidDrawData(3, char_m, 1, 0);
            //LCD_voidDrawData(4, char_y, 0, 0);
            //break;
        //}
//
        //if (is_true == F) {
            //LCD_voidClear();
            //LCD_voidGoToXY(0, 0);
            //LCD_voidSendString("ERROR: wrong password");
            //counter++;
        //} else {
            //LCD_voidClear();
            //LCD_voidGoToXY(0, 0);
            //LCD_voidSendString("Welcome Home!!");
            //DIO_voidSetPortDir(DIO_PORTC, OUTPUT);
            //DIO_voidSetPinVal(DIO_PORTC, 2, HIGH);
            //_delay_ms(500);
            //break;
        //}
    //}
//}
//
//











//int main(void)
//{
	///* LCD INIT  */
	//DIO_voidSetPortDir(LCD_DPORT,0xf0)  ;
	//DIO_voidSetPortDir(LCD_CPORT,0x0E) ;  // 00000111
	//LCD_voidInit() ;
	//DIO_voidSetPinDir(DIO_PORTD, DIO_PIN2,INPUT);
	//
	//DIO_voidSetPinDir(DIO_PORTD, DIO_PIN6,INPUT);
	//
	//DIO_voidSetPinDir(DIO_PORTB, DIO_PIN0,INPUT);
	//
	//u8 val = 2;
	//u8 val2 = 3;
	//u8 sum = 0;
	//u8 char1[8] = {0x00,0x06,0x04,0x0E,0x04,0x04,0x04,0x00};
	//u8 char2[8] = {0x00,0x00,0x00,0x0C,0x02,0x1F,0x00,0x00};
	//u8 char3[8] = {0x00,0x00,0x00,0x04,0x0A,0x1B,0x04,0x00};
	//u8 char4[8] = {0x00,0x00,0x00,0x04,0x02,0x07,0x00,0x00};
	//u8 counter = 0, tens = 1, actual = 0;
	//LCD_voidSendString("current num:");
	//LCD_voidGoToXY(12,0);
		//while(1)
		//{
			//// increment
			//if(DIO_u8ReadPinVal(DIO_PORTD,DIO_PIN2) == 1)
			//{
				//_delay_ms(20);
				//if(DIO_u8ReadPinVal(DIO_PORTD,DIO_PIN2) == 1)
				//counter++;
				//actual++;
			//}
			//// decrement
			//
			//if (DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN6) == 1)
			//{
				//_delay_ms(20);
				//if (DIO_u8ReadPinVal(DIO_PORTD, DIO_PIN6) == 1)
				//{
					//if (counter > 0) 
					//{
						//counter--;
					//}
					//else
					//{
							//if (tens > 0)
							//{
								 //tens--;
								//counter = 9;	 
							//}
							//LCD_SendNumber(tens, 12,0);
					//}
				//
					    //LCD_SendNumber(counter,13,0);
				//}
			//}
			//// reset
			//if(DIO_u8ReadPinVal(DIO_PORTB,DIO_PIN0) == 1)
			//{
				//_delay_ms(20);
				//if(DIO_u8ReadPinVal(DIO_PORTB,DIO_PIN0) == 1)
				//{
					//counter = 0;
					//tens = 1;
					//LCD_voidClear();
					//_delay_ms(500);
					//LCD_voidSendString("current num:");
					//LCD_SendNumber(tens, 12, 0);
					//LCD_SendNumber(counter, 12,0);
				//}
//
			//}
			//
		  //// Handle overflow of counter
		  //if (counter == 10)
		  //{
			  //tens++;
			  //counter = 0;
			  	//LCD_SendNumber(tens, 12, 0);
			  //
		  //}
		  	//LCD_SendNumber(counter, 13,0);
//
		  //_delay_ms(100);
			//
		//}
//}
	












//int main(void)
//{
	 ///* LCD INIT  */
	 //DIO_voidSetPortDir(LCD_DPORT,0xf0)  ;
	 //DIO_voidSetPortDir(LCD_CPORT,0x0E) ;  // 00000111
	 //LCD_voidInit() ;
	 //DIO_voidSetPinDir(DIO_PORTC, DIO_PIN0,INPUT);
	 //DIO_voidSetPinVal(DIO_PORTC, DIO_PIN0,OUTPUT);
	 //DIO_voidSetPinDir(DIO_PORTC, DIO_PIN1,INPUT);
	 //DIO_voidSetPinVal(DIO_PORTC, DIO_PIN1,OUTPUT);
	 //DIO_voidSetPinDir(DIO_PORTC, DIO_PIN2,INPUT);
	 //DIO_voidSetPinVal(DIO_PORTC, DIO_PIN2,OUTPUT);
	 //u8 val = 2;
	 //u8 val2 = 3;
	 //u8 sum = 0;
	//u8 char1[8] = {0x00,0x06,0x04,0x0E,0x04,0x04,0x04,0x00};
	//u8 char2[8] = {0x00,0x00,0x00,0x0C,0x02,0x1F,0x00,0x00};
	//u8 char3[8] = {0x00,0x00,0x00,0x04,0x0A,0x1B,0x04,0x00};
	//u8 char4[8] = {0x00,0x00,0x00,0x04,0x02,0x07,0x00,0x00};
		//u8 vertical =1;
	//
	 //while(1)
	 //{
		 //for(u8 i = 1; i < 12; i+=2)
		 //{
			 //if(vertical)
			 //vertical = 0;
			 //else
			 //vertical = 1;
			 //
			 //LCD_voidDrawData(0,char4,0+i,vertical);
			 //LCD_voidDrawData(1,char3,1+i,vertical);
			 //LCD_voidDrawData(2,char2,2+i,vertical);
			 //LCD_voidDrawData(3,char1,3+i,vertical);
			 //_delay_ms(500);
			 //LCD_voidClear();
			 //
		 //}
		 //for(u8 i = 12; i > 0; i-=2)
		 //{
			 //if(vertical)
			 //vertical = 0;
			 //else
			 //vertical = 1;
			 //
			 //LCD_voidDrawData(0,char4,0+i,vertical);
			 //LCD_voidDrawData(1,char3,1+i,vertical);
			 //LCD_voidDrawData(2,char2,2+i,vertical);
			 //LCD_voidDrawData(3,char1,3+i,vertical);
			 //_delay_ms(500);
			 //LCD_voidClear();
			 //
		 //}
		 //if (DIO_u8ReadPinVal(DIO_PORTC, DIO_PIN0) == 0)
		 //{
			 //LCD_voidGoToXY(0,0);
			 //LCD_SendNumber(val);
			  //LCD_voidGoToXY(2,0);
			  //LCD_voidSendData('+');
			////  _delay_ms(500);
		 //}
		  //if (DIO_u8ReadPinVal(DIO_PORTC, DIO_PIN1) == 0)
		  //{
			  //LCD_voidGoToXY(3,0);
			  	   //LCD_SendNumber(val2);
			   //LCD_voidGoToXY(4,0);
			  //LCD_voidSendData('=');
			  ////  _delay_ms(500);
		  //}
		   //if (DIO_u8ReadPinVal(DIO_PORTC, DIO_PIN2) == 0)
		   //{
			   //LCD_voidGoToXY(5,0);
			   //sum = val+val2;
			   //LCD_SendNumber(sum);
			   ////  _delay_ms(500);
		   //}
	 //  _delay_ms(500);
	 //}
//}
//

//int main(void)
//{
	//u8 data[8] = { 0x0E,
		//0x0E,
		//0x04,
		//0x04,
		//0x0A,
		//0x15,
		//0x0A,
		//0x0A};
		//u8 clr[8] = {  0x00,
			//0x00,
			//0x00,
			//0x00,
			//0x00,
			//0x00,
			//0x00,
			//0x00};
		//
         ///* LCD INIT  */
		 //DIO_voidSetPortDir(LCD_DPORT,0xf0)  ; 
		 //DIO_voidSetPortDir(LCD_CPORT,0x0E) ;  // 00000111 
		 //LCD_voidInit() ; 
		 //LCD_voidClear();
		  //_delay_ms(900);
		  //for(u8 i = 1, j=0 ; i < 16; i++, j++)
		  //{
			  //LCD_voidDrawData(0,data,i,0);
			   //_delay_ms(500);
			   //LCD_voidClear();
			 //// LCD_voidDrawData(i,clr,i,0);
			  //
		  //}
 //_delay_ms(500);
    //while (1) 
    //{
		////LED_voidToggle(DIO_PORTC,DIO_PIN2) ; 
    //}
//}
//

