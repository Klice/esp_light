import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import light, output
from esphome.components.light import LightType

esp_light_ns = cg.esphome_ns.namespace("esp_light")
EspLightOutput = esp_light_ns.class_("EspLightOutput", light.LightOutput)

CONFIG_SCHEMA = light.light_schema(
    EspLightOutput, type_=LightType.BRIGHTNESS_ONLY
)


async def to_code(config):
    var = await light.new_light(config)