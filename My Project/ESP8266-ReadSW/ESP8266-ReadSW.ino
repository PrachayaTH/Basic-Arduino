/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/
#include <SoftwareSerial.h>
SoftwareSerial NodeSerial(D6, D5); // RX | TX
// digital pin 2 has a pushbutton attached to it. Give it a name:


#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "JpVM5Hp30IN3wOc82-vfblqsF_KN9r3S";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Prachaya WiFi Mobile";
char pass[] = "50005000";


int LED = D1;
int pushButtonUp = D2;
int pushButtonDown = D3;
int pushButtonReset = D4;
int count = 5;
int count_check;

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);
}

BLYNK_READ(V2) {
  if (count >= 10) {
    count_check = 9;
    Blynk.virtualWrite(V2, count_check);
  } else if (count <= -1) {
    count_check = 0;
    Blynk.virtualWrite(V2, count_check);
  } else
    Blynk.virtualWrite(V2, count);
}
BLYNK_WRITE(V3) {
  int buttonState = param.asInt();
  if (buttonState == LOW) {
    count = count + 1 ;
  }
}
BLYNK_WRITE(V4) {
  int buttonState = param.asInt();
  if (buttonState == LOW) {
    count = count - 1 ;
  }
}
BLYNK_WRITE(V5) {
  int buttonState = param.asInt();
  if (buttonState == LOW) {
    count = 5;
  }
}

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  // make the pushbutton's pin an input:
  pinMode(D6, INPUT);
  pinMode(D5, OUTPUT);

  NodeSerial.begin(57600);

  pinMode(LED, OUTPUT);
  pinMode(pushButtonUp, INPUT);
  pinMode(pushButtonDown, INPUT);
  pinMode(pushButtonReset, INPUT);
  count = 5;
}

// the loop routine runs over and over again forever:
void loop() {
  Blynk.run();
  // read the input pin:
  if (digitalRead(pushButtonUp) == LOW) {
    count = count + 1 ;
    delay(250);
  }
  if (digitalRead(pushButtonDown) == LOW) {
    count = count - 1 ;
    delay(250);
  }
  if (digitalRead(pushButtonReset) == LOW) {
    count = 5 ;
    Serial.print(" : Push Button Reset : ");
    Serial.println(count);
    delay(250);
  }
  if (count >= 10) {
    NodeSerial.print(count); // print out the state of the button:
    NodeSerial.print(" ");
    NodeSerial.print("\n");
    delay(1000);
    count = 9;
  }
 if (count <= -1) {
    NodeSerial.print(count); // print out the state of the button:
    NodeSerial.print(" ");
    NodeSerial.print("\n");
    delay(1000);
    count = 0;
  }
  Serial.print("Count Data : ");
  Serial.println(count);
  NodeSerial.print(count); // print out the state of the button:
  NodeSerial.print(" ");
  NodeSerial.print("\n");
  delay(100);        // delay in between reads for stability
}
