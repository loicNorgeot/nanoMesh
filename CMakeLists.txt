cmake_minimum_required(VERSION 3.5)
project(nanoMesh)

# Disable building extras we won't need (pure C++ project)
set(NANOGUI_BUILD_EXAMPLE OFF CACHE BOOL " " FORCE)
set(NANOGUI_BUILD_PYTHON  OFF CACHE BOOL " " FORCE)
set(NANOGUI_INSTALL       OFF CACHE BOOL " " FORCE)
add_subdirectory(ext/nanogui)
# For reliability of parallel build, make the NanoGUI targets dependencies
set_property(TARGET glfw glfw_objects nanogui PROPERTY FOLDER "dependencies")
add_definitions(${NANOGUI_EXTRA_DEFS})
include_directories(${NANOGUI_EXTRA_INCS})

# Add libCommons
add_subdirectory(${PROJECT_SOURCE_DIR}/ext/commons)
include_directories(${PROJECT_SOURCE_DIR}/ext/commons/sources)
link_directories(${CMAKE_BINARY_DIR}/ext/commons)
if(TARGET Commons)
  get_target_property(COMMONS_TYPE Commons TYPE)
  message("FOUND THE ${COMMONS_TYPE} Commons")
else()
  message("DID NOT FIND THE COMMONS LIB")
endif()


# Custom definitions
add_definitions(-std=c++11 -g)
add_definitions(-DSHADERS_PATH="${PROJECT_SOURCE_DIR}/src/lib/shaders")

# Files
include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/src/lib)
file(GLOB LIBRARY_HEADERS ${PROJECT_SOURCE_DIR}/src/lib/*.h)
file(GLOB LIBRARY_SOURCES ${PROJECT_SOURCE_DIR}/src/lib/*.cpp)

# Library
add_library(libNanoMesh SHARED ${LIBRARY_HEADERS} ${LIBRARY_SOURCES})
target_link_libraries(libNanoMesh Commons nanogui ${NANOGUI_EXTRA_LIBS})
set_target_properties(libNanoMesh PROPERTIES PREFIX "")

# Executable
add_executable(nanoMesh ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(nanoMesh libNanoMesh)
