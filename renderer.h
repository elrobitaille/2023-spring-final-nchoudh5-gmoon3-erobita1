// Nikhil Choudhary - nchoudh5
// Sun Moon - gmoon3 
// Edgar Robitaille - erobita1
#ifndef RENDERER_H
#define RENDERER_H

#include "plot.h"
#include "image.h"

class Renderer {
private:
  // it's convenient to have these as fields, to avoid the need
  // to pass them explicitly to helper functions
  const Plot &m_plot;
  Image *m_img;

  // value semantics prohibited
  Renderer(const Renderer &);
  Renderer &operator=(const Renderer &);

  // Function and helper function declarations
  void draw_pixel(int x, int y, Color &func_color);
  void renderFills();
  void renderFunctions();
  Color color_blend(const Color& orig, const Color& fill, double alpha);
  std::pair<double, double> pixel_to_XY(int i, int j, double x_min, double x_max, double y_min, double y_max, int width, int height);
  int find_pixel_row(int j, const Expr *f, double x_min, double x_max, double y_min, double y_max, int width, int height);
  const Function* get_func_name(const std::string& name);
  bool is_valid_fill(const Fill* fill, double x, double y);

public:
  // Non-default constructor and destructor 
  Renderer(const Plot &plot);
  ~Renderer();

  Image *render();

};

#endif // RENDERER_H
