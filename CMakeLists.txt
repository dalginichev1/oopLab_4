cmake_minimum_required(VERSION 3.14)
project(Figures_template)

set(CMAKE_CXX_STANDARD 20)

# Поиск GoogleTest в системе
find_package(GTest REQUIRED)

# Основная программа
file(GLOB HEADER_FILES include/*.hpp)
file(GLOB INLINE_FILES inline/*.ipp) 
file(GLOB SOURCE_FILES src/*.cpp)

add_executable(Figures
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${INLINE_FILES}
)

target_include_directories(Figures PRIVATE include inline)

# Исполняемый файл для тестов
add_executable(figures_tests 
    test/FigureTest.cpp
    test/main.cpp
    ${HEADER_FILES}
    ${INLINE_FILES}
)

target_link_libraries(figures_tests GTest::gtest GTest::gtest_main)
target_include_directories(figures_tests PRIVATE include inline)

include(GoogleTest)
gtest_discover_tests(figures_tests)