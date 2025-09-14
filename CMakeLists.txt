cmake_minimum_required(VERSION 3.10)
project(DevanagriTextRecognizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# OpenCV
set(OpenCV_DIR "C:/opencv/build")   # adjust if needed
find_package(OpenCV REQUIRED)

# Include headers
include_directories(${OpenCV_INCLUDE_DIRS} src include())

# Source files
file(GLOB SRC_FILES src/*.cpp)

# Executable
add_executable(DevanagriTextRecognizer ${SRC_FILES})

# Link libraries
target_link_libraries(DevanagriTextRecognizer PRIVATE ${OpenCV_LIBS})
