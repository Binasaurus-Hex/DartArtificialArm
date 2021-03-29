project(core)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

find_package(DART REQUIRED COMPONENTS collision-bullet CONFIG)
find_package(TinyXML REQUIRED)

include_directories(${DART_INCLUDE_DIRS})

file(GLOB srcs "*.h" "*.cpp")

add_library(core ${srcs} artificialArm/ArtificialArm.cpp artificialArm/ArtificialArm.h artificialArm/Muscle.cpp artificialArm/Muscle.h artificialArm/Muscles.cpp artificialArm/Muscles.h environments/PhysicalEnvironment.cpp environments/PhysicalEnvironment.h ../playground/main.cpp)
target_link_libraries(core ${DART_LIBRARIES} ${TinyXML_LIBRARIES})