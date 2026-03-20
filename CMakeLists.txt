cmake_minimum_required(VERSION 3.20)

# ---- Project ----
project(lutop)

set(CMAKE_CXX_STANDARD 23)
if(NOT CMAKE_BUILD_TYPE)
    set(default_build_type "Debug")
    message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
    set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "lutop Build Type: ${CMAKE_BUILD_TYPE}")

# ---- Add source files ----
file(GLOB_RECURSE headers 
        "${CMAKE_SOURCE_DIR}/include/*.h"
        "${CMAKE_SOURCE_DIR}/include/*.hpp"
        )
file(GLOB_RECURSE sources
        "${CMAKE_SOURCE_DIR}/src/*.c"
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        )

# ---- Generating executable ----
add_definitions(-DSOME_DEFINITION)

add_executable(lutop ${sources})

target_include_directories(lutop PRIVATE "${CMAKE_SOURCE_DIR}/include")

# ---- Setting the version for lutop ----
set(lutop_Version_Major 0)
set(lutop_Version_Minor 1)
set(lutop_Version_Patch 0)
set(lutop_Version_Status "-dev")
set(PROJECT_VERSION
    "${lutop_Version_Major}.${lutop_Version_Minor}.${lutop_Version_Patch}${lutop_Version_Status}"
)
