#include <SoftwareSerial.h>
SoftwareSerial NodeSerial(D6, D5); // RX | TX
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

int LED_Check = D0;
int pushButtonUp = D1;
int pushButtonDown = D2;
int pushButtonReset = D7;
int count = 5;
WidgetLED LED1(V4);


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
    count = count + 1 ;
  }
  //delay(200);
}
BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
  //Serial.print("Switch 2 : ");
  //Serial.println(buttonState);
  if (buttonState == HIGH) {
    count = 5;
  }
  //delay(200);
}
BLYNK_WRITE(V2) {
  int buttonState = param.asInt();
  //Serial.print("Switch 3 : ");
  //Serial.println(buttonState);

  if (buttonState == HIGH) {
    count = count - 1 ;
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

  //pinMode(LED_Check, INPUT);
  pinMode(pushButtonUp, INPUT);
  pinMode(pushButtonDown, INPUT);
  pinMode(pushButtonReset, INPUT);
  count = 5;
 // NodeSerial.print(count);
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
    Serial.print(" : Push Button Reset : ");
    Serial.println(count);
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
    
  Serial.print("Count Data : ");
  Serial.println(count);
  NodeSerial.print(count); // print out the state of the button:
  NodeSerial.print(" ");
  NodeSerial.print("\n");
  delay(100);        // delay in between reads for stability
  if (count >= 10) {
    count = 9;
  }
  if (count <= -1) {
    count = 0;
  }
  Serial.print("Data : ");
  Serial.println(count);
  Blynk.virtualWrite(V3, count);
}
