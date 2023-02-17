#include <iostream>
#include <cstring>
#include <vector>
#include "Tokenizer.hpp"
#include "Token.hpp"
#include "OpenTagStack.hpp"
#include "CompletedTags.hpp"

using namespace std;

OpenTagStack tagStack;
CompletedTags completedTags;

Token handleOpenTag(Tokenizer &tokenizer, Token &token) {
    Token nextToken = tokenizer.getToken();
    if (nextToken.isCloseAngleBracket()) {
        tagStack.addTag(token); // add to stack if it's a valid open tag
        return tokenizer.getToken();
    } else if (nextToken.isCloseStandAloneTag()) {
        completedTags.addCompletedTag(token, nextToken);
        return tokenizer.getToken();
    } else {
        token.print();
        cout << " is missing a '>' or '/>'. Will discard it." << endl;
        return nextToken;
    }
}

Token handleCloseTag(Tokenizer &tokenizer, Token &token) {
    Token nextToken = tokenizer.getToken();
    if (!nextToken.isCloseAngleBracket()) {
        token.print();
        cout << " is missing a '>'. Will discard it." << endl;
        return nextToken;
    }
    if (!tagStack.empty()) {
        Token topOfStack = tagStack.top();
        if (topOfStack.tagName() == token.tagName()) {
            completedTags.addCompletedTag(topOfStack, token);
            tagStack.pop();
            return tokenizer.getToken();
        } else if (tagStack.isInStack(token.tagName())) {
            token.print();
            cout << " closes while the following tags remain open." << endl;
            tagStack.printTokensAbove(token.tagName());
            tagStack.removeElementWithTagName(token.tagName());
            return tokenizer.getToken();
        }
    }
    token.print();
    cout << " (with close angle bracket ";
    nextToken.print();
    cout << ") doesn't have a matching open tag. Will discard it." << endl;
    return tokenizer.getToken();
}

int main(int argc, char *argv[]) {
    if(argc != 2) { // require file as program argument
        cout << "usage: " << argv[0] << " nameOfAnInputFile" << endl;
        exit(1);
    }

    ifstream inputStream;
    inputStream.open(argv[1], ios::in);
    if(!inputStream.is_open()) {
        cout << "Unable top open " << argv[1] << ". Terminating...";
        cout << strerror(errno) << endl;
        exit(2);
    }

    Tokenizer tokenizer(argv[1]);
    Token token = tokenizer.getToken();  // get the first token to start the while loop

    while(!token.endOfFile()) {
        if (token.isOpenTag()) {
            token = handleOpenTag(tokenizer,token); // handleOpenTag returns the next token
        } else if (token.isCloseTag()) {
            token = handleCloseTag(tokenizer, token); // handleCloseTag returns the next token
        } else if (token.isCloseAngleBracket() || token.isOpenAngleBracket()) {
            token.printPosition();
            cout << (token.isCloseAngleBracket() ? "> ignoring random close angle-bracket."
                                                 : "< ignoring random open angle-bracket.") << endl;
            token = tokenizer.getToken();
        } else {
            token.print();
            cout << " unknown token."  << endl;
            exit(1);
        }
    }
    cout << endl;
    completedTags.print();
    return 0;
}

