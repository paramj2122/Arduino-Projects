// Define pins for the ultrasonic sensor
const int trigPin = 7;
const int echoPin = 8;

void setup() {
  Serial.begin(9600);          // Start serial communication at 9600 baud
  pinMode(trigPin, OUTPUT);     // Set the trigger pin as an output
  pinMode(echoPin, INPUT);      // Set the echo pin as an input
}

void loop() {
  // Clear the trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by setting the trigPin high for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the time in microseconds from the echoPin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance (no intermediate formula needed)
  long distance = duration / 29 / 2;
  int waterlevel=15-distance;
  //here 15cm is distance of our container

  // Print the distance in the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(waterlevel);
  Serial.println(" cm");

  delay(1000); // Short delay for readability
}
