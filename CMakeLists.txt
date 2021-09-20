project(AlgebraicCalculator)
add_executable(AlgebraicCalculator AlgebraicCalculator.cpp)

# Data Types
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/DataTypes")
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/DataTypes/Circle")
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/DataTypes/ExponentialInt")
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/DataTypes/Fraction")
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/DataTypes/Terms")
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/DataTypes/RightAngleShapes")

# Problem Types
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ProblemTypes")
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ProblemTypes/FixedDistanceUniformMotion")
target_include_directories(AlgebraicCalculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ProblemTypes/Polynomials")