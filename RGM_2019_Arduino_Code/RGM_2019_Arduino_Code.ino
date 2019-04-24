/*Author: Lorenzo Pedroza
 * Date: 042319
 * Code for Rube Goldberg Machine 2019
 * Abbreviations:
 *  - LS = LIGHT SENSOR
*/
#define LS0 A0
#define LS1 A2
#define RED_LED 2
#define YELLOW_LED 3
#define GREEN_LED 12
#define SERVO 5

int LS0Value = 0;
int LS1Value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LS0, INPUT);
  pinMode(LS1, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  LS0Value = getConstrainedLSValue(LS0);
  LS1Value = getConstrainedLSValue(LS1);
  Serial.print("incoming value from photocell sensor =");
  Serial.println(LS0Value); 
  Serial.println(LS1Value);
  delay(100);
  
}

int getConstrainedLSValue(int analogPin){
  int photocellValue = 0;
  
  photocellValue = analogRead(analogPin);
  photocellValue = constrain(photocellValue, 200, 800);

  return photocellValue;
}
