#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2); //lcd için hangi portlar kullanılacak ise onlar yazılıyor
int sensorPin0 = 0;  //analog pin 0 - A0 pinine bağlanacak
int sensorPin1 = 1;  //analog pin 1 - A1 pinine bağlanacak
int sensorPin2 = 2;  //analog pin 2 - A2 pinine bağlanacak
int sensorPin3 = 3;  //analog pin 3 - A3 pinine bağlanacak
void setup() {
lcd.begin(16,2);  //lcd nin kaça kaç oldugu yazılıyor

}

void loop() {
int sayi0=0;
int sayi1=0;
int sayi2=0;
int sayi3=0;
int sayitop=0;
float aci;
int deger0 = analogRead(sensorPin0);
int deger1 = analogRead(sensorPin1);
int deger2 = analogRead(sensorPin2);
int deger3 = analogRead(sensorPin3);
lcd.clear();  //ekran siliniyor
if(deger0<500){
  deger0=0;
  sayi0=0;
}
else{
  deger0=1;
  sayi0=8;
}
if(deger1<500){
  deger1=0;
  sayi1=0;
}
else{
  deger1=1;
  sayi1=4;
}
if(deger2<500){
  deger2=0;
  sayi2=0;
}
else{
  deger2=1;
  sayi2=2;
}
if(deger3<500){
  deger3=0;
  sayi3=0;
}
else{
  deger3=1;
  sayi3=1;
}
sayitop=sayi0+sayi1+sayi2+sayi3;
aci=sayitop*22.5;


lcd.print("DONDURME ACISI");
lcd.setCursor(0,1);
lcd.print(aci);

if(aci==0){
lcd.setCursor(5,1);
lcd.print("Derece");
delay(1000);
}
else if(aci<100){
lcd.setCursor(6,1);
lcd.print("Derece");
delay(1000);
}
else{
lcd.setCursor(7,1);
lcd.print("Derece");
delay(1000);
}
}
