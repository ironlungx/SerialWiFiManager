
# SerialWiFiManager

SerialWiFiManager is an Arduino library designed for streamlined management of WiFi credentials, inspired by tzapu's WiFi Manager. This library simplifies the process of connecting your Arduino projects to WiFi networks by reducing boilerplate code and providing an easy-to-use interface.

## 🚀 Features / Key Points

- **Inspiration from WiFi Manager Library:** SerialWiFiManager draws inspiration from tzapu's WiFi Manager library, offering a simplified and efficient alternative.

- **Reduced Boilerplate Code:** Bid farewell to extensive boilerplate code. SerialWiFiManager provides straightforward functions for managing and connecting to WiFi networks.

- **Ideal for Demos and Testing:** Perfect for scenarios where WiFi credentials are unknown beforehand, making it suitable for testing and demonstrations in various locations.

- **Highly Customizable:** Tailor SerialWiFiManager to your specific needs. Customize prompts, provide default credentials, and configure it seamlessly into your project.

- **Available on PlatformIO:** Easily integrate SerialWiFiManager into your PlatformIO projects for a seamless development experience.

## 🔧 Library Usage

### Installation

1. Download and install SerialWiFiManager through PlatformIO by adding it to your `platformio.ini` file:

    ```ini
    lib_deps =
        SerialWiFiManager
    ```

2. Include the library in your Arduino sketch:

    ```cpp
    #include <SerialWiFiManager.h>
    ```

3. Create an instance of the SerialWiFiManager class:

    ```cpp
    SerialWiFiManager wm;
    ```

4. Utilize SerialWiFiManager functions for managing WiFi credentials:

    ```cpp
    wm.addParameter({"CustomParam", enum::DATA_TYPE});
    wm.begin(onSuccess, onFailure, timeout);
    auto customParam = wm.getParameter("CustomParam");
    ```

## 🛠️ Adding Custom Parameters

SerialWiFiManager allows you to add custom parameters to tailor the library to your specific project requirements. The `addParameter` function enables the addition of custom parameters, each represented by a simple structure with two strings: name and value.

### Usage

```cpp
wm.addParameter({"CustomParam", "CustomValue"});
```

Replace `"CustomParam"` with the desired name and `"CustomValue"` with the corresponding value for your custom parameter.

### Example

Adding a custom parameter:

```cpp
wm.addParameter({"TemperatureThreshold", "25°C"});
```

This straightforward approach allows you to include additional information within the configuration process. The added custom parameters become part of the initialization, providing flexibility for various project needs.

## 🤝 Contributing

Contributions, suggestions, and bug fixes are welcome! Feel free to submit issues or pull requests on the [GitHub repository](https://github.com/yourusername/serialwifimanager).

## 📄 License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
