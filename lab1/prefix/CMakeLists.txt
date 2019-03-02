cmake_minimum_required(VERSION 3.13)
project(prefix)

SET(CMAKE_CXX_FLAGS  "-Wwrite-strings")

set(SOURCE_FILES
        "src/main.cpp"
        "src/emitter.cpp"
        "src/init.cpp"
        "src/lexer.cpp"
        "src/parser.cpp"
        "src/symbol.cpp")

add_executable(prefix ${SOURCE_FILES})