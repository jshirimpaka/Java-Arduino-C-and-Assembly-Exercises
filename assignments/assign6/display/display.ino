/* display

    CSE 132 - Assignment 7

    Fill this out so we know whose assignment this is.

    Name:
    WUSTL Key:

    Name:
    WUSTL Key:

*/

#include <Arduino.h>
#include "font.h"


int buttonPIN1 = A0;
int buttonPIN2 = A1;

int x = 0;


char c = 0x03;
//7rows
int pinRows[7] = {13, 12, 11, 10, 9, 8, 7};

//5col
int pinCols[5] = {6, 5, 4, 3, 2};


void setup ()
{
  // insert code here as needed
  // initialize digital pin 13 as an output.
  Serial.begin(9600);

  pinMode(buttonPIN1, INPUT);
  pinMode(buttonPIN2, INPUT);

  for (int icol = 0; icol < 5; icol++) {
    pinMode(pinCols[icol], OUTPUT);
  }

  //SET UP rows, anodes(+) 7
  for (int irow = 0; irow < 7; irow++) {
    pinMode(pinRows[irow], OUTPUT);
  }
}



boolean button1Press() {
  int button1 = analogRead(buttonPIN1);
  if (button1 == 1023) {
    return true;
  }
}

boolean button2Press() {
  int button2 = analogRead(buttonPIN2);
  if (button2 == 1023) {
    return true;
  }
}


void loop () {

  if (button1Press()) {
    c =c+1;
  }

  if (button2Press()) {
    c = c - 1;
  }
  // TURN OFF ALL THE COLUMS
  for (int i = 0; i < 5; i++) {
    digitalWrite(pinCols[i], 1);
  }
  // GO THROUGH ALL COLUMS AND TURN ON EACH ONE AT A TIME
  for (int col = 0; col < 5; col++) {

    digitalWrite(pinCols[col], 0);

    
    for (int row = 1; row < 8; row++) {
      for (int j = 0; j < 5; j++) {
        // TURN OFF ALL OTHER COLUMS EXCEPT THE CURRENT ONE
        if (j != col) {
          digitalWrite(pinCols[j], 1);
        }
        digitalWrite(pinCols[j], 0);
      }
      //WRITE THE CURRENT BIT TO THE CURRENT ROW
      x = bitRead(font_5x7[c][col], row);
      digitalWrite(pinRows[row - 1], x);
      Serial.print(x);

      delay(1);
    }

    
  }

}


