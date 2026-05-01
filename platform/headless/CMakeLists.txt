find_package(OpenGL REQUIRED)

add_library(
    mbgl-headless
    ${PROJECT_SOURCE_DIR}/platform/headless/egl_shared_backend.cpp
    ${PROJECT_SOURCE_DIR}/platform/headless/egl_shared_frontend.cpp
    ${PROJECT_SOURCE_DIR}/platform/headless/wayland_renderable.cpp
    ${PROJECT_SOURCE_DIR}/platform/headless/wayland_renderable_resource.cpp
    ${PROJECT_SOURCE_DIR}/platform/headless/mbgl_headless.cpp
)

add_executable(
    mbgl-headless-app
    ${PROJECT_SOURCE_DIR}/platform/headless/app.cpp
)

include(${PROJECT_SOURCE_DIR}/vendor/tinyobjloader.cmake)

target_link_libraries(
    mbgl-headless
    PRIVATE
        mbgl-vendor-args
        mbgl-vendor-rapidjson
        Mapbox::Map
        mbgl-compiler-options
        MapLibreNative::Base::cheap-ruler-cpp
        tinyobjloader
        OpenGL::GL
)

target_link_libraries(
    mbgl-headless-app
        mbgl-headless
)

set_property(TARGET mbgl-headless PROPERTY FOLDER MapLibre)

install(TARGETS mbgl-headless RUNTIME DESTINATION lib)
