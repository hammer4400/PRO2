/*
================================================================================
==              ==                                                            ==
== Source File: ==  main.cpp                                                  ==
== File Name:   ==  7_segment_control.cpp                                     ==
== Author:      ==  Poul Erik Tjørnfelt                                       ==
== Date:        ==  07/05-2017                                                ==
== Copyright:   ==  Open to all                                               ==
== Version:     ==  0.6 - Creation of file.                                   ==
==              ==                                                            ==
== Description: ==  The .cpp file for a class, that creates instances of      ==
==              ==  the setup of 3 seven-segmented displays that is used in   ==
==              ==  project.                                                  ==
==              ==                                                            ==
================================================================================
*/

#include "mbed.h"
#include "7_segment_control.h"

segment_7::segment_7(PinName seg_A, PinName seg_B, PinName seg_C, PinName seg_D,
                     PinName seg_E, PinName seg_F, PinName seg_G, PinName DP,
                     PinName dig_1, PinName dig_2, PinName dig_3)
          :Seg_A(seg_A), Seg_B(seg_B), Seg_C(seg_C), Seg_D(seg_D), Seg_E(seg_E),
           Seg_F(seg_F), Seg_G(seg_G), _DP(DP), Dig_1(dig_1), Dig_2(dig_2),
           Dig_3(dig_3)
/*
        At line 7 starts the constructor. It creates instances in the memory,
        that gets tied to the physical pins of the class. That is, it creates a
        software representation of the pin.
 */
{
    
}

void segment_7::show(int number, int dig)
{    
    switch(dig)     // First switch is for switching the transistor for the
    {               // actual digit on.
        case 1:
            Dig_1 = 1;
            Dig_2 = 0;
            Dig_3 = 0;
            switch(number)  // Second switch is for opening the output pin
            {               // for the segments on the actual display to 
                            // showcase a number due to the right combination.
                case 0:         // 0 is used for 'L' for low.
                    Seg_A = 0;
                    Seg_B = 0;
                    Seg_C = 0;
                    Seg_D = 1;
                    Seg_E = 1;
                    Seg_F = 1;
                    Seg_G = 0;
                    break;
                case 1:         // 1 is used for 'H' for high.
                    Seg_A = 0;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 0;
                    Seg_E = 1;
                    Seg_F = 1;
                    Seg_G = 1;
                    break;
                default:            // If the letter to be shown here is neither
                    Dig_1 = 0;      // 'H' nor 'L', then we just turn off the
                    Dig_2 = 0;      // display to prevent odd numbers from being
                    Dig_3 = 0;      // shown at all.
            }
            break;  // This break does not tie to the default case. It instead
        case 2:     // ends the first level case 1.
            Dig_1 = 0;
            Dig_2 = 1;
            Dig_3 = 0;
            switch(number)
            {
                case 0:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 1;
                    Seg_F = 1;
                    Seg_G = 0;
                    break;
                case 1:
                    Seg_A = 0;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 0;
                    Seg_E = 0;
                    Seg_F = 0;
                    Seg_G = 0;
                    break;
                case 2:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 0;
                    Seg_D = 1;
                    Seg_E = 1;
                    Seg_F = 0;
                    Seg_G = 1;
                    break;
                case 3:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 0;
                    Seg_F = 0;
                    Seg_G = 1;
                    break;
                case 4:
                    Seg_A = 0;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 0;
                    Seg_E = 0;
                    Seg_F = 1;
                    Seg_G = 1;
                    break;
                case 5:
                    Seg_A = 1;
                    Seg_B = 0;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 0;
                    Seg_F = 1;
                    Seg_G = 1;
                    break;
                case 6:
                    Seg_A = 1;
                    Seg_B = 0;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 1;
                    Seg_F = 1;
                    Seg_G = 1;
                    break;
                case 7:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 0;
                    Seg_E = 0;
                    Seg_F = 0;
                    Seg_G = 0;
                    break;
                case 8:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 1;
                    Seg_F = 1;
                    Seg_G = 1;
                    break;
                case 9:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 0;
                    Seg_F = 1;
                    Seg_G = 1;
                    break;
                default:        // Erroneous data. So we turn off all the 
                    Dig_1 = 0;  // displays.
                    Dig_2 = 0;
                    Dig_3 = 0;
            }
            break;
        case 3:
            Dig_1 = 0;
            Dig_2 = 0;
            Dig_3 = 1;
            switch(number)
            {
                case 0:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 1;
                    Seg_F = 1;
                    Seg_G = 0;
                    break;
                case 1:
                    Seg_A = 0;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 0;
                    Seg_E = 0;
                    Seg_F = 0;
                    Seg_G = 0;
                    break;
                case 2:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 0;
                    Seg_D = 1;
                    Seg_E = 1;
                    Seg_F = 0;
                    Seg_G = 1;
                    break;
                case 3:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 0;
                    Seg_F = 0;
                    Seg_G = 1;
                    break;
                case 4:
                    Seg_A = 0;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 0;
                    Seg_E = 0;
                    Seg_F = 1;
                    Seg_G = 1;
                    break;
                case 5:
                    Seg_A = 1;
                    Seg_B = 0;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 0;
                    Seg_F = 1;
                    Seg_G = 1;
                    break;
                case 6:
                    Seg_A = 1;
                    Seg_B = 0;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 1;
                    Seg_F = 1;
                    Seg_G = 1;
                    break;
                case 7:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 0;
                    Seg_E = 0;
                    Seg_F = 0;
                    Seg_G = 0;
                    break;
                case 8:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 1;
                    Seg_F = 1;
                    Seg_G = 1;
                    break;
                case 9:
                    Seg_A = 1;
                    Seg_B = 1;
                    Seg_C = 1;
                    Seg_D = 1;
                    Seg_E = 0;
                    Seg_F = 1;
                    Seg_G = 1;
                    break;
                default:        // Erroneous data. So we turn off all the 
                    Dig_1 = 0;  // displays.
                    Dig_2 = 0;
                    Dig_3 = 0;                    
            }
            break;    
    }
}