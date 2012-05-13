void turnRight(int moveTime) {
  /*
  Adjust to lower speed for turning, and reset
  to the default when done.
  */
  setMotorSpeed(TURN_SPEED);  
  
  // Start the motors.
  leftSide.run(FORWARD);
  rightSide.run(BACKWARD);
  delay(moveTime);
  
  // Release both motors to stop.
  haltMotors();
  
  // Reset speed to default forward speed.
  setMotorSpeed(MOTOR_SPEED);
}


void moveBackward(int moveTime) {
  /*
  Move both sides backward for 'moveTime' milliseconds
  then release the motors.
  */
  // Start the motors
  leftSide.run(BACKWARD);
  rightSide.run(BACKWARD);
  delay(moveTime);

  // Release both motors to stop
  haltMotors();  
}

void moveForward(int moveTime) {
  /*
  Move both sides forward for 'moveTime' milliseconds
  then release the motors.
  */
  // Start the motors.
  leftSide.run(FORWARD);
  rightSide.run(FORWARD);
  delay(moveTime);

  // Release both motors to stop.
  haltMotors(); 
}


void haltMotors() {
  /*
  Release both motors. This function will be called after each
  call to move a direction.
  */
  leftSide.run(RELEASE);
  rightSide.run(RELEASE);
  delay(RELEASE_DELAY);    // To ensure the motors are not overloaded.
}


void setMotorSpeed(int newSpeed) {
  /*
  This function will set both sides to the speed
  specified by 'newSpeed'
  */
  leftSide.setSpeed(newSpeed);
  rightSide.setSpeed(newSpeed);
}
