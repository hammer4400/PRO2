//Defining and Including stuff up here
#include <mbed.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SHTx/sht15.hpp"               //"CMSIS Target not recognised"
#define temperature_low = 18; //For use in the Data Analysis
#define temperature_high = 25;  //For use in the Data Analysis
#include "rgb_led.h"            //For use in the RGB_LED_output part
#include "7_segment_control.h"  //For use in the RGB_LED_output part


//The correct order of files:

//Declaration of GLOBAL VARIABLES:
float temperature, humidity;            //this will be data read from sensor
void GetTemperatureAndHumidity();
 
    Serial pc(USBTX, USBRX);
    DigitalOut busy(LED1);                  //Don't think we need it.
    InterruptIn event(USER_BUTTON);
    DigitalOut myled(LED1);
    DigitalIn up(p5);
    DigitalIn down(p6);
    
    int status, humidity, temperature;
    int Compare_values();
 
//ports on the Nucleo: PB_8, PB_9
SHTx::SHT15 sensor(PB_8, PB_9);


//At the very top, we're going to have main()

int main() {
    
    Logging();
    
    Hiberation();
    
    Settings();
    
    //Data Collection
    GetTemperatureAndHumidity();

    Comparevalues(); //Data Analysis
    
    void rgb_outp(int status)(); //RGB_LED_output
    
    return 0;
    }

    
//1) Logging
    void Logging() { //This needs to be updated before we have
    //the final program done. 
        FILE *fp;
 
 
    if ((fp = fopen("Logger_data", "a+")) == NULL) { //filename logging_data
        fprintf (stdout, "Can't open \"Logger_data\" file.\n");
        exit(EXIT_FAILURE);//making sure that we can open the file
    }
 
    fprintf(fp,"\n\nlogger_data kl.00.00 D.dd-mm-yyyy\n");//writing in the file
    fprintf(fp,"Temperatur:x\n");//variable from temp will be put here
    fprintf(fp,"Co2:x\n");//variable from Co2
    fprintf(fp,"H2o:x"); //variable from H2o
 
 
    fprintf(fp,"Logger_data update complete!"); 
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n"); //Closing file
    
    //i and t are assigned to 0 here
    i=0
    t=0
 
    return 0; //goes into Hibernation
}

    

//2) Hibernation


void Hibernation() {
    int t;
    int i;
    //Or whatever that brings it into Hibernation at once
    
    while(1)
    {
        if (i>0)
        {
            Settings();
            }
            else if (t=600) {
                GetTemperatureAndHumidity(); //Data Collection
                Comparevalues(); //Data Analysis
                rgb.output(Olga_variable);
                }
                else
                {
                    t++;
                    wait 1000 ms;
                }
            
          
          return 0;
          
            

//3) Settings

    void Settings(int t,i,set_temp,extern int timespan) {
        while(i<1){ //Opening set_temp for input
    
    
        if (up==1) {//Recieving input from the user
           set_temp = (set_temp +1); } //if up, temp rises by 1
        if (down==1) { //Recieving input from the user
            set_temp = (set_temp -1);} //If down, temp drops by 1
        else if (timespan == 500);{ 
            break;}
        }
        
        //If the system is passive for 5 seconds, i will be assigned to 2
        //and t will get the value 700
        //This forces it to go past hibernation
        
        i=2
        t=700
        return 0;
    }


//4) Data Collection

void GetTemperatureAndHumidity()
{
    // Speed things up a bit.
sensor.setOTPReload(false);
sensor.setResolution(true);
 
while(1)
{
    busy = true;
    sensor.update();
    busy = false;
 
    // Temperature in celcius
    sensor.setScale(false);
    temperature=sensor.getTemperature();        //don't know if it works
 
    // Relative Humidity
    humidity=sensor.getHumidity();               //don't know if it works
 
    wait(5);
    return;
}
}

//5) Data Analysis

    void Comparevalues() {
        
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


//6) RGB_LED_output
  void rgb_outp(int status)   {
        
    int status;                  // Status carries data from data analysis().
    RGB_LED lamp(PC_8,PC_6,PB_9);// Creates an object out of the class RGB_LED.
                                // Connect pins on the Nucleo, to the pins the
                                // class.
    // Following is a object of the class segment_7. It is the actual analogy
 // to our 7 segmented displays. There needs to go 11 pins into the parenteses.
    //segment_7 seg_num(11 pins);              
        
        enum colour     // Enumeration is used only for making the program more 
    {               // easily readable.
        green,      // Is alike an int, starts at green = 1,
        orange,     // orange = 2 etc.
        red,
        red_blink,
        blue
    }; 
 
    colour RGB_out = static_cast<colour>(status);
    // Taking the value from the sensors and change them the enum type.
    // Enum is somewhat akin to an int already, but RGB_out != status..
    
    switch(RGB_out)
    {
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

        
       
        
