
#include <SoftwareSerial.h>

int DonmeHizi = 255;
/* bu değişken ile motorların dönme hızı kontrol edilebilir */

/* motor sürücüsüne bağlanacak INPUT ve ENABLE pinleri belirleniyor */
#define OnMotor_sol 9 // ÖN MOTOR SOL
#define OnMotor_sag 10 // ÖN MOTOR SAĞ
#define ArkaMotor_ileri 11 // ARKA MOTOR İLERİ
#define ArkaMotor_Geri 12 // ARKA MOTOR GERİ
#define ArkaMotor_hiz 5 // ARKA MOTOR HIZ PİNİ
#define OnMotor_hiz 4 // ÖN MOTOR HIZ PİNİ
const int led  = 13;
int estado;

int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3

int dataFromBt;

boolean lightBlink = false;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

// robotun yön komutları
void ileri()
{
  analogWrite(ArkaMotor_hiz, HIGH);
  analogWrite(OnMotor_hiz, LOW);
  digitalWrite(OnMotor_sag, LOW);
  digitalWrite(OnMotor_sol, LOW);
  digitalWrite(ArkaMotor_Geri, LOW);
  digitalWrite(ArkaMotor_ileri, HIGH);
}
void geri()
{
  analogWrite(ArkaMotor_hiz, HIGH);
  analogWrite(OnMotor_hiz, LOW);
  digitalWrite(OnMotor_sag, LOW);
  digitalWrite(OnMotor_sol, LOW);
  digitalWrite(ArkaMotor_Geri, HIGH);
  digitalWrite(ArkaMotor_ileri, LOW);
}
void sol_ileri()
{
  analogWrite(ArkaMotor_hiz, HIGH);
  analogWrite(OnMotor_hiz, HIGH);
  digitalWrite(OnMotor_sag, LOW);
  digitalWrite(OnMotor_sol, HIGH);
  digitalWrite(ArkaMotor_Geri, LOW);
  digitalWrite(ArkaMotor_ileri, HIGH);
}
void sol_geri()
{
  analogWrite(ArkaMotor_hiz, HIGH);
  analogWrite(OnMotor_hiz, HIGH);
  digitalWrite(OnMotor_sag, LOW);
  digitalWrite(OnMotor_sol, HIGH);
  digitalWrite(ArkaMotor_Geri, HIGH);
  digitalWrite(ArkaMotor_ileri, LOW);
}

void sag_ileri()
{
  analogWrite(ArkaMotor_hiz, HIGH);
  analogWrite(OnMotor_hiz, HIGH);
  digitalWrite(OnMotor_sol, LOW);
  digitalWrite(OnMotor_sag, HIGH);
  digitalWrite(ArkaMotor_ileri, HIGH);
  digitalWrite(ArkaMotor_Geri, LOW);
}
void sag_geri()
{
  analogWrite(ArkaMotor_hiz, HIGH);
  analogWrite(OnMotor_hiz, HIGH);
  digitalWrite(OnMotor_sol, LOW);
  digitalWrite(OnMotor_sag, HIGH);
  digitalWrite(ArkaMotor_ileri, LOW);
  digitalWrite(ArkaMotor_Geri, HIGH);
}

void dur()
{
  analogWrite(OnMotor_hiz, LOW);
  digitalWrite(OnMotor_sag, LOW);
  digitalWrite(OnMotor_sol, LOW);
  digitalWrite(ArkaMotor_ileri, LOW);
  digitalWrite(ArkaMotor_Geri, LOW);
}

void setup() {
  /* Bluetooth için port açılıyor */
  Serial.begin(9600);
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
  pinMode(OnMotor_sol, OUTPUT);
  pinMode(OnMotor_sag, OUTPUT);
  pinMode(ArkaMotor_ileri, OUTPUT);
  pinMode(ArkaMotor_Geri, OUTPUT);
  pinMode(ArkaMotor_hiz, OUTPUT);
  pinMode(OnMotor_hiz, OUTPUT);
}

void loop() {

  if (bluetooth.available()) // If the bluetooth sent any characters
  {

    if (Serial.available() > 0) { // lee el bluetooth y almacena en estado
      estado = Serial.read();
    }
    Serial.println(estado);
    // Send any characters the bluetooth prints to the serial monitor

    Serial.println((char)bluetooth.read());

    dataFromBt = bluetooth.read();

    if ( dataFromBt == 'w' )ileri();
    if ( dataFromBt == 'e' )dur();
    if ( dataFromBt == 'a' )sol_ileri();
    if ( dataFromBt == 's' )sol_geri();
    if ( dataFromBt == 'd' ) sag_ileri();
    if ( dataFromBt == 'f' ) sag_geri();
    if ( dataFromBt == 'x' ) geri();

    /*
        //Bluetooth’tan veri bekliyoruz
        if (Serial.available() > 0)
        {
          char tus = (char)Serial.read();
          if ( tus == 'w' )
            ileri(DonmeHizi);
          if ( tus == 's' )
            dur();
          if ( tus == 'a' )
            solaDon(DonmeHizi);
          if ( tus == 'd' )
            sagaDon(DonmeHizi);
          if ( tus == 'x' )
            geri(DonmeHizi);
        }

    */
  }
}
