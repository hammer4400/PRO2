/*
================================================================================
==              ==                                                            ==
== Source File: ==  main.cpp                                                  ==
== File Name:   ==  rgb_led.cpp                                               ==
== Author:      ==  Poul Erik Tjørnfelt                                       ==
== Date:        ==  07/05-2017                                                ==
== Copyright:   ==  Open to all                                               ==
== Version:     ==  0.6 - Creation of file.                                   ==
==              ==                                                            ==
== Description: ==  The .cpp file for a class, that creates instances of      ==
==              ==  the actual RGB lamp that is used.                         ==
==              ==                                                            ==
================================================================================
*/

#include "mbed.h"
#include "rgb_led.h"

RGB_LED::RGB_LED(PinName pin_R, PinName pin_G, PinName pin_B)
        :pin_r(pin_R), pin_g(pin_G), pin_b(pin_B)   // Constructor
{

}
 
void RGB_LED::set(float red,float green, float blue)
{
    pin_r = red;    // The amount of the single colours that we want in the
    pin_g = green;  // actual colour (ex. purple = 0.7f, 0.0, 0.7f), gotten from
    pin_b = blue;   // www.w3schools.com/colors/colors_picker.asp.
    /*
        We only use red, orange (2 parts red, 1 part green), green and blue.
     */
}

void RGB_LED::flash(float period, float on_timer)
{
    pin_r.period(period);   // Sets the period in seconds of the LED.
    pin_r.write(on_timer);  // The %age of the period that the LED is turned on.
    pin_g.period(period);
    pin_g.write(on_timer);
    pin_b.period(period);   
    pin_b.write(on_timer);  
}