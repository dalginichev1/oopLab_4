cmake_minimum_required(VERSION 3.14)
project(Figures_template)

set(CMAKE_CXX_STANDARD 20)

file(GLOB HEADER_FILES include/*.hpp inline/*.ipp)
file(GLOB SOURCE_FILES src/*.cpp)

add_executable(Figures
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

target_include_directories(Figures PRIVATE include inline)