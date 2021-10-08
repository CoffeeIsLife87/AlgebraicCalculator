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
