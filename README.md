# TinyDebug

> ATtiny85 Serial-like debug interface for the Wokwi.com simulator.

Use this library to log debug information from your code while running ATtiny85 projects on the [Wokwi Arduino Simulator](https://wokwi.com). It provides an interface similar to the familiar `Serial` object.

You can keep it when running your code on a physical ATtiny85 chip, and the debug prints will simply be ignored without affecting the rest of your program.

## Usage

1. Include the library in your Sketch:

```cpp
#include <TinyDebug.h>
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

## Zero-SRAM interface

The `Debug` interface about 30 bytes of SRAM and 150 bytes of Flash memory, depending on the methods that you use in your code. TinyDebug also provides a lightweight logging interface, which does not use any SRAM
and uses about 30 bytes of Flash: `tdPrint()` and `tdPrintln()`. The caveat is that you can only print c-style strings, i.e. `char *` strings.

Usage example:

```cpp
#include <TinyDebug.h>

void setup() {
  tdPrintln(F("I do not use any SRAM!"));
}

void loop() {
  /* ... */
}
```

## License

Released under the [MIT License](LICENSE). Copyright (C) 2021 Uri Shaked.
