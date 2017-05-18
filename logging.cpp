#include "mbed.h"

void logging ()
{
    int i,t;
    FILE *fp;


    if ((fp = fopen("Logger_data", "a+")) == NULL) { //filnavn logger_data
        fprintf (stdout, "Can't open \"Logger_data\" file.\n");
        exit(EXIT_FAILURE);//sikre at filen kan åbnes
    }

    fprintf(fp,"\n\nlogger_data kl.00.00 D.dd-mm-yyyy\n"); //skriver i fil
    fprintf(fp,"Temperatur:x\n");//variable fra temp indsættes
    fprintf(fp,"Co2:x\n");//variable fra Co2 indsættes
    fprintf(fp,"H2o:x"); //variable fra H2o indsættes


    fprintf(fp,"Logger_data update complete!"); // 
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n"); //lukker fil
    
    //sætter i og t = 0
    i=0;
    t=0;
 
    return; //går over i hibernation
}