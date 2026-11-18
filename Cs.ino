#include <KiwisIoT.h>

const char* ssid = "wifi name";              // Replace with your WiFi name
const char* pass = "wifi password";          // Replace with your WiFi password
const char* topic = "dash_1790138701162";    // Replace with your dashboard topic ID

#define CURRENT_PIN A0

KiwisIoT kiwisiot(ssid, pass, topic);

void setup() {
  Serial.begin(115200);
  delay(1000);

  kiwisiot.begin();

  Serial.println();
  Serial.println("Current Sensor Started");
}

void loop() {
  kiwisiot.run();

  // Read current sensor analog value
  int sensorValue = analogRead(CURRENT_PIN);

  Serial.print("Current Sensor Value: ");
  Serial.println(sensorValue);

  // Send data to KiwisIoT Channel 1
  kiwisiot.send("1", sensorValue);

  delay(2000);
}