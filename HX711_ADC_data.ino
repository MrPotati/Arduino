//-------------------------------------------------------------------------------------------
// HX711_ADC_data_only.ino
// This program reads data from HX711 boards to measure voltage across a resistive bridge. 
// Arduino UNO allows you to connect up to 4 HX711 boards due to I/O availability. 
// The data is sent to a computer through USB using UART interface.
// This scripts requires the "HX711-master" library for Arduino to run which can be found 
// in https://github.com/sphanlung/Arduino/blob/master/HX711-master.zip
// For long term data logging see the timed logger for serial data in the 
// https://github.com/sphanlung/Python repository
// Date: 
// Author:
//-------------------------------------------------------------------------------------------

//User settings
//Sample rate and averaging are constrained by hardware limitations

int sample_average = 5;  // The number of samples to average before printing the value
int sampleRate = 15;     // Sample Rate in Hz
unsigned long loopDelay = 1001;   // Set delay between long-term samples (seconds * 1000). 
                         // Delay may need manual calibration to improve time accuracy.
                         // 60050 = 1 sample per minute
                         // 1000  = 10 samples per second
                        

#include "HX711.h"
#define delim "\t"

// Initialize the scales
int DOUT1 = 3;					// Select Arduino GPIO
int CLK1 = 2;
HX711 scale1(DOUT1, CLK1);    	// Optional 3rd argument sets gain. 128, 64, and 32 are your options

int DOUT2 = 5;
int CLK2 = 4;
HX711 scale2(DOUT2, CLK2);

int DOUT3 = 7;
int CLK3 = 6;
HX711 scale3(DOUT3, CLK3);

int DOUT4 = 9;
int CLK4 = 8;
HX711 scale4(DOUT4, CLK4);

long prevMillis;
//unsigned int long loopDelay = 100;

void setup() {
  prevMillis = millis();
  Serial.begin(115200);                          //set serial baud rate
}

void loop() 
{
  printValues(sample_average);                    // Sample & print HX711 boards
  while ((millis() - prevMillis) < loopDelay) {}  // Delay
  prevMillis = millis();
}

void printValues(int x) {       // x = number of samples to average
  long s1Val,s2Val,s3Val,s4Val = 0;
  s1Val = scale1.get_units(x);  //Print the value of scale1
  s2Val = scale2.get_units(x);  
  s3Val = scale3.get_units(x);  
  s4Val = scale4.get_units(x);  
  Serial.print(s1Val);          //Print the value of scale1
  Serial.print(delim);
  Serial.print(s2Val);
  Serial.print(delim);
  Serial.print(s3Val);
  Serial.print(delim);
  Serial.print(s4Val);  
  Serial.println();            // start a new line
}
