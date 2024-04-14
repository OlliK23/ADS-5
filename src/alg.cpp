// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int priority(char ch) {
    if (ch == '*' || ch == '/') {
        return 2;
    }
    if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

bool isOperator(char x) {
    return x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')';
}

std::string infx2pstfx(std::string inf) {
  // добавьте код
      std::string postfix;
    Stack<char, 100> stack;
    for (int i = 0; i < infix.length(); i++) {
        if (isdigit(infix[i])) {
            postfix += infix[i];
        }
        else if (isOperator(infix[i])) {
            if (infix[i] == '(') {
                stack.push(infix[i]);
            }
            else if (stack.isEmpty() || stack.get() == '(' || priority(infix[i]) > priority(stack.get())) {
                stack.push(infix[i]);
            }
            else if (infix[i] == ')') {
                while (!stack.isEmpty() && stack.get() != '(') {
                    postfix += ' ';
                    postfix += stack.get();
                    stack.pop();
                }
                stack.pop();
            }
            else {
                while (!stack.isEmpty() && priority(infix[i]) <= priority(stack.get())) {
                    postfix += ' ';
                    postfix += stack.get();
                    stack.pop();
                }
                stack.push(infix[i]);
            }
        }
    }
    while (!stack.isEmpty()) {
        postfix += ' ';
        postfix += stack.get();
        stack.pop();
    }
    return postfix;
}

int eval(std::string pref) {
  // добавьте код
Stack<int, 100> stack;
std::string number = "";
for (int i = 0; i < pref.length(); i++) {
    if (pref[i] == ' ') {
        continue;
    }
    number += pref[i];
}
for (int i = 0; i < number.length(); i++) {
    int num = number[i];
    if (isdigit(num)) {
        stack.push(num -'0');
    }
    else if (isOperator(number[i])) {
        int n1 = stack.get();
        stack.pop();
        int n2 = stack.get();
        stack.pop();
        if (num == '+') {
            stack.push(n1 + n2);
        }
        else if (num == '-') {
            stack.push(n2 - n1);
        }
        else if (num == '*') {
            stack.push(n1 * n2);
        }
        else if (num == '/') {
            stack.push(n2 / n1);
        }
        else {
            continue;
        }
    }
    else {
        continue;
    }
}
return stack.get();
}
