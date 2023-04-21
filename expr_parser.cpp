#include <string>
#include <sstream>
#include <memory>
#include <deque>
#include <iostream>
#include <cctype> // added for std::isdigit()
#include "exception.h"
#include "expr.h"
#include "expr_parser.h"

using std::string;

ExprParser::ExprParser() {
}

ExprParser::~ExprParser() {
}

Expr* parsePfxExpr(std::deque<std::string>& tokens) {
  if (tokens.empty()) {
    throw PlotException("Empty");
  }

  std::string n = tokens.front();
  tokens.pop_front();

  if (n == "x" || n == "pi" || std::isdigit(n[0])) { // n is a variable, constant, or literal number
    // create appropriate expression node and return it
    if (std::isdigit(n[0])) {
      double value = std::stod(n);
      return new LiteralNumber(value);
    }
    else {
      return new X();
    }
  }
  else if (n == "(") {
    if (tokens.empty()) {
      throw PlotException("Empty");
    }

    n = tokens.front();
    tokens.pop_front();

    if (n != "sin" && n != "cos" && n != "+" && n != "-" && n != "*" && n != "/") {
      throw PlotException("Invalid function name");
    }

    // create appropriate function node
    Expr* result = nullptr;
    if (n == "sin") {
      if (tokens.empty()) {
        throw PlotException("Empty");
      }
      Expr* arg = parsePfxExpr(tokens);
      result = new Sin(arg);
    }
    else if (n == "cos") {
      if (tokens.empty()) {
        throw PlotException("Empty");
      }
      Expr* arg = parsePfxExpr(tokens);
      result = new Cos(arg);
    }
    else if (n == "+") {
      result = new AddExpr();
    }
    else if (n == "-") {
      result = new SubExpr();
    }
    else if (n == "*") {
      result = new MultExpr();
    }
    else if (n == "/") {
      result = new DivExpr();
    }

    while (!tokens.empty() && tokens.front() != ")") {
      Expr* arg = parsePfxExpr(tokens);
      result->addChild(arg);
    }

    if (tokens.empty()) {
      throw PlotException("Missing right parenthesis");
    }

    tokens.pop_front(); // remove the right parenthesis token

    return result;
  }
  else {
    throw PlotException("Unexpected token");
  }
}


Expr* ExprParser::parse(std::istream& in) {
  // Recommended strategy: read all of the tokens in the expression
  // from the istream and put them in a sequence collection
  // such as a vector or deque. The call a recursive helper function
  // which parses the tokens and returns a pointer to an Expr object
  // representing the parsed expression.

  std::deque<std::string> tokens;
  std::string token;

  while (in >> token) {
    tokens.push_back(token);
  }

  std::deque<std::string> tokenDeque(tokens.begin(), tokens.end());
  Expr* parsedExpr = parsePfxExpr(tokenDeque);

  return parsedExpr;
}
