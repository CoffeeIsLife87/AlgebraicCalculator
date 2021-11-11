cmake_minimum_required(VERSION 3.18)

project(AlgebraicCalculator)
add_executable(AlgebraicCalculator AlgebraicCalculator.cpp)

# Data Types
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/DataTypes")
target_sources( AlgebraicCalculator PRIVATE
    "DataTypes/Circle.hpp"
    "DataTypes/Fraction.hpp"
    "DataTypes/Parabola.hpp"
    "DataTypes/Primes.hpp"
    "DataTypes/Radical.hpp"
    "DataTypes/RightAngleShape.hpp"
    "DataTypes/Term.hpp"
)

# Problem Types
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ProblemTypes")
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ProblemTypes/FixedDistanceUniformMotion")
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ProblemTypes/Polynomials")

# Qt stuff
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
#
#find_package(Qt5 COMPONENTS Core)
#target_link_libraries(AlgebraicCalculator Qt5::Core)
#
#find_package(Qt5 COMPONENTS Widgets)
#target_link_libraries(AlgebraicCalculator Qt5::Widgets)
#
#find_package(Qt5 COMPONENTS Gui)
#target_link_libraries(AlgebraicCalculator Qt5::Gui)
#
#if ($(Qt5Widgets_FOUND) Qt5Gui_FOUND Qt5Core_FOUND)

