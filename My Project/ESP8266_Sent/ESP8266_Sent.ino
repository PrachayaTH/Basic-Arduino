#include <SoftwareSerial.h>
SoftwareSerial NodeSerial(D6, D5); // RX | TX
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLw94jOCLP"
#define BLYNK_DEVICE_NAME "Smart Control"

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

int LED_Check = D7;
int pushButtonUp = D2;
int pushButtonDown = D0;
int pushButtonReset = D1;
int count = 5;

WidgetLED LED1(V4);

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V0); //sw1 up
  Blynk.syncVirtual(V1); //sw2 reset
  Blynk.syncVirtual(V2); //sw3 down
  Blynk.syncVirtual(V3); //sent data to net
  Blynk.syncVirtual(V4); //sent LEDWidget
}
BLYNK_WRITE(V0) {
  int buttonState = param.asInt();
  if (buttonState == HIGH) {
    count = count + 1 ;
  }
}
BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
  if (buttonState == HIGH) {
    count = 5;
  }
}
BLYNK_WRITE(V2) {
  int buttonState = param.asInt();
  if (buttonState == HIGH) {
    count = count - 1 ;
  }
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
  pinMode(LED_Check, INPUT);
  pinMode(D6, INPUT);
  pinMode(D5, OUTPUT);
  pinMode(pushButtonUp, INPUT);
  pinMode(pushButtonDown, INPUT);
  pinMode(pushButtonReset, INPUT);
  count = 5;
  NodeSerial.begin(56700);
}

void loop() {
  BlynkEdgent.run();
  if (digitalRead(pushButtonUp) == LOW) {
    count = count + 1 ;
    delay(200);
  }
  if (digitalRead(pushButtonDown) == LOW) {
    count = count - 1 ;
    delay(200);
  }
  if (digitalRead(pushButtonReset) == LOW) {
    count = 5 ;
    delay(200);
  }
  if (count >= 10) {
    NodeSerial.print(count); // print out the state of the button:
    NodeSerial.print(" ");
    NodeSerial.print("\n");
    delay(750);
    count = 9;
  }
  if (count <= -1) {
    NodeSerial.print(count); // print out the state of the button:
    NodeSerial.print(" ");
    NodeSerial.print("\n");
    delay(750);
    count = 0;
  }

  if (digitalRead(LED_Check) == HIGH) {
    LED1.on();
    delay(250);
  }
  else
    LED1.off();

  NodeSerial.print(count);
  NodeSerial.print(" ");
  NodeSerial.print("\n");
  delay(100);
  Serial.print("Data Sent : ");
  Serial.println(count);
  Blynk.virtualWrite(V3, count);
}
