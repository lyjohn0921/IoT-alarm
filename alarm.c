#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"

int main(int argc, char const *argv[])
{
    int i;
    if (wiringPiSetup() != -1){
        pinMode(2, OUTPUT);
    
        
    
        pinMode(0, INPUT);
        pinMode(1, OUTPUT);
        while(1) {
            printf("Waiting for reset\n");        
            while(digitalRead(0) == 1)
                digitalWrite (1, HIGH) ;
            
            printf("Alarm\n");
            while(digitalRead(0) == 0){
                digitalWrite (1, LOW) ;
                digitalWrite (2, HIGH) ; delay (1000) ;
                digitalWrite (2, LOW) ; delay (500) ;
            }
                
            printf("Alarm\n");
            ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/123", "my1", "my 2", "my 33333");

        
        
        printf("Waiting for event\n");
        digitalWrite (1, LOW) ;
        
        
        }
    }
    return 0;
}

