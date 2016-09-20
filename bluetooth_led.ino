#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int ledPin = 12; 
int state = 0;
int flag = 0; 
 
void setup() {
  pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, LOW);
  lcd.begin(16, 2);
 Serial.begin(9600); // Default connection rate for my BT module
lcd.setCursor(0, 1);
  lcd.print("By: Youssef Emad");
}

  
void loop() {

 if(Serial.available()){
 state = Serial.read();
 flag=0;
 }

 if (state == '0') {
 digitalWrite(ledPin, LOW);
 if(flag == 0){
 lcd.print("LED: off");
 delay(1000);
 lcd.clear();
 Serial.println("LED: off");
 flag = 1;
 }}
 else if (state == '1') {
 digitalWrite(ledPin, HIGH);
 if(flag == 0){
 lcd.print("LED: on");
  delay(1000);
 lcd.clear();
 Serial.println("LED: on");
 flag = 1;
 }}
}

 
