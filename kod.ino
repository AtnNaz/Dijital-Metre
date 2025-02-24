#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

const int trigPin = 9;
const int echoPin = 8;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Mesafe:");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW); // hc
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  float distance = duration * 0.034 / 2; // mesafe

 
  lcd.setCursor(0, 1); 
  lcd.print("       ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");


 Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}