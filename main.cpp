//Defining and Including stuff up here
#include <mbed.h>
#include "SHTx/sht15.hpp"
#define temperature_low         //For use in the Data Analysis
#define temperature_high        //For use in the Data Analysis
#include "rgb_led.h"            //For use in the RGB_LED_output part
#include "7_segment_control.h"  //For use in the RGB_LED_output part

// MAIN er ikke færdig rettet!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//Prototype definitions
void Logging(); //Prototype for Logging
void Hibernation();
void Settings();
void Comparevalues();
void rgb_outp();


//The correct order of files:

//Declaration of GLOBAL VARIABLES:
float temperature, humidity;            //this will be data read from sensor
void GetTemperatureAndHumidity();
int i,t,set_temp,timespan,status;

Serial pc(USBTX, USBRX);
//DigitalOut busy(LED1);                 
InterruptIn event(USER_BUTTON);
DigitalOut myled(LED1);
DigitalIn up(PA_5);
DigitalIn down(PA_6);


//ports on the Nucleo: PB_8, PB_9
SHTx::SHT15 sensor(PB_8, PB_9);



int main()
{

    Logging();

    Settings();
    
    GetTemperatureAndHumidity();        //Data Collection

    Comparevalues( );                   //Data Analysis

    rgb_outp(status);                   //RGB_LED_output

    return 0;
}