cmake_minimum_required(VERSION 3.5)
project(pas_c)

include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11")

set(SOURCE_FILES
        src/main.cpp
        src/Scanner.cpp
        src/Scope.cpp
        src/Symbol.cpp
        src/Syntax.cpp
        src/TestCase.cpp
        src/Token.cpp
        src/TokenType.cpp
        src/Expressions.cpp
        src/Statements.cpp
        include/test/TokenTypeTest.h)

add_executable(pasc ${SOURCE_FILES})