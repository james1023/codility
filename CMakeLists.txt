set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_SOURCE_PATH /home/work/project/cmake)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_PATH}/linux-arm-toolchain.cmake)

project(test_codility)

include(${CMAKE_SOURCE_PATH}/linux-arm-platform.cmake)

message(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})

#common arg
#add_compile_options(-std=c++0x -Wall -fPIC -g -O0)

#set(CMAKE_SHARDED_LINKER_FLAGS "${CMAKE_SHARDED_LINKER_FLAGS} -lstdc++")

set(SOURCE_FILES Equi.cpp)

add_executable(test ${SOURCE_FILES})

#target_link_libraries(test_libjpeg libjpeg-turbo.so)
#add_dependencies(test_libjpeg jpeg-turbo)
