cmake_minimum_required(VERSION 2.8.12)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(IR AST.cc
            Value.cc User.cc
            Type.cc
            Constant.cc Constants.cc
            Instruction.cc BasicBlock.cc)
