#ifndef EXPR_H
#define EXPR_H

#include <vector>

// Base expression class
class Expr {
private:
  // TODO: field(s) to store links to child Expr nodes


  // value semantics are prohibited
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
class Expr : public 

#endif // EXPR_H
