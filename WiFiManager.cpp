// #include <Arduino.h>
#include "WiFiManager.h"

#define WAIT_FOR_SERIAL while (Serial.available() <= 0)

using std::function;
using std::vector;

WiFiManager::WiFiManager(const WiFiCredentials defaultWiFi, long baud)
    : defaultWIFI(defaultWiFi), baudrate(baud)
{
}

WiFiManager::WiFiManager(const WiFiCredentials defaultWiFi)
    : defaultWIFI(defaultWiFi)
{
}

WiFiManager::WiFiManager(long baud)
    : defaultWIFI({"NONE", "NONE"}), baudrate(baud)
{
}

WiFiManager::WiFiManager()
    : defaultWIFI({"NONE", "NONE"}), baudrate(115200)
{
}

WiFiManager::~WiFiManager()
{
}

void WiFiManager::begin(function<void(WiFiCredentials WiFi)> onSuccessCallback, function<int(WiFiCredentials WiFi, int errorCode)> onFailureCallback, long timeout)
{
    Serial.begin(this->baudrate);
    Serial.println("Serial WiFi manager");
    Serial.println("*******************\n\n");
    Serial.println("Attempting to connect to provided WiFi: " + this->defaultWIFI.ssid + " with passkey: " + this->defaultWIFI.pass);
    Serial.println(connectToWiFi(this->defaultWIFI, timeout) ? "Success" : "Failure");

    for (auto &p : this->parameters)
    {
        Serial.print("Enter Value for custom parameter " + p.Name + ":\t");
        WAIT_FOR_SERIAL;
        p.Value = Serial.readString();
        p.Value.trim();
    } 

    WiFiCredentials cred;
    Serial.print("Enter SSID:\t");
    WAIT_FOR_SERIAL;
    cred.ssid = Serial.readString();
    cred.ssid.trim();
    Serial.println();

    Serial.print("Enter password:\t");
    WAIT_FOR_SERIAL;
    cred.pass = Serial.readString();
    cred.pass.trim();
    Serial.println();


    if (connectToWiFi(cred, timeout) == OK) onSuccessCallback(cred);
    if (connectToWiFi(cred, timeout) == ERR_NO_WIFI) onFailureCallback(cred, ERR_NO_WIFI);
}

int WiFiManager::connectToWiFi(WiFiCredentials cred, long timeout)
{
    WiFi.begin(cred.ssid, cred.pass);

    long startMS = millis();

    while (1)
    {
        if (WiFi.status() == WL_CONNECTED)
        {
            return OK;
        }
        else if (startMS > timeout)
        {
            return ERR_NO_WIFI;
        }
    }

    // HACK: Fixes a warning. In reality the function would never really reach till here
    return OK;
}

int WiFiManager::addParameter(String name)
{
    if (name != "")
    {
        this->parameters.push_back({name, ""});
        return 0;
    }
    else
    {
        return 1;
    }
}

Parameter WiFiManager::getParameter(String name)
{
    for (const Parameter i : this->parameters)
    {
        if (i.Name == name)
        {
            return i;
        }
    }

    return Parameter{"", ""};
}
