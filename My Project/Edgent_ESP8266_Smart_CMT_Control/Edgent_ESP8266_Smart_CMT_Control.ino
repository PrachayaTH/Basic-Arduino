
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLUkhiyAMz"
#define BLYNK_DEVICE_NAME "Smart CMT Control"

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
int Switch1, Switch2, Switch3, Switch4;
int Relay1 = D0;
int Relay2 = D1;
int Relay3 = D2;
int Relay4 = D3;
int pushSwitch1 = D4;
int pushSwitch2 = D5;
int pushSwitch3 = D6;
int pushSwitch4 = D7;

WidgetLED Lamp1(V4);
WidgetLED Lamp2(V5);
WidgetLED Lamp3(V6);
WidgetLED Lamp4(V7);

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
}
BLYNK_WRITE(V0) {
  int buttonState = param.asInt();
  Serial.print("Switch 1 : ");
  Serial.println(buttonState);
  if (buttonState == HIGH) {
    Switch1 = 1;
  }
  else
    Switch1 = 0;
}
BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
  Serial.print("Switch 2 : ");
  Serial.println(buttonState);
  if (buttonState == HIGH) {
    Switch2 = 1;
  }
  else
    Switch2 = 0;
}
BLYNK_WRITE(V2) {
  int buttonState = param.asInt();
  Serial.print("Switch 3 : ");
  Serial.println(buttonState);
  if (buttonState == HIGH) {
    Switch3 = 1;
  }
  else
    Switch3 = 0;
}
BLYNK_WRITE(V3) {
  int buttonState = param.asInt();
  Serial.print("Switch 4 : ");
  Serial.println(buttonState);
  if (buttonState == HIGH) {
    Switch4 = 1;
  }
  else
    Switch4 = 0;
}

int ledState1 = LOW;     // the current state of LED
int ledState2 = LOW;     // the current state of LED
int ledState3 = LOW;     // the current state of LED
int ledState4 = LOW;     // the current state of LED
int lastButtonState1;    // the previous state of button
int lastButtonState2;    // the previous state of button
int lastButtonState3;    // the previous state of button
int lastButtonState4;    // the previous state of button
int currentButtonState1; // the current state of button
int currentButtonState2; // the current state of button
int currentButtonState3; // the current state of button
int currentButtonState4; // the current state of button

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);

  currentButtonState1 = digitalRead(pushSwitch1);
  currentButtonState2 = digitalRead(pushSwitch2);
  currentButtonState3 = digitalRead(pushSwitch3);
  currentButtonState4 = digitalRead(pushSwitch4);
}

void loop() {
  lastButtonState1    = currentButtonState1;      // save the last state
  lastButtonState2    = currentButtonState2;      // save the last state
  lastButtonState3    = currentButtonState3;      // save the last state
  lastButtonState4    = currentButtonState4;      // save the last state
  currentButtonState1 = digitalRead(pushSwitch1);
  currentButtonState2 = digitalRead(pushSwitch2);
  currentButtonState3 = digitalRead(pushSwitch3);
  currentButtonState4 = digitalRead(pushSwitch4);

  if (lastButtonState1 == HIGH && currentButtonState1 == LOW) {
    Serial.println("The button 1 is pressed");

    // toggle state of LED
    ledState1 = !ledState1;

    // control LED arccoding to the toggled state
    digitalWrite(Relay1, ledState1);
    Blynk.virtualWrite(V0,ledState1);
  }

  if (lastButtonState2 == HIGH && currentButtonState2 == LOW) {
    Serial.println("The button 2 is pressed");

    // toggle state of LED
    ledState2 = !ledState2;

    // control LED arccoding to the toggled state
    digitalWrite(Relay2, ledState2);
    Blynk.virtualWrite(V2,ledState2);
  }
    if (lastButtonState3 == HIGH && currentButtonState3 == LOW) {
    Serial.println("The button 3 is pressed");

    // toggle state of LED
    ledState3 = !ledState3;

    // control LED arccoding to the toggled state
    digitalWrite(Relay3, ledState3);
    Blynk.virtualWrite(V3,ledState3);
  }
    if (lastButtonState4 == HIGH && currentButtonState4 == LOW) {
    Serial.println("The button 4 is pressed");

    // toggle state of LED
    ledState4 = !ledState4;

    // control LED arccoding to the toggled state
    digitalWrite(Relay4, ledState4);
    Blynk.virtualWrite(V4,ledState4);
  }
  
  BlynkEdgent.run();
/* 
  if (Switch1 == HIGH) {
    digitalWrite(Relay1, HIGH);
    Lamp1.on();
    delay(200);
  }
  if (digitalRead(ledState1) == LOW) {
    digitalWrite(Relay1, HIGH);
    //Blynk.virtualWrite(V0,HIGH);
    Lamp1.on();
    delay(200);
  }
  if (Switch1 == LOW and digitalRead(ledState1) == HIGH) {
    digitalWrite(Relay1, LOW);
    Lamp1.off();
    delay(200);
  }

  if (Switch2 == HIGH) {
    digitalWrite(Relay2, HIGH);
    Lamp2.on();
    delay(200);
  }
  if (digitalRead(ledState2) == LOW) {
    digitalWrite(Relay2, HIGH);
    Lamp2.on();
    delay(200);
  }
  if (Switch2 == LOW and digitalRead(ledState2) == HIGH) {
    digitalWrite(Relay2, LOW);
    Lamp2.off();
    delay(200);
  }

  if (Switch3 == HIGH) {
    digitalWrite(Relay3, HIGH);
    Lamp3.on();
    delay(200);
  }
  if (digitalRead(ledState3) == LOW) {
    digitalWrite(Relay3, HIGH);
    Lamp3.on();
    delay(200);
  }
  if (Switch3 == LOW and digitalRead(ledState3) == HIGH) {
    digitalWrite(Relay3, LOW);
    Lamp3.off();
    delay(200);
  }

  if (Switch4 == HIGH) {
    digitalWrite(Relay4, HIGH);
    Lamp4.on();
    delay(200);
  }
  if (digitalRead(ledState4) == LOW) {
    digitalWrite(Relay4, HIGH);
    Lamp4.on();
    delay(200);
  }
  if (Switch4 == LOW and digitalRead(ledState4) == HIGH) {
    digitalWrite(Relay4, LOW);
    Lamp4.off();
    delay(200);
  }
  */
}
