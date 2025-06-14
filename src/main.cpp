#include <Arduino.h>
#include <DexcomESP32.h>  // Use angle brackets for library header

DexcomESP32 dexcom("YourSSID", "YourPassword", "YourClientID", "YourClientSecret");  // Pass required constructor arguments

void setup() {
    Serial.begin(115200);
    delay(1000);

    // Connect to WiFi
    dexcom.connectWiFi("YourSSID", "YourPassword");

    // Start the Dexcom authentication flow
    dexcom.startAuthFlow("YourClientID", "YourClientSecret");
}

void loop() {
    // You can add code here to handle periodic tasks
    // like refreshing tokens, reading glucose data, etc.
}
//
// Created by Akaash Dhayalan on 7/6/25.
//
