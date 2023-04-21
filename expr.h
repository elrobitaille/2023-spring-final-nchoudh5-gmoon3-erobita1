#ifndef EXPR_H
#define EXPR_H

#include <cmath>
#include <vector>

// Base expression class
class Expr {
private:
  // TODO: field(s) to store links to child Expr nodes
  // value semantics are prohibited
  std::vector<Expr*> children; // links to child Expr nodes
  Expr(const Expr &);
  Expr &operator=(const Expr &);

public:
  Expr();
  virtual ~Expr();

  virtual double eval(double x) const = 0;

  // TODO: add member functions
  void addChild(Expr* child) { children.push_back(child); }
  Expr* getChild(size_t i) const { return children[i]; }
  size_t numChildren() const { return children.size(); }
};

// TODO: add derived expression classes
class AddExpr : public Expr {
public:
  // constructor
  AddExpr(Expr *left, Expr *right) : left_(left), right_(right) {}

  // destructor
  ~AddExpr() {
    delete left_;
    delete right_;
  }

  // evaluation function
  virtual double eval(double x) const;
private:
  // links to child nodes
  Expr *left_;
  Expr *right_;
};

class SubExpr : public Expr {
public:
  // constructor
  SubExpr(Expr *left, Expr *right) : left_(left), right_(right) {}

  // destructor
  ~SubExpr() {
    delete left_;
    delete right_;
  }

  // evaluation function
  virtual double eval(double x) const;
private:
  // links to child nodes
  Expr *left_;
  Expr *right_;
};

// MultExpr

class MultExpr : public Expr {

public:
  MultExpr(Expr* left, Expr* right) : m_left(left), m_right(right) {}

  ~MultExpr() {
    delete m_left;
    delete m_right;
  }

  virtual double eval(double x) const;

private:
  Expr* m_left;
  Expr* m_right;
};


// DivExpr

class DivExpr : public Expr {
public:
  DivExpr(Expr* left, Expr* right) : m_left(left), m_right(right) {}

  ~DivExpr() {
    delete m_left;
    delete m_right;
  }

  virtual double eval(double x) const;
private:
  Expr* m_left;
  Expr* m_right;
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
};

#endif // EXPR_H
