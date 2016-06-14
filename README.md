# Ubidots SODAQ Autonomo with WiFibee


This library is to connect easily an mDot with SODAQ Autonomo

## Requiremets

* [SODAQ Autonomo](http://shop.sodaq.com/nl/arduino-boards/)
* [WiFi bee](http://gprsbee.com/)
* [Arduino IDE 1.6.7 or higher](https://www.arduino.cc/en/Main/Software)

## Setup

1. Download Arduino IDE [here](https://www.arduino.cc/en/Main/Software)
2. Go to Arduino IDE **File -> Preferences -> Additional Board Manager URLs** and add next line there "http://downloads.sodaq.net/package_sodaq_index.json".
3. Open Board Manager via **Tools -> Board -> Board Manager** and search for SODAQ boards, select SODAQ SAMD boards for the Autonomo.
4. Download the GPRSbee library of Ubidots [here](https://github.com/ubidots/ubidots-sodaq-gprsbee)
5. Go to the Arduino IDE, click on **Sketch -> Include Library -> Add .ZIP Library**
6. Select the .ZIP file of GPRSbee and then "Accept" or "Choose"
5. Close the Arduino IDE and open it again.

Note: 
    * This library uses WiFly library of SeeedStudio. For this reason I added it to this repository.
    * This library creates a new Ubidots data source named "SODAQWiFly", Inside that the library will save the variables.
    
## Send one value to Ubidots

In the next example we explain how to send a Temperature value to Ubidots API from your device. Please don't forget to change **SSID**, **KEY**, **AUTH** and **TOKEN**.

```cpp
#include <SODAQWiFibee.h>

/* Change the AUTH according to your network settings
   If is open change to WIFLY_AUTH_OPEN
   If is WPA1 change to WIFLY_AUTH_WPA1
   If is WPA1_2 change to WIFLY_AUTH_WPA1
   If is WPA2 change to WIFLY_AUTH_WPA1
*/

// To add space in RN171 you just put "$" instead of " "
#define SSID "WIFI$SSID"  
#define KEY "WiFi_Pass"
#define AUTH WIFLY_AUTH_WPA2_PSK
#define TOKEN "asdasenas12321adaxxxxx"  // Replace it with your Ubidots token

Ubidots client(TOKEN);

void setup() {
    client.wifiConnection(SSID, KEY, AUTH);    
}

void loop() {
    float value = analogRead(A0);
    client.add("Tmeperature", value);
    client.sendAll();
    delay(1000);
}
```

## Get one value from Ubidots

In the next example we will explain you how to get the last value from a Ubidots variable. Please don't forget to change **SSID**, **KEY**, **AUTH** and **TOKEN**.

```cpp
#include <SODAQWiFibee.h>

/* Change the AUTH according to your network settings
   If is open change to WIFLY_AUTH_OPEN
   If is WPA1 change to WIFLY_AUTH_WPA1
   If is WPA1_2 change to WIFLY_AUTH_WPA1
   If is WPA2 change to WIFLY_AUTH_WPA1
*/

// To add space in RN171 you just put "$" instead of " "
#define SSID "WIFI$SSID"  
#define KEY "WiFi_Pass"
#define AUTH WIFLY_AUTH_WPA2_PSK
#define TOKEN "asdasenas12321adaxxxxx"  // Replace it with your Ubidots token

Ubidots client(TOKEN);

void setup() {
    client.wifiConnection(SSID, KEY, AUTH);    
}

void loop() {
    float value = client.getValue(ID);
    delay(1000);
}
```

