#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
int led = 13;
char myChar = 'a';
String string;
//char myString[5];
char LorR;

int enA = 3;
int in1 = 4;
int in2 = 5;
int enB = 6;
int in3 = 7;
int in4 = 8;

void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  pinMode(led, OUTPUT);
  Serial.println("Goodnight moon!");
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}


void loop() // run over and over
{
  string = "";

//Add to string
while(true){
  myChar=mySerial.read();
  if(32<=myChar && myChar<=127){
  string += myChar;
  }
  if (myChar==':'){
  break;
  }
  delay(10);
}// While End

//Analyse string
if (string !="off:" && string !="on:"){
 if (string != "L0:" && string != "R0:") { 
  //code for setting motor left or right
  if (string[0]=='L'){
    LorR= 'L';
  }else {
    LorR= 'R';
  }
  string.remove(0, 1);
  
  //code for putting it in reverse
  if (string[0]=='-')
  {
    string.remove(0, 1);
    string.remove((string.length()-1), 1);
    Serial.println(string);
    if (LorR== 'L'){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, string.toInt());
    } else{
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enB, string.toInt());
    }
  } 
  else 
  {
    string.remove((string.length()-1), 1);
    Serial.println(string);
    if (LorR== 'L'){
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(enA, string.toInt());
      } else{
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(enB, string.toInt());
      }
  } 
 } else {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
 }
}//End of long if statment

if(string == "on:"){
  digitalWrite(led, HIGH);
}
if(string =="off:"){
  digitalWrite(led, LOW);
}

}//Loop End 




