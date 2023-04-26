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
      if(!(iss >> x_min >> y_min >> x_max >> y_max)) {
        throw PlotException("Failed to read bound values");
      }
      if (x_min >= x_max || y_min >= y_max) {
        throw PlotException("Invalid bounds");
      }
      plot.set_bound(Bounds(x_min, x_max, y_min, y_max));

      int width, height;
      if(!(iss >> width >> height)) {
        throw PlotException("Failed to image width and height");
      }
      if (width <= 0 || height <= 0) {
        throw PlotException("Invalid image size");
      }
      plot.set_width(width);
      plot.set_height(height);
    } 
    else if (command == "Color") {
      std::string fn_name;
      int r = -1, g = -1, b = -1;
      iss >> fn_name;
      if (!(iss >> r >> g >> b)) {
        throw PlotException("Failed to read color values");
      }
      if (r > 255 || g > 255 || b > 255) {
        throw PlotException("Invalid color");
      }
      else if (r < 0 || g < 0 || b < 0) {
        throw PlotException("Invalid color");
      }
      Color color(r, g, b);
      plot.add_color(fn_name, color);
    }

   else if (command == "Function") {
      string fn_name;
      string expr;
      if (!(iss >> fn_name)) {
        throw PlotException("Failed to read function name");
      }
      getline(iss, expr);
      expr.erase(0, expr.find_first_not_of(" \t")); // Removes leading spaces and tabs, avoids core dump
      std::istringstream expr_stream(expr);
      ExprParser parser;
      Function* function = new Function(fn_name, parser.parse(expr_stream));
      plot.add_function(function);
    }

   else if (command == "FillAbove" || command == "FillBelow" || command == "FillBetween") {
      std::string fn_name1;
      std::string fn_name2; // only used for FillBetween
      double opacity;
      int r, g, b;
      if (command == "FillBetween") {
        if (!(iss >> fn_name1 >> fn_name2 >> opacity >> r >> g >> b)) {
          throw PlotException("Failed to read FillBetween values");
        }
      } else {
        if (!(iss >> fn_name1 >> opacity >> r >> g >> b)) {
          throw PlotException("Failed to read FillAbove or FillBelow values");
        }
      }
      // Check for errors after reading values
      if (opacity < 0 || opacity > 1) {
        throw PlotException("Invalid opacity");
      }
      if (r > 255 || g > 255 || b > 255) {
        throw PlotException("Invalid color");
      }
      else if (r < 0 || g < 0 || b < 0) {
        throw PlotException("Invalid color");
      }
      Color color(r, g, b);
      if (command == "FillAbove") {
        Fill* fill = new Fill(FillType::ABOVE, fn_name1, opacity, color);
        plot.add_fill(fill);
      } else if (command == "FillBelow") {
        Fill* fill = new Fill(FillType::BELOW, fn_name1, opacity, color);
        plot.add_fill(fill);
      } else if (command == "FillBetween") {
        Fill* fill = new Fill(FillType::BETWEEN, fn_name1, fn_name2, opacity, color);
        plot.add_fill(fill);
      }
    } 
    else {
      throw PlotException("Invalid command");
    }
  }
}