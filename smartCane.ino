#include <LiquidCrystal.h>

/*
Author: Krushil Amrutiya
Dec 31, 2021
Desc: I created this project to help out my 
      friends for biomed to create a 
      working prototype of a smart cane
      use ultra-sonic senors, vibration motors, 
      4 channel relay module, and an arduino.
*/

#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(11,10,9,2,3,4,5);  //Create Liquid Crystal Object called LCD

#define trigPin 13 //Sensor Echo pin connected to Arduino pin 13
#define echoPin 12 //Sensor Trip pin connected to Arduino pin 12

const int RELAY_PIN = 7;  //Pin number 7 for the relay which connects the first channel relay
const int RELAY_PIN1 = 4; //Pin number 4 for the relay which connects the second channel relay
const int RELAY_PIN2 = 6; // Pin number 6 for the relay which connects the third channel relay
const int RELAY_PIN3 = 5; // Pin number 5 for the relay which connects the fouth channel relay

void setup() {  
  
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RELAY_PIN1, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);
  pinMode(RELAY_PIN3, OUTPUT);
  
  
  LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
  LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("Distance:");  //Print Message on First Row
}

void loop() {
  
  long duration, distance, distance_in;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  distance_in = distance * 0.393701;    

  LCD.setCursor(0,1);  //Set cursor to first column of second row
//  LCD.print("                "); //Print blanks to clear the row
  LCD.setCursor(0,1);   //Set Cursor again to first column of second row

//  if (distance_in <= 5) {
//    Serial.print(distance_in);
//    Serial.print(" inches, ");
    
//    LCD.print(distance_in);
//    LCD.print(" inches");  //Print your units.
//    digitalWrite(RELAY_PIN, LOW);
//    digitalWrite(RELAY_PIN, HIGH);
//    digitalWrite(RELAY_PIN1, HIGH);
//    digitalWrite(RELAY_PIN2, HIGH);
//    digitalWrite(RELAY_PIN3, HIGH);
    
//  } 

  if (distance_in <= 20) { //1 feet 8 inches
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(RELAY_PIN1, LOW);
    digitalWrite(RELAY_PIN2, LOW);
    digitalWrite(RELAY_PIN3, LOW);
 
  }

  else if (distance_in <= 36) { //3 feet
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(RELAY_PIN1, LOW);
    digitalWrite(RELAY_PIN2, HIGH);
    digitalWrite(RELAY_PIN3, HIGH);
  }
 
  else {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(RELAY_PIN1, HIGH);
    digitalWrite(RELAY_PIN2, HIGH);
    digitalWrite(RELAY_PIN3, HIGH);
  }

  
  delay(200); //pause to let things settle
}
