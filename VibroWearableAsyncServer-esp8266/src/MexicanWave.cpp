/**
	Mexican wave effect - feature.
	
	@author Dariusz Rumiński

*/
#include "MexicanWave.h"
#include <Arduino.h>


unsigned char *pointerToPins;
int pinn;

MexicanWave::MexicanWave(unsigned char* pp) {

  pointerToPins = pp;
  
}

// starts a mexican wave for fingers
void MexicanWave::start() {
  int x = 0;
  
  // 1024 means 3.3V for ESP
  for (int v = 0; v < 1024; v++) {
      
      // assume that a pointer points into 5 elements (fingers) array of pins
      for (int i = 0; i < 5; i++) {
    
        pinn = *(pointerToPins + i);

        v = v + x;
        
        analogWrite(pinn, v);
        delay(5);

        x = x + 10;
        
      }
  }


  // now backwards
  for (int v = 1024; v > 0; v--) {

      for (int i = 5; i > 0; i--) {

        pinn = *(pointerToPins + i);

        if (v <= 0) {
          analogWrite(pinn, LOW);
        } else {
          analogWrite(pinn, (v-50));
        }
        
        delay(3);
      }    
  }
}

/*        
  if (powerVar == 0) {
    analogWrite(pin, LOW);  
  } else {
    analogWrite(pin, powerVar);
  }
*/    

