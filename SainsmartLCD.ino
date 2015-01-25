//////////////////////////////////////////////////////////////////////////////////
// Name:   SainsmartLCD.txt                                                     //
//                                                                              //
// Author: Sergio PL                                                            //
//         http://idielectronica.blogspot.com/                                  //
//         http://github.com/MrPotati/                                          //
//                                                                              //
// Date:   09-08-2014                                                           //
//                                                                              //
// Description: This code was designed to use the 20x4 SainSmart LCD module     //
// with the Arduino Uno. To use it, you need to replace the LiquidCrystal_I2C   //
// with LiquidCrystal_V1.2.1.zip, created by F. Malpartida.                     //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////

#include <Wire.h>                  // Loads I2C interface library
#include <LiquidCrystal_I2C.h>     // Loads LCD library for I2C 

#define I2C_ADDR 0x27              // Set I2C device address
								   // Find it in datasheet

//Define pins in LCD controller for I2C interface. Don't change.
#define BACKLIGHT_PIN 3  
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin, D5_pin,D6_pin,D7_pin);

void setup()
{
lcd.begin (20,4,LCD_5x8DOTS);      //Define type of LCD display
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
}

// Start LCD display loop
void loop()                  
{
lcd.setBacklight(HIGH);            // Turn on LCD backlight
lcd.clear();                       // Clear LCD characters
lcd.print("HELLO WORLD 1       "); // Print rows 1 through 4
lcd.print("HELLO WORLD 2       ");
lcd.print("HELLO WORLD 3       "); 
lcd.print("HELLO WORLD 4       ");
delay(1000);                       // Wait 1000 ms (1 sec)
lcd.clear();                       // Clear LCD characters     
lcd.setBacklight(LOW);             // Turn off LCD backlight
delay(1000);                       // Wait 1000 ms (1 sec)
}