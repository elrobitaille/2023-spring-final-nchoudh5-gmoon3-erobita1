#include <cmath>
#include <stdexcept>
#include "exception.h"
#include "expr.h"

// Expr (base class)

Expr::Expr() {
}

Expr::~Expr() {
  // TODO: deallocate child nodes (if any)
  for (size_t i = 0; i < children.size(); i++) {
    delete children[i];
  }
}

// TODO: implement member functions for derived classes
double AddExpr::eval(double x) const {
  return left_->eval(x) + right_->eval(x);
}

double SubExpr::eval(double x) const {
  return left_->eval(x) - right_->eval(x);
}

double MultExpr::eval(double x) const {
  return m_left->eval(x) * m_right->eval(x);
}

double DivExpr::eval(double x) const {
  double denominator = m_right->eval(x);

  if (denominator == 0) {
    throw std::runtime_error("Divide by zero error");
  }

  return m_left->eval(x) / denominator;
}

double Pi::eval(double x) const {
  return M_PI;
}

double LiteralNumber::eval(double x) const {
    return m_value;
}

double Sin::eval(double x) const {
    return sin(m_arg->eval(x));
}

double Cos::eval(double x) const {
    return cos(m_arg->eval(x));
}
