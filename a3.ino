


#include <Servo.h>

//#define trigPin4 0
//#define echoPin4 1
#define trigPin1 2
#define echoPin1 4
#define trigPin2 7
#define echoPin2 8
#define trigPin3 12
#define echoPin3 13

const int val00 = A0;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int pos1 = 1000;
int pos2 = 1000;
int pos3 = 1000;
int pos4 = 1000;
int pos5 = 1000;
int pos6 = 1000;

//===========Servo_1_Intervals=============
const unsigned long servo1interval_a = 500;
const unsigned long servo1interval_b = 250;

//===========Servo_2_Intervals=============
const unsigned long servo2interval_a = 500;
const unsigned long servo2interval_b = 250;

//===========Servo_3_Intervals=============
const unsigned long servo3interval_a = 500;
const unsigned long servo3interval_b = 250;

//===========Servo_4_Intervals=============
const unsigned long servo4interval_a = 500;
const unsigned long servo4interval_b = 250;

//===========Servo_5_Intervals=============
const unsigned long servo5interval_a = 500;
const unsigned long servo5interval_b = 250;

//===========Servo_6_Intervals=============
const unsigned long servo6interval_a = 500;
const unsigned long servo6interval_b = 250;


//=====Servo_timers======
unsigned long servo1timer;
unsigned long servo2timer;
unsigned long servo3timer;
unsigned long servo4timer;
unsigned long servo5timer;
unsigned long servo6timer;


//===========VOID_SETUP==================
//=======================================

void setup() {

  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);
  
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  //pinMode(trigPin4, OUTPUT);
  //pinMode(echoPin4, INPUT);

}

//==============moveServo1====================
void moveServo1 () {
   if (pos1 <= 1000)
      {
        pos1 = 2000;
        servo1.writeMicroseconds(pos1);
        }
   else
      {
        pos1 = 1000;
        servo1.writeMicroseconds(pos1);
        }
  
  servo1timer = millis ();
  }

//==============moveServo2====================
  void moveServo2 () {
   if (pos2 <= 1000)
      {
        pos2 = 2000;
        servo2.writeMicroseconds(pos2);
        }
   else
      {
        pos2 = 1000;
        servo2.writeMicroseconds(pos2);
        }
 
  servo2timer = millis ();
  }

//==============moveServo3====================
  void moveServo3 () {
   if (pos3 <= 1000)
      {
        pos3 = 2000;
        servo3.writeMicroseconds(pos3);
        }
   else
      {
        pos3 = 1000;
        servo3.writeMicroseconds(pos3);
        }

  servo3timer = millis ();
  }

//==============moveServo4====================
  void moveServo4 () {
   if (pos4 <= 1000)
      {
        pos4 = 2000;
        servo4.writeMicroseconds(pos4);
        }
   else
      {
        pos4 = 1000;
        servo4.writeMicroseconds(pos4);
        }
  
  servo4timer = millis ();
  }

//==============moveServo5====================
  void moveServo5 () {
   if (pos5 <= 1000)
      {
        pos5 = 2000;
        servo5.writeMicroseconds(pos5);
        }
   else
      {
        pos5 = 1000;
        servo5.writeMicroseconds(pos5);
        }
   
  servo5timer = millis ();
  }

//==============moveServo6====================
  void moveServo6 () {
   if (pos6 <= 1000)
      {
        pos6 = 2000;
        servo6.writeMicroseconds(pos6);
        }
   else
      {
        pos6 = 1000;
        servo6.writeMicroseconds(pos6);
        }
   
  servo6timer = millis ();
  }        
  

//=================VOID_LOOP=======================
//=================================================

void loop() {

//========Sensor_1========  
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;


//========Sensor_2======== 
    long duration2, distance2;
  digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;

  
//========Sensor_3======== 
    long duration3, distance3;
  digitalWrite(trigPin3, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3/2) / 29.1;
 

//========Sensor_4========   
//    long duration4, distance4;
//  digitalWrite(trigPin4, LOW);  
//  delayMicroseconds(2); 
//  digitalWrite(trigPin4, HIGH);
//  delayMicroseconds(10); 
// digitalWrite(trigPin4, LOW);
//  duration4 = pulseIn(echoPin4, HIGH);
//  distance4 = (duration4/2) / 29.1;
  

//==============Servos_1_and_2_controlled_by_Sensor_1====================
//======Servo1

if (distance1 >= 30){
 if ( (millis () - servo1timer) >= servo1interval_a) 
    moveServo1 ();
}
 
else {
 if ( (millis () - servo1timer) >= servo1interval_b) 
    moveServo1 ();
  }   

//======Servo2

if (distance1 >= 30){
 if ( (millis () - servo2timer) >= servo2interval_a) 
    moveServo2 ();
}
 
else {
 if ( (millis () - servo2timer) >= servo2interval_b) 
    moveServo2 ();
  } 



//==============Servos_3_and_4_controlled_by_Sensor_2====================
//======Servo3

if (distance2 >= 30){
 if ( (millis () - servo3timer) >= servo3interval_a) 
    moveServo3 ();
}
 
else {
 if ( (millis () - servo3timer) >= servo3interval_b) 
    moveServo3 ();
  }    

//======Servo4

if (distance2 >= 30){
 if ( (millis () - servo4timer) >= servo4interval_a) 
    moveServo4 ();
}
 
else {
 if ( (millis () - servo4timer) >= servo4interval_b) 
    moveServo4 ();
  }  



//==============Servos_5_and_6_controlled_by_Sensor_3====================
//======Servo5

if (distance3 >= 30){
 if ( (millis () - servo5timer) >= servo5interval_a) 
    moveServo5 ();
}
 
else {
 if ( (millis () - servo5timer) >= servo5interval_b) 
    moveServo5 ();
  }    

//======Servo6

if (distance3 >= 30){
 if ( (millis () - servo6timer) >= servo6interval_a) 
    moveServo6 ();
}
 
else {
 if ( (millis () - servo6timer) >= servo6interval_b) 
    moveServo6 ();
  } 


    
    Serial.print(distance1);
    Serial.print(",");
    Serial.print(distance2);
    Serial.print(",");
    Serial.print(distance3);
    Serial.print(",");
    Serial.println(analogRead(val00));

  delay(250);
}
