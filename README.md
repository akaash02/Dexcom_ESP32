# DexcomAPI

**DexcomAPI** is a C++ library for ESP32 boards that allows you to fetch Dexcom CGM (Continuous Glucose Monitoring) data using OAuth2 authentication and HTTP requests. The library is designed for real-time monitoring and prints data to the ESP32 Serial Monitor.

## Features

- OAuth2 authentication with Dexcom's sandbox API
- Periodic fetching of CGM (glucose) data
- Automatic token refresh
- Serial Monitor output (for ESP32 projects)

## Getting Started

1. Clone this repository.
2. Build the library using CMake in your development environment (e.g., CLion).
3. Link the library to your ESP32 project.
4. Replace desktop-specific code with ESP32/Arduino equivalents when deploying to hardware.

## Example

```cpp
#include "DexcomESP32.h"

void setup() {
    Serial.begin(115200);
    // Initialize WiFi and authenticate with Dexcom
}

void loop() {
    // Fetch and print CGM data
}

```
## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.