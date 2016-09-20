#include <IRremote.h>

int RECV_PIN = 11; //

int in1 = 9;
int in2 = 8;
int pwm1 = 10;

int in3 = 4;
int in4 = 7;
int pwm2 = 5;

#define code1 0xFD8877 //
#define code2 0xFD9867 //
#define code3 0xFDA857 //
#define code4 0xFD6897 //
#define code5 0xFD28D7 //

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {

  //Serial.begin(9600); //
  irrecv.enableIRIn(); //
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
      case code1:
      forward();
      break;

      case code2:
      back();
      break;

      case code3:
      stopit();
      break;

      case code4:
      right();
      break;

      case code5:
      left();
      break;
}
//Serial.println(value); 
irrecv.resume(); // Receive the next value
}
}
void forward()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(pwm1,230);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(pwm2,255);
}

void back()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(pwm1,250);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(pwm2,250);
}

void stopit()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  analogWrite(pwm1,0);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(pwm2,0);
}

void right()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  analogWrite(pwm1,0);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(pwm2,150);
}

void left()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(pwm1,150);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(pwm2,0);
}

