#pragma once

#include <mbgl/gfx/renderable.hpp>

class WaylandRenderable final : public mbgl::gfx::Renderable {
public:
    WaylandRenderable(
        mbgl::Size size_,
        std::unique_ptr<mbgl::gfx::RenderableResource> resource);
};