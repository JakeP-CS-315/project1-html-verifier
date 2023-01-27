#include <iostream>
#include <cstring>
#include <vector>
#include "Tokenizer.hpp"
#include "Token.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if( argc != 2 ) { // require file as program argument
        cout << "usage: " << argv[0] << " nameOfAnInputFile" << endl;
        exit(1);
    }

    ifstream inputStream;
    inputStream.open(argv[1], ios::in);
    if( ! inputStream.is_open()) {
        cout << "Unable top open " << argv[1] << ". Terminating...";
        cout << strerror(errno) << endl;
        exit(2);
    }

    Tokenizer tokenizer(argv[1]);
    Token token = tokenizer.getToken();  // get the first token to start the while loop

    while( ! token.endOfFile() ) {
        token.print();
        token = tokenizer.getToken();
    }
}
