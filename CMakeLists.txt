cmake_minimum_required(VERSION 3.17)
project(artificialArm)

add_compile_options(-fPIC)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake")
add_definitions(-DMASS_ROOT_DIR="${CMAKE_HOME_DIRECTORY}")

add_subdirectory(core)
add_subdirectory(training)
add_subdirectory(playground)


