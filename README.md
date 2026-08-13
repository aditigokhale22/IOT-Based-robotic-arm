# IOT-Based-robotic-arm
Embedded C program for an IoT-based robotic arm using a microcontroller, servo motors, and sensors. The program controls arm movements and supports wireless operation for basic automation and pick-and-place tasks.
3. Components Used:
ESP8266 NodeMCU
6 Servo Motors
Robotic Arm Mechanical Structure
Power Supply
Connecting Wires
Wi-Fi / Mobile Hotspot

4. Technologies Used:
Embedded C/C++
Arduino IDE
ESP8266
HTML
Wi-Fi / IoT

5. Working:
ESP8266 creates/connects to a Wi-Fi network.
A web server runs on the ESP8266.
A web page provides sliders for controlling the six servo motors.
The user changes the slider position.
The ESP8266 receives the control command.
The corresponding servo motor moves to the selected angle.
Six servo motors together control the robotic arm.
6. Features
Wireless control of robotic arm
Six servo motor control
Web-based control interface
Real-time servo angle adjustment
ESP8266-based IoT implementation
Simple and user-friendly interface

7. Software:
Arduino IDE is used to program the ESP8266.

Main libraries used:
ESP8266WiFi.h
ESP8266WebServer.h
Servo.h
8. How to Run
Install Arduino IDE.
Install ESP8266 board support.
Install the required libraries.
Open robotic_arm.ino.
Enter your Wi-Fi credentials.
Connect the ESP8266 to the computer.
Select the correct ESP8266 board and COM port.
Upload the program.
Connect to the ESP8266 web interface.
Use the sliders to control the robotic arm.
9. Project Status

Completed / Working Prototype
