#include <SoftwareSerial.h>

// Bluetooth module connection
SoftwareSerial bluetooth(0, 1); // RX, TX

// Motor driver connections
const int EN1 = 9;
const int IN1 = 8;
const int IN2 = 7;
const int IN3 = 6;
const int IN4 = 5;
const int EN2 = 3;
int MotorSpeed=90;
const int trigPin = 2;
const int echoPin = 10;

// Variables
long duration;
int distance;
int alertDistance = 7;// 7 cm
char crashavoiderstate='1';
char Command;

// LED connections
const int movingLedPin = 12; // Green LED
const int stoppedLedPin = 13; // Red LED

char lastcommand='S';


void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(movingLedPin, OUTPUT);
  pinMode(stoppedLedPin, OUTPUT);

  stopCar();
  // Ensure the car starts in a stopped state
}

void loop() {

  digitalWrite(trigPin, LOW);         // initializing the distance sensor
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  bluetooth.println(distance);       // for transmitting to bluetooth
  Serial.println(distance);

  

  if (bluetooth.available() > 0) {
     Command = bluetooth.read();  
  }
  if(Command=='1')
{
  crashavoiderstate=Command;
}
 
  switch (Command)  // for motor speeds
  {
    case '2':
         MotorSpeed=90;
         break;
    case '3':
         MotorSpeed=100;
         break;
    case '4':
         MotorSpeed=150;
         break;
  }
  setMotorSpeed(MotorSpeed);

  if(Command=='F'|| Command=='B'|| Command=='L'|| Command=='R'|| Command=='S')
  {
    lastcommand=Command;
  }
  // move car
  
  
    // Update LEDs based on car movement
  if (lastcommand == 'F' || lastcommand == 'B' || lastcommand == 'L' || lastcommand == 'R') {
    digitalWrite(movingLedPin, HIGH);   // Green LED ON
    digitalWrite(stoppedLedPin, LOW);  // Red LED OFF
  } else {
    digitalWrite(movingLedPin, LOW);    // Green LED OFF
    digitalWrite(stoppedLedPin, HIGH);  // Red LED ON
  }



 if(crashavoiderstate=='1' )
 {
  // Check if the distance is within the alert range(less than 18 cm)
  if(distance < 18) {

    stopCar();
    lastcommand='S';
    Command='S';
    crashavoiderstate='0';
  } 
 }
   controlCar(lastcommand);
  // Store the last received command

  delay(100);
}

void controlCar(char speedCommand) {
  switch (speedCommand) {
    case 'F':
      moveForward();
      break;
    case 'B':
      moveBackward();
      break;
    case 'L':
      moveLeft();
      break;
    case 'R':
      moveRight();
      break;
    case 'S':
      stopCar();
  }

}

void setMotorSpeed(int speed) {
  analogWrite(EN1, speed);
  analogWrite(EN2, speed);
}

void moveForward() { 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() { 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moveLeft() { 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveRight() { 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  setMotorSpeed(0); // Set speed to 0
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  digitalWrite(movingLedPin, LOW);    // Green LED OFF
  digitalWrite(stoppedLedPin, HIGH);  // Red LED ON
}

