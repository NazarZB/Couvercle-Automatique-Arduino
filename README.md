# **Couvercle poubelle automatique**

Ce projet a été réalisé par @Nazar.ZB et @olgaBD

## **Résultat final :** 

# Branchements 

![Schéma](https://image.noelshack.com/fichiers/2019/05/2/1548778068-shema-bb.png)


# Matériels utilisés 

> - [Arduino Uno](https://store.arduino.cc/arduino-uno-rev3)
> ![Arduino](https://store-cdn.arduino.cc/uni/catalog/product/cache/1/image/520x330/604a3538c15e081937dbfbd20aa60aad/a/0/a000066_featured_1_.jpg)

> - [Capteur de proximité](https://www.generationrobots.com/fr/401575-capteur-sonar-%C3%A0-ultrasons-hc-sr04.html)
> ![HCS04](https://tse4.mm.bing.net/th?id=OIP.CAUvtM78fxMdGrpHJbLJewHaHa&pid=Api)

> - [Servo-Moteur](https://www.amazon.fr/Longruner-Moteur-H%C3%A9licopt%C3%A8re-Bateau-robots/dp/B07236KYVC/ref=sr_1_1?ie=UTF8&qid=1548777698&sr=8-1&keywords=servomoteur+arduino) 
>![Servo-Moteur]( https://images-na.ssl-images-amazon.com/images/I/716vnlbiEeL._SL1000_.jpg)

# Bibliothèques utilisées  

-  Servo 
-  HCSR04

# Code 

On inclut les deux bibliothèques utilisées : 

``` c++
#include <Servo.h>
#include <HCSR04.h>
``` 
On crée l'objet "ServoMotor" puis un objet "distanceSensor" : 

``` c++
Servo servoMotor;
UltraSonicDistanceSensor distanceSensor(RIG_PIN, ECHO_PIN);
```
On initialise la vitesse de transmission ainsi que le servo-moteur :

``` c++
Serial.begin(9600);

servoMotor.attach(SERVO_PIN);
``` 
On récupère la distance entre le capteur et l'obstacle :

``` c++
double distance = distanceSensor.measureDistanceCm();
```

On ajoute une condition pour l'ouverture et la fermeture du moteur : 
 
``` c++
 if(distance < 30 && distance >0) {
  
  for(int i = 0; i < 80; i++) {
    servoMotor.write(i);
    delay(40);
}     
    delay(5000);
    
} else {  
  servoMotor.write(10);
   
}
``` 


