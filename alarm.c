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
            while(digitalRead(0) == 1){
                digitalWrite (1, HIGH) ;
		ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/123", "Hello", "World", "my 3333311111");
		}
            printf("Waiting for event\n");
            while(digitalRead(0) == 0){
                digitalWrite (1, LOW);
		digitalWrite (2, HIGH) ; delay (300) ;
                digitalWrite (2, LOW) ; delay (300) ;
            }
                
            printf("Alarm\n");        
        }
    }
    return 0;
}

