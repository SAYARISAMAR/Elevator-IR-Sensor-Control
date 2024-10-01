#include <Arduino.h>

// Pin definitions
const int buttonPin = 4; // Single button for both floors
const int motorPin1 = 9; // Motor control pin 1
const int motorPin2 = 8; // Motor control pin 2
const int pwmPin = 10;   // PWM pin for motor speed
const int sevenSegmentPins[7] = {6, 5, A5, 13, 12, 7, 11}; // Seven segment display pins

// IR sensor pins
const int irSensorGround = 3; // IR sensor for ground floor
const int irSensorFirst = 2;  // IR sensor for 1st floor

// Seven segment display patterns for digits 0 and 1
const int segmentPatterns[2][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0 (all segments except G)
  {0, 1, 1, 0, 0, 0, 0}  // 1 (segments B and C)
};

int currentFloor = 0; // Start at ground floor (0)
int targetFloor = 0;
bool moving = false; // To track if the elevator is moving

void setup() {
  Serial.begin(9600);

  // Set up button pin
  pinMode(buttonPin, INPUT_PULLUP);

  // Set up motor control pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(pwmPin, OUTPUT);

  // Set up IR sensor pins
  pinMode(irSensorGround, INPUT);
  pinMode(irSensorFirst, INPUT);

  // Set up seven segment display pins
  for (int i = 0; i < 7; i++) {
    pinMode(sevenSegmentPins[i], OUTPUT);
  }

  // Initialize seven segment display to show the current floor
  displayFloor(currentFloor);
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(buttonPin) == 1 && !moving) { // Button pressed (LOW for active low)
    delay(50); // Debounce
    if (digitalRead(buttonPin) == HIGH) { // Check again to confirm it's pressed
      targetFloor = (currentFloor == 0) ? 1 : 0; // Switch target floor
      Serial.print("Button pressed: Going to floor ");
      Serial.println(targetFloor);
      moveElevator();
    }
  }

  // Check IR sensors for floor detection
  if (digitalRead(irSensorGround) == HIGH && moving && targetFloor == 0) {
    currentFloor = 0;
    Serial.println("Reached ground floor");
    stopElevator();
    displayFloor(currentFloor);
  } 
  else if (digitalRead(irSensorFirst) == HIGH && moving && targetFloor == 1) {
    currentFloor = 1;
    Serial.println("Reached first floor");
    stopElevator();
    displayFloor(currentFloor);
  }

  delay(100); // Short delay before the next loop
}

// Function to move the elevator
void moveElevator() {
  moving = true;
  if (targetFloor > currentFloor) {
    // Move up
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    analogWrite(pwmPin, 250);  // Set motor speed

    Serial.println("Moving up...");
  } else {
    // Move down
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    analogWrite(pwmPin, 250);  // Set motor speed

    Serial.println("Moving down...");
  }
}

// Function to stop the elevator
void stopElevator() {
  moving = false;
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(pwmPin, 0); // Stop the motor
  Serial.println("Elevator stopped.");
}

// Function to display the current floor on the seven-segment display
void displayFloor(int floor) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(sevenSegmentPins[i], segmentPatterns[floor][i]);
  }
}
