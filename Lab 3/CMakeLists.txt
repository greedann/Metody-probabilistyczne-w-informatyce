cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
    func.asm
)

set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64) # using elf64 for 64-bit

enable_language(ASM_NASM)

add_executable(lab3 ${SOURCES})
