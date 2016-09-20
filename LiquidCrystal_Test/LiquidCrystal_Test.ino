#include <FastIO.h>
#include <I2CIO.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_I2C_ByVac.h>
#include <LiquidCrystal_SI2C.h>
#include <LiquidCrystal_SR.h>
#include <LiquidCrystal_SR1W.h>
#include <LiquidCrystal_SR2W.h>
#include <LiquidCrystal_SR3W.h>
#include <SI2CIO.h>
#include <SoftI2CMaster.h>


#include <Wire.h>

#define BACKLIGHT_PIN     13
LiquidCrystal_I2C lcd(0x27 , 16, 2);

void setup()
{

  lcd.begin();
  lcd.backlight();

  // Switch on the backlight
  pinMode ( BACKLIGHT_PIN, OUTPUT );

  digitalWrite ( BACKLIGHT_PIN, HIGH );

  // Ekrana yazdırılacak metin
  lcd.print("Proje Hocam");


}

void loop()
{

}
