//
// Created by Ali Kooshesh on 2/5/23.
//

#include "CompletedTags.hpp"

using namespace std;

void CompletedTags::addCompletedTag(const Token &token1, const Token &token2) {
    pair<Token, Token> tokenPair = make_pair(token1, token2);
    if (completedTags.count(token1.tagName()) == 0) { // check if the tag isn't already in the map
        // create a new vector of token pairs and add the pair to it
        vector<pair<Token, Token>> tokens;
        tokens.push_back(tokenPair);
        completedTags[token1.tagName()] = tokens; // add a new entry to the map at the tagName
    } else {
        completedTags[token1.tagName()].push_back(tokenPair); // adds the tag pair to the vector at the tagName key
    }
}

void CompletedTags::print() {
    cout << "The following is a list of well-formed HTML tags." << endl << endl;
    for (auto &tagGroup : completedTags) { // iterate over all tags and their vectors
        cout << tagGroup.first << " appeared in the following ";
        if (tagGroup.second.size() == 1) {
            cout << "location." << endl;
        } else {
            cout << tagGroup.second.size() << " locations." << endl;
        }
        for (auto &tokenPair : tagGroup.second) { // iterate over all pairs of tokens for a tag
            cout << "\t";
            tokenPair.first.print();
            cout << " -- ";
            tokenPair.second.print();
            cout << endl;
        }
        cout << endl;
    }
}
