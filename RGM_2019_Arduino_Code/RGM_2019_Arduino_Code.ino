/*Author: Lorenzo Pedroza
 * Date: 042419
 * Code for Rube Goldberg Machine 2019
 * Abbreviations:
 *  - LS = LIGHT SENSOR
*/

#include <Servo.h>

#define LS0 A0
#define LS1 A2
#define RED_LED 2
#define YELLOW_LED 7
#define GREEN_LED 12
#define SERVO_PIN 5
#define BOTTLE_TRIGGER 4

int LS0Value = 0;
int LS1Value = 0;
int TRIGGER_STATE = LOW;
Servo keyBoardPresser;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LS0, INPUT);
  pinMode(LS1, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BOTTLE_TRIGGER, INPUT);
  keyBoardPresser.attach(SERVO_PIN);
  keyBoardPresser.write(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  LS0Value = getConstrainedLSValue(LS0);
  LS1Value = getConstrainedLSValue(LS1);
  TRIGGER_STATE = digitalRead(BOTTLE_TRIGGER);
  Serial.print("incoming value from photocell sensor =");
  Serial.println(LS0Value); 
  Serial.println(LS1Value);
  Serial.println("Triggerd\n");
  Serial.println(TRIGGER_STATE);
  
  delay(100);

  if(TRIGGER_STATE == LOW)
  {
      digitalWrite(RED_LED, HIGH);
      delay(3000);
      digitalWrite(RED_LED, LOW);

      digitalWrite(YELLOW_LED, HIGH);
      delay(3000);
      digitalWrite(YELLOW_LED, LOW);

      digitalWrite(GREEN_LED, HIGH);
      delay(3000);
      digitalWrite(GREEN_LED, LOW);

  }

  while(true);
  
}

int getConstrainedLSValue(int analogPin){
  int photocellValue = 0;
  
  photocellValue = analogRead(analogPin);
  photocellValue = constrain(photocellValue, 200, 800);

  return photocellValue;
}
