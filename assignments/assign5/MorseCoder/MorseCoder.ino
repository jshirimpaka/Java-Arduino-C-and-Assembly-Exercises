#include"MorseCodes.h"

int ledPin = 13;
int ledState = LOW;
int unit = 500;

int intervalDot = 0;
int intervalDash = 0;
int intervalWords = 0;
unsigned long currentTime = 0;

// Argument: Any character
// Return Value: Either:
//                  1) If the character is a letter, the upper case equivalent.
//                  2) If the character is not a letter, the original value.
char toUpper(char c) {
  if (c >= 97 && c <= 122) {
    c = c - 32;

  }
  return c;
}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void convertIncomingCharsToMorseCode() {


  if (Serial.available() > 0) {

    char a = Serial.read();

    String morse = morseEncode(a);
    char test;



    int i = 0;
    while (i < morse.length()) {

      test = morse[i];

      if (test == '.') {

        if (ledState == LOW) {
          intervalDot = unit;
          if (millis() - currentTime > intervalDot) { //how long to light on
            currentTime += intervalDot;


            digitalWrite(ledPin, HIGH);
            ledState = LOW;


          } else {


            if (millis() - currentTime > intervalDot) { //how long between dots

              if (i == morse.length()) {
                intervalDot = 3 * unit;
              }
              currentTime += intervalDot;

              //ledState=LOW;
              digitalWrite(ledPin, ledState);

              i++;

            }

          }
        }

      } else if (test == '-') {
        if (ledState == LOW) {
          intervalDash = 3 * unit;
          if (millis() - currentTime > intervalDash) { //how long to light on
            currentTime += intervalDash;


            digitalWrite(ledPin, HIGH);
            ledState = HIGH;
          }


        } else {
          intervalDash = unit;
          if (millis() - currentTime > intervalDash) { //how long between dashes
            if (i == morse.length()) {
              intervalDash = 3 * unit;
            }
            currentTime += intervalDash;

            digitalWrite(ledPin, LOW);
            ledState = LOW;

            i++;
            //Serial.print(i);
          }

        }



      } else if (test == ' ') {


        intervalWords = 7 * unit;
        if (millis() - currentTime > intervalWords) { //how long between dashes

          currentTime += intervalWords;
          ledState == LOW;
          digitalWrite(ledPin, ledState);

        }
        i++;

      }
    }
  }
}




void loop() {
  // No Need to Modify this.  Put most of your code in "convertIncomingCharsToMorseCode()"
  convertIncomingCharsToMorseCode();

}
