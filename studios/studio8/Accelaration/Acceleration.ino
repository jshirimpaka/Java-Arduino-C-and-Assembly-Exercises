#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // Includes the SFE_MMA8452Q library

MMA8452Q accel;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 accel.init();
}

void loop() {
  // put your main code here, to run repeatedly:
 if (accel.available())
  {
     accel.read();
     printAccels();
     Serial.println(); // Print new line every time.
  }
}

void printAccels()
{
  Serial.print(accel.cx, 3);
  Serial.print("\t");
  Serial.print(accel.cy, 3);
  Serial.print("\t");
  Serial.print(accel.cz, 3);
  Serial.print("\t");
}
