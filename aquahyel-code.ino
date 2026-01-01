#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <HX711.h>
#include <Servo.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD Display

//Alerts
#define buzzer  13
#define led 12

//Indicators
#define frontButton1 A3
#define frontButton2 11  
#define leftButton 10
#define rightButton A2

// Load Sensor 
HX711 scale;
#define loadCellClk  A1
#define loadCellDOut A0

//Motor Drivers
#define leftMotorIn1 9
#define leftMotorIn2 8
#define rightMotorIn3 7
#define rightMotorIn4 6

//Conveyor
#define relay 5

//Servo
#define servo 4
Servo paddle;

//Ultrasonic
#define trigger 2
#define echo 3
 
float maxWeight = 100.0;   // maximum weight (g)
float maxDistance = 10.0;  // threshold distance (cm)
 
int turnDuration = 3000;    // ms for a turn
int returnDuration = 10000; // ms for return to start
 
float weight = 0;
float distance = 0;
String status = "Starting";
 
void setup() {
  Serial.begin(9600);
 
  // LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hi! I am AquaHyel");
  delay(600);
 
  // Motors
  pinMode(leftMotorIn1, OUTPUT);
  pinMode(leftMotorIn2, OUTPUT);
  pinMode(rightMotorIn3, OUTPUT);
  pinMode(rightMotorIn4, OUTPUT);
 
  // Buttons
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(frontButton1, INPUT_PULLUP);
  pinMode(frontButton2, INPUT_PULLUP);
 
  // Conveyor relay (Active LOW)
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);  // start OFF
 
  // Alerts
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
  // Load cell
  scale.begin(loadCellDOut, loadCellClk);
  scale.set_scale(420.0);
  scale.tare();
 
  // Servo
  paddle.attach(servo);
  paddle.write(90);
 
  // Ultrasonic
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
 
  forwardMotion();
  lcd.clear();
}
 
void stop() {
  digitalWrite(leftMotorIn1, LOW);
  digitalWrite(leftMotorIn2, LOW);
  digitalWrite(rightMotorIn3, LOW);
  digitalWrite(rightMotorIn4, LOW);
}
 
void forwardMotion() {
  digitalWrite(leftMotorIn1, LOW);
  digitalWrite(leftMotorIn2, HIGH);
  digitalWrite(rightMotorIn3, LOW);
  digitalWrite(rightMotorIn4, HIGH);
}
 
void reverseMotion() {
  digitalWrite(leftMotorIn1, HIGH);
  digitalWrite(leftMotorIn2, LOW);
  digitalWrite(rightMotorIn3, HIGH);
  digitalWrite(rightMotorIn4, LOW);
}
 
void leftMotion() {
  digitalWrite(leftMotorIn1, LOW);
  digitalWrite(leftMotorIn2, HIGH);
  digitalWrite(rightMotorIn3, LOW);
  digitalWrite(rightMotorIn4, LOW);
}
 
void rightMotion() {
  digitalWrite(leftMotorIn1, LOW);
  digitalWrite(leftMotorIn2, LOW);
  digitalWrite(rightMotorIn3, LOW);
  digitalWrite(rightMotorIn4, HIGH);
}
 
void conveyorOn()  { 
  digitalWrite(relay, LOW); 
  }
void conveyorOff() { 
  digitalWrite(relay, HIGH); 
  }
 
void servoDown() {
   paddle.write(0); 
   } // down
void servoUp() { 
  paddle.write(90); 
   } // up
 
float calculateDistance() {
  digitalWrite(trigger, LOW); delayMicroseconds(2);
  digitalWrite(trigger, HIGH); delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  long duration = pulseIn(echo, HIGH, 30000UL);
  if (duration == 0) 
  return -1;
  return duration * 0.034f / 2.0f;
}
 
float calculateWeight() {
  float value = scale.get_units(5);
  if (value < 0) 
  return 0; 
  return value;
}
 
void alertOn()  {
   digitalWrite(led,HIGH); 
   tone(buzzer,1000);
}
void alertOff() {
   digitalWrite(led,LOW);  
   noTone(buzzer);
}
 
void updateLCD(String message, float weight, float distance) {
  lcd.setCursor(0,0);
  lcd.print("W:");
  lcd.print((int)weight);
  lcd.print("g D:");
  lcd.print((int)distance);
  lcd.print("cm  ");
  lcd.setCursor(0,1);
  lcd.print(message);
  lcd.print("            ");
}
 
void loop() {
  
  weight = calculateWeight();
  distance = calculateDistance();
 
  bool plantsAlert = (distance > 0 && distance <= maxDistance);
 
  if (plantsAlert) {
    conveyorOn();
    servoDown();
    status = "Collecting";
  } else {
    conveyorOff();
    servoUp();
    status = "Forward";
  }
 
  if (weight >= maxWeight) {
    stop();
    alertOn();
    updateLCD("MAX LIMIT", weight, distance);
    reverseMotion();
    delay(returnDuration);
    alertOff();
    stop();
    scale.tare();
    status = "Returned";
  }
 
  bool left   = !digitalRead(leftButton);
  bool right  = !digitalRead(rightButton);
  bool front_1 = !digitalRead(frontButton1);
  bool front_2 = !digitalRead(frontButton2);
 
  if (front_1 || front_2) {
    rightMotion();
    status = "Turn Right";
    delay(turnDuration);
  }
  else if (left) {
    rightMotion();
    status = "Turn Right";
    delay(turnDuration);
  }
  else if (right) {
    leftMotion();
    status = "Turn Left";
    delay(turnDuration);
  }
  else {
    forwardMotion(); //default moving direction
  }
  updateLCD(status, weight, distance);
  delay(50); 
}
 