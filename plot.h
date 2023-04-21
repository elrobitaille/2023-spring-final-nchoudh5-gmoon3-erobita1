#ifndef PLOT_H
#define PLOT_H

#include <vector>
#include <map>
#include <string>
#include "bounds.h"
#include "image.h"
#include "func.h"
#include "fill.h"
#include "color.h"

class Plot {
private:
  Bounds bound_;
  int width_;
  int height_;
  std::vector<Function*> functions_;
  std::vector<Fill*> fills_;
  std::map<std::string, Color> colors_;

  Plot(const Plot&);
  Plot& operator=(const Plot&);

public:
  Plot();
  ~Plot();

  // Getter and setter for bound_
  void set_bound(const Bounds& bound) { bound_ = bound; }
  Bounds get_bound() const { return bound_; }

  // Getter and setter for width_
  void set_width(int width) { width_ = width; }
  int get_width() const { return width_; }

  // Getter and setter for height_
  void set_height(int height) { height_ = height; }
  int get_height() const { return height_; }

  // Getter and setter for functions_
  void add_function(Function* function) { functions_.push_back(function); }
  const std::vector<Function*>& get_functions() const { return functions_; }

  // Getter and setter for fills_
  void add_fill(Fill* fill) { fills_.push_back(fill); }
  const std::vector<Fill*>& get_fills() const { return fills_; }

  // Getter and setter for colors_
  void add_color(const std::string& name, const Color& color) {
    if (colors_.find(name) != colors_.end()) {
      throw PlotException("Color with the same name already exists");
    }
    colors_[name] = color;
  }

  const std::map<std::string, Color>& get_colors() const { return colors_; }
};

#endif // PLOT_H
