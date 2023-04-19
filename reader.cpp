#include <iostream>
#include <map>
#include <sstream>
#include <cstdint>
#include "exception.h"
#include "plot.h"
#include "reader.h"
#include "expr_parser.h"
#include "fill.h"


Reader::Reader() {
}

Reader::~Reader() {
}

void Reader::read_input(std::istream &in, Plot &plot) {
  // TODO: read plot input from in, add information to plot
  std::string line;
  //read plot input from in, add information to plot
  while (std::getline(in, line)) {
    std::istringstream iss(line);
    std::string command;
    iss >> command;
    if (command == "Plot") {
      int x_min, x_max, y_min, y_max;
      iss >> x_min >> x_max >> y_min >> y_max;
      plot.set_bound(Bound(x_min, x_max, y_min, y_max));
    }
  }
}