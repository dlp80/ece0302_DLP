#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include <stack>

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix){

    std::stack<string> sstack;
    
    // Scan each character from left to right
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        // If the character is an operator, pop two operands from stack and
        // concatenate them with the operator in the prefix form
        if (isoperator(c)) {
            string operand1 = sstack.top();
            sstack.pop();
            string operand2 = sstack.top();
            sstack.pop();
            string temp_prefix = c + operand2 + operand1;
            sstack.push(temp_prefix);
        } else {
            // If the character is an operand, push it onto the stack as a string
            string operand = string(1, c);
            sstack.push(operand);
        }
    }
    
    // The final element on the stack will be the prefix expression
    prefix = sstack.top();
}
