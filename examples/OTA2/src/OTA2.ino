#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char* ssid = "LASSE";
const char* password = "lassesemfio";
const int ledPin = 13;

void setupOTA() {
    // Port defaults to 8266
    // ArduinoOTA.setPort(8266);

    // Hostname defaults to esp8266-[ChipID]
    // ArduinoOTA.setHostname("myesp8266");

    // No authentication by default
    // ArduinoOTA.setPassword((const char *)"123");

    ArduinoOTA.onStart([]() {
      Serial.println("Start");
    });
    ArduinoOTA.onEnd([]() {
      Serial.println("\nEnd");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });
    ArduinoOTA.begin();
}

void setupwifi () {
  Serial.begin(115200);
  delay(5000);
  Serial.println("Booting---");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  int teltje = 0;
  pinMode(ledPin, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  while (WiFi.status()!= WL_CONNECTED) {
    delay(250);
    digitalWrite(ledPin, HIGH); 
    delay(250);
    digitalWrite(ledPin, LOW);  
    teltje++;
    Serial.print(".");
    if (teltje>20) {
      Serial.println("Connection Failed! Rebooting...");
      delay(500);
      ESP.restart();
    }
  }
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  setupwifi();
  setupOTA();
}

void loop() {
  ArduinoOTA.handle();

}