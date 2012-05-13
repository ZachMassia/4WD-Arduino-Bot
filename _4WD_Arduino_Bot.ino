/*
Arduino Robot V1
By: Zachary Massia
*/

// Import the libraries
#include <LiquidCrystal.h>
#include <Ping.h>
#include <AFMotor.h>

// Initialize the libraries
LiquidCrystal lcd(26, 27, 28, 29, 30, 31);
Ping             ping(48,0,0);
AF_DCMotor leftSide(1, MOTOR12_8KHZ);
AF_DCMotor rightSide(2, MOTOR12_8KHZ);
// -------------------------------------------


// Constant Variables
const int PING_DELAY  = 25;   // Delay in ms after taking a Ping reading.
const int SAMPLE_RATE = 3;    // How many readings to take each time we check for objects
const int DANGER_ZONE = 25;   // Distance in CM before stopping robot.
const int MOTOR_SPEED = 245;  // Speed range : 0-255
const int TURN_SPEED  = 200;  // The speed to use for turning.
const int RELEASE_DELAY = 5;  // How long to delay after releases motors.

// Instance Variables
int OBJECT_DISTANCE;          // Stores raw distance from Ping sensor.
boolean IS_SAFE;              // False if within 'DANGER_ZONE'.
// -------------------------------------------


void setup() {
  Serial.begin(115200);
  lcd.begin(16,2);             // Set LCD size + initialize.
  lcd.print("Zach's Robot 1.5");
  
  setMotorSpeed(MOTOR_SPEED);  // Set both motors to default speed.
}


void loop() {
  // Mandatory functions:
  OBJECT_DISTANCE = pingSampler(SAMPLE_RATE);  // Read the distance w/ Ping sensor
  IS_SAFE = checkDistance();                   // Are we in the 'DANGER_ZONE'?
  // --------------------
  
  // Rest of code:
  pingMover();
}
