void pingMover() {
  /*
  If things seem safe try moving ahead 200 milliseconds. If we detect
  that the up coming path is not safe, perform the object avoidance routine.
  */
  if (IS_SAFE) {
    moveForward(200);
  }
  else if (!IS_SAFE) {
    avoidObject();
  }
}


void avoidObject() {
  /*
  Simple object avoidance. Backup, turn right and check again.
  */
  moveBackward(650);    // Backup to get away from object
  turnRight(1400);      // Turn right and hope we cleared it.
}
