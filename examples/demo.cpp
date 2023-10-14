#include <WiFiManager.h>

/* Following are the constructors */
WiFiManager wm;
// WiFiManager wm(115200);
// WiFiManager wm({"default SSID", "default Password"}, 115200);

void onWiFiSuccess(WiFiCredentials WiFi)
{

}

int onWiFiError(WiFiCredentials WiFi, int errorCode)
{
    return CB_RETRY; // Return this to retry connecting & prompting the user
    return CB_RETRY; // Return this to quit the processs
}

void setup()
{
    wm.addParameter({"Name of Custom Parameter1"});
    wm.addParameter({"Name of Custom Parameter2"});
    wm.addParameter({"Name of Custom Parameter3"});

    wm.begin(onWiFiSuccess, onWiFiError, 1000);

    auto x = wm.getParameter("Name of Custom Parameter2");
    Serial.println("Name:\t" + x.Name + "\tValue:\t" + x.Value);
}   

void loop()
{

}