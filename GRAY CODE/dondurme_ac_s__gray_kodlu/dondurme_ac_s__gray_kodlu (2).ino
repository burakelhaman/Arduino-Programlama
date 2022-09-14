#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

//SENSÖRLERDEN ALINACAK DEGERLER İÇİN DEĞİŞKENLER
int sensorPin0 = 0;
int sensorPin1 = 1;
int sensorPin2 = 2;
int sensorPin3 = 3;
void setup() {
lcd.begin(16,2);
}
void loop() {

//10'LUK TABAN İÇİN KULLANILACAK DEĞİŞKENLER
int bet3=0;
int bet2=0;
int bet1=0;
int bet0=0;

float aci;
int sayi=0;
//BINNARY'E ÇEVİRMEDE KULLANILACAK DEĞİŞKENLER
int sayi0=0;
int sayi1=0;
int sayi2=0;
int sayi3=0;

//SENSÖRDEN GELEN DEĞERLERİ OKUMA
int deger0 = analogRead(sensorPin0);
int deger1 = analogRead(sensorPin1);
int deger2 = analogRead(sensorPin2);
int deger3 = analogRead(sensorPin3);
lcd.clear();

//HASSASİYET
if(deger0<500){
  deger0=0;
}
else{
  deger0=1;
}
if(deger1<500){
  deger1=0;
}
else{
  deger1=1;
}
if(deger2<500){
  deger2=0;
}
else{
  deger2=1;
}
if(deger3<500){
  deger3=0;
}
else{
  deger3=1;
}

//GRAY'I BINNARY'E ÇEVİRME VE 10'LUK TABANA ALMA
sayi0=deger0;
if(sayi0==1){
  bet3=8;
}
if(sayi0!=deger1){
  sayi1=1;
  bet2=4;
}
if(sayi1!=deger2){
  sayi2=1;
  bet1=2;
}
if(sayi2!=deger3){
  sayi3=1;
  bet0=1;
}
sayi=bet0+bet1+bet2+bet3;

//AÇI DEĞERİNİ HESAPLAMA
aci=sayi*22.5;

//EKRANA YAZDIRMA
lcd.print("DONDURME ACISI");
lcd.setCursor(0,1);
lcd.print(aci);

//SAYIYA GÖRE "DERECE" KELİMESİNİN YERİNİ DEĞİŞTİRME
if(aci==0){
lcd.setCursor(5,1);
lcd.print("Derece");
delay(500);
}
else if(aci<100){
lcd.setCursor(6,1);
lcd.print("Derece");
delay(500);
}
else{
lcd.setCursor(7,1);
lcd.print("Derece");
delay(500);
}
}
