cmake_minimum_required(VERSION 3.28.3)
project(llvm-playground VERSION 0.1.0
                        DESCRIPTION "Learning about compilers"
                        LANGUAGES C)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
file(GLOB MY_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
message(STATUS "SOURCES: ${MY_SOURCES}")
add_executable(${CMAKE_PROJECT_NAME}_${CMAKE_PROJECT_VERSION} ${MY_SOURCES})
target_include_directories(${CMAKE_PROJECT_NAME}_${CMAKE_PROJECT_VERSION}
                            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
