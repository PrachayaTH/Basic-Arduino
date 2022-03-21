
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID           "TMPLVaPI3PXk"
#define BLYNK_DEVICE_NAME           "Kittiya"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG
#include <SimpleDHT.h>
// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

int pinDHT11 = D5 ;
SimpleDHT11 dht11(pinDHT11);


#include "BlynkEdgent.h"
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);
}
BLYNK_WRITE(V0) {
  int buttonState = param.asInt();
  digitalWrite(D1, buttonState);
}
BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
  digitalWrite(D2, buttonState);
}
BLYNK_WRITE(V2) {
  int buttonState = param.asInt();
  digitalWrite(D2, buttonState);
  digitalWrite(D1, buttonState);
}
BLYNK_WRITE(V3) {
  int buttonState = param.asInt();
  digitalWrite(D6, buttonState);
}

void setup()
{
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D6,OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");

  Blynk.virtualWrite(V4,temperature);
  Blynk.virtualWrite(V5,humidity);
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
