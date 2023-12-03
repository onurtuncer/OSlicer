cmake_minimum_required(3.25)

project(OSlicer LANGUAGES CXX)

option (RELEASE          "Make a release build"                       OFF)
option (DEBUG            "Make a debug build"                          ON)
option (GIT_SUBMODULE    "Check submodules during build"               ON)

set(SOURCE_DIR          "${PROJECT_SOURCE_DIR}/OSlicer/src")
set(3RD_PARTY_DIR       "${PROJECT_SOURCE_DIR}/OSlicer/vendor")

IF (RELEASE AND DEBUG)
  MESSAGE(FATAL_ERROR "You can only make a release OR and debug build.")
ENDIF()

IF (RELEASE)
  SET(CMAKE_BUILD_TYPE Release)
ELSEIF (DEBUG)
  SET(CMAKE_BUILD_TYPE Debug)
ENDIF ()

message(STATUS "PROJECT_NAME               :" ${PROJECT_NAME})
message(STATUS "CMAKE_HOST_SYSTEM          :" ${CMAKE_HOST_SYSTEM})
message(STATUS "CMAKE_BUILD_TYPE           :" ${CMAKE_BUILD_TYPE})
message(STATUS "CMAKE_CXX_COMPILER         :" ${CMAKE_CXX_COMPILER})
message(STATUS "CMAKE_CXX_COMPILER_ID      :" ${CMAKE_CXX_COMPILER_ID})
message(STATUS "CMAKE_CXX_COMPILER_VERSION :" ${CMAKE_CXX_COMPILER_VERSION})
message(STATUS "CMAKE_CXX_FLAGS            :" ${CMAKE_CXX_FLAGS})
message(STATUS "CMAKE_MODULE_PATH:         :" ${CMAKE_MODULE_PATH})
message(STATUS "CMAKE_CURRENT_SOURCE_DIR   :" ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "CMAKE_CURRENT_BINARY_DIR   :" ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS "CMAKE_CURRENT_LIST_DIR     :" ${CMAKE_CURRENT_LIST_DIR})
message(STATUS "CMAKE_EXE_LINKER_FLAGS     :" ${CMAKE_EXE_LINKER_FLAGS})
message(STATUS "CMAKE_INSTALL_PREFIX       :" ${CMAKE_INSTALL_PREFIX})
message(STATUS "SOURCE_DIRECTORY           :" ${SOURCE_DIR})
message(STATUS "3RD_PARTY_DIRECTORTY       :" ${3RD_PARTY_DIR})
message(STATUS "CHECK GIT SUBMODULES       :" ${GIT_SUBMODULE})

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")

execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                OUTPUT_VARIABLE PACKAGE_GIT_VERSION
                ERROR_QUIET
                OUTPUT_STRIP_TRAILING_WHITESPACE)

    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(WARNING "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)



add_subdirectory(src)

add_subdirectory(vendor/hello_imgui)
