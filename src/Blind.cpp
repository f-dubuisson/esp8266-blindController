#include <Arduino.h>
#include "Blind.h"

Blind::Blind(int upPin, int downPin) {
  this->upPin = upPin;
  this->downPin = downPin;

  pinMode(upPin, OUTPUT);
  pinMode(downPin, OUTPUT);
  digitalWrite(upPin, HIGH);
  digitalWrite(downPin, HIGH);
}

void Blind::stop() {
  digitalWrite(upPin, HIGH);
  digitalWrite(downPin, HIGH);
}

void Blind::up() {
  digitalWrite(downPin, HIGH);
  digitalWrite(upPin, LOW);
}

void Blind::down() {
  digitalWrite(upPin, HIGH);
  digitalWrite(downPin, LOW);
}
