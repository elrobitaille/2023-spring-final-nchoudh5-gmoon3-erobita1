// Nikhil Choudhary - nchoudh5
// Sun Moon - gmoon3 
// Edgar Robitaille - erobita1
#ifndef FN_PARSER_H
#define FN_PARSER_H

#include <iostream>
#include "expr.h"

class ExprParser {
private:
  // Declare copy constructor for ExprParser and assignment operator
  // value semantics are prohibited
  ExprParser(const ExprParser &);
  ExprParser &operator=(const ExprParser &);
  // Helper function to check if a string is numeric
  bool is_numeric(const std::string& str);

public:
  // Default Constructor for ExprParser
  ExprParser();
  // Destructor for ExprParser
  ~ExprParser();
  // Parse function that reads expression from input stream 
  Expr *parse(std::istream &in);
};

#endif // FN_PARSER_H
