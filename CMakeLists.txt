# CMakeList.txt : CMake project for cs281_fa2020, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project ("cs281_adventure")

# Add source to this project's executable.
file(GLOB CPP_SOURCE
	"${PROJECT_SOURCE_DIR}/src/*.cpp"
)

include_directories(${PROJECT_SOURCE_DIR}/src)

# add_executable (cs281_adventure "cs281_adventure.cpp" "cs281_adventure.h")
add_executable (cs281_adventure ${CPP_SOURCE})

# TODO: Add tests and install targets if needed.
