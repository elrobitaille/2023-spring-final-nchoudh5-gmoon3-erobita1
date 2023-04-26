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
using std::deque;

ExprParser::ExprParser() {
}

ExprParser::~ExprParser() {
}

bool is_numeric(const string& str) {
  for (char c : str) {
    if (!isdigit(c) && c != '.') {
      return false;
    }
  }
  return !str.empty();
}

Expr* parsePfxExpr(deque<string>& tokens) {
  if (tokens.empty()) {
    throw PlotException("Empty");
  }

  string n = tokens.front();
  tokens.pop_front();

  if (n == "x" || n == "pi" || is_numeric(n)) {
    if (is_numeric(n)) {
      double value = std::stod(n);
      return new LiteralNumber(value);
    }
    else if (n == "pi") {
      return new Pi();
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
        throw PlotException("Missing argument for sin");
      }
      else if (!tokens.empty() && tokens.front() == ")") {
        throw PlotException("Missing argument for sin");
      }

      Expr* arg = parsePfxExpr(tokens);
      result = new Sin(arg);
    }
    else if (n == "cos") {
      if (tokens.empty()) {
        throw PlotException("Missing argument for cos");
      }
      else if (!tokens.empty() && tokens.front() == ")") {
        throw PlotException("Missing argument for cos");
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

    tokens.pop_front();

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

  deque<string> tokens;
  string token;

  while (in >> token) {
    tokens.push_back(token);
  }

  deque<string> tokenDeque(tokens.begin(), tokens.end());
  Expr* parsedExpr = parsePfxExpr(tokenDeque);

  return parsedExpr;
}
