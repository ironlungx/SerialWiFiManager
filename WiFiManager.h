#pragma once
#include <Arduino.h>
#include <vector>
#include <functional>
#include <WiFi.h>

#define OK 0

#define ERR_SERIAL -1 // No Serial port
#define ERR_NO_WIFI 1 // Unable to connect to wifi

#define CB_QUIT 0   // Callback Cancel
#define CB_RETRY 1  // Callback Retry


using std::function;
using std::vector;

struct Parameter
{
    String Name;
    String Value;
};

struct WiFiCredentials
{
    String ssid;
    String pass;
};

class WiFiManager
{
private:
    WiFiCredentials defaultWIFI;
    WiFiCredentials ObtainedWiFi;

    long baudrate;

    vector<Parameter> parameters;

    int connectToWiFi(WiFiCredentials cred, long timeout);

public:
    /**
     * @brief Constructs a WiFiManager object with provided default WiFi credentials and baud rate. 
     *
     * @param defaultWiFi The default WiFi credentials (SSID and password). Leave blank for no default WiFi
     * @param baud The baud rate for serial communication.
     *
     */
    WiFiManager(const WiFiCredentials defaultWiFi, long baud);
    WiFiManager(const WiFiCredentials defaultWiFi);
    WiFiManager(long baud);
    WiFiManager();

    /**
     * @brief Start the serial communication for SSID & passkey exchange.
     * 
     * @param onSuccessCallback. A function that is to be called when the operation is successful
     */
    void begin(function<void(WiFiCredentials WiFi)> onSuccessCallback, function<int(WiFiCredentials WiFi, int errorCode)> onFailureCallback, long timeout);
    int addParameter(Parameter _parameter);
    Parameter getParameter(String _name);

    ~WiFiManager();
};
