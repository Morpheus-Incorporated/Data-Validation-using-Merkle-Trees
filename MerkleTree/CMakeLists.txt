# Create the MerkleTree Interface library
add_library(MerkleTree INTERFACE)

# Create a library called "MerkleTree" which includes the source file "MerkleTree.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (MerkleTree MerkleTree.cpp)

# Make sure the compiler can find include files for our MerkleTree library
# when other libraries or executables link to Hello
target_include_directories (MerkleTree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set MerkleTree compilation features to be propagated to client code.
target_compile_features(MerkleTree INTERFACE cxx_std_17)

# target_include_directories(MerkleTree INTERFACE ${CMAKE_INSTALL_INCLUDEDIR})
# Add the include paths to the Reaktoro target
target_include_directories(MerkleTree
    INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Install Monotone interface library
install(TARGETS MerkleTree)

# EXPORT autodiffTargets

# Install autodiff header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/MerkleTree
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    PATTERN "CMakeLists.txt" EXCLUDE)
