
//Original sketch sourced from Trollmaker.com

#define trigPin 13
#define echoPin 12
#define led 11 // Red
#define led2 10 // Green
#define led3 9 // Yellow
const int val00 = A0;  // pot 01
const int val01 = A1;  // pot 02
const int val02 = A2;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;


  if (distance < 5) {       // Red
    digitalWrite(led,HIGH); 
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    
}

else if (distance > 200) {  // Yellow
    digitalWrite(led3,HIGH); 
    digitalWrite(led2,LOW);
    digitalWrite(led,LOW);
}

  else {                   // Green
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);

    
  }
    if (distance >= 200 || distance <= 0){
    Serial.print("201");
    Serial.print(",");
    Serial.print(analogRead(val01));
    Serial.print(",");
    Serial.print(analogRead(val00));
    Serial.print(",");
    Serial.println(analogRead(val02));
    
  }
  else {
    Serial.print(distance);
    Serial.print(",");
    Serial.print(analogRead(val01));
    Serial.print(",");
    Serial.print(analogRead(val00));
    Serial.print(",");
    Serial.println(analogRead(val02));
  }
  delay(50);
}
