cmake_minimum_required(VERSION 3.15)

# Set your project name to Trace
project(Trace CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory for your headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Find the libcurl library installed via vcpkg
find_package(CURL REQUIRED)

# Explicitly list your source files
set(SOURCES 
    src/main.cpp 
    src/network.cpp
    src/parser.cpp
)

# Create the executable target named 'trace'
add_executable(trace ${SOURCES})

# Link libcurl to your 'trace' executable
target_link_libraries(trace PRIVATE CURL::libcurl)