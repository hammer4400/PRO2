//Author : Olga Hoeyer
//Date : 18 May 2017
//Version : 2.0
//Changes: Structure changed to modular, to ease future use of the funktion.
//Copyright : Open for everyone
//
// Description : Analysis part for EDE PRO2 Team 1 project. 
//Program takes temperature and humidity as arguments (read from sensors), 
//together with lower and higher limit on temperature and evaluate air quality. 
//Output is status (int, from 1 to 5).

#include "mbed.h"

int Compare_values(float hum, float temp, 
                    int temperature_low, int temperature_high)
{
//local variables
int status, humidity, temperature;

//__________________________________
// Definition of limits
//__________________________________

//Humidity limits.
    const int HUMIDITY_LOW = 20;
    const int HUMIDITY_HIGH= 60;

//Extra limits where LED will start blinking in red:
//13 < Temp < 30; 10%< hum < 80%
    const int HUMIDITY_EXTRA_LOW = 10;
    const int HUMIDITY_EXTRA_HIGH= 80;
    const int TEMPERATURE_EXTRA_LOW = 13;
    const int TEMPERATURE_EXTRA_HIGH= 30;

//Definition of output values
    const int GOOD_LEVEL = 1;               //green
    const int ACCEPT_LEVEL = 2;             //orange
    const int CRITICAL_LEVEL = 3;           //red
    const int EXTRA_CRITICAL_LEVEL = 4;     //red strobe
    const int USER_NEEDED = 5;              //blue strobe


//__________________________________
// main body: comparison
//__________________________________

    humidity=(int)hum;                          //convertation of float to int.
    temperature=(int)temp;

// check if there is a connection to the sensor
// (if null=no data=there is no connection

    if ((temperature == 0)  || (humidity == 0))
        status= USER_NEEDED;

    //comparing in nested loop.
    else if ((temperature < TEMPERATURE_EXTRA_LOW)  ||
             (temperature > TEMPERATURE_EXTRA_HIGH))

        status= EXTRA_CRITICAL_LEVEL;

    else if ((humidity < HUMIDITY_EXTRA_LOW)  ||
             (humidity > HUMIDITY_EXTRA_HIGH))

        status= EXTRA_CRITICAL_LEVEL;

    else if ((temperature < temperature_low) ||
             (temperature > temperature_high))

        status= CRITICAL_LEVEL;

    else if ((temperature < temperature_high) &&
             (temperature > temperature_low) &&
             (humidity < HUMIDITY_HIGH) &&
             (humidity > HUMIDITY_LOW))

        status= GOOD_LEVEL;

    else status= ACCEPT_LEVEL;

    return(status);
}