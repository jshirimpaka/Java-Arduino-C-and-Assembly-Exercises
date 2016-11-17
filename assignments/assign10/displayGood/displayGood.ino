


// the setup function runs once when you press reset or power the board


#include <Arduino.h>
#include "font.h"

int x = 0;
int keys=0x0;
int magicN=0x21;
int potVal=0;
float currentTime=0.0;

int c =0x32;
//R=32
//p=30;
//C=23
//W=37
//F=26
//7rows
int pinRows[7] = {13, 12, 11, 10, 9, 8, 7};

//5col
int pinCols[5] = {6, 5, 4, 3, 2};


const int POT_PIN = A1;

void setup() {
  Serial.begin(230400);
  
  analogReference(DEFAULT);
  pinMode(POT_PIN, INPUT);
  
  //SET UP cols, cathodes(-) 5
  for (int icol = 0; icol < 5; icol++) {
    pinMode(pinCols[icol], OUTPUT);
  }

  //SET UP rows, anodes(+) 7
  for (int irow = 0; irow < 7; irow++) {
    pinMode(pinRows[irow], OUTPUT);
  }
}
int countRow=14;
int countCol=6;


void loop() {
   if(millis()-currentTime>=1000.0){
    currentTime+=1000.0;
    Serial.write(magicN);
    keys=0x33;
    Serial.write(keys);
    potVal = analogRead(POT_PIN);
    Serial.write(potVal>>8); 
    Serial.write(potVal>>0);
    if(potVal<400){
      keys=0x32;
      Serial.write(magicN);
      Serial.write(keys);
    }
    else if(400<potVal&&potVal<800){
      keys=0x31;
      Serial.write(magicN);
      Serial.write(keys);
    }else if(potVal>800){
      keys=0x30;
      Serial.write(magicN);
      Serial.write(keys);
    }

   }
 
      for(int col=0; col<5;col++){
        for (int row=1; row<8;row++){
          x = bitRead(font_5x7[c][col], row);
                  //Serial.print(x);
                  
                    
                        countRow--;
                      if(countRow==6){
                        countRow=13;
                      }
          //Serial.print(countRow);
          if(x==1){
            digitalWrite(countRow,1);
            digitalWrite(countCol,0);
            delay(1);
            digitalWrite(countRow,0);
            digitalWrite(countCol,1);
          }
      
        }
        //Serial.println("");
        countCol--;
        if(countCol==1){
          countCol=6; 
        }
        
      }
      
      
      
      
       
}   
