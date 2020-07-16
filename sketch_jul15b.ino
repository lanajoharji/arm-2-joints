// inverse kinematics: 
// given: X, Y, theta, L1, L2
// unknown: alpha1, alpha2
// alpha1 = theta - alpha2
// alpha2 = cos^-1((X^2 + Y^2 - L1^2 - L2^2)/(2 * L1 * L2))
// theta = alpha1 + alpha2


#include <Servo.h>
Servo motor1;
Servo motor2;
int L1 = 20; // length of first part of arm
int L2 = 30; // length of second part of arm
float theta = 70; // end effector's angle in degrees
float X = 29; // end effector's X coordinate
float Y = 35; // end effector's Y coordinate

float alpha1; // first servo rotating angle in degrees
float alpha2; // second servo rotating angle in degrees
float alpha2radian; // second servo rotating angle in radians

void setup() {
  // motor1.attach(3);
  // motor2.attach(4);
  alpha2radian = acos((sq(X) + sq(Y) - sq(L1) - sq(L2))/(2 * L1 * L2));
  alpha2 = alpha2radian / PI * 180;
  alpha1 = theta - alpha2;
  
  Serial.begin(9600);
  Serial.print("The first motor's angle: ");
  Serial.println(alpha1);
  Serial.print("The second motor's angle: ");
  Serial.println(alpha2);
}

void loop() {
  motor1.attach(3);
  motor2.attach(4);
  motor1.write(alpha1); // rotatig the first motor with angle alpha1
  motor2.write(theta); // rotating second motor with angle alpha1+alpha2
}
