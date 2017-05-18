//Author : Olga Hoeyer
//Date : 18 May 2017
//Version : 2.0
//Changes: Structure changed to modular, to ease future use of the funktion.
//Copyright : Open for everyone
//
// Description : Function will get a humidity value from the SHF-15 sensor
// Output is relative humidity (float).


#include "mbed.h"
#include "SHTx/sht15.hpp"

DigitalOut busy(LED1);
//ports on the Nucleo: PB_8, PB_9
SHTx::SHT15 sensor(PB_8, PB_9);

float GetHumid()
{
//VARIABLES:
    float humidity;          //this will be data read from sensor

// Speed things up a bit.
    sensor.setOTPReload(false);
    sensor.setResolution(true);

    busy = true;
    sensor.update();
    busy = false;

    // Temperature in celcius
    sensor.setScale(false);
    humidity=sensor.getHumidity();        //don't know if it works

    wait(5);
    return (humidity);

}