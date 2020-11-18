cmake_minimum_required(VERSION 3.10)

project(Data-Validation-using-Merkle-Trees VERSION 1.0)

add_library(Data-Validation-using-Merkle-Trees INTERFACE)
target_include_directories(Data-Validation-using-Merkle-Trees INTERFACE ${CMAKE_SOURCE_DIR}/Monotone)
target_compile_features(Data-Validation-using-Merkle-Trees INTERFACE cxx_std_17)

add_subdirectory(src)
add_subdirectory(BinaryTree)
add_subdirectory(MerkleTree)
