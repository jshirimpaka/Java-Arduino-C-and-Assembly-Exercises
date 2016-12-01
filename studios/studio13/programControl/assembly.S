#include <avr/io.h>


.global greaterThan
greaterThan:
   cp r22,r24
   brlt label
   ldi r24,0
  ret
 label:
   ldi r24,1
   ret 

.global slowMultiply
slowMultiply:
    ldi r20, 0
    
    while_loop:
     inc r20
     exit_while:
     
  ret

.global slowExponent
slowExponent:
  ret
