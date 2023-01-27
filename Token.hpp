//
// Created by Ali Kooshesh on 1/22/23.
//

#ifndef PROJECT1_PHASE1_TOKEN_HPP
#define PROJECT1_PHASE1_TOKEN_HPP


#include <string>

using namespace std;

class Token {
public:
    Token();
    Token(int, int);
    bool &isOpenTag();
    bool &isCloseTag();

    bool &isCloseAngleBracket();
    bool &isOpenAngleBracket();

    bool &isError();

    bool &endOfFile();
    bool &isCloseStandAloneTag();

    string &tagName();

    void atPosition(int, int);
    bool hasPosition();

    void makeOpenTag(string);
    void makeCloseTag(string);
    void print();

private:
    bool _isOpenTag, _isCloseTag, _isCloseAngleBracket, _isOpenAngleBracket,
            _isError, _eof, _isCloseStandAloneTag;

    string _tagName;
    int _lineNumber, _charPos;
};

#endif //PROJECT1_PHASE1_TOKEN_HPP