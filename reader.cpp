#include <iostream>
#include <map>
#include <sstream>
#include <cstdint>
#include "exception.h"
#include "plot.h"
#include "reader.h"
#include "expr_parser.h"
#include "fill.h"

using std::string;
using std::istringstream;
using std::getline;

Reader::Reader() {
}

Reader::~Reader() {
}

void Reader::read_input(std::istream &in, Plot &plot) {
  // TODO: read plot input from in, add information to plot
  std::string line;
  //read plot input from in, add information to plot
  while (std::getline(in, line)) {
    istringstream iss(line);
    string command;
    iss >> command;
    if (command == "Plot") {
      double x_min, x_max, y_min, y_max;
      iss >> x_min >> y_min >> x_max >> y_max;
      if (x_min >= x_max || y_min >= y_max) {
        throw PlotException("Invalid bounds");
      }
      plot.set_bound(Bounds(x_min, x_max, y_min, y_max));

      int width, height;
      iss >> width >> height;
      if (width <= 0 || height <= 0) {
        throw PlotException("Invalid image size");
      }
      plot.set_width(width);
      plot.set_height(height);
    } 
    else if (command == "Color") {
      std::string fn_name;
      int r, g, b;
      iss >> fn_name >> r >> g >> b;
      if (r > 255 || g > 255 || b > 255) {
        throw PlotException("Invalid color");
      }
      Color color(r, g, b);
      plot.add_color(fn_name, color);
    }

   else if (command == "Function") {
      string fn_name;
      string expr;
      iss >> fn_name;
      getline(iss, expr);
      expr = expr.substr(1);
      std::istringstream expr_stream(expr);
      ExprParser parser;
      Function* function = new Function(fn_name, parser.parse(expr_stream));
      plot.add_function(function);
    } 
    else {
      throw PlotException("Invalid command");
   }
  }
}