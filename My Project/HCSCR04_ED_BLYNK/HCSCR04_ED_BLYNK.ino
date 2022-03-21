#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(D5, D6);

// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLUXf_gxD2"
#define BLYNK_DEVICE_NAME "HC SR04"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

BLYNK_CONNECTED(){
  Blynk.syncVirtual(V0);
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();

}

void loop() {
  BlynkEdgent.run();
  
  Serial.println(distanceSensor.measureDistanceCm());
  delay(500);
  Blynk.virtualWrite(V0,distanceSensor.measureDistanceCm());
}
