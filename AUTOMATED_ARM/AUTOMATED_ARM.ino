#include <Servo.h>

Servo servo[4];  // Array of 4 servos (we're using 1-3)

void servopos(int servo_num, int angle, int servo_delay) {
  servo[servo_num].write(angle);
  delay(servo_delay); // Keep behavior same
}

void setup() {
  // Attach servo pins
  servo[1].attach(8);
  servo[2].attach(9);
  servo[3].attach(10);

  // Set starting positions
  for (int i = 1; i <= 3; i++) {
    servo[i].write(0);
  }

  // Initialize Serial
  Serial.begin(9600);
}

void loop() {
  // Servo movement sequence
  servopos(2, 90, 1000);
  servopos(1, 180, 1000);
  servopos(3, 0, 1000);
  servopos(3, 40, 2000);
  servopos(3, 0, 1000);
  servopos(1, 0, 1000);
  servopos(2, 30, 2000);
}