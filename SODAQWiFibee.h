/*
    SODAQ library to using mDot bee. Some function are based on GPRSbee
    library of Kees Bakker
    Copyright (C) 2016  Mateo Velez - Metavix for Ubidots Inc.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef __SODAQWiFibee_H_
#define __SODAQWiFibee_H_

#include <stdint.h>
#include <Arduino.h>
#include <Stream.h>
#include "WiFly.h"

#define DEFAULT_BUFFER_SIZE      64
#define MAX_VALUES 4

#define WIFLY_AUTH_OPEN        0    // Open (default)  
#define WIFLY_AUTH_WEP         1    // WEP-128
#define WIFLY_AUTH_WPA1        2    // WPA1
#define WIFLY_AUTH_WPA1_2      3    // Mixed-mode WPA1 and WPA2-PSK
#define WIFLY_AUTH_WPA2_PSK    4    // WPA2-PSK
#define WIFLY_AUTH_ADHOC       6    // Ad-hoc, join any Ad-hoc network

#define BAUDRATE 9600
#define TCP_CLIENT_DEFAULT_TIMEOUT         30000  // 3s

#define SERVER "industrial.api.ubidots.com"
#define PORT 9012
#define MAX_VALUES 5


typedef struct Value {
  char  *idName;
  float valueName;
  char *ctext;
} Value;

class Ubidots {
 public:
    Ubidots(char* token);
    bool sendAll();
    bool wifiConnection(const char *ssid, const char *phrase, int auth = WIFLY_AUTH_OPEN);
    float getValue(char* id);
    void add(char *variable_id, float value);
    void add(char *variable_id, float value, char* context);
    bool setDatasourceName(char* dsName);
    bool setDatasourceTag(char* dsTag);

 private:    
    int currentValue;
    float parseValue(String body);
    Value * val;
    WiFly _client = WiFly(&Serial1);
    char* _token;
    char* _dsTag;
    char* _dsName;
};
#endif
