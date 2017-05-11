/*
================================================================================
==              ==                                                            ==
== Source File: ==  main.cpp                                                  ==
== File Name:   ==  rgb_led.h                                                 ==
== Author:      ==  Poul Erik Tjørnfelt                                       ==
== Date:        ==  07/05-2017                                                ==
== Copyright:   ==  Open to all                                               ==
== Version:     ==  0.6 - Creation of file.                                   ==
==              ==                                                            ==
== Description: ==  The header file for a class, that creates instances of    ==
==              ==  the actual RGB lamp that is used.                         ==
==              ==                                                            ==
================================================================================
*/

#ifndef RGB_LED_H
#define RGB_LED_H
#include "mbed.h"

class RGB_LED
{
    public:
        RGB_LED(PinName pin_R, PinName pin_G, PinName pin_B);
        void set(float red, float green, float blue);
        void flash(float period, float on_timer);
    
    private:
        PwmOut pin_r;
        PwmOut pin_g;
        PwmOut pin_b;    
};

#endif