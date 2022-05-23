#include <iostream>
#include "bitsum.h"

int numberOfOnes(unsigned long int value) {
   unsigned long int x = 0; 
    while (value && (value >= 0 || value <= 18446744073709551615U)) { 
        x += value & 1; 
        value >>= 1; 
    } 
   if (value > 18446744073709551615U) {
       return -1;
   }
    return x; 
}