
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL99GWH4Bh"
#define BLYNK_DEVICE_NAME "Smart Home Control"

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

#define DEBUG_SW 1

#define S1 D1
#define R1 D5

#define S2 D2
#define R2 D6

#define S3 D3
#define R3 D7

#define S4 D4
#define R4 D8

int MODE = 0;

int switch_ON_Flag1_previous_I = 0;
int switch_ON_Flag2_previous_I = 0;
int switch_ON_Flag3_previous_I = 0;
int switch_ON_Flag4_previous_I = 0;

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
}

BLYNK_WRITE(V1) {
  int buttonState1 = param.asInt();
  Serial.print("Switch 1 : ");
  Serial.println(buttonState1);
  digitalWrite(R1, buttonState1);
  // process received value
}
BLYNK_WRITE(V2) {
  int buttonState2 = param.asInt();
  Serial.print("Switch 2 : ");
  Serial.println(buttonState2);
  digitalWrite(R2, buttonState2);
  // process received value
}
BLYNK_WRITE(V3) {
  int buttonState3 = param.asInt();
  Serial.print("Switch 3 : ");
  Serial.println(buttonState3);
  digitalWrite(R3, buttonState3);
  // process received value
}
BLYNK_WRITE(V4) {
  int buttonState4 = param.asInt();
  Serial.print("Switch 4 : ");
  Serial.println(buttonState4);
  digitalWrite(R4, buttonState4);
  // process received value
}
BLYNK_WRITE(V5) {
  int buttonState5 = param.asInt();
  Serial.print("DATA 5 : ");
  Serial.println(buttonState5);
  if (buttonState5 == HIGH) {
    MODE = 0;
  }
  else
    MODE = 1;

  // process received value
}

void with_internet()
{
  if (digitalRead(S1) == LOW)
  {
    if (switch_ON_Flag1_previous_I == 1)
    {
      digitalWrite(R1, HIGH);
      if (DEBUG_SW) Serial.println("Relay1- ON");
      Blynk.virtualWrite(V1, 1);
      switch_ON_Flag1_previous_I = 0;
    }
    if (DEBUG_SW) Serial.println("Switch1 -ON");
  }
  if (digitalRead(S1) == HIGH )
  {
    if (switch_ON_Flag1_previous_I == 0)
    {
      digitalWrite(R1, LOW);
      if (DEBUG_SW) Serial.println("Relay1 OFF");
      Blynk.virtualWrite(V1, 0);
      switch_ON_Flag1_previous_I = 1;
    }
    if (DEBUG_SW)Serial.println("Switch1 OFF");
  }

  //Dhaddammm Robotics//
  if (digitalRead(S2) == LOW)
  {
    if (switch_ON_Flag2_previous_I == 1 )
    {
      digitalWrite(R2, HIGH);
      if (DEBUG_SW)  Serial.println("Relay2- ON");
      Blynk.virtualWrite(V2, 1);
      switch_ON_Flag2_previous_I = 0;
    }
    if (DEBUG_SW) Serial.println("Switch2 -ON");
  }
  if (digitalRead(S2) == HIGH )
  {
    if (switch_ON_Flag2_previous_I == 0)
    {
      digitalWrite(R2, LOW);
      if (DEBUG_SW) Serial.println("Relay2 OFF");
      Blynk.virtualWrite(V2, 0);
      switch_ON_Flag2_previous_I = 1;
    }
    if (DEBUG_SW)Serial.println("Switch2 OFF");
    //delay(200);
  }

  if (digitalRead(S3) == LOW)
  {
    if (switch_ON_Flag3_previous_I == 1)
    {
      digitalWrite(R3, HIGH);
      if (DEBUG_SW) Serial.println("Relay3- ON");
      Blynk.virtualWrite(V3, 1);
      switch_ON_Flag3_previous_I = 0;
    }
    if (DEBUG_SW) Serial.println("Switch3 -ON");
  }
  if (digitalRead(S3) == HIGH )
  {
    if (switch_ON_Flag3_previous_I == 0)
    {
      digitalWrite(R3, LOW);
      if (DEBUG_SW) Serial.println("Relay3 OFF");
      Blynk.virtualWrite(V3, 0);
      switch_ON_Flag3_previous_I = 1;
    }
    if (DEBUG_SW)Serial.println("Switch3 OFF");
  }

  if (digitalRead(S4) == LOW)
  {
    if (switch_ON_Flag4_previous_I == 1)
    {
      digitalWrite(R4, HIGH);
      if (DEBUG_SW) Serial.println("Relay4- ON");
      Blynk.virtualWrite(V4, 1);
      switch_ON_Flag4_previous_I = 0;
    }
    if (DEBUG_SW) Serial.println("Switch4 -ON");
  }
  if (digitalRead(S4) == HIGH )
  {
    if (switch_ON_Flag4_previous_I == 0)
    {
      digitalWrite(R4, LOW);
      if (DEBUG_SW) Serial.println("Relay4 OFF");
      Blynk.virtualWrite(V4, 0);
      switch_ON_Flag4_previous_I = 1;
    }
    if (DEBUG_SW)Serial.println("Switch4 OFF");
  }
}

void without_internet()
{
  Serial.println("OFFLINE MODE");
  digitalWrite(R1, digitalRead(S1));
  digitalWrite(R2, digitalRead(S2));
  digitalWrite(R3, digitalRead(S3));
  digitalWrite(R4, digitalRead(S4));

}

void setup()
{
  if (DEBUG_SW) Serial.begin(115200);
  pinMode(S1, INPUT);
  pinMode(R1, OUTPUT);

  pinMode(S2, INPUT);
  pinMode(R2, OUTPUT);

  pinMode(S3, INPUT);
  pinMode(R3, OUTPUT);

  pinMode(S4, INPUT);
  pinMode(R4, OUTPUT);

  digitalWrite(R1, HIGH) ;
  digitalWrite(R2, HIGH );
  digitalWrite(R3, HIGH) ;
  digitalWrite(R4, HIGH );
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  if (MODE == 0)
    with_internet();
  else
    without_internet();
}
