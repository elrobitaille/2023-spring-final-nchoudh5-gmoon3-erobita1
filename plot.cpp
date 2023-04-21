#include <cassert>
#include "plot.h"

// TODO: initialize fields
Plot::Plot() {
  bound = Bounds();
  width = 0;
  height = 0; 
}

Plot::~Plot() {
  // TODO: delete dynamically-allocated objects
  for (int i = 0; i < functions.size(); i++) {
    delete functions[i];
  }

  for (int i = 0; i < fills.size(); i++) {
    delete fills[i];
  }
}

// TODO: implementations of Plot member functions

