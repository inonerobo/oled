#include <Wire.h>
#include "OLED.h"
//TTGO 0.91s OLED connection:
//SSD 1306
//LCD 128x32
//ADRESS 0x3E
//SDA -- D4
//SCL -- D5
//RST -- D2
//OLED display(SDA, SCL);

OLED display(D4, D5);
String myNum = "";

void setup() {

pinMode(D2, OUTPUT);
digitalWrite(D2, LOW); // turn D2 low to reset OLED
delay(50);
digitalWrite(D2, HIGH); // while OLED is running, must set D2 in high
Serial.begin(9600);
Serial.println("OLED LCD test!");
// Initialize display
display.begin();
// Test message
display.print("Hallo KOOS");
display.on();
delay(3*1000);

}
int r = 0, c = 0, TT = 0;
void loop() {
TT = TT+1;
r = r % 4;
c = micros() % 6;
if (r == 0) display.clear();
char b[3];
//itoa(TT,b,2);                // Int to Array
myNum = String(TT);
myNum.toCharArray(b,3);   // Int to Array
display.print(b , r++, c++);
display.print("-Koos" , r-1, c+1);
delay(500);
Serial.println("OLED! ");
}
