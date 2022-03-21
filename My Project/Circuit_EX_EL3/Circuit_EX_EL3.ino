//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int LDR = A0;
int VR = A1;
int MT = 6;
int Sw1 = 8;
int Sw2 = 9;
int LED = 13;

int dataLDR = map(analogRead(LDR), 0, 1023, 0, 100);
int dataVR = map(analogRead(VR), 0, 1023, 0, 100);
int dataSW1 = 0;
int dataSW2 = 0;

void setup()
{
  lcd.init();                      // initialize the lcd
  lcd.init();
  pinMode(LDR, INPUT);
  pinMode(VR, INPUT);
  pinMode(MT, OUTPUT);
  pinMode(Sw1, INPUT);
  pinMode(Sw2, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Hello World!");
  lcd.setCursor(2, 1);
  lcd.print("Press Put SW");
}


void loop()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

  if (digitalRead(Sw1) == LOW) {
    dataSW1 = dataSW1 + 1;
    //Serial.println(dataSW1);
    delay(250);
    lcd.clear();
  }
  if (digitalRead(Sw2) == LOW) {
    dataSW1 = 0;
    //Serial.println(dataSW2);
    delay(250);
    lcd.clear();
    //MT = 0;
    //dataVR = 0;
    //dataLDR = 0;
    digitalWrite(LED, LOW);
    delay(250);
  }
  if (dataSW1 >= 3) {
    dataSW1 = 0;
    lcd.clear();
  }

  dataLDR = analogRead(LDR);
  dataVR = map(analogRead(VR), 0, 1023, 0, 100);
  
  switch (dataSW1) {
    case 0:
      lcd.setCursor(2, 0);
      lcd.print("Hello World!");
      lcd.setCursor(2, 1);
      lcd.print("Press Put SW");
      //MT = 0;
      dataVR = 0;
      analogWrite(MT, dataVR);
      dataLDR = 0;
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Light : ");
      lcd.print(dataLDR);
      lcd.print(" lux  ");
      if (dataLDR >= 20) {
        digitalWrite(LED, LOW);
        delay(250);
      }
      if (dataLDR <= 10) {
        digitalWrite(LED, HIGH);
        delay(250);
      }
      delay(250);
      Serial.println(dataLDR);
      break;
    case 2:
      digitalWrite(LED, LOW);
      lcd.setCursor(0, 1);
      lcd.print("SP Motor : ");
      lcd.print(dataVR);
      analogWrite(MT, dataVR);
      lcd.print(" %   ");
      break;
  }

}
