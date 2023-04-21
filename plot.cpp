#include <cassert>
#include "plot.h"

// TODO: initialize fields
Plot::Plot() {
  bound_ = Bounds();
  width_ = 0;
  height_ = 0; 
}

Plot::~Plot() {
  // TODO: delete dynamically-allocated objects
  for (int i = 0; i < functions_.size(); i++) {
    delete functions_[i];
  }

  for (int i = 0; i < fills_.size(); i++) {
    delete fills_[i];
  }
}

// TODO: implementations of Plot member functions

