#include "scarlett_cat.h"

IRLevelSensor::IRLevelSensor(int tx_pin, int rx_pin) 
: PollingComponent(600000), ir_tx_pin(tx_pin), ir_rx_pin(rx_pin) {
  binary_sensor = new binary_sensor::BinarySensor();
}

void IRLevelSensor::setup() {
  pinMode(ir_tx_pin, OUTPUT);
  pinMode(ir_rx_pin, INPUT);
}

void IRLevelSensor::update() {
  digitalWrite(ir_tx_pin, HIGH);
  delay(5);
  digitalWrite(ir_tx_pin, LOW);

  bool detected = (digitalRead(ir_rx_pin) == LOW);
  binary_sensor->publish_state(detected);
}
