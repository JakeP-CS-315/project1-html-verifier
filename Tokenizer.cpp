//
// Created by Jake Potrebic on 1/23/23.
//

#include "iostream"
#include "Tokenizer.hpp"

using namespace std;

Tokenizer::Tokenizer(string fileName): lineNum{1},
                                       colNum{0},
                                       fileName{fileName} {
    inputStream.open(fileName, ios::in);
}

bool Tokenizer::charOfInterest(char c) {
    // return true if c is a '<', '>', or '/' followed by a '>'
    return c == '>' || c == '<' || (c == '/' && inputStream.peek() == '>');
}

string Tokenizer::readTag() {
    string tagName;
    char c;
    // read the name as long as the character is an alphanumeric [0-9a-zA-Z]
    while (isalnum(inputStream.peek()) && inputStream.get(c)) {
        tagName += c;
        colNum++;
    }
    return tagName;
}

void Tokenizer::skipChars(int length) {
    // skip a specific number of chars
    for (int i = 0; i < length; i++) {
        inputStream.ignore();
        colNum++;
    }
}

Token Tokenizer::getToken() {
    char c;

    if( ! inputStream.is_open()) {
        cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        cout << "Make sure that " << fileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while (inputStream.get(c) && !charOfInterest(c)) {
        if (c == '\n') {
            lineNum++;
        }
        colNum++;
    }
    colNum++;

    Token token(lineNum, colNum);
    if( inputStream.eof() ) {
        token.endOfFile() = true;
        return token;
    }

    if (c == '<') {
        token.isOpenAngleBracket() = true;
        if (inputStream.peek() == '/') {
            skipChars(1); // skip the '/'
            string tagName = readTag();
            token.makeCloseTag(tagName);
        } else if (isalpha(inputStream.peek())){
            token.makeOpenTag(readTag());
        }
    } else if (c == '>') {
        token.isCloseAngleBracket() = true;
    } else if (c == '/') {
        token.isCloseStandAloneTag() = true;
        skipChars(1); // skip next char because charOfInterest already made sure it's a '>'
    }
    return token;
}
