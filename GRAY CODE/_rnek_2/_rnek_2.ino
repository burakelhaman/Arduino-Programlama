#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int say[4],bet[4],sensorPin[4]={0,1,2,3},deger[4];

void setup() {
lcd.begin(16,2);}
void loop() {
float aci; int sayitop=0;
  
for(int i=3;i>=0;i--){bet[i]=0;}
for(int i=0;i<=3;i++){
  say[i]=0;
  deger[i]=analogRead(sensorPin[i]);
}
lcd.clear();
for(int i=0;i<=3;i++){
if(deger[i]<500){
  deger[i]=0;}
else{
  deger[i]=1;
}}
deger[0]=say[0];
if(say[0]==1){
  bet[3]=8;
}
for(int i=1;i<=3;i++){
  if(say[i]!=deger[i]){
  say[i]=1;
  bet[3-i]=4;
}}
sayitop=bet[0]+bet[1]+bet[2]+bet[3];
aci=sayitop*22.5;

lcd.print("DONDURME ACISI");
lcd.setCursor(0,1);
lcd.print(aci);
//SAYIYA GÖRE "DERECE" KELİMESİNİN YERİNİ DEĞİŞTİRME
  if(aci==0){
lcd.setCursor(5,1);
lcd.print("Derece");
delay(400);}
  else if(aci<100){
lcd.setCursor(6,1);
lcd.print("Derece");
delay(400);}
  else{
lcd.setCursor(7,1);
lcd.print("Derece");
delay(400);
}}
