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
  Bound bound;

public:
  Plot();
  ~Plot();

  // TODO: add member functions to set and modify plot data
  void set_bound(Bound bound){this->bound = bound;}
  Bound get_bound() const {return bound;}
  
};

#endif // PLOT_H
