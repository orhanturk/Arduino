const int ledPin = 13;
int say = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
void loop()
{
  if (say == 15)
  {
    digitalWrite(ledPin, HIGH); // ledi yak
    delay(500);
    Serial.write(say);
  }
  say = say + 1;
}
