#include "DexcomESP32.h"
#include <iostream>
#include <WiFi.h>

void DexcomESP32::connectWiFi(char* ssid, char* password) {
    _ssid = ssid;
    _password = password;

    WiFi.begin(_ssid, _password);
    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnected to WiFi!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

}

void DexcomESP32::monitorWiFi() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi disconnected, attempting to reconnect...");
        WiFi.reconnect();
        delay(2000);
    }
}

