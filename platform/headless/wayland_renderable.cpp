#include "wayland_renderable.h"

WaylandRenderable::WaylandRenderable(
    mbgl::Size size_,
    std::unique_ptr<mbgl::gfx::RenderableResource> resource)
    : mbgl::gfx::Renderable(size_, std::move(resource))
{}
