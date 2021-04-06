#include <Arduino.h>

const int sw_pin = 2;
const int x_pin = 0; // 506 - default or 505
const int y_pin = 1; // 517 - defaulr or 518
int count_sw = 0; 

void setup() {
    pinMode(sw_pin, INPUT);
    digitalWrite(sw_pin, HIGH);
    Serial.begin(9600);
}

void loop() {
    int x_coord = analogRead(x_pin);
    if (x_coord > 505+2) {
        int a = 1;
        Serial.write("left56789");
    }
    if (x_coord < 505-2) {
        int a = 2;
        Serial.write("up3456789");
        
    }
    int y_coord = analogRead(y_pin);
    if (y_coord > 517+2) {
        Serial.write("up3456789");
    }
    if (y_coord < 517-2) {
        Serial.write("down56789");
    }
   // Serial.print("x: ");
   // Serial.println(analogRead(x_pin));
   // Serial.print("y: ");
   // Serial.println(analogRead(y_pin));
    delay(100);
}