// Yazılım Geliştirme By Robimek - 2015
//oyuncak araba içim
#include <Servo.h>// servo motor kütüphanesi
#include <NewPing.h>
//motor pinleri
#define OnMotor_sol 9 // ÖN MOTOR SOL
#define OnMotor_sag 10 // ÖN MOTOR SAĞ
#define ArkaMotor_ileri 11 // ARKA MOTOR İLERİ
#define ArkaMotor_Geri 12 // ARKA MOTOR GERİ
#define ArkaMotor_hiz 5 // ARKA MOTOR HIZ PİNİ
#define OnMotor_hiz 4 // ÖN MOTOR HIZ PİNİ
//sensör pinleri
#define USTrigger 6 
#define USEcho 7
#define Maksimum_uzaklik 100
Servo servo; //servo motor tanımlama
NewPing sonar(USTrigger, USEcho, Maksimum_uzaklik);//ultrasonik sensör tanımlama
//kullanılacak eleman tanımı
unsigned int uzaklik;
unsigned int on_uzaklik;
unsigned int sol_uzaklik;
unsigned int sag_uzaklik;
unsigned int zaman;
// program ilk çalıştığında sadece bir kez çalışacak programlar
void setup()
{
//motor çıkışları
pinMode(OnMotor_sol, OUTPUT);
pinMode(OnMotor_sag, OUTPUT);
pinMode(ArkaMotor_ileri, OUTPUT);
pinMode(ArkaMotor_Geri, OUTPUT);
pinMode(ArkaMotor_hiz, OUTPUT);
pinMode(OnMotor_hiz, OUTPUT);
servo.attach(4); //servo pin tanımı
}
// sonsuz döngü
void loop()
{
delay(500);
servo.write(90);
sensor_olcum();
on_uzaklik = uzaklik;
if(on_uzaklik < 35 || on_uzaklik == 0)
{
ileri();
}
else
{
yavas_git();
servo.write(180);
delay(500);
sensor_olcum();
sol_uzaklik = uzaklik;
servo.write(0);
delay(500);
sensor_olcum();
sag_uzaklik = uzaklik;
servo.write(90);
delay(500);
if(sag_uzaklik <sol_uzaklik)
{
sag_geri();
delay(500);
sol_ileri();
delay(500);
ileri();
}
else if(sol_uzaklik <sag_uzaklik)
{
sol_geri();
delay(500);
sag_ileri();
delay(500);
ileri();
}
else
{
geri();
delay(500);
}
}
}
 
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

void yavas_git()
{
analogWrite(ArkaMotor_hiz, 180); // MOTOR HIZI
analogWrite(OnMotor_hiz, LOW);
digitalWrite(OnMotor_sag, LOW);
digitalWrite(OnMotor_sol, LOW);
digitalWrite(ArkaMotor_Geri, LOW);
digitalWrite(ArkaMotor_ileri, HIGH);
}
// sensörün mesafe ölçümü
void sensor_olcum()
{
delay(50);
zaman = sonar.ping();
uzaklik = zaman / US_ROUNDTRIP_CM;
}
