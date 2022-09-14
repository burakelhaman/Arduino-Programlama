#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int say[4]={0,0,0,0},bet[4]={0,0,0,0},deger[4],sensorPin[4]={0,1,2,3};
void setup() {lcd.begin(16,2);}
void loop() {
float aci=0; int sayitop=0;
for(int i=0;i<=3;i++){
  deger[i]=analogRead(sensorPin[i]);}
lcd.clear();
for(int i=0;i<=3;i++){
  say[i]=0; bet[i]=0;
if(deger[i]<500){
  deger[i]=0;}
else{
  deger[i]=1;
}}
say[0]=deger[0];
if(say[0]==1){
  bet[3]=8;
}
for(int i=1;i<=3;i++){
  if(say[i-1]!=deger[i]){say[i]=1;}
  if(say[1]==1){bet[2]=4;} if(say[2]==1){bet[1]=2;} if(say[3]==1){bet[0]=1;}}
sayitop=bet[0]+bet[1]+bet[2]+bet[3];
aci=sayitop*22.5;
lcd.print("DONDURME ACISI");
lcd.setCursor(0,1);
lcd.print(aci);
  if(aci==0){
lcd.setCursor(5,1);
lcd.print("Derece");
delay(200);}
  else if(aci<100){
lcd.setCursor(6,1);
lcd.print("Derece");
delay(200);}
  else{
lcd.setCursor(7,1);
lcd.print("Derece");
delay(200);}}
