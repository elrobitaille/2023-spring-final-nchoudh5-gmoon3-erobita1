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
  return getChild(0)->eval(x) - getChild(1)->eval(x);
}

double MultExpr::eval(double x) const {
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
  (void) x;
  return M_PI;
}

double LiteralNumber::eval(double x) const {
  (void) x;
  return m_value;
}

double Sin::eval(double x) const {
  return std::sin(m_arg->eval(x));
}
void Sin::addChild(Expr* expr) {
  if (m_arg != nullptr) {
    throw PlotException("Sin only takes one argument");
  }
  m_arg = expr;
}

double Cos::eval(double x) const {
  return std::cos(m_arg->eval(x));
}
void Cos::addChild(Expr* expr) {
  if (m_arg != nullptr) {
    throw PlotException("Cos only takes one argument");
  }
  m_arg = expr;
}

