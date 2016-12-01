#include <avr/io.h>

; AVR assembly comments start with a semicolon 
// (or a double slash, like C)
; Lines without labels should be indented once.

 
 

.global giveMeMax
giveMeMax:
  //printRegs
  ldi r24, 255 // Load the value 1 into register 24
  //printRegs
  ret
.global giveMeZero
giveMeZero:
   ldi r24,0
   ret

.global addFour
 addFour:
   ldi r24,4
   ret
 // Define further "functions" below:
 // .global functionName
 // functionName:
 //   *code*
 //   ret

 .global hasAOne
  hasAOne:
   ldi r24,2
   or r24,r24
   ret
