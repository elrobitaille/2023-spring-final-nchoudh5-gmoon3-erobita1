#include <string>
#include <sstream>
#include <memory>
#include <deque>
#include "exception.h"
#include "expr.h"
#include "expr_parser.h"

ExprParser::ExprParser() {
}

ExprParser::~ExprParser() {
}

Expr* parsePfxExpr(std::deque<std::string> &tokens) {
  if (tokens.empty()) {
    throw PlotException("Empty");
  }

  std::string n = tokens.front();
  tokens.pop_front();

  if (n == "x" || n == "pi" ) { //n is natural number) 
    
  } else if (n == "(") {
    if (tokens.empty()) {
      throw PlotException("Empty");
    }

    n = tokens.front();
    tokens.pop_front();

    if (n != "sin" && n != "cos" && n != "+" && n != "-" && n != "*" && n != "/") {
      throw PlotException("Invalid function name");
    }

    while (tokens.front() != ")") {
      Expr *arg = parsePfxExpr(tokens);
    }

    //return result;

  } else {
    throw PlotException("Unexpected token");
  }
}


Expr *ExprParser::parse(std::istream &in) {
  // Recommended strategy: read all of the tokens in the expression
  // from the istream and put them in a sequence collection
  // such as a vector or deque. The call a recursive helper function
  // which parses the tokens and returns a pointer to an Expr object
  // repersenting the parsed expression.

  std::deque<std::string> tokens;
  std::string token;

  while (in >> token) {
    tokens.push_back(token);
  }

  std::deque<std::string> tokenDeque(tokens.begin(), tokens.end());
  Expr *parsedExpr = parsePfxExpr(tokenDeque);

  return parsedExpr;

}


/* 
  // assume tokens is a sequence of tokens comprising
  // the prefix expression
function parsePfxExpr(tokens) {
  n = remove first token from tokens

  if (n is "x", "pi", or a literal number) {
    create appropriate expression node and return it
  } else if (n is a left parenthesis) {
    n = remove first token from tokens

    if (n is none of sin, cos, +, -, *, or /) {
      throw exception // invalid function name
    }

    result = create appropriate function node

    while (first token of tokens is not right parenthesis) {
      arg = parsePfxExpr(tokens)
      add arg as child of result
    }

    remove first token from tokens // should be right paren

    return result
  } else {
    throw exception // unexpected token
  }
}
  */