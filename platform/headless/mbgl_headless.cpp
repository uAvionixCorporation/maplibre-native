#include "egl_shared_backend.cpp"
#include "wayland_renderable.h"
#include "wayland_renderable_resource.h"
#include "egl_shared_frontend.h"

#include <mbgl/map/map.hpp>

int initialize() {

    mbgl::Size size(800, 480);

    auto resource = std::make_unique<WaylandRenderableResource>();

    WaylandRenderable renderableSurface(size, std::move(resource));

    EGLSharedBackend rendererBackend;

    EGLSharedRendererFrontend rendererFrontend;

    mbgl::Map map(
        rendererFrontend,
        mbgl::MapObserver::nullObserver(),
        mbgl::MapOptions(),
        mbgl::ResourceOptions());

    return 0;
}
