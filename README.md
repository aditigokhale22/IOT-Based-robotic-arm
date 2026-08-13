# IOT-Based-robotic-arm
Embedded C program for an IoT-based robotic arm using a microcontroller, servo motors, and sensors. The program controls arm movements and supports wireless operation for basic automation and pick-and-place tasks.

## 🔧 Components Used

- ESP8266 NodeMCU
- 6 Servo Motors
- Robotic Arm Mechanical Structure
- Power Supply
- Connecting Wires
- Wi-Fi / Mobile Hotspot

## 💻 Technologies Used

- Embedded C/C++
- Arduino IDE
- ESP8266
- HTML
- Wi-Fi / IoT

## ⚙️ Working

1. ESP8266 connects to a Wi-Fi network.
2. A web server runs on the ESP8266.
3. A web page provides six sliders for controlling the servo motors.
4. The user changes the slider position.
5. ESP8266 receives the control command.
6. The corresponding servo motor moves to the selected angle.
7. Six servo motors together control the robotic arm.

## ✨ Features

- Wireless control of robotic arm
- Six servo motor control
- Web-based control interface
- Real-time servo angle adjustment
- ESP8266-based IoT implementation
- Simple and user-friendly interface

## 🛠️ Software

Arduino IDE is used to program the ESP8266.

### Main Libraries Used

- `ESP8266WiFi.h`
- `ESP8266WebServer.h`
- `Servo.h`

## 🚀 How to Run

1. Install Arduino IDE.
2. Install ESP8266 board support.
3. Install the required libraries.
4. Open `robotic_arm.ino`.
5. Enter your Wi-Fi credentials.
6. Connect the ESP8266 to the computer.
7. Select the correct ESP8266 board and COM port.
8. Upload the program.
9. Connect to the ESP8266 web interface.
10. Use the sliders to control the robotic arm.

## 📷 Project Images

Project images can be added here.

## 📌 Project Status

**Completed / Working Prototype**

