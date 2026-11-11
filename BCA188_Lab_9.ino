#include <WiFi.h>
#include <WiFiManager.h>

constexpr unsigned long RESET_HOLD_TIME = 3000;
const char* AP_NAME = "BCA188-ESP32-2024-2015-TESTING";

WiFiManager wm;

unsigned long buttonPressedAt = 0;
bool resetTriggered = false;

void setup() {
  Serial.begin(115200);
  pinMode(BOOT_PIN, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);
  wm.setConfigPortalTimeout(180);

  Serial.println("Connecting to saved Wi-Fi...");
  if (!wm.autoConnect(AP_NAME)) {
    Serial.println("Wi-Fi setup timed out. Restarting...");
    delay(1000);
    ESP.restart();
  }

  Serial.println("Connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Hold BOOT for 3 seconds to clear saved Wi-Fi settings.");
}

void loop() {
  if (digitalRead(BOOT_PIN) == LOW) {
    if (buttonPressedAt == 0) {
      buttonPressedAt = millis();
    } else if (!resetTriggered &&
               millis() - buttonPressedAt >= RESET_HOLD_TIME) {
      resetTriggered = true;
      Serial.println("Clearing saved Wi-Fi settings...");
      wm.resetSettings();
      delay(500);
      ESP.restart();
    }
  } else {
    buttonPressedAt = 0;
    resetTriggered = false;
  }
}