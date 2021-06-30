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

#endif