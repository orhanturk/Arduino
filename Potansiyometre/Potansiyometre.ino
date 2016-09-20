
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Seri haberleşme
   pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int okunandeger = analogRead(A0);
  //map fonksiyonu okuduğumuz değeri 0-1023 aralığını 2 //ye böler 0-511 ise menzile 0 değerini verir. 512-1023 //ise menzile 1 değerini verir.
  int menzil = map(okunandeger, 0, 1023, 0, 1);
  switch (menzil) {
    case 0: //Pot döndürülmesi 0-49% arasında ise
    //  digitalWrite(ledPin, LOW);
      digitalWrite(ledPin, LOW);
      Serial.println("dusuk"); //Seri port ekranına yazdır
      break; // döngüden çıkış
    case 1: // Pot döndürülmesi 50-100% arasında ise
      Serial.println("yuksek");
      digitalWrite(ledPin, HIGH);
      break;
  } // döngüden çıkış
  delay(1000); // stabil çalışması için 1 milisaniye bekleme

}
