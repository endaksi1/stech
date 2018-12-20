//https://forum.arduino.cc/index.php?topic=582044.0 Forum Question
//http://forum.arduino.cc/index.php?topic=223286.0 SeveralthingsAtTheSameTime
//https://www.youtube.com/watch?v=fl9S-NQh1kc K Hofstadter supporting video


#include <Servo.h>

#define led 13
#define led2 1 
#define led3 2

// create servo object to control a servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

// variable to store the servo position
int pos1 = 1000;    
int pos2 = 1000;
int pos3 = 1000;
int pos4 = 1000;
int pos5 = 1000;
int pos6 = 1000;


// Time periods of blinks in milliseconds (1000 to a second).
const unsigned long servo1interval = 500;
const unsigned long servo2interval = 100;
const unsigned long servo3interval = 300;
const unsigned long servo4interval = 800;
const unsigned long servo5interval = 1000;
const unsigned long servo6interval = 300;
    




// Variable holding the timer value so far. One for each "Timer"
unsigned long servo1timer;
unsigned long servo2timer;
unsigned long servo3timer;
unsigned long servo4timer;
unsigned long servo5timer;
unsigned long servo6timer;




void setup ()
  {
  servo1.attach(3);  // attaches the servos to the servo objects
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);


      // set the Led pins as output:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  Serial.begin(9600); 
  }  // end of setup

//========================================servo1
void moveServo1 () 
  {

   Serial.print("what goes in the if: ");
   Serial.println(pos1);
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
  // remember when we toggled it
  servo1timer = millis ();
  }


//2========================================servo2
void moveServo2 ()
    {
   Serial.print("what goes in the if: ");
   Serial.println(pos2);
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


//3========================================servo3
void moveServo3 ()
    {
   Serial.print("what goes in the if: ");
   Serial.println(pos3);
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


//4========================================servo4
void moveServo4 ()
    {
   Serial.print("what goes in the if: ");
   Serial.println(pos4);
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


//5========================================servo5
void moveServo5 ()
    {
   Serial.print("what goes in the if: ");
   Serial.println(pos5);
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




//6========================================servo6
void moveServo6 ()
    {
   Serial.print("what goes in the if: ");
   Serial.println(pos6);
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

//========================================

void loop ()
  {


  if ( (millis () - servo1timer) >= servo1interval) 
    moveServo1 (); 

  if ( (millis () - servo2timer) >= servo2interval) 
    moveServo2 (); 

  if ( (millis () - servo3timer) >= servo3interval) 
    moveServo3 (); 

  if ( (millis () - servo4timer) >= servo4interval) 
    moveServo4 (); 

  if ( (millis () - servo5timer) >= servo5interval) 
    moveServo5 (); 

  if ( (millis () - servo6timer) >= servo6interval) 
    moveServo6 (); 


    digitalWrite(led,HIGH);
    delay(5);
    digitalWrite(led,LOW);
    delay(5); 

    digitalWrite(led2,HIGH);
    delay(5);
    digitalWrite(led2,LOW);
    delay(5);    
    
    digitalWrite(led3,HIGH);
    delay(5);
    digitalWrite(led3,LOW);
    delay(5);

/* Other code that needs to execute goes here.
   It will be called many thousand times per second because the above code
   does not wait for the LED blink interval to finish. */

}  // end of loop
