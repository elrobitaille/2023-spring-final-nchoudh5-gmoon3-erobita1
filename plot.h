#ifndef PLOT_H
#define PLOT_H

#include <vector>
#include <map>
#include <string>
#include "bounds.h"
#include "image.h"
#include "func.h"
#include "fill.h"

class Plot {
private:
  // TODO: add fields to represent plot bounds, functions, fills, etc.

  // value semantics are prohibited
  Plot(const Plot &);
  Plot &operator=(const Plot &);
  Bounds bound;
  int width;
  int height;

public:
  Plot();
  ~Plot();

  // TODO: add member functions to set and modify plot data
  void set_bound(Bounds bound){this->bound = bound;}
  Bounds get_bound() const {return bound;}

  void set_width(int width){this->width = width;}
  int get_width() const {return width;}

  void set_height(int height){this->height = height;}
  int get_height() const {return height;}
  
};

#endif // PLOT_H
