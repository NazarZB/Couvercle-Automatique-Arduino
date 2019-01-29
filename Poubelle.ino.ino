#include <Servo.h>
#include <HCSR04.h>

Servo servoMotor;
UltraSonicDistanceSensor distanceSensor(7, 8);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

servoMotor.attach(6);

}

void loop() {
  // put your main code here, to run repeatedly:

  double distance = distanceSensor.measureDistanceCm();

Serial.println(distance);


if(distance < 30) {

  servoMotor.write(100);
    
} else {
  servoMotor.write(10);

}
}
