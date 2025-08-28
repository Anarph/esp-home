#include "scarlett_cat.h"
#include "esphome/core/log.h"

namespace esphome {
namespace scarlett_cat {

static const char *TAG = "scarlett_cat";

void ScarlettCat::setup() {
  ESP_LOGI(TAG, "Scarlett Cat component setup");
  // Ici tu initialises ton feeder et ta caméra
}

void ScarlettCat::loop() {
  // Ici tu gères la machine à état pour nourrissage non bloquant
  if (feeding_active_) {
    ESP_LOGD(TAG, "Feeding in progress: %d doses left", feeding_doses_);
    // TODO: ajouter la logique moteur
  }
}

void ScarlettCat::on_give_food(int doses) {
  ESP_LOGI(TAG, "Service called: give_food(%d)", doses);
  feeding_doses_ = doses;
  feeding_active_ = true;
  // TODO: déclencher moteur
}

void ScarlettCat::on_take_photo() {
  ESP_LOGI(TAG, "Service called: take_photo()");
  // TODO: déclencher caméra + upload HTTP
}

}  // namespace scarlett_cat
}  // namespace esphome
