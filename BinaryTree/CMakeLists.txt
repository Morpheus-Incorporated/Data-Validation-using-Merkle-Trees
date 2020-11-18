# Create the BinaryTree Interface library
add_library(BinaryTree INTERFACE)

# Create a library called "BinaryTree" which includes the source file "BinaryTree.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (BinaryTree BinaryTree.cpp)

# Make sure the compiler can find include files for our BinaryTree library
# when other libraries or executables link to Hello
target_include_directories (BinaryTree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set BinaryTree compilation features to be propagated to client code.
target_compile_features(BinaryTree INTERFACE cxx_std_17)

# target_include_directories(BinaryTree INTERFACE ${CMAKE_INSTALL_INCLUDEDIR})
# Add the include paths to the Reaktoro target
target_include_directories(BinaryTree
    INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Install Monotone interface library
install(TARGETS BinaryTree)

# EXPORT autodiffTargets

# Install autodiff header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/BinaryTree
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    PATTERN "CMakeLists.txt" EXCLUDE)
