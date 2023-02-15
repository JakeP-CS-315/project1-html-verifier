//
// Created by Ali Kooshesh on 2/5/23.
//

#ifndef PROJECT1_PHASE2_STUDENT_FILES_COMPLETEDTAGS_HPP
#define PROJECT1_PHASE2_STUDENT_FILES_COMPLETEDTAGS_HPP

#include <iostream>
#include <map>
#include <vector>

#include "Token.hpp"

using namespace std;

class CompletedTags {
public:

    // addCompletedTag takes two arguments
    //     -- an open tag and its corresponding close tag
    //  or
    //     -- an open tag and a stand-alon close tag

    // In either case, if the map doesn't have an entry for the tag-name,
    // you add a vector to the map using the tag name and add the two tokens
    // to the vector.
    // On the other hand, if the tag-name already exists in the map, you just add the two
    // token to its vector.
    void addCompletedTag(const Token &token1, const Token &token2);

    // The error messages get printed in the main function.
    // This function prints each completed tag and the locations
    // where the tag has been found in the input.
    void print();

private:
    map<string, vector<pair<Token, Token>>> completedTags;
};


#endif //PROJECT1_PHASE2_STUDENT_FILES_COMPLETEDTAGS_HPP
