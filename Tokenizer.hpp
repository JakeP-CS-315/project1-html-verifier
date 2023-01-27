//
// Created by Jake Potrebic on 1/23/23.
//

#ifndef PROJECT1_HTML_TOKENIZER_TOKENIZER_HPP
#define PROJECT1_HTML_TOKENIZER_TOKENIZER_HPP

#include "string"
#include "fstream"
#include "optional"
#include "vector"
#include "Token.hpp"

using namespace std;

class Tokenizer {
public:
    explicit Tokenizer(string fileName);
    Token getToken();
private:
    int lineNum, colNum;
    string fileName;

    ifstream inputStream;
    bool charOfInterest(char c);

    string readTag();

    void skipChars(int length);
};


#endif //PROJECT1_HTML_TOKENIZER_TOKENIZER_HPP
