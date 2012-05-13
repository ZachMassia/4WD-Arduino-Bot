boolean checkDistance() {
  /*
  Check to see if we are going to hit something.
  */
  if (OBJECT_DISTANCE <= DANGER_ZONE) {
    // We're going to hit something.
    return false;
  } 
  else if (OBJECT_DISTANCE > DANGER_ZONE) {
    // Let's assume it's safe.
    return true;
  }
}


int pingSampler(int resolution) {
  /*
  Read the distance from the Ping sensor 'resolution' times, add
  all the values and find the average. This will produce a more
  accurate reading of the distance.
  */
  int avgValue;               // This will be used to return the sampled value.
  int totalValue;             // This will hold all the readings.
  
  // Loop through each reading and assign to array
  for (int i=0; i < resolution; i++) {
    ping.fire();                       // Send a pulse to the Ping.
    totalValue += ping.centimeters();  // Add the CM value to the total.
    delay(PING_DELAY);                 // Wait so the sensor is not overloaded. 
  }
  
  avgValue = ( totalValue / resolution );  // Get the average value.
  return avgValue;
}

int getObjectDistance() {
  /*
  !! Use pingSampler
  This function will fire off a single ping reading, but it is
  not as accurate, only use if a quick one of reading is needed.
  
  Fire off the Ping Ultrasonic Sensor, return
  the distance in CM
  */
  ping.fire();        // Fire the ping  
  int pingVal = ping.centimeters();  // Store the distance.
  delay(PING_DELAY);  // Wait so we don't overload the sensor
  return pingVal;     // Return the distance.
}






