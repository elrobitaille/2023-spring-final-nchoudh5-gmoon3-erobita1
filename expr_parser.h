#ifndef FN_PARSER_H
#define FN_PARSER_H

#include <iostream>
#include "expr.h"

class ExprParser {
private:
  // value semantics are prohibited
  ExprParser(const ExprParser &);
  ExprParser &operator=(const ExprParser &);
  bool is_numeric(const std::string& str);

public:
  ExprParser();
  ~ExprParser();

  Expr *parse(std::istream &in);
};

#endif // FN_PARSER_H
