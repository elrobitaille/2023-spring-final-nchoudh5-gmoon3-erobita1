#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <cassert>

struct Color {
  uint8_t r, g, b;

  Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0) : r(r), g(g), b(b) { }
  // member functions for doing operations on Color values
  // could be helpful
};



#endif // COLOR_H
