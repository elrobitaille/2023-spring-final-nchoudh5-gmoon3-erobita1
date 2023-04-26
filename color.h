#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <cassert>

struct Color {
  // RGB values: red, green, and blue parts of color, each is an 8-bit unsigned integer [0, 255]
  uint8_t r, g, b;

  // Constructor for Color struct, initializes color components with provided values or zero if not provided 
  Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0) : r(r), g(g), b(b) { }
};



#endif // COLOR_H
