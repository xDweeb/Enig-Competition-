#include <SoftwareSerial.h>
SoftwareSerial BT(A0, A1); // RX, TX

int ENAF = 3, IN1FL = 2, IN2FL = 4, IN3FR = 5, IN4FR = 7, ENBF = 6;
int ENAB = 9, IN1BR = 8, IN2BR = 10, IN3BL = 12, IN4BL = 13, ENBB = 11;

char val;
char m = 'w';
char t = 'u';
void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  // pins front motors
  pinMode(ENAF, OUTPUT);
  pinMode(ENAF, OUTPUT);
  pinMode(IN1FL, OUTPUT);
  pinMode(IN2FL, OUTPUT);
  pinMode(IN3FR, OUTPUT);
  pinMode(IN4FR, OUTPUT);
  // pins back motors
  pinMode(ENAB, OUTPUT);
  pinMode(ENBB, OUTPUT);
  pinMode(IN1BR, OUTPUT);
  pinMode(IN2BR, OUTPUT);
  pinMode(IN3BL, OUTPUT);
  pinMode(IN4BL, OUTPUT);
}
//#############Functions##############//
int f(int enaf, int enbf, int enab, int enbb) {
  digitalWrite(IN1FL, 1);
  digitalWrite(IN2FL, 0);
  digitalWrite(IN3FR, 0);
  digitalWrite(IN4FR, 1);
  analogWrite(ENAF, enaf);
  analogWrite(ENBF, enbf );
  digitalWrite(IN1BR, 0);
  digitalWrite(IN2BR, 1);
  digitalWrite(IN3BL, 1);
  digitalWrite(IN4BL, 0);
  analogWrite(ENAB, enab);
  analogWrite(ENBB, enbb );
}
int b(int enaf, int enbf, int enab, int enbb) {
  digitalWrite(IN1FL, 0);
  digitalWrite(IN2FL, 1);
  digitalWrite(IN3FR, 1);
  digitalWrite(IN4FR, 0);
  analogWrite(ENAF, enaf);
  analogWrite(ENBF, enbf );
  digitalWrite(IN1BR, 1);
  digitalWrite(IN2BR, 0);
  digitalWrite(IN3BL, 0);
  digitalWrite(IN4BL, 1);
  analogWrite(ENAB, enab);
  analogWrite(ENBB, enbb );
}
int r(int enaf, int enbf, int enab, int enbb) {
  digitalWrite(IN1FL, 1);
  digitalWrite(IN2FL, 0);
  digitalWrite(IN3FR, 1);
  digitalWrite(IN4FR, 0);
  analogWrite(ENAF, enaf);
  analogWrite(ENBF, enbf );
  digitalWrite(IN1BR, 1);
  digitalWrite(IN2BR, 0);
  digitalWrite(IN3BL, 1);
  digitalWrite(IN4BL, 0);
  analogWrite(ENAB, enab);
  analogWrite(ENBB, enbb );
}
int frk(int enaf, int enbf, int enab, int enbb) {
  digitalWrite(IN1FL, 1);
  digitalWrite(IN2FL, 0);
  digitalWrite(IN3FR, 0);
  digitalWrite(IN4FR, 0);
  analogWrite(ENAF, enaf);
  analogWrite(ENBF, enbf );
  digitalWrite(IN1BR, 0);
  digitalWrite(IN2BR, 0);
  digitalWrite(IN3BL, 1);
  digitalWrite(IN4BL, 0);
  analogWrite(ENAB, enab);
  analogWrite(ENBB, enbb );
}
int l(int enaf, int enbf, int enab, int enbb) {
  digitalWrite(IN1FL, 0);
  digitalWrite(IN2FL, 1);
  digitalWrite(IN3FR, 0);
  digitalWrite(IN4FR, 1);
  analogWrite(ENAF, enaf);
  analogWrite(ENBF, enbf );
  digitalWrite(IN1BR, 0);
  digitalWrite(IN2BR, 1);
  digitalWrite(IN3BL, 0);
  digitalWrite(IN4BL, 1);
  analogWrite(ENAB, enab);
  analogWrite(ENBB, enbb );
}
int flk(int enaf, int enbf, int enab, int enbb) {
  digitalWrite(IN1FL, 0);
  digitalWrite(IN2FL, 0);
  digitalWrite(IN3FR, 0);
  digitalWrite(IN4FR, 1);
  analogWrite(ENAF, enaf);
  analogWrite(ENBF, enbf );
  digitalWrite(IN1BR, 0);
  digitalWrite(IN2BR, 1);
  digitalWrite(IN3BL, 0);
  digitalWrite(IN4BL, 0);
  analogWrite(ENAB, enab);
  analogWrite(ENBB, enbb );
}
void s() {
  digitalWrite(IN1FL, 0);
  digitalWrite(IN2FL, 0);
  digitalWrite(IN3FR, 0);
  digitalWrite(IN4FR, 0);
  analogWrite(ENAF, 0);
  analogWrite(ENBF, 0 );
  digitalWrite(IN1BR, 0);
  digitalWrite(IN2BR, 0);
  digitalWrite(IN3BL, 0);
  digitalWrite(IN4BL, 0);
  analogWrite(ENAB, 0);
  analogWrite(ENBB, 0 );
}
//#############Main#################//
void loop() {
  if (BT.available()) {
    val = BT.read();
    Serial.println(val);
    switch (val) {
      case 'F':
        if (m == 'W') {
          //tourner(255, 255);
        } else if (t == 'U') {
          //tourner(255, 255);
        } else {
          f(200, 200, 200, 200);
        }

        break;
      case 'B':
        if (m == 'W') {
          //bakni(255, 255);
        } else if (t == 'U') {
          //bakni(255, 255);
        } else { //45
          b(200, 200, 200, 200);
        }

        break;
      case 'L':
        if (m == 'W') {
          //v2 < 180 ? v2+=5 : v2 = 180;
          //tourD();
        } else if (t == 'U') {
          //tourD();
        } else { //15
          l(200, 200, 200, 200);
        }

        break;
      case 'R':
        if (m == 'W') {
          //tourG();
        } else if (t == 'U') {
          //tourG();
        } else { //60
          r(200, 200, 200, 200);
        }

        break;
      case 'G':
        if (m == 'W') {
          //v2 < 180 ? v2+=5 : v2 = 180;
          //tourner(255, 50);
        } else if (t == 'U') {
          //tourner(255, 50);
        } else { //15
          flk(200, 200, 200, 200);
        }
        break;
      case 'I':
        if (m == 'W') {
          //v2 < 180 ? v2+=5 : v2 = 180;
          //tourner(50, 255);
        } else if (t == 'U') {
          //tourner(50, 255);
        } else { //15
          frk(200, 200, 200, 200);
        }

        break;
      //      case 'H':
      //        bakni(255, 90);
      //        break;
      //      case 'J':
      //        bakni(90, 255);
      //        break;
      //      case 'S':
      //        stopper();
      //        break;
      //      case 'w':
      //        m = 'w';
      //        break;
      //      case 'W':
      //        m = 'W';
      //        break;
      //      case 'u':
      //        t = 'u';
      //        break;
      //      case 'U':
      //        t = 'U';
      //        break;
      default:
        s();
    }
  }

}
