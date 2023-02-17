cmake_minimum_required(VERSION 3.24)
project(project1-html-verifier)

set(CMAKE_CXX_STANDARD 17)

add_executable(project1-html-verifier main.cpp CompletedTags.cpp CompletedTags.hpp OpenTagStack.cpp OpenTagStack.hpp Token.cpp Token.hpp Tokenizer.cpp Tokenizer.hpp)
