


const int buttonPin = 2;    
const int ledPin = 13;      


int ledState = HIGH;        
int buttonState;             
int lastButtonState = LOW; 


long lastDebounceTime = 0;  
long debounceDelay = 50;    

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  

  
  if (reading != lastButtonState) {
    
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    

    
    if (reading != buttonState) {
      buttonState = reading;

      
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  
  digitalWrite(ledPin, ledState);

  
  lastButtonState = reading;
}

