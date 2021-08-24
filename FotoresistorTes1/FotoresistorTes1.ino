#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int changeButton;
int photoResistor1;
int photoResistor2;
int photoResistor3;
int photoResistor4;
int photoResistor5;
int buttonIncrementor;

const int changeButtonPin = 6;
const int sensorPin1 = A5;
const int sensorPin2 = A4;
const int sensorPin3 = A3;
const int sensorPin4 = A2;
const int sensorPin5 = A1;

void setup() {
  Serial.begin(9600);
  Serial.println(" Time, Sensor1, Sensor2, Sensor3,  Sensor4, Sensor5");
  lcd.begin(16, 2);
  buttonIncrementor = 0;

}

void loop() {
  photoResistor1 = analogRead(sensorPin1);
  photoResistor2 = analogRead(sensorPin2);
  photoResistor3 = analogRead(sensorPin3);
  photoResistor4 = analogRead(sensorPin4);
  photoResistor5 = analogRead(sensorPin5);

  changeButton = digitalRead(changeButtonPin);
  /*
    Serial.print(" Senzor 1: ");
    Serial.print(photoResistor1);
    Serial.print(" Senzor 2: ");
    Serial.print(photoResistor2);
    Serial.print(" Senzor 3: ");
    Serial.print(photoResistor3);
    Serial.print(" Senzor 4: ");
    Serial.print(photoResistor4);
    Serial.print(" Senzor 5: ");
    Serial.println(photoResistor5);
  */
  Serial.print(",");
  Serial.print(photoResistor1);
  Serial.print(",");
  Serial.print(photoResistor2);
  Serial.print(",");
  Serial.print(photoResistor3);
  Serial.print(",");
  Serial.print(photoResistor4);
  Serial.print(",");
  Serial.print(photoResistor5);
  Serial.println(",");

  delay(2000);

  if (changeButton == 1 && buttonIncrementor < 2) {
    buttonIncrementor++;
  }
  else if (changeButton == 1 && buttonIncrementor >= 2) {
    buttonIncrementor = 0;
  }

  lcd.clear();
  if (buttonIncrementor == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Senzor 1: ");
    lcd.print(photoResistor1);
    lcd.setCursor(0, 1);
    lcd.print("Senzor 2: ");
    lcd.print(photoResistor2);
  }
  else if (buttonIncrementor == 1) {
    lcd.setCursor(0, 0);
    lcd.print("Senzor 3: ");
    lcd.print(photoResistor3);
    lcd.setCursor(0, 1);
    lcd.print("Senzor 4: ");
    lcd.print(photoResistor4);

  }

  else if (buttonIncrementor == 2) {
    lcd.setCursor(0, 0);
    lcd.print("Senzor 5: ");
    lcd.print(photoResistor5);
    //lcd.setCursor(0, 1);
    //lcd.print("Senzor 4: ");
    //lcd.print(photoResistor4);

  }
}
