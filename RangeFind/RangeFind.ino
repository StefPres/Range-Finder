#include "NewPing.h"
#include "LiquidCrystal.h"
#define trig 13
#define echo 12
#define maximum 200

int usec;
int cm;
float inch;
NewPing sonar(trig, echo, maximum);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
lcd.begin(16,2);
Serial.begin(9600);
}

void loop(){ 
lcd.clear();
lcd.setCursor(2,0);
lcd.print("Range Finder");
usec=sonar.ping();
cm=usec/58;
inch=usec/58/2.54;
lcd.setCursor(0,1);
lcd.print(cm);
lcd.print("cm");
lcd.setCursor(7,1);
lcd.print(inch);
lcd.print("inch");
Serial.println(inch);
delay(500);
}
