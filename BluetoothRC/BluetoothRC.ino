// Proje Hocam - www.projehocam.com
// Android Kontrollü RC Araba Programı
#include <SoftwareSerial.h>

char dataIn = 'S'; // Durma fonksiyonu için karakter
int pinsol = 9; // ÖN MOTOR SOL
int pinsag = 10; //ÖN MOTOR SAĞ
int pinileri = 11; //ARKA MOTOR İLERİ
int pingeri = 12; // ARKA MOTOR GERİ

#define OnMotor_sol 9 // ÖN MOTOR SOL
#define OnMotor_sag 10
#define ArkaMotor_ileri 11 // ARKA MOTOR İLERİ
#define ArkaMotor_Geri 12 // ARKA MOTOR GERİ
#define ArkaMotor_hiz 5 // ARKA MOTOR HIZ PİNİ
#define OnMotor_hiz 4 // ÖN MOTOR HIZ PİNİ


char determinant; //Program döngüsü için karakter
char det; //Program döngüsü için karakter
const int led  = 13;
int estado;

int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3
boolean lightBlink = false;
int dataFromBt;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  Serial.begin(9600); //HC-07 bluetooth modülü için btu 9600
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  /* motorları kontrol eden pinler çıkış olarak ayarlanıyor */
  pinMode(led, OUTPUT);
  pinMode(pinileri, OUTPUT);
  pinMode(pingeri, OUTPUT);
  pinMode(pinsol, OUTPUT);
  pinMode(pinsag, OUTPUT);
}

void loop()
{
  det = check();
  while (det == 'F') //Telefondaki programda atanmış olan ileri sürüş butonunun harf eşdeğeri
  {
    digitalWrite(pinileri, HIGH);
    det = check();
  }
  while (det == 'B') //Telefondaki programda atanmış olan geri sürüş butonunun harf eşdeğeri
  {
    digitalWrite(pingeri, HIGH);
    det = check();
  }

  while (det == 'L') //Telefondaki programda atanmış olan sola dönüş butonunun harf eşdeğeri
  {
    digitalWrite(pinsol, HIGH);
    det = check();
  }
  while (det == 'R') //Telefondaki programda atanmış olan sağa butonunun harf eşdeğeri
  {
    digitalWrite(pinsag, HIGH);
    det = check();
  }
  while (det == 'G') //Telefondaki programda atanmış olan sağa butonunun harf eşdeğeri
  {
    digitalWrite(pinileri, HIGH);
    digitalWrite(pinsol, HIGH);
    det = check();
  }
  while (det == 'I') //Telefondaki programda atanmış olan sağa butonunun harf eşdeğeri
  {
    digitalWrite(pinileri, HIGH);
    digitalWrite(pinsag, HIGH);
    det = check();
  }
  while (det == 'H') //Telefondaki programda atanmış olan sağa butonunun harf eşdeğeri
  {
    digitalWrite(pingeri, HIGH);
    digitalWrite(pinsol, HIGH);
    det = check();
  }
  while (det == 'J') //Telefondaki programda atanmış olan sağa butonunun harf eşdeğeri
  {
    digitalWrite(pingeri, HIGH);
    digitalWrite(pinsag, HIGH);
    det = check();
  }
  while (det == 'S') //Telefondaki programda atanmış olan durma fonksiyonun harf eşdeğeri
  {
    digitalWrite(pinileri, LOW);
    digitalWrite(pingeri, LOW);
    digitalWrite(pinsol, LOW);
    digitalWrite(pinsag, LOW);
    det = check();
  }

}

int check()
{

  if (bluetooth.available()) // If the bluetooth sent any characters
  {

    if (Serial.available() > 0) { // lee el bluetooth y almacena en estado
      estado = Serial.read();
    }
    Serial.println(estado);
    // Send any characters the bluetooth prints to the serial monitor

    Serial.println((char)bluetooth.read());

    dataIn = bluetooth.read();

    if (dataIn == 'F')
    {
      determinant = 'F';
    }
    else if (dataIn == 'B')
    {
      determinant = 'B';
    }
    else if (dataIn == 'L')
    {
      determinant = 'L';
    }
    else if (dataIn == 'R')
    {
      determinant = 'R';
    }
    else if (dataIn == 'G')
    {
      determinant = 'G';
    }
    else if (dataIn == 'I')
    {
      determinant = 'I';
    }
    else if (dataIn == 'H')
    {
      determinant = 'H';
    }
    else if (dataIn == 'J')
    {
      determinant = 'J';
    }
    else if (dataIn == 'S')
    {
      determinant = 'S';
    }

  }
  return determinant;
}
