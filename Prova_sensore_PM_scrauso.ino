//pressing nothing to display value of analog revolving potentiometer
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int measurePin = 0; //Connect dust sensor to Arduino A0 pin
int ledPower = 2;   //Connect 3 led driver pins of dust sensor to Arduino D2
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
void setup(){
  lcd.begin();                      // initialize the lcd 
  lcd.begin();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Raw Signal Value: ");
  lcd.setCursor(0,2);
  lcd.print("Voltage:");
  lcd.setCursor(0,3);
  lcd.print("Dust Density:");
  pinMode(ledPower,OUTPUT);
}
void loop(){
  digitalWrite(ledPower,LOW); // power on the LED
  delayMicroseconds(samplingTime);
  voMeasured = analogRead(measurePin); // read the dust value
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); // turn the LED off
  delayMicroseconds(sleepTime);
  // 0 - 5V mapped to 0 - 1023 integer values
  // recover voltage
  calcVoltage = voMeasured * (5.0 / 1024.0);
  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  dustDensity = 0.17 * calcVoltage - 0,1;
  lcd.setCursor(1,1);
  lcd.print(voMeasured);
  lcd.setCursor(9,2);
  lcd.print(calcVoltage);
  lcd.setCursor(14,3);
  lcd.print(dustDensity);
  delay(1000);
}
