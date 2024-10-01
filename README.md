
## Elevator Control System with IR Sensors and Seven-Segment Display
This Arduino-based project simulates a two-floor elevator control system. The elevator uses IR sensors to detect the current floor and a single button to switch between floors. A seven-segment display shows the current floor, while a DC motor controls the elevator’s movement.

## Features
IR Sensors for Floor Detection: Detects whether the elevator is at the ground or first floor.
Motorized Elevator Control: Moves the elevator between floors using a DC motor.
Seven-Segment Display: Displays the current floor number (0 for ground, 1 for first floor).
Button-Controlled Floor Selection: A single button toggles between the two floors.
Smooth Elevator Operation: Motor speed and direction are controlled to ensure smooth movement between floors.
## Components
Arduino Uno (or any compatible microcontroller)
DC Motor with driver (e.g., L298N)
IR Sensors (for ground and first floor detection)
Seven-Segment Display (for showing the current floor)
Push Button (to control the floor selection)
Motor Driver Pins: Pins 9 and 8 for direction, and pin 10 for PWM speed control.
IR Sensor Pins: Pins 3 (ground floor) and 2 (first floor).
Seven-Segment Display Pins: Pins 6, 5, A5, 13, 12, 7, 11.
## How It Works
The system starts with the elevator at the ground floor (0).
A button press changes the target floor between 0 and 1.
The motor moves the elevator up or down, depending on the target floor.
When the elevator reaches the correct floor, detected by the IR sensors, it stops.
The current floor is displayed on a seven-segment display using segment patterns.
## Code Explanation
Motor Control: The motor direction is controlled using pins 9 and 8, and its speed is controlled using the PWM pin 10.
Floor Detection: IR sensors connected to pins 2 and 3 detect the elevator’s arrival at each floor.
Button Input: A single button is used to switch the target floor, with debouncing to ensure stable input.
Seven-Segment Display: The display is controlled using predefined segment patterns for the digits 0 and 1, showing the current floor.
## Setup
Install Arduino IDE: If you don't have it already, download and install the Arduino IDE.
Connect Components: Follow the wiring diagram and connect your motor, IR sensors, button, and seven-segment display to the Arduino as described in the code.
Upload the Code: Copy the provided code into the Arduino IDE and upload it to your board.
Test the System: Press the button to move the elevator between the two floors. The seven-segment display will update accordingly.
## Future Improvements
Add more floors by increasing the number of IR sensors and modifying the code.
Implement safety features such as automatic stopping if an obstruction is detected.
Add more informative display elements, such as an LCD to show additional details.
## License
This project is licensed under the MIT License – see the LICENSE file for details.
