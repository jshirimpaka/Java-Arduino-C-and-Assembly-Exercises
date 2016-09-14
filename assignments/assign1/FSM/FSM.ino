/*
   FSM intro
*/

#include <Arduino.h>
#include <Wire.h>

enum State {
  up0,        // 0
  up1,        // 1
  up2,        // 2
  up3,        // 3
  up4,        // 4
  up5,        // 5
  up6,        // 6
  up7,        // 7
  
  dn0,        // 0
  dn1,        // 1
  dn2,        // 2
  dn3,        // 3
  dn4,        // 4
  dn5,        // 5
  dn6,        // 6
  dn7,        // 7
};

State counterState = up0; //What state are we currently in?

bool bit1;
bool bit2;
bool bit3;

boolean key=false;
int val=0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  counterState = nextState(counterState);
  delay(1000);
//    while(Serial.available()==0);
//  
//    val=Serial.read();
//    if(val!=0){
//      key=true;
//    }

}


bool checkReverse(){
  if(Serial.available()>0){
  
    val=Serial.read();
    Serial.println("--Reverse--");
    return true;
  }else{
   //Serial.println(key);
     return false;
}
}

State nextState(State state) {
  
  switch (state) {
    
    case up0:               //When state up0 , the FSM must:

      bit1 = 0;        //set the bits to match the Count
      bit2 = 0;
      bit3 = 0;

      //pprint(state);
      Serial.println("0: 000");

      if(!checkReverse()){
      state = up1;  
      }else{
        
        state=dn1;
      }
      //The next loop will go to case up1

      break;                       //Break to the end of the switch
    //So the next case won't run

    case up1:               //only if counterState == up1
      bit1 = 1;
      Serial.println("1: 001");
      //pprint(state);
      if(!checkReverse()){
      state = up2;
      }else{
        
        state=dn2;
      }
      break;

    case up2:
      bit1 = 0;
      bit2 = 1;
      //pprint(state);
      Serial.println("2: 010");
      if(!checkReverse()){
      state = up3;
      }else{
        
        state=dn3;
      }
      break;

    case up3:
      bit1 = 1;
      Serial.println("3: 011");
      //pprint(state);
      if(!checkReverse()){
      state = up4;
      }else{
        
        state=dn4;
      }
      break;

    case up4:
      bit1 = 0;
      bit2 = 0;
      bit3 = 1;
      Serial.println("4: 100");
      //pprint(state);
      if(!checkReverse()){
      state = up5;
      }else{
        
        state=dn5;
      }
      break;

    case up5:
      bit1 = 1;
      //pprint(state);
      Serial.println("5: 101");
      if(!checkReverse()){
      state = up6;
      }else{
       
        state=dn6;
      }
      break;

    case up6:
      bit1 = 0;
      bit2 = 1;
      //pprint(state);
      Serial.println("6: 110");
      if(!checkReverse()){
      state = up7;
      }else{
        
        state=dn7;
      }
      break;

    case up7:
      bit1 = 1;
      //pprint(state);
      Serial.println("7: 111");
      if(!checkReverse()){
      state = up0;
      }else{
        
        state=dn0;
      }
      break;
    
    case dn0:               //When state up0 , the FSM must:

      bit1 = 0;        //set the bits to match the Count
      bit2 = 0;
      bit3 = 0;

      //pprint(state);
      Serial.println("0: 000");

      if(!checkReverse()){
      state = dn7;          
      }else{
        
        state=up1;
      }
       //Move to the next state
      //The next loop will go to case up1

      break;                       //Break to the end of the switch
    //So the next case won't run

    case dn7:               //only if counterState == up1
      bit1 = 1;
      bit2 = 1;
      bit3 = 1;
      
      //pprint(state);
      Serial.println("7: 111");
      if(!checkReverse()){
      state = dn6;
      }else{
       
       state = up0;

      }
      break;

    case dn6:
      bit1 = 0;
      //pprint(state);
      Serial.println("6: 110");
      if(!checkReverse()){
      state = dn5;
      }else{
        
        state=up7;
      }
      break;

    case dn5:
      bit1 = 1;
      bit2=0;
      bit3=1;
      //pprint(state);
      Serial.println("5: 101");
      if(!checkReverse()){
      state = dn4;
      }else{
        
        state=up6;
      }
      break;

    case dn4:
      bit1 = 0;
      bit2 = 0;
      bit3 = 1;
      //pprint(state);
      Serial.println("4: 100");
      if(!checkReverse()){
      state = dn3;
      }else{
        
        state=up5;
      }
      break;

    case dn3:
      bit1 = 1;
      bit2 = 1;
      bit3 = 0;
      //pprint(state);
      Serial.println("3: 011");
      if(!checkReverse()){
      state = dn2;
      }else{
        
        state=up4;
      }
      break;

    case dn2:
      bit1 = 0;
      //pprint(state);
      Serial.println("2: 010");
      if(!checkReverse()){
      state = dn1;
      }else{
        
        state=up3;
      }
      break;

    case dn1:
      bit2 = 0;
      bit3 = 1;
      //pprint(state);
      Serial.println("1: 001");
      if(!checkReverse()){
      state = dn0;
      }else{
        state=dn2;
      }
      break;
   
  }
  return state;
}

//int number=0;

//void pprint(State state) {
//  
//  Serial.print(state);
//  Serial.print("  :  ");
//  Serial.print(bit3);
//  Serial.print(bit2);
//  Serial.println(bit1);
//}

