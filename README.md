# Scarlett Cat ESPHome External Component

Ce composant combine :
- un **feeder** (moteur + boutons)
- une **caméra ESP32-CAM** (upload HTTP)

## Installation

Dans ton fichier YAML ESPHome :

```yaml
esphome:
  name: scarlett-cat
  friendly_name: Scarlett Cat

external_components:
  - source: github://TON_GITHUB/esphome-scarlett-cat
    components: [ scarlett_cat ]

scarlett_cat:
