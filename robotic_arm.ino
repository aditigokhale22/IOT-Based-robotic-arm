#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

const char* ssid = "robotic";        // 🔹 Your Wi-Fi or Hotspot name
const char* password = "12345678"; // 🔹 Your password

ESP8266WebServer server(80);

// Create 6 Servo objects
Servo s1, s2, s3, s4, s5, s6;

// Servo angles
int angle1 = 0, angle2 = 0, angle3 = 0, angle4 = 0, angle5 = 0, angle6 = 0;

// HTML page with 6 sliders
const char HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>6 Servo Control</title>
  <style>
    body { font-family: Arial; text-align: center; margin-top: 40px; }
    input[type=range] { width: 80%; }
    .servo-block { margin: 20px; }
  </style>
</head>
<body>
  <h2>ESP8266 - 6 Servo Web Control</h2>

  <div class="servo-block">
    <h3>Servo 1 (D1)</h3>
    <input type="range" min="0" max="180" value="0" id="servo1"
     oninput="document.getElementById('val1').innerText=this.value;
     fetch('/set?servo=1&angle='+this.value)">
    <p>Angle: <span id="val1">0</span>°</p>
  </div>

  <div class="servo-block">
    <h3>Servo 2 (D2)</h3>
    <input type="range" min="0" max="180" value="0" id="servo2"
     oninput="document.getElementById('val2').innerText=this.value;
     fetch('/set?servo=2&angle='+this.value)">
    <p>Angle: <span id="val2">0</span>°</p>
  </div>

  <div class="servo-block">
    <h3>Servo 3 (D5)</h3>
    <input type="range" min="0" max="180" value="0" id="servo3"
     oninput="document.getElementById('val3').innerText=this.value;
     fetch('/set?servo=3&angle='+this.value)">
    <p>Angle: <span id="val3">0</span>°</p>
  </div>

  <div class="servo-block">
    <h3>Servo 4 (D6)</h3>
    <input type="range" min="0" max="180" value="0" id="servo4"
     oninput="document.getElementById('val4').innerText=this.value;
     fetch('/set?servo=4&angle='+this.value)">
    <p>Angle: <span id="val4">0</span>°</p>
  </div>

  <div class="servo-block">
    <h3>Servo 5 (D7)</h3>
    <input type="range" min="0" max="180" value="0" id="servo5"
     oninput="document.getElementById('val5').innerText=this.value;
     fetch('/set?servo=5&angle='+this.value)">
    <p>Angle: <span id="val5">0</span>°</p>
  </div>

  <div class="servo-block">
    <h3>Servo 6 (D8, limited 0–40°)</h3>
    <input type="range" min="0" max="40" value="0" id="servo6"
     oninput="document.getElementById('val6').innerText=this.value;
     fetch('/set?servo=6&angle='+this.value)">
    <p>Angle: <span id="val6">0</span>°</p>
  </div>

</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", HTML);
}

void handleSet() {
  if (server.hasArg("servo") && server.hasArg("angle")) {
    int servoNum = server.arg("servo").toInt();
    int angle = server.arg("angle").toInt();

    // Limit Servo 6 to 0–40°
    if (servoNum == 6) {
      angle = constrain(angle, 0, 40);
    } else {
      angle = constrain(angle, 0, 180);
    }

    switch (servoNum) {
      case 1:
        angle1 = angle;
        s1.write(angle);
        Serial.printf("Servo 1 -> %d°\n", angle);
        break;
      case 2:
        angle2 = angle;
        s2.write(angle);
        Serial.printf("Servo 2 -> %d°\n", angle);
        break;
      case 3:
        angle3 = angle;
        s3.write(angle);
        Serial.printf("Servo 3 -> %d°\n", angle);
        break;
      case 4:
        angle4 = angle;
        s4.write(angle);
        Serial.printf("Servo 4 -> %d°\n", angle);
        break;
      case 5:
        angle5 = angle;
        s5.write(angle);
        Serial.printf("Servo 5 -> %d°\n", angle);
        break;
      case 6:
        angle6 = angle;
        s6.write(angle);
        Serial.printf("Servo 6 -> %d° (limited)\n", angle);
        break;
      default:
        server.send(400, "text/plain", "Invalid servo number");
        return;
    }

    server.send(200, "text/plain", "OK");
  } else {
    server.send(400, "text/plain", "Invalid parameters");
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("\nStarting 6-servo Wi-Fi control...");

  // Attach servos to pins
  s1.attach(D1, 500, 2500);  // GPIO5
  s2.attach(D2, 500, 2500);  // GPIO4
  s3.attach(D5, 500, 2500);  // GPIO14
  s4.attach(D6, 500, 2500);  // GPIO12
  s5.attach(D7, 500, 2500);  // GPIO13
  s6.attach(D8, 500, 2500);  // GPIO15 - limited servo

  // Initialize all servos at 0°
  s1.write(0);
  s2.write(0);
  s3.write(0);
  s4.write(0);
  s5.write(0);
  s6.write(0);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  // Start server
  server.on("/", handleRoot);
  server.on("/set", handleSet);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
