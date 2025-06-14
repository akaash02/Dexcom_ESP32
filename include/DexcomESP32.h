#ifndef DEXCOM_ESP32_LIBRARY_H
#define DEXCOM_ESP32_LIBRARY_H

#include <Arduino.h>
#include <WiFi.h>

class DexcomESP32 {
public:
    DexcomESP32(const char* ssid, const char* password, const char* clientId, const char* clientSecret);

    // WiFi setup
    void connectWiFi(char* ssid, char* password);
    void monitorWiFi();               // Check WiFi connection status

    // OAuth2 Authentication
    void startAuthFlow(char* clientId, char* clientSecret);              // Print URL for manual code entry
    bool handleAuthCode(const String& code);  // Exchange code for access token
    bool refreshAccessToken();

    // Dexcom API
    bool getGlucoseData();            // Fetch latest glucose data
    float getLatestGlucoseValue();    // Latest value in mg/dL
    String getLatestGlucoseTime();    // Timestamp string

    // Background monitoring
    void startMonitoring(unsigned long intervalMs = 300000);  // default 5 minutes
    void stopMonitoring();

    // Debug
    void printLatestReading();
    bool isAuthenticated() const;

private:
    const char* _ssid;
    const char* _password;
    const char* _clientId;
    const char* _clientSecret;
    static constexpr const char* AUTH_URL = "https://api.dexcom.jp/v2/oauth2/login";  // Base URL for Dexcom API
    static constexpr const char* REDIRECT_URL = "http://localhost:5000/callback";  // Redirect URI for OAuth2

    String _accessToken;
    String _refreshToken;
    float _latestValue;
    String _latestTime;

    bool _authenticated;
    TaskHandle_t _monitorTaskHandle;

    void fetchLoop();  // background task function
};

#endif //DEXCOM_ESP32_LIBRARY_H
