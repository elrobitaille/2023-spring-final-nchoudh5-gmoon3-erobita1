// Nikhil Choudhary - nchoudh5
// Sun Moon - gmoon3 
// Edgar Robitaille - erobita1
#ifndef EXPR_H
#define EXPR_H

#include "exception.h"
#include <cmath>
#include <vector>

// Base expression class
class Expr {
private:
  // Field to store links to child Expr nodes
  std::vector<Expr*> children;

  // Disable value semantics
  Expr(const Expr &);
  Expr &operator=(const Expr &);

public:
  Expr();
  virtual ~Expr();

  virtual double eval(double x) const = 0;

  // Add member functions
  void addChild(Expr* child) { children.push_back(child); }
  Expr* getChild(size_t i) const { return children[i]; }
  size_t numChildren() const { return children.size(); }
};

// Derived expression classes
class AddExpr : public Expr {
public:
  // Constructor
  AddExpr() {}

  // Destructor
  virtual ~AddExpr() {}

  // Evaluation function
  virtual double eval(double x) const;
};

class SubExpr : public Expr {
public:
  // Constructor
  SubExpr() {}

  // Destructor
  virtual ~SubExpr() {}

  // Evaluation function
  virtual double eval(double x) const;
};

class MultExpr : public Expr {
public:
  // Constructor
  MultExpr() {}

  // Destructor
  virtual ~MultExpr() {}

  // Evaluation function
  virtual double eval(double x) const;
};

class DivExpr : public Expr {
public:
  // Constructor
  DivExpr() {}

  // Destructor
  virtual ~DivExpr() {}

  // Evaluation function
  virtual double eval(double x) const;
};

// X class
class X : public Expr {
public:
  X() {}

  double eval(double x) const {
    return x;
  }
};

// Pi class
class Pi : public Expr {
public:
  Pi() {}

  virtual double eval(double x) const;
};

// LiteralNumber class
class LiteralNumber : public Expr {
private:
  double m_value;

public:
  LiteralNumber(double value) : m_value(value) {}

  virtual double eval(double x) const;
};

// Sin class
class Sin : public Expr {
private:
  Expr *m_arg;

public:
  Sin(Expr *arg) : m_arg(arg) {}

  ~Sin() {
    delete m_arg;
  }

  virtual double eval(double x) const;
  
  virtual void addChild(Expr* expr);
};

// Cos class
class Cos : public Expr {
private:
  Expr *m_arg;

public:
  Cos(Expr *arg) : m_arg(arg) {}

  ~Cos() {
    delete m_arg;
  }

  virtual double eval(double x) const;

  virtual void addChild(Expr* expr);
};

#endif // EXPR_H
