
const int buttonPin = 2;     
const int ledPin =  13;    
int count=0; 


int buttonState = 0;        

void setup() {
  
  pinMode(ledPin, OUTPUT);
  
  pinMode(buttonPin, INPUT);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  
  if (buttonState == HIGH) {
    
    digitalWrite(ledPin, HIGH);
    count++;
  } else {
    
    digitalWrite(ledPin, LOW);
    
  }
  Serial.println(count);
}
