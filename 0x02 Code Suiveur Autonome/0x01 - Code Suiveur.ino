#include <Ultrasonic.h>

// Motor control pins
#define enA 2
#define in1 3
#define in2 4
#define enB 7
#define in3 5
#define in4 6

// Line sensor pins
#define sensor1 31
#define sensor2 33
#define sensor3 35
#define sensor4 37
#define sensor5 39


int val1, val2, val3, val4, val5;
// Ultrasonic sensor pins for front and left
Ultrasonic ultrasonicFront(44, 46); // Front ultrasonic sensor
Ultrasonic ultrasonicLeft(45, 47); // Left ultrasonic sensor

void setup() {
  // Initialize motor, sensor, and serial pins as per your setup
  Serial.begin(9600);
}
int Readleft() {
  return ultrasonicLeft.read();
}
bool useRightAlgorithm = false; // Flag to switch between left and right line following
bool useLeftUltrasonic = false; // Flag to control the use of the left ultrasonic sensor
bool obstacleDetected = false;

void loop() {
  int distanceFront = ultrasonicFront.read();
  int distanceLeft = -1; // Initialize with an invalid distance

  // Read from the front ultrasonic sensor
  if (distanceFront < 21 && distanceFront > 2) {
    if (!obstacleDetected) {
      // Detected obstacle for the first time
      stopMotors();
      delay(300);
      turnLeft();
      delay(500);
      goForward();
      delay(400);
      obstacleDetected = true;
      useLeftUltrasonic = true; // Activate left ultrasonic sensor after front obstacle maneuver
    } else {
      if (distanceFront < 7 && distanceFront > 0) {
        // Detected obstacle again after previous maneuver
        stopMotors();
        delay(5000); // Stop for 5 seconds
        goF();
        delay(2500);
      }
    }
  }

  // Conditional reading from the left ultrasonic sensor based on the flag
  if (useLeftUltrasonic) {
    distanceLeft = ultrasonicLeft.read();
    if (Readleft() < 15 && Readleft() > 5) {
      // Detected obstacle on the left, stop and switch to the right algorithm
      stopMotors();
      delay(3000);
      goForward(); // Proceed forward after stopping
      delay(1000);
      useRightAlgorithm = true; // Switch to right line following algorithm
      useLeftUltrasonic = false; // Optionally deactivate left ultrasonic if not needed
    }
  }

  // Line following logic based on the algorithm flag
  if (useRightAlgorithm) {
    lineFollowingright(); // Use the right line following algorithm
  } else {
    lineFollowingleft(); // Use the left line following algorithm
  }
}


// Include the rest of your functions (sped, turnLeft, stopMotors, goForward, capteur) here without modification
void turnLeft() {
  //sped(0, 100); // Adjust the speed values as needed for your robot to turn left
  // Adjust delay for the duration of the turn
  analogWrite(enA, 90);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  analogWrite(enB, 90);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopMotors() {
  sped(0, 0); // Stop both motors
}

void goForward() {
  sped(110, 110); // Adjust speed to go forward
  //delay(1000); // Adjust delay to move forward for a moment
}

void goF() {
  sped(150, 150); // Adjust speed to go forward
  //delay(1000); // Adjust delay to move forward for a moment
}

void lineFollowingleft() {
  // Your line following logic here
  capteur(); // Reads the line sensor values

  // Based on the sensor values, adjust the motor speeds
  if (val1 == LOW) {
    sped(0, 80);
    delay(300);
  } else if (val2 == LOW) {
    sped(90, 100);
  } else if (val5 == LOW) {
    sped(80, 0);
  } else if (val4 == LOW) {
    sped(100, 90);
  } else if (val3 == LOW) {
    sped(110, 110);
  }
}

void lineFollowingright() {
  // Your line following logic here
  capteur(); // Reads the line sensor values

  // Based on the sensor values, adjust the motor speeds
  if (val5 == LOW && val4 == LOW && val3 == LOW && val1 == HIGH ) {
    sped(90, 0);
    delay(300);
  } else if (val5 == LOW && val4 == LOW && val3 == LOW && val2 == LOW) {
    sped(0, 90);
    delay(1000);
    sped(90, 0);
    delay(1000);
  } else if (val5 == LOW) {
    sped(80, 0);
    delay(300);
  } else if (val4 == LOW) {
    sped(100, 90);
  } else if (val1 == LOW) {
    sped(0, 80);
  } else if (val2 == LOW) {
    sped(90, 100);
  } else if (val3 == LOW) {
    sped(110, 110);
  }
}
void capteur() {
  val1 = digitalRead(sensor1);
  val2 = digitalRead(sensor2);
  val3 = digitalRead(sensor3);
  val4 = digitalRead(sensor4);
  val5 = digitalRead(sensor5);

  Serial.print("val1: ");
  Serial.print(val1);
  Serial.print("\tval2: ");
  Serial.print(val2);
  Serial.print("\tval3: ");
  Serial.print(val3);
  Serial.print("\tval4: ");
  Serial.print(val4);
  Serial.print("\tval5: ");
  Serial.println(val5);
}

void sped(int spedA, int spedB) {
  analogWrite(enA, spedA);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(enB, spedB);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
