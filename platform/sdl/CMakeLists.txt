find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(
    mbgl-sdl
    ${PROJECT_SOURCE_DIR}/platform/sdl/main.cpp
    ${PROJECT_SOURCE_DIR}/platform/sdl/sdl_view.cpp
    ${PROJECT_SOURCE_DIR}/platform/sdl/sdl_renderer_frontend.cpp
    ${PROJECT_SOURCE_DIR}/platform/sdl/settings_json.cpp
    ${PROJECT_SOURCE_DIR}/platform/sdl/test_writer.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/map/map_snapshotter.cpp
    ${PROJECT_SOURCE_DIR}/platform/sdl/example_custom_drawable_style_layer.cpp
    ${PROJECT_SOURCE_DIR}/platform/sdl/sdl_gl_backend.cpp
)

include(${PROJECT_SOURCE_DIR}/vendor/tinyobjloader.cmake)

target_link_libraries(
    mbgl-sdl
    PRIVATE tinyobjloader
)

set_property(
    SOURCE ${PROJECT_SOURCE_DIR}/platform/sdl/sdl_view.cpp
    PROPERTY COMPILE_DEFINITIONS MLN_ASSETS_PATH=\"${PROJECT_SOURCE_DIR}/platform/sdl/assets/\"
)

target_compile_definitions(
    mbgl-sdl
    PRIVATE
        MBGL_WITH_EGL=1
        MLN_WITH_WAYLAND=1
)

target_include_directories(
    mbgl-sdl
    PRIVATE
        ${GLFW_INCLUDE_DIRS}
        # For /platform/default/src/mbgl/map/map_snapshotter.hpp
    PRIVATE ${PROJECT_SOURCE_DIR}/src
)

# Use target_link_directories when we move away from CMake 3.10.
target_link_libraries(
    mbgl-sdl
    PRIVATE $<$<BOOL:${GLFW_LIBRARY_DIRS}>:-L${GLFW_LIBRARY_DIRS}> tinyobjloader
)

target_link_libraries(
    mbgl-sdl
    PRIVATE
        ${GLFW_LIBRARIES}
)

target_link_libraries(
    mbgl-sdl
    PRIVATE
        mbgl-vendor-args
        mbgl-vendor-rapidjson
        Mapbox::Map
        mbgl-compiler-options
        MapLibreNative::Base::cheap-ruler-cpp
        PRIVATE OpenGL::GL
)

set_property(TARGET mbgl-sdl PROPERTY FOLDER MapLibre)

install(TARGETS mbgl-sdl RUNTIME DESTINATION bin)
