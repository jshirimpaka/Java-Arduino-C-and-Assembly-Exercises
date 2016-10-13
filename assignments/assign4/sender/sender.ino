/* helloworld
 *
 * output simple hello message
 *
 */

#include <Arduino.h>
#include <Wire.h>

 
#define FILTER_COUNTS 6

float temperatures[FILTER_COUNTS];
int counts=0; 

int debugLh=0;
int magicN=0x21;
int keys=0;


unsigned long timeData=0.0;

float currentTime=0.0;


const int POT_PIN = A1;
const int SENSOR_PIN = A2;

int potVal=0;
int rawVal=0;
float voltge=0.0;
float convTemp=0.0;

void setup() {
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(POT_PIN, INPUT);
  pinMode(SENSOR_PIN, INPUT);
  
}

void loop() {
 if(millis()-currentTime>=1000.0){
    currentTime+=1000.0;
    Serial.write(magicN);
    keys=0x30;
    Serial.write(keys);
    Serial.write(debugLength());
    Serial.print(debug());
    
    Serial.write(magicN);
    keys=0x32;
    Serial.write(keys);
    timeData=millis();
    Serial.write(timeData>>24); 
    Serial.write(timeData>>16);
    Serial.write(timeData>>8);
    Serial.write(timeData>>0);
    
    Serial.write(magicN);
    keys=0x33;
    Serial.write(keys);
    potVal = analogRead(POT_PIN);
    Serial.write(potVal>>8); 
    Serial.write(potVal>>0);
    if(potVal>600){
      keys=0x31;
      Serial.write(magicN);
      Serial.write(keys);
    }
    Serial.write(magicN);
    keys=0x34;
    Serial.write(keys);
    rawVal = analogRead(SENSOR_PIN);
    voltge=(rawVal*500.0)/1024.0;//in mV
    Serial.write(rawVal>>8); 
    Serial.write(rawVal>>0);

    Serial.write(magicN);
    keys=0x35;
    Serial.write(keys);
    convTemp=voltge/10.0;
    Serial.println(convTemp);
    
    Serial.print(convTemp*16777216); //shit by 24
    Serial.print(convTemp*65536);
    Serial.print(convTemp*256); 
    Serial.print(convTemp*1);

    
  
    temperatures[counts%FILTER_COUNTS]=convTemp;
    counts+=1;
  
    float sum=0;
    for(int i=0; i<6;i++){
       
       sum+=temperatures[i];
       
    }
    float tempFiltered=sum/FILTER_COUNTS;

    Serial.write(magicN);
    keys=0x36;
    Serial.write(keys);
    
    
    Serial.print(tempFiltered*16777216); 
    Serial.print(tempFiltered*65536);
    Serial.print(tempFiltered*256); 
    Serial.print(tempFiltered*1);
    } 
    
    
  
}

String debug(){
  return "Hello";
}



int debugLength(){
  return debug().length();
}


             
