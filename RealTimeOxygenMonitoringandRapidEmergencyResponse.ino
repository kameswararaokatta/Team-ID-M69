int pressureSensorPin = A0; // Analog pin connected to the pressure sensor
int greenLEDPin = 13; // Digital pin connected to the green LED
int redLEDPin = 12; // Digital pin connected to the red LED
int buzzerPin = 11; // Digital pin connected to the buzzer

void setup() {
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  int sensorValue = analogRead(pressureSensorPin); // Read the analog value from the sensor
  float voltage = sensorValue * (5.0 / 1023.0); // Convert the analog value to voltage (for a 5V system)
  float pressurePercentage = (voltage / 1.2) * 100; // Convert voltage to pressure percentage assuming 1.2V represents 100% pressure

  // Print the pressure percentage to the serial monitor for debugging
  Serial.print("Pressure Percentage: ");
  Serial.print(pressurePercentage);
  Serial.println("%");

  if (pressurePercentage < 20) { // If pressure is less than 20%
    digitalWrite(redLEDPin, HIGH); // Turn on the red LED
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    digitalWrite(greenLEDPin, LOW); // Turn off the green LED
  } else { // If pressure is 20% or greater
    digitalWrite(redLEDPin, LOW); // Turn off the red LED
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    digitalWrite(greenLEDPin, HIGH); // Turn on the green LED
  }

  delay(1000); // Wait for 1 second before the next reading
}