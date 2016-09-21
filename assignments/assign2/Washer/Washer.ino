#include <Arduino.h>
#include <Wire.h>

enum State {
  off_State,
  washer_State,
  dryer_State,
};

State counterState = off_State; //What state are we currently in?

//Fill in the values below with the pins that you chose to use
const int POT_PIN = A0;
const int BUTTON_PIN = 2;

const int COLD_PIN = 10;
const int HOT_PIN = 11;
const int DRY_PIN = 12;
const int LOCK_PIN =13 ;

int potVal=0;
int buttonState=0;        // variable for reading the pushbutton status


void setup() {
Serial.begin(9600);

pinMode(BUTTON_PIN, INPUT);
pinMode(POT_PIN, INPUT);
pinMode(HOT_PIN, OUTPUT); 
pinMode(COLD_PIN, OUTPUT);
pinMode(DRY_PIN, OUTPUT);
pinMode(LOCK_PIN, OUTPUT);

}



void loop() {
  counterState = nextState(counterState);
  buttonState = digitalRead(BUTTON_PIN);
  potVal = analogRead(POT_PIN);
  delay(1);
  Serial.println(buttonState);
}

boolean start_Button(){
  if(buttonState==HIGH){
    return true;
  }else{
    return false;
  }
}

boolean economY(){
  if(potVal<341){
    return true;
    
  }else{
    return false;
  }
}

boolean deluxE(){
  if(potVal>341&&potVal<682){
    return true; 
  }else{
    return false;
  }
}

boolean superDeluxe(){
  if(potVal>682){
    return true;
  }else{
    return false;
  }
}


State nextState(State state) {
  
  switch (state) {
    
    case off_State:              
      digitalWrite(LOCK_PIN, LOW);   // turn all LEDs off. 
      digitalWrite(DRY_PIN, LOW);  
      digitalWrite(COLD_PIN, LOW); 
      digitalWrite(HOT_PIN, LOW);    
      
      if(start_Button()){
      
      state = washer_State;  
      }
      break; 
                           
    case washer_State:               
       digitalWrite(LOCK_PIN, HIGH);
      if(economY()){
        digitalWrite(COLD_PIN, HIGH);     
        delay(5000);
      }else if(deluxE()){
        digitalWrite(HOT_PIN, HIGH);
        delay(7000);
      }else if (superDeluxe()){
        digitalWrite(HOT_PIN, HIGH);
        delay(7000);
        
        digitalWrite(HOT_PIN, HIGH);
        digitalWrite(COLD_PIN, HIGH);
        delay(7000);
      }
      state =dryer_State ;
      
      break;

    case dryer_State:
            digitalWrite(COLD_PIN, LOW);
            digitalWrite(HOT_PIN, LOW);
            digitalWrite(DRY_PIN, HIGH);
            if(economY()){
              delay(2000);
            }else{
            delay(7000);
          }
          
      state = off_State;
   }
   return state;
}
 
