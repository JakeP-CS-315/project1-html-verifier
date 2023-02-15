//
// Created by Ali Kooshesh on 2/5/23.
//

#include <iostream>
#include "OpenTagStack.hpp"

using namespace std;

bool OpenTagStack::isInStack(string tagName) {
    for (int i = 0; i < stack.size(); i++) {
        if (stack[i].tagName() == tagName) {
            return true;
        }
    }
    return false;
}

void OpenTagStack::addTag(const Token &token) {
    stack.push_back(token);
}

bool OpenTagStack::empty() {
    return stack.empty();
}

Token OpenTagStack::top() {
    return stack.back();
}

void OpenTagStack::pop() {
    stack.pop_back();
}

void OpenTagStack::removeElementWithTagName(string tagName) {
    for (int i = stack.size() - 1; i >= 0; i--) {
        if (stack[i].tagName() == tagName) {
            stack.erase(stack.begin() + i);
            break;
        }
    }
}

void OpenTagStack::printStack() {
    for (int i = 0; i < stack.size(); i++) {
        cout << stack[i].tagName() << endl;
    }
}

void OpenTagStack::printTokensAbove(string tagName) {
    for (int i = stack.size() - 1; i >= 0; i--) {
        if (stack[i].tagName() == tagName) {
            break;
        }
        cout << "\t";
        stack[i].printPosition();
        cout << "<" << stack[i].tagName() << endl;
    }
}