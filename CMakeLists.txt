# Use with MS vcpkg: "cmake .. -DCMAKE_TOOLCHAIN_FILE=C:\dev\vcpkg\scripts\buildsystems\vcpkg.cmake"
# Req. raylib 3.0 to be installed via vcpkg. 2nd alternative is to just run this fetch content CMakeLists.txt.

cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(cppRpgGame)

set(CMAKE_CXX_STANDARD 17)

# Set this to the minimal version you want to support
find_package(raylib 3.0 QUIET) # Let CMake search for a raylib-config.cmake

# You could change the QUIET above to REQUIRED and remove this if() clause
# This part downloads raylib and builds it if it's not installed on your system
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)

    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/master.tar.gz
    )

    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)

        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

        # build raylib
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})

    endif()

endif()

# This is the main part:

# file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*/*.cpp" "src/*/*.hpp")

# add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(
    "${CMAKE_SOURCE_DIR}/src/engine"
    "${CMAKE_SOURCE_DIR}/src/engine/default_components"
    "${CMAKE_SOURCE_DIR}/src/engine/default_objects"
    "${CMAKE_SOURCE_DIR}/src/game/"
    "${CMAKE_SOURCE_DIR}/src/game/components"
    "${CMAKE_SOURCE_DIR}/src/game/objects")

add_executable(${PROJECT_NAME}
    "src/engine/engine.cpp"
    "src/engine/object.cpp"
    "src/engine/camera.cpp"
    "src/engine/component.cpp"
    "src/engine/sprite.cpp"
    "src/engine/object_manager.cpp"
    "src/engine/scene_loader.cpp"
    "src/engine/depth_buffer.cpp"
    "src/engine/default_components/sprite_renderer.cpp"
    "src/engine/default_components/transform.cpp"
    "src/engine/default_objects/spritesheet.cpp"
    "src/game/components/comp_player_controller.cpp"
    "src/game/components/comp_top_down_controller.cpp"
    "src/game/components/comp_cam_transform.cpp"
    "src/game/objects/testobject.cpp"
    "src/game/objects/obj_player.cpp"
)

#set(raylib_VERBOSE 1)

target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${raylib_LIBRARIES})