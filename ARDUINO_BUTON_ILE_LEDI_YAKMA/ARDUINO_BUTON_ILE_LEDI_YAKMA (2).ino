const int LED=9;
const int BUTON=2;
void setup() {
 pinMode(LED, OUTPUT);
 pinMode(BUTON, INPUT);
}

void loop() {
 if(digitalRead(BUTON)==HIGH){
  digitalWrite(LED, HIGH);
 }
else{
  digitalWrite(LED, LOW);
}
}
