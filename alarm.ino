#include <SimpleDHT.h>
#include <LiquidCrystal.h>
int Contrast = 60;
LiquidCrystal lcd(5, 11, 8, 4, 3, 2);

int pinDHT11 = 12;
SimpleDHT11 dht11;
void setup()
{
  Serial.begin(9600);
  analogWrite(6, Contrast);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print(String("Temperature "));
}
void loop()
{
  byte temperature = 0;
  byte humidity = 0;
  dht11.read(pinDHT11, &temperature, &humidity, NULL);
  int temp = (int) temperature;

  lcd.setCursor(12,0);
  lcd.print(String(temp));
  Serial.println(temp);
  // Serial.print(" ");
  delay(1000);
  if(temp>=35)
  {
  t();
  }
  else
  {
  if(temp>30)
  {
   t1();
  }
  if(temp<30);
  {
  noTone(7);
  }
}
}
void t()
{
  lcd.setCursor(0, 1);
  lcd.print(String("EVACUATE !!"));
  tone(7, 494, 500);
  delay(1000);
}
void t1()
{
  lcd.setCursor(0, 1);
  lcd.print(String("ALERT !!"));
  tone(7, 494, 500);
  delay(2000);
} 
