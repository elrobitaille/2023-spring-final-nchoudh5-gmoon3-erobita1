#ifndef FILL_H
#define FILL_H

#include <string>
#include "image.h"
#include "color.h"
#include "plot.h"
#include "func.h"

enum class FillType {ABOVE, BELOW, BETWEEN};

class Fill {
private:
  // TODO: add fields to represent the fill
  std::string fn_name1_;
  std::string fn_name2_;
  FillType fill_type_;
  Color color_;
  double opacity_;
  

public:
  // TODO: add appropriate constructors
  // Add constructors for each fill type (above, below, between), account for FillAbove and FillBelow, then FillBetween
  Fill(FillType fill_type, const std::string& fn_name1, double opacity, const Color& color);
  Fill(FillType fill_type, const std::string& fn_name1, const std::string& fn_name2, double opacity, const Color& color);
  
  // Destructor 
  ~Fill();

  // TODO: add appropriate member functions
};

#endif // FILL_H
