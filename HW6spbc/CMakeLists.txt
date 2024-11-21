# CMakeList.txt : CMake project for HW6spbc, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (HW6spbc "HW6spbc.cpp" "HW6spbc.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HW6spbc PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
