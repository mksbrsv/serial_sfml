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
    int[2] array;
    int x_coord = analogRead(x_pin);
    int y_coord = analogRead(y_pin);
    array[0] = x_coord;
    array[1] = y_coord;
    Serial.write(array, 2);
   // if (x_coord > 505+2) {
   //     array[0] = x_coord;
   //     array[1] = y_coord;
   //     Serial.write(array, 2);
   // }
   // if (x_coord < 505-2) {
   //     Serial.print("right0");
   //     
   // }
   // if (y_coord > 517+2) {
   //     Serial.print("up0");
   // }
   // if (y_coord < 517-2) {
   //     Serial.print("down0");
   // }
   // Serial.print("x: ");
   // Serial.println(analogRead(x_pin));
   // Serial.print("y: ");
   // Serial.println(analogRead(y_pin));
    delay(100);
}
