#pragma once

#include <mbgl/gl/renderable_resource.hpp>

class WaylandRenderableResource final : public mbgl::gl::RenderableResource {
public:
    WaylandRenderableResource();

    void bind() override;

    void swap() override;
};
