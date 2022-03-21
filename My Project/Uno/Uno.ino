int Switch1 = 0;
int pushButton = 10;
int pushButton1 = 11;
int pushButton2 = 12;

void setup() {
  pinMode(2, OUTPUT);//a
  pinMode(3, OUTPUT);//b
  pinMode(4, OUTPUT);//g
  pinMode(5, OUTPUT);//f
  pinMode(6, OUTPUT);//e
  pinMode(7, OUTPUT);//d
  pinMode(8, OUTPUT);//c
  pinMode(13, OUTPUT);

  Serial.begin(9600);

  Switch1 = 5;

  pinMode(pushButton, INPUT);
  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);
}

void loop() {

  int buttonState = digitalRead(pushButton);
  int buttonState1 = digitalRead(pushButton1);
  int buttonState2 = digitalRead(pushButton2);


  if (buttonState == LOW) {
    Switch1++;
    if (Switch1 > 10 )
      Switch1 = 0;

    delay(200);

  }
  Serial.println(Switch1);

  if (buttonState1 == LOW) {
    Switch1--;
    if (Switch1 < -1 )
      Switch1 = 0;

    delay(200);


  }
  Serial.println(Switch1);

  if (buttonState2 == LOW) {
    Switch1 = 5;

    delay(200);

  }
  Serial.println(Switch1);

  if (Switch1 == -1) {

    digitalWrite(2, LOW);//a //-1
    digitalWrite(3, LOW);//b
    digitalWrite(4, HIGH);//g
    digitalWrite(5, LOW);//f
    digitalWrite(6, LOW);//e
    digitalWrite(7, LOW);//d
    digitalWrite(8, LOW);//c

    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
    digitalWrite(13, HIGH);
    Switch1 = 0;

  }

  if (Switch1 == 0) {

    digitalWrite(2, LOW);//a //0
    digitalWrite(3, LOW);//b
    digitalWrite(4, HIGH);//g
    digitalWrite(5, LOW);//f
    digitalWrite(6, LOW);//e
    digitalWrite(7, LOW);//d
    digitalWrite(8, LOW);//c

    digitalWrite(13, HIGH);

    delay(200);

  }

  if (Switch1 == 1) {

    digitalWrite(2, HIGH);//a //1
    digitalWrite(3, LOW);//b
    digitalWrite(4, HIGH);//g
    digitalWrite(5, HIGH);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, HIGH);//d
    digitalWrite(8, LOW);//c
    digitalWrite(13, LOW);
    delay(200);
  }

  if (Switch1 == 2) {

    digitalWrite(2, LOW);//a //2
    digitalWrite(3, LOW);//b
    digitalWrite(4, LOW);//g
    digitalWrite(5, HIGH);//f
    digitalWrite(6, LOW);//e
    digitalWrite(7, LOW);//d
    digitalWrite(8, HIGH);//c

    digitalWrite(13, LOW);

    delay(200);
  }

  if (Switch1 == 3) {

    digitalWrite(2, LOW);//a //3
    digitalWrite(3, LOW);//b
    digitalWrite(4, LOW);//g
    digitalWrite(5, HIGH);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, LOW);//d
    digitalWrite(8, LOW);//c

    digitalWrite(13, LOW);

    delay(200);
  }

  if (Switch1 == 4) {

    digitalWrite(2, HIGH);//4
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);

    digitalWrite(13, LOW);

    delay(200);
  }
  if (Switch1 == 5) {


    digitalWrite(2, LOW);//a //5
    digitalWrite(3, HIGH);//b
    digitalWrite(4, LOW);//g
    digitalWrite(5, LOW);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, LOW);//d
    digitalWrite(8, LOW);//c

    digitalWrite(13, LOW);

    delay(200);

  }

  if (Switch1 == 6) {

    digitalWrite(2, LOW); //6
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);

    digitalWrite(13, LOW);

    delay (200);
  }


  if (Switch1 == 7) {

    digitalWrite(2, LOW);//a //7
    digitalWrite(3, LOW);//b
    digitalWrite(4, HIGH);//g
    digitalWrite(5, HIGH);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, HIGH);//d
    digitalWrite(8, LOW);//c

    digitalWrite(13, LOW);

    delay(200);
  }

  if (Switch1 == 8) {

    digitalWrite(2, LOW);//a //8
    digitalWrite(3, LOW);//b
    digitalWrite(4, LOW);//g
    digitalWrite(5, LOW);//f
    digitalWrite(6, LOW);//e
    digitalWrite(7, LOW);//d
    digitalWrite(8, LOW);//c

    digitalWrite(13, LOW);

    delay(200);
  }

  if (Switch1 == 9) {
    digitalWrite(2, LOW);//a //9
    digitalWrite(3, LOW);//b
    digitalWrite(4, LOW);//g
    digitalWrite(5, LOW);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, LOW);//d
    digitalWrite(8, LOW);//c

    digitalWrite(13, LOW);

    delay(200);
  }

  if (Switch1 == 10) {

    digitalWrite(13, HIGH);
    digitalWrite(2, LOW);//a //9
    digitalWrite(3, LOW);//b
    digitalWrite(4, LOW);//g
    digitalWrite(5, LOW);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, LOW);//d
    digitalWrite(8, LOW);//c
    delay(250);
    digitalWrite(13, LOW);
    digitalWrite(2, HIGH);//a //9
    digitalWrite(3, HIGH);//b
    digitalWrite(4, HIGH);//g
    digitalWrite(5, HIGH);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, HIGH);//d
    digitalWrite(8, HIGH);//c
    delay(250);
    digitalWrite(13, HIGH);
    digitalWrite(2, LOW);//a //9
    digitalWrite(3, LOW);//b
    digitalWrite(4, LOW);//g
    digitalWrite(5, LOW);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, LOW);//d
    digitalWrite(8, LOW);//c
    delay(250);
    digitalWrite(13, LOW);
    digitalWrite(2, HIGH);//a //9
    digitalWrite(3, HIGH);//b
    digitalWrite(4, HIGH);//g
    digitalWrite(5, HIGH);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, HIGH);//d
    digitalWrite(8, HIGH);//c
    delay(250);
    digitalWrite(13, HIGH);
    digitalWrite(2, LOW);//a //9
    digitalWrite(3, LOW);//b
    digitalWrite(4, LOW);//g
    digitalWrite(5, LOW);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, LOW);//d
    digitalWrite(8, LOW);//c
    delay(250);
    digitalWrite(13, LOW);
    digitalWrite(2, HIGH);//a //9
    digitalWrite(3, HIGH);//b
    digitalWrite(4, HIGH);//g
    digitalWrite(5, HIGH);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, HIGH);//d
    digitalWrite(8, HIGH);//c
    delay(250);

    digitalWrite(2, LOW);//a //9
    digitalWrite(3, LOW);//b
    digitalWrite(4, LOW);//g
    digitalWrite(5, LOW);//f
    digitalWrite(6, HIGH);//e
    digitalWrite(7, LOW);//d
    digitalWrite(8, LOW);//c
    digitalWrite(13, LOW);
    Switch1 = 9;
    /*
      digitalWrite(2, LOW);//a //9
      digitalWrite(3, LOW);//b
      digitalWrite(4, LOW);//g
      digitalWrite(5, LOW);//f
      digitalWrite(6, HIGH);//e
      digitalWrite(7, LOW);//d
      digitalWrite(8, LOW);//c
    */

  }


  /*
      Serial.println(buttonState);
      Serial.println(buttonState1);
      Serial.println(buttonState2);
    delay(50);
  */


}
