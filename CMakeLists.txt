cmake_minimum_required(VERSION 3.20)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(MoarPtr)

add_library(MoarPtr INTERFACE)

target_include_directories(MoarPtr INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(DIRECTORY include/MoarPtr/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/MoarPtr)

install(TARGETS MoarPtr EXPORT MoarPtrTargets)

install(EXPORT MoarPtrTargets
    FILE MoarPtrTargets.cmake
    NAMESPACE MoarPtr::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MoarPtr
)

option(BUILD_TESTS "Build Unit Tests." OFF)
if(BUILD_TESTS)
enable_testing()
add_subdirectory(test)
endif()
