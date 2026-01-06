#include "esp_light.h"

namespace esphome {
namespace esp_light {

const int LED_ao = 4;

void EspLightOutput::setup() {
  pinMode(LED_ao, OUTPUT);
}

light::LightTraits EspLightOutput::get_traits() {
  auto traits = light::LightTraits();
  traits.set_supported_color_modes({light::ColorMode::BRIGHTNESS});
  return traits;
}

void EspLightOutput::write_state(light::LightState *state) {
  float brightness;
  state->current_values_as_brightness(&brightness);
  analogWrite(LED_ao, round(255.0f * brightness));
}

}
}