#include "exception.h"

// Constructor for PlotException, msg is the exception message passed 
PlotException::PlotException(const std::string &msg)
  : std::runtime_error(msg) {
}

// Copy Constructor for PlotException, other is object to be copied
PlotException::PlotException(const PlotException &other)
  : std::runtime_error(other) {
}

// Destructor for PlotException 
PlotException::~PlotException() {
}
