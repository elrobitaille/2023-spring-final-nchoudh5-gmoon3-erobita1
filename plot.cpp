// Nikhil Choudhary - nchoudh5
// Sun Moon - gmoon3 
// Edgar Robitaille - erobita1
#include <cassert>
#include "plot.h"

Plot::Plot() {
  // Initialize the bounds to the default values of 0
  bound_ = Bounds();
  width_ = 0;
  height_ = 0; 
}

Plot::~Plot() {
  // Dynamically deallocate all the functions and fills
  for (std::size_t i = 0; i < functions_.size(); i++) {
    delete functions_[i];
  }

  for (std::size_t i = 0; i < fills_.size(); i++) {
    delete fills_[i];
  }
}

