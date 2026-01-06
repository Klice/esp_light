#pragma once

#include "esphome/core/component.h"
#include "esphome/components/light/light_output.h"

namespace esphome {
  namespace esp_light {
    extern const int LED_ao;

    class EspLightOutput : public Component, public light::LightOutput {
    public:
      void setup() override;
      light::LightTraits get_traits() override;
      void write_state(light::LightState *state) override;
    };
  }
}