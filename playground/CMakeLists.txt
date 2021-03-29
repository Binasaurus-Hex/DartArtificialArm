project(playground)

add_compile_options(-fPIC)
add_compile_options(-std=gnu++11)
add_compile_options(-Wdeprecated-declarations)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${DART_INCLUDE_DIRS})
find_package(Boost 1.66.0 COMPONENTS filesystem python3 numpy3)
find_package(DART REQUIRED COMPONENTS gui collision-bullet CONFIG)

link_directories("/core")
include_directories("/core")

file(GLOB srcs "*.h" "*.cpp")

add_executable(playground ${srcs} ../EnvWindow.cpp ../EnvWindow.h)
target_link_libraries(playground ${DART_LIBRARIES} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} core)