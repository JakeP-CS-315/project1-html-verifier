//
// Created by Ali Kooshesh on 1/22/23.
//

#include <iostream>
#include <iomanip>
#include "Token.hpp"

using namespace std;

Token::Token(int line, int pos): _isOpenTag{false},
                                 _isCloseTag{false},
                                 _isCloseAngleBracket{false},
                                 _isOpenAngleBracket{false},
                                 _eof{false},
                                 _isCloseStandAloneTag{false},
                                 _lineNumber{line},
                                 _charPos{pos} {}

bool &Token::isOpenTag() { return _isOpenTag; }
bool &Token::isCloseTag() { return _isCloseTag; }

bool &Token::isOpenAngleBracket() { return _isOpenAngleBracket; }
bool &Token::isCloseAngleBracket() { return _isCloseAngleBracket; }

bool &Token::endOfFile() { return _eof; }
bool &Token::isCloseStandAloneTag() { return _isCloseStandAloneTag; }

string Token::tagName() const {
    return _tagName;
}

void Token::makeOpenTag(string name) {
    _tagName = name;
    isOpenTag() = true;
}

void Token::makeCloseTag(string name) {
    _tagName = name;
    isCloseTag() = true;
}

void Token::print() {
    printPosition();
    if (isOpenAngleBracket() && isOpenTag()) {
        cout << "<" << tagName();
    } else if (isOpenAngleBracket() && isCloseTag()) {
        cout << "</" << tagName();
    } else if (isOpenAngleBracket()) {
        cout << "<";
    } else if (isCloseStandAloneTag()) {
        cout << "/>";
    } else if (isCloseAngleBracket()) {
        cout << ">";
    } else {
        cout << "Token::print -- unknown token.\n" << endl;
        exit(1);
    }
}

void Token::printPosition() {
    cout << "[" << setw(2) << _lineNumber << ", " <<  setw(3) << _charPos << "] ";
}
