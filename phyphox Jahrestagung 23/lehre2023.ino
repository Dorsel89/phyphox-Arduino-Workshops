#include "Adafruit_VL53L0X.h"
#include <phyphoxBle.h> 

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  PhyphoxBLE::start("Dominiks ESP32");                 //Start the BLE serve
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test.");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power
  Serial.println(F("VL53L0X API Continuous Ranging example\n\n"));

  // start continuous ranging
  lox.startRangeContinuous();
}

void loop() {
  if (lox.isRangeComplete()) {
    Serial.print("Distance in mm: ");
    float range = lox.readRange():
    Serial.println(range);

    PhyphoxBLE::write(range);     //Send value to phyphox

  }
}