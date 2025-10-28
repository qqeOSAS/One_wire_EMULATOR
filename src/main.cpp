#include <Arduino.h>
#include <OneWire.h>
#include "OW_Emulator_Master_Utils.h"

#define ONEWIRE_PIN D2
OneWire ow(ONEWIRE_PIN);

// Тестова ROM-адреса слейва
uint8_t slaveROM[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07};

void setup() {
  Serial.begin(115200);
  ow.begin(ONEWIRE_PIN);
  delay(500);
  



  Serial.println("Sending all data types...");

  // int8
  int8_t int8_val = -12;
  ow_write_int8(ow, int8_val);
  Serial.println("Sent INT8");

  // int16
  int16_t int16_val = 1234;
  ow_write_int16(ow, int16_val);
  Serial.println("Sent INT16");

  // uint16
  uint16_t uint16_val = 5678;
  ow_write_uint16(ow, uint16_val);
  Serial.println("Sent UINT16");

  // int32
  int32_t int32_val = -12345678;
  ow_write_int32(ow, int32_val);
  Serial.println("Sent INT32");

  // uint32
  uint32_t uint32_val = 98765432;
  ow_write_uint32(ow, (int32_t&)uint32_val); // підлаштування під сигнатуру
  Serial.println("Sent UINT32");

  // float32
  float float_val = 3.14159;
  ow_write_float32(ow, float_val);
  Serial.println("Sent FLOAT32");

  // char8
  char char_val = 'A';
  ow_write_char8(ow, char_val);
  Serial.println("Sent CHAR8");

  Serial.println("All packets sent");
}

void loop() {
  // Майстер поки нічого не робить
}
