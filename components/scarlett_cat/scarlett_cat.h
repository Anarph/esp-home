#include "esphome.h"

class IRLevelSensor : public PollingComponent {
 public:
  int ir_tx_pin;
  int ir_rx_pin;
  binary_sensor::BinarySensor *binary_sensor = new binary_sensor::BinarySensor();

  IRLevelSensor(int tx_pin, int rx_pin) : PollingComponent(30000) { // 600000 10 min
    this->ir_tx_pin = tx_pin;
    this->ir_rx_pin = rx_pin;
  }

  void setup() override {
    pinMode(ir_tx_pin, OUTPUT);
    pinMode(ir_rx_pin, INPUT);
  }

  void update() override {
    // Envoi d’un petit flash IR
    digitalWrite(ir_tx_pin, HIGH);
    delay(5);
    digitalWrite(ir_tx_pin, LOW);

    // Lire l’état du récepteur
    bool detected = (digitalRead(ir_rx_pin) == LOW);  
    // LOW = signal reçu → vide
    binary_sensor->publish_state(detected);
  }
};
