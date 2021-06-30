/**
  ATtiny85 Serial-like debug interface for the Wokwi.com simulator.

  Copyright (C) 2021, Uri Shaked.
  Released under the MIT license.
*/

#include <avr/io.h>
#include "TinyDebug.h"

#define TDDR	_SFR_IO8(0x1A)

#define TDCR	_SFR_IO8(0x1B)
#define TDEN 1
#define TDPEEK 2

TinyDebug Debug;

void TinyDebug::begin() {
  TDCR |= TDEN;
}

size_t TinyDebug::write(uint8_t b)
{
  TDDR = b;
  return 1;
}

void TinyDebug::flush()
{
}

int TinyDebug::available()
{
  return TDCR >> 4;
}

int TinyDebug::peek() {
  asm("cli");
  TDCR |= TDPEEK;
  int result = TDCR >> 4 ? TDDR : -1;
  TDCR &= ~TDPEEK;
  asm("sei");
  return result;
}

int TinyDebug::read()
{
  asm("cli");
  int result = TDCR >> 4 ? TDDR : -1;
  asm("sei");
  return result;
}

/* Zero SRAM functions: */

void tdPrint(char *message) {
  TDCR |= TDEN;
  for (;*message;message++) {
    TDDR = *message;
  }
}

void tdPrint(const __FlashStringHelper *message) {
  PGM_P p = reinterpret_cast<PGM_P>(message);
  TDCR |= TDEN;
  for (;pgm_read_byte(p); p++) {
    TDDR = pgm_read_byte(p);
  }
}

void tdPrintln(char *message) {
  tdPrint(message);
  TDDR = '\n';
}

void tdPrintln(const __FlashStringHelper *message) {
  tdPrint(message);
  TDDR = '\n';
}
