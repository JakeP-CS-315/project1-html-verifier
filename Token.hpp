//
// Created by Ali Kooshesh on 1/22/23.
//

#ifndef PROJECT1_PHASE1_TOKEN_HPP
#define PROJECT1_PHASE1_TOKEN_HPP


#include <string>

using namespace std;

class Token {
public:
    Token(int, int);
    bool &isOpenTag();
    bool &isCloseTag();

    bool &isCloseAngleBracket();
    bool &isOpenAngleBracket();

    bool &endOfFile();
    bool &isCloseStandAloneTag();

    string tagName() const;

    void makeOpenTag(string);
    void makeCloseTag(string);
    void print();

    void printPosition();

    int lineNumber() { return _lineNumber; }
    int charPos() { return _charPos; }

private:
    bool _isOpenTag, _isCloseTag, _isCloseAngleBracket, _isOpenAngleBracket,
            _eof, _isCloseStandAloneTag;

    string _tagName;
    int _lineNumber, _charPos;
};

#endif //PROJECT1_PHASE1_TOKEN_HPP
