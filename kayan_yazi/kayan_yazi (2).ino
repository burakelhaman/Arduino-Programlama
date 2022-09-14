#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
lcd.begin(16,2);
}

void loop() {
int i;

for(i=0; i<17; i++){
lcd.setCursor(i,0);
lcd.print("TUBA'CIM"); // İstediğinizi yazabilirsiniz. Tabi 16 karakter den küçük olmalı…
lcd.setCursor(i,1);
lcd.print("SENI SEVIYORUM"); // İstediğinizi yazabilirsiniz. Tabi 16 karakter den küçük olmalı…
delay(500);
lcd.setCursor(i,0);
lcd.print(" ");
lcd.setCursor(i,1);
lcd.print(" ");
}
}
