/*
  studio42-usb-pid.ino

  minimal USB example using TinyUSB on RP2040/RP2350
  basic USB descriptor configuration to demonstrate the use of the allocated PID.

  Yi donghoon
  2025/09/26
  http://studio42.kr/
  icq4ever.studio42@gmail.com
*/

#include <Arduino.h>
#include <Adafruit_TinyUSB.h>

static const char* kManufacturer = "studio42";
static const char* kProduct = "studio42 USB Device";
static const char* kISerial = "studio42 USB Device";

// (optional) 
static const uint16_t kVID = 0x1209;
static const uint16_t kPID = 0x2A42;

void setup() {
  // set VID, PID
  TinyUSBDevice.setID(kVID, kPID);

  // set other information
  TinyUSBDevice.setManufacturerDescriptor(kManufacturer);
  TinyUSBDevice.setProductDescriptor(kProduct);
  TinyUSBDevice.setSerialDescriptor(kISerial);

  Serial.begin(115200);
  while (!Serial) { delay(10); }
}

void loop() {
  // do something
}
