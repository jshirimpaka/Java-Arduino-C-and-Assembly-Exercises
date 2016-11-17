

void setup() {
 
  Serial.begin(9600);
 
  pinMode(13,OUTPUT);
}

void loop() {
  String text = Serial.readString();
  if(text=="C"){
    digitalWrite(13,1);
    delay(1000);
    digitalWrite(13,0);
    
  }
}
