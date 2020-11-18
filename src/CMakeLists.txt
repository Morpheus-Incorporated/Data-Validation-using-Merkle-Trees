add_library(main INTERFACE)

# Create a library called "MerkleTree" which includes the source file "MerkleTree.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (src main.cpp)

# Make sure the compiler can find include files for our MerkleTree library
# when other libraries or executables link to Hello
target_include_directories (src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set MerkleTree compilation features to be propagated to client code.
target_compile_features(src INTERFACE cxx_std_17)