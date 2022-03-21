/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

#define DEBUG_SW 1

#define S1 D5
#define R1 D0

#define S2 D6
#define R2 D1

#define S3 D7
#define R3 D2

#define S4 D8
#define R4 D3

//Dhaddammm Robotics//

int MODE = 0;

// Go to the Project Settings (nut icon).
char auth[] = "hgrqB-nLi72NaOPiVh3jtySDCu-dsYNc";  // You should get Auth Token in the Blynk App.

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Prachaya Mobile"; //Prachaya Mobile
char pass[] = "50005000";

int switch_ON_Flag1_previous_I = 0;
int switch_ON_Flag2_previous_I = 0;
int switch_ON_Flag3_previous_I = 0;
int switch_ON_Flag4_previous_I = 0;

//Dhaddammm Robotics//
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  digitalWrite(R1, pinValue);
  // process received value
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V2 to a variable
  digitalWrite(R2, pinValue);
  // process received value
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V2 to a variable
  digitalWrite(R3, pinValue);
  // process received value
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V2 to a variable
  digitalWrite(R4, pinValue);
  // process received value
}
//Dhaddammm Robotics//
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
    if (switch_ON_Flag3_previous_I == 1 )
    {
      digitalWrite(R3, HIGH);
      if (DEBUG_SW)  Serial.println("Relay3- ON");
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
    //delay(200);
  }

  if (digitalRead(S4) == LOW)
  {
    if (switch_ON_Flag4_previous_I == 1 )
    {
      digitalWrite(R4, HIGH);
      if (DEBUG_SW)  Serial.println("Relay4- ON");
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
      if (DEBUG_SW) Serial.println("Relay2 OFF");
      Blynk.virtualWrite(V4, 0);
      switch_ON_Flag4_previous_I = 1;
    }
    if (DEBUG_SW)Serial.println("Switch4 OFF");
    //delay(200);
  }
}

void without_internet()
{
  digitalWrite(R1, digitalRead(S1));
  digitalWrite(R2, digitalRead(S2));
  digitalWrite(R3, digitalRead(S3));
  digitalWrite(R4, digitalRead(S4));
}

void checkBlynk() { // called every 3 seconds by SimpleTimer

  bool isconnected = Blynk.connected();
  if (isconnected == false) {
    MODE = 1;
    //(LED1, HIGH);
    // digitalWrite(LED2, LOW);
    //  digitalWrite(LED3, LOW);
  }
  if (isconnected == true) {
    MODE = 0;
    //  digitalWrite(LED1, HIGH);
    //  digitalWrite(LED2, HIGH);
    //digitalWrite(LED3, HIGH);
  }
}

void setup()
{
  // Debug console
  if (DEBUG_SW) Serial.begin(9600);
  pinMode(S1, INPUT);
  pinMode(R1, OUTPUT);

  pinMode(S2, INPUT);
  pinMode(R2, OUTPUT);

  pinMode(S3, INPUT);
  pinMode(R3, OUTPUT);

  pinMode(S4, INPUT);
  pinMode(R4, OUTPUT);
  
  //Dhaddammm Robotics//
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, HIGH);
  
  WiFi.begin(ssid, pass);
  timer.setInterval(3000L, checkBlynk); // check if connected to Blynk server every 3 seconds
  Blynk.begin(auth, ssid, pass, "prachaya-th.trueddns.com", 46660); //, ssid, pass);

}
//Dhaddammm Robotics//
void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    if (DEBUG_SW) Serial.println("Not Connected");
  }
  else
  {
    if (DEBUG_SW) Serial.println(" Connected");
    Blynk.run();
  }

  timer.run(); // Initiates SimpleTimer
  if (MODE == 0)
    with_internet();
  else
    without_internet();
  //Dhaddammm Robotics//
}
