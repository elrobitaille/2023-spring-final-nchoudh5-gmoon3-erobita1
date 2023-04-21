#include <cmath>
#include <stdexcept>
#include "exception.h"
#include "expr.h"

// Expr (base class)

Expr::Expr() {
}

Expr::~Expr() {
  // Deallocate child nodes (if any)
  for (size_t i = 0; i < children.size(); i++) {
    delete children[i];
  }
}

// TODO: implement member functions for derived classes
double AddExpr::eval(double x) const {
  if (numChildren() < 2) {
    throw PlotException("Add expression requires at least two operands");
  }
  double result = 0.0;
  for (size_t i = 0; i < numChildren(); i++) {
    result += getChild(i)->eval(x);
  }
  return result;
}

double SubExpr::eval(double x) const {
  if (numChildren() != 2) {
    throw PlotException("Subtract expression requires exactly two operands");
  }
  return getChild(1)->eval(x) - getChild(0)->eval(x);
}

double MultExpr::eval(double x) const {
  if (numChildren() < 2) {
    throw PlotException("Multiply expression requires at least two operands");
  }
  double result = 1.0;
  for (size_t i = 0; i < numChildren(); i++) {
    result *= getChild(i)->eval(x);
  }
  return result;
}

double DivExpr::eval(double x) const {
  if (numChildren() != 2) {
    throw PlotException("Divide expression requires exactly two operands");
  }
  double denominator = getChild(1)->eval(x);

  if (denominator == 0) {
    throw PlotException("Divide by zero error");
  }

  return getChild(0)->eval(x) / denominator;
}

double Pi::eval(double x) const {
  return M_PI;
}

double LiteralNumber::eval(double x) const {
    return m_value;
}

double Sin::eval(double x) const {
    if (numChildren() != 1) {
        throw PlotException("Sin expression requires exactly one operand");
    }
    return sin(getChild(0)->eval(x));
}

double Cos::eval(double x) const {
    if (numChildren() != 1) {
        throw PlotException("Cos expression requires exactly one operand");
    }
    return cos(getChild(0)->eval(x));
}
