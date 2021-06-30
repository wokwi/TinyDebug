# TinyDebug

> ATtiny85 Serial-like debug interface for the Wokwi.com simulator.

Use this library to log debug information from your code while running ATtiny85 projects on the [Wokwi Arduino Simulator](https://wokwi.com). It provides an interface similar to the familiar `Serial` object.

You can keep it when running your code on a physical ATtiny85 chip, and the debug prints will simply be ignored without affecting the rest of your program. This library consumes about 30 bytes of RAM, used by the Stream object instance.

## Usage

1. Include the library in your Sketch:

```cpp
#include "TinyDebug.h"
```

2. Call `Debug.begin()` in your setup() function:

```cpp
void setup() {
  Debug.begin();
}
```

3. Use `Debug.print()` and `Debug.println()` to log debug messages. E.g.:

```cpp
void loop() {
  Debug.print(F("Hello world! Millis:"));
  Debug.println(millis());
  delay(1000);
}
```

You can also read values from the debug interface using any of the [Stream input functions](https://www.arduino.cc/reference/en/language/functions/communication/stream/) such as `read()` and `readStringUntil()`.

For a complete example, check out [the demo project on wokwi.com](https://wokwi.com/arduino/projects/300650387867697672).

## License

Released under the [MIT License](LICENSE). Copyright (C) 2021 Uri Shaked.
