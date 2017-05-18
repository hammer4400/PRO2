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
//
// Usage: Compare_values(float hum, float temp, 
//                       int temperature_low, int temperature_high)

int Compare_values(float hum, float temp, 
                    int temperature_low, int temperature_high);