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
    int y_coord = analogRead(y_pin);
//    String x_string = String(x_coord, DEC);
//    String y_string = String(y_coord, DEC);
//    String xy_string(x_string + ":" + y_string);
    Serial.println("");
    Serial.println(x_coord);
    Serial.println(y_coord);
    delay(100);
}