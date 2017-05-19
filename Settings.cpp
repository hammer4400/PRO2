//Author : Emil Hammer
//Date : 19 May 2017
//Version : 1.0
//Copyright : Open for everyone
//Description : Settings

#include "mbed.h"

DigitalOut myled(LED1);
DigitalIn up(p5);
DigitalIn down(p6);


extern int timespan;
int t;
int i, set_temp;
int temperature_low,temperature_high;

int main()
{
    while(i<1) { //Open set_temp for user input.

        if (up==1) {//recieve input from user
            set_temp = (set_temp +1);
        } // when "up" tricked set_temp raise 1
        if (down==1) {
            set_temp = (set_temp -1);
        } // when "down" tricked set_temp raise 1
        else if (timespan == 500);
        {
            /* if 500 ms passes without a user input
             the program will break the loop*/
            break;
        }
    }

    int temperature_low = (set_temp-5);
    int temperature_high = (set_temp+5);
    /* Temperature that defines what uncomfortable */


    i=2;
    t=700; //force the program to pass hibernation.
    return 0;
}