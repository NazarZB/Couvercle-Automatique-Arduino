#include <Servo.h>
#include <HCSR04.h>

Servo servoMotor;
UltraSonicDistanceSensor distanceSensor(7, 8);


void setup() {
  

Serial.begin(9600);
servoMotor.attach(6);

}

void loop() {
 

  double distance = distanceSensor.measureDistanceCm();

//Serial.println(distance);


 if(distance < 30 && distance >0) {
  
  for(int i = 10; i < 80; i++) {
    servoMotor.write(i);
    delay(35);
}     
    delay(5000);
    
} else {  
  servoMotor.write(10);
   
}
  
   
    
}
