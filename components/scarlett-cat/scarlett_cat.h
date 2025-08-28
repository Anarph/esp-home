#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

namespace esphome {
namespace scarlett_cat {

class ScarlettCat : public Component {
 public:
  void setup() override;
  void loop() override;

  // Services exposés à Home Assistant
  void on_give_food(int doses);
  void on_take_photo();

 protected:
  // Exemple : stockage état interne
  int feeding_doses_{0};
  bool feeding_active_{false};
};

}  // namespace scarlett_cat
}  // namespace esphome
