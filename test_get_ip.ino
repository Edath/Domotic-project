#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

const char* ssid     = "DESKTOP-PMGUL08 7652";
const char* password = "1q5[752H";
void setup() {
  
  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32

  Serial.println("I'm gonna print you out");
  display.display();
  delay(1000);
 

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(WiFi.localIP());
  display.display();
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
}

void loop() {
}
