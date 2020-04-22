#include <Adafruit_MAX31856.h>
// Use SPI pins: CS, MISO, MOSI, CLK
Adafruit_MAX31856 tc0 = Adafruit_MAX31856(D0,D7,D6,D5);
Adafruit_MAX31856 tc1 = Adafruit_MAX31856(D1,D7,D6,D5);

void setup() {
  Serial.begin(115200);
  tc0.begin();
  tc1.begin();
  tc0.setThermocoupleType(MAX31856_TCTYPE_K);
  tc1.setThermocoupleType(MAX31856_TCTYPE_K);
}

void loop() {
  float temp0 = (tc0.readThermocoupleTemperature() * 9.0/5.0) + 32.0;
  float temp1 = (tc1.readThermocoupleTemperature() * 9.0/5.0) + 32.0;
  Serial.print(temp0); Serial.print(","); Serial.println(temp1);
}
