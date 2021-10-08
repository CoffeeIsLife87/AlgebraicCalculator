project(AlgebraicCalculator)
add_executable(AlgebraicCalculator AlgebraicCalculator.cpp)

# Data Types
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/DataTypes")

# Problem Types
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ProblemTypes")
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ProblemTypes/FixedDistanceUniformMotion")
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ProblemTypes/Polynomials")
