/* helloworld
 *
 * output simple hello message
 */
int keys=0x0;
long times=0;
long currentTime=0;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
 if(millis()-currentTime>=1000.0){
    Serial.write(0x21);
    keys=0x30;
    Serial.write(keys);
    Serial.write(debugLength());
    Serial.print(debug());
    keys=0x32;
    Serial.write(keys);
    times=tStamp();
    byte bufT [4];
    for (int i=0;i<4;i++){
          bufT[i]=(times>>(8*i))&0xff;
         }
     Serial.write(bufT, sizeof(bufT));
    
    currentTime+=1000.0;
    
  }
  
}



String debug(){
  return "Hello";
}


 unsigned long tStamp(){
    
   float g=currentTime;
    
   unsigned long rawBits= *(unsigned long *) &g;
                 
   return rawBits;
  //return currentTime;
}


int debugLength(){
  return debug().length();
}


             
