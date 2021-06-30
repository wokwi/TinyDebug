/**
  ATtiny85 Serial-like debug interface for the Wokwi.com simulator.

  Copyright (C) 2021, Uri Shaked.
  Released under the MIT license.
*/

#ifndef TinyDebug_h
#define TinyDebug_h

#include <inttypes.h>
#include <Stream.h>

class TinyDebug : public Stream
{
  public:
    void begin();
    virtual int available();
    virtual int peek();
    virtual int read();
    virtual void flush();
    virtual size_t write(uint8_t byte);
    using Print::write;
};

extern TinyDebug Debug;

/* The following functions do not use any SRAM, and only take about 30 bytes of Flash space.
   You can use them if you are short in SRAM or Flash program space.
*/
extern void tdPrint(char *message);
extern void tdPrint(const __FlashStringHelper *message);
extern void tdPrintln(char *message);
extern void tdPrintln(const __FlashStringHelper *message);

#endif