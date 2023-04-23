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
  renderFunctions();

  return img.release();
}

Color colorBlend(const Color& orig, const Color& fill, double alpha) {
  uint8_t r = std::floor((1 - alpha) * orig.r + alpha * fill.r);
  uint8_t g = std::floor((1 - alpha) * orig.g + alpha * fill.g);
  uint8_t b = std::floor((1 - alpha) * orig.b + alpha * fill.b);
  return Color(r, g, b);
}
    

// TODO: implement private helper functions
