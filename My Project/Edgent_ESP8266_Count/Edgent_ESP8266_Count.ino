
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLAjFV0ck8"
#define BLYNK_DEVICE_NAME "Count Number"

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

#include <SoftwareSerial.h>
SoftwareSerial NodeSerial(D6, D5); // RX | TX
int i_data;

int CountUP = 0;
int CountDown = 0;
int Reset = 0;
int num = 5;
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
}
BLYNK_WRITE(V0) {
  int buttonState = param.asInt();
  //Serial.print("Switch 1 : ");
  //Serial.println(buttonState);
  if (buttonState == HIGH) {
    num = num + 1;
  }
  //delay(200);
}
BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
  //Serial.print("Switch 2 : ");
  //Serial.println(buttonState);
  if (buttonState == HIGH) {
    num = 5;
  }
  //delay(200);
}
BLYNK_WRITE(V2) {
  int buttonState = param.asInt();
  //Serial.print("Switch 3 : ");
  //Serial.println(buttonState);

  if (buttonState == HIGH) {
    num = num - 1;
  }
  //delay(200);
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();

  // make the pushbutton's pin an input:
  pinMode(D6, INPUT);
  pinMode(D5, OUTPUT);

  NodeSerial.begin(57600);

}

void loop() {
  BlynkEdgent.run();
  if (num >= 10) {
    //NodeSerial.print(count);
    num = 9;
  }
  if (num <= -1) {
    //NodeSerial.print(count);
    num = 0;

  }
  
  while (NodeSerial.available() > 0)
  {
    i_data = NodeSerial.parseInt();
    if (NodeSerial.read() == '\n')
    {
      Serial.print("Count Data : ");
      Serial.println(i_data);
    }
  }
  Serial.print("Data : ");
  Serial.println(num);
  Blynk.virtualWrite(V3, num);
}
