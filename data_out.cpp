/*
================================================================================
==              ==                                                            ==
== Source File: ==  main.cpp                                                  ==
== Author:      ==  Poul Erik Tjørnfelt                                       ==
== Date:        ==  07/05-2017                                                ==
== Copyright:   ==  Open to all                                               ==
== Version:     ==  0.6 - Creation of file.                                   ==
==              ==  0.7 - Added a 5th choice for colour. Red_Blink.           ==
==              ==                                                            ==
== Description: ==  A program (for a school project) that needs to collect    ==
==              ==  data from sensors, and show an output to 3 seven-segmented==
==              ==  displays and to a RGB-LED.                                ==
==              ==                                                            ==
================================================================================
*/

#include "mbed.h"
#include "rgb_led.h"
#include "7_segment_control.h"
#include "data_out.h"

void rgb_outp(int status)
{
     RGB_LED lamp(PC_8,PC_6,PB_9);   // Creates an object out of the class RGB_LED.
    // Connect pins on the Nucleo, to the pins the
    // class.
// Following is a object of the class segment_7. It is the actual analogy
// to our 7 segmented displays. There needs to go 11 pins into the parenteses.
//segment_7 seg_num(11 pins);

     enum colour {   // Enumeration is used only for making the program more
        // easily readable.
        green,      // Is alike an int, starts at green = 1,
        orange,     // orange = 2 etc.
        red,
        red_blink,
        blue
    };

    colour RGB_out = static_cast<colour>(status);
    // Taking the value from the sensors and change them the enum type.
    // Enum is somewhat akin to an int already, but RGB_out != status..

    switch(RGB_out) {
        case green:
            lamp.set(0.0f, 1.0f, 0.0f);
            lamp.flash(1.0f, 1.0f);         // On constantly.
            break;
        case orange:
            lamp.set(1.0f, 0.6f, 0.0f);
            lamp.flash(1.0f, 1.0f);         // On constantly.
            break;
        case red:
            lamp.set(1.0f, 0.0f, 0.0f);
            lamp.flash(1.0f, 1.0f);         // On constantly.
            break;
        case red_blink:
            lamp.set(1.0f, 0.0f, 0.0f);
            lamp.flash(2.0f, 0.5f);         // On for 50% of every 2 seconds.
            break;
        case blue:
            lamp.set(0.0f, 0.0f, 1.0f);
            lamp.flash(2.0f, 0.5f);         // On for 50% of every 2 seconds.
            break;
        default:   // Error has occured, blue. Could just have defaulted instead
            lamp.set(0.0f, 0.0f, 1.0f);     // of case blue, however I think
            lamp.flash(2.0f, 0.5f);         // this is more understandable.
    }

    return;
}