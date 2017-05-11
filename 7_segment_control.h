/*
================================================================================
==              ==                                                            ==
== Source File: ==  main.cpp                                                  ==
== File Name:   ==  7_segment_control.h                                       ==
== Author:      ==  Poul Erik Tjørnfelt                                       ==
== Date:        ==  07/05-2017                                                ==
== Copyright:   ==  Open to all                                               ==                        
== Version:     ==  0.6 - Creation of file.                                   ==
==              ==                                                            ==
== Description: ==  The header file for a class, that creates instances of    ==
==              ==  the setup of 3 seven-segmented displays that is used in   ==
==              ==  project.                                                  ==
==              ==                                                            ==
================================================================================
*/

#ifndef SEGMENT_7_H
#define SEGMENT_7_H
#include "mbed.h"

class segment_7 // Compiler does not like numbers at the start.
{
    public:
        segment_7(PinName seg_A, PinName seg_B, PinName seg_C, PinName seg_D,
                  PinName seg_E, PinName seg_F, PinName seg_G, PinName DP,
                  PinName dig_1, PinName dig_2, PinName dig_3);
        void show(int number, int dig);
    
    private:
        DigitalOut Seg_A;
        DigitalOut Seg_B;
        DigitalOut Seg_C;
        DigitalOut Seg_D;
        DigitalOut Seg_E;
        DigitalOut Seg_F;
        DigitalOut Seg_G;
        DigitalOut _DP;
        DigitalOut Dig_1;
        DigitalOut Dig_2;
        DigitalOut Dig_3;
};

#endif