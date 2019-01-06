cmake_minimum_required (VERSION 3.2.0)
project (spicyTech)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/neo")

add_subdirectory (${SRC_DIR}/engine)

set(GLFW_DIR "${SRC_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")




