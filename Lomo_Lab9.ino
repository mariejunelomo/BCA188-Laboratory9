#include <WiFi.h>
#include <WiFiManager.h>

const char* AP_NAME = "BCA188-ESP32-2024-1006"; // The setup network the ESP32 creates.
const int RESET_BUTTON = 0;                     // The BOOT button on the board.
unsigned long pressStart = 0;

void setup() {
  Serial.begin(115200);
  delay(3000);
  pinMode(RESET_BUTTON, INPUT_PULLUP);

  WiFiManager wm;
  wm.setConfigPortalTimeout(180); // Seconds. Restart if nobody completes setup.

  if (!wm.autoConnect(AP_NAME)) {
    Serial.println("Connection failed");
    delay(3000);
    ESP.restart();
  }

  Serial.println("Connected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Hold BOOT for 3 seconds to erase saved Wi-Fi and restart.
  if (digitalRead(RESET_BUTTON) == LOW) {
    if (pressStart == 0) pressStart = millis();
    if (millis() - pressStart >= 3000) {
      Serial.println("Resetting Wi-Fi settings...");
      WiFiManager wm;
      wm.resetSettings();
      delay(1000);
      ESP.restart();
    }
  } else {
    pressStart = 0;
  }

  static unsigned long lastPrint = 0;
  if (millis() - lastPrint >= 5000) {
    lastPrint = millis();
    Serial.print("Connected! IP: ");
    Serial.println(WiFi.localIP());
  }
}