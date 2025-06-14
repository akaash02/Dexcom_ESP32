#include <DexcomESP32.h>
#include <iostream>
#include <WiFi.h>
#include <Arduino.h>

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

void DexcomESP32::startAuthFlow(char *clientId, char *clientSecret) {
    _clientId = clientId;
    _clientSecret = clientSecret;

    String url = String(AUTH_URL) + "?client_id=" + clientId +
             "&redirect_uri=" + String(REDIRECT_URL) +
             "&response_type=code&scope=offline_access";

    Serial.println("Visit this URL to authorize: ");
    Serial.println(url);
}
