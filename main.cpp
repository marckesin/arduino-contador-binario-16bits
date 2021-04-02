// _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Contador binário 16 bits
// 
// Made by ronaldo r
// License: CC-BY-SA 3.0
// Downloaded from: http://123d.circuits.io/circuits/700291-contador-binario-16-bits

#include <Arduino.h>

const int latchPin = 18; //pino 12 74hc595
const int clockPin = 16; //pino 11 74hc595
const int dataPin = 17; //pino 14 74hc595
int inc = 0;

void setup() { 
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(latchPin, LOW);
}

void loop() { 
  for (int i = 0; i <= 255; i++)
  {
    for (int x = 0; x <= 255; x++)
    {
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, x);
      shiftOut(dataPin, clockPin, LSBFIRST, i);
      digitalWrite(latchPin, HIGH);
      delay(500); 
    }
  } 
} 