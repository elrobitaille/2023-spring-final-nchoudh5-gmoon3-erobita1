#include <iostream>
#include <cmath>
#include <cassert>
#include <memory>
#include "exception.h"
#include "renderer.h"

//#define DEBUG_FILL
//#define DEBUG_PLOT

Renderer::Renderer(const Plot &plot)
  : m_plot(plot)
  , m_img(nullptr) {
}

Renderer::~Renderer() {
  // Note: the Renderer object does not "own" the Image object,
  // since the render() member function transfers ownership of
  // the Image object to the caller (in the main function)
}

Image *Renderer::render() {
  int width = m_plot.get_width();
  int height = m_plot.get_height();

  // the unique_ptr will take care of deleting the Image object
  // if an exception is thrown
  std::unique_ptr<Image> img(new Image(width, height));
  m_img = img.get();

  // TODO: render the plot image
  // 1. fill the background
  // 2. render the functions
  // 3. render the fills
  // 4. return the image

  renderFills();
  //renderFunctions();

  return img.release();
}

// Color blending function which utilizes formula provided C_blend = (1 - alpha) * C_orig + alpha * C_fill to blend the original color with the fill color
Color Renderer::color_blend(const Color& orig, const Color& fill, double alpha) {
  uint8_t r = std::floor((1 - alpha) * orig.r + alpha * fill.r);
  uint8_t g = std::floor((1 - alpha) * orig.g + alpha * fill.g);
  uint8_t b = std::floor((1 - alpha) * orig.b + alpha * fill.b);
  return Color(r, g, b);
}

std::pair<double, double> pixel_to_XY(int i, int j, double x_min, double x_max, double y_min, double y_max, int width, int height) {
  double x = x_min + (j/(width)) * (x_max - x_min);
  double y = y_min + ((height - 1 - i)/(height)) * (y_max - y_min);
  return std::make_pair(x, y);
}

int find_pixel_row(int j, const Expr *f, double x_min, double x_max, double y_min, double y_max, int width, int height) {
  double x = x_min + (j /(width)) * (x_max - x_min);
  double y = f->eval(x);
  int i = height - 1 - std::floor(((y - y_min) / (y_max - y_min)) * height);
  return i;
}


void Renderer::renderFills() { 
  int width = m_img->get_width();
  int height = m_img->get_height();
  Bounds plot_bounds = m_plot.get_bound();
  double x_min = plot_bounds.get_xmin();
  double x_max = plot_bounds.get_xmax();
  double y_min = plot_bounds.get_ymin();
  double y_max = plot_bounds.get_ymax();

}

