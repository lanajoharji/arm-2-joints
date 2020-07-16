// forward kinematics: 
// given: alpha1, alpha2, L1, L2
// unknown: X, Y, theta
// X = L1 cos(alpha1) + L2 cos(theta)
// Y = L1 sin(alpha1) + L2 sin(theta)
// theta = alpha1 + alpha2


#include <Servo.h>
Servo motor1;
Servo motor2;
int L1 = 20; // length of first part of arm
int L2 = 30; // length of second part of arm
float alpha1 = 20; // first servo rotating angle in degrees
float alpha2 = 50; // second servo rotating angle in degrees
float theta = alpha1 + alpha2;

float alpha1radian; // first servo rotating angle in radians
float alpha2radian; // second servo rotating angle in radians

float thetaradian; // end effector angle in radians
float X; // end effector's X coordinate
float Y; // end effector's Y coordinate

void setup() {
  motor1.attach(3);
  motor2.attach(4);
  alpha1radian = alpha1 * PI / 180; // converting to radians
  alpha2radian = alpha2 * PI / 180; // converting to radians
  thetaradian = alpha1radian + alpha2radian;
  X = (L1 * cos(alpha1radian)) + (L2 * cos(thetaradian));
  Y = (L1 * sin(alpha1radian)) + (L2 * sin(thetaradian));
  Serial.begin(9600);
  Serial.print("X: ");
  Serial.println(X,DEC);
  Serial.print("Y: ");
  Serial.println(Y,DEC);
}

void loop() {
  motor1.write(alpha1); // rotatig the first motor with angle alpha1
  motor2.write(theta); // rotating second motor with angle alpha1+alpha2
}
