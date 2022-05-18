/*
Author: Krushil Amrutiya
Dec 31, 2021
Desc: I created this project to help out my 
      friends for biomed to create a 
      working prototype of a smart cane
      use ultra-sonic senors, vibration motors, 
      4 channel relay module, and an arduino.
*/


//  if (distance_in <= 5) {
    

//    digitalWrite(RELAY_PIN, LOW);
//    digitalWrite(RELAY_PIN, HIGH);
//    digitalWrite(RELAY_PIN1, HIGH);
//    digitalWrite(RELAY_PIN2, HIGH);
//    digitalWrite(RELAY_PIN3, HIGH);
    
//  } 


  else if (distance_in <= 36) {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(RELAY_PIN1, LOW);
    digitalWrite(RELAY_PIN2, HIGH);
    digitalWrite(RELAY_PIN3, HIGH);

  }

  else if (distance_in <= 72) {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(RELAY_PIN1, LOW);
    digitalWrite(RELAY_PIN2, LOW);
    digitalWrite(RELAY_PIN3, LOW);
  }
 
  else {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(RELAY_PIN1, HIGH);
    digitalWrite(RELAY_PIN2, HIGH);
    digitalWrite(RELAY_PIN3, HIGH);
  }

  
  delay(250); //pause to let things settle
}
