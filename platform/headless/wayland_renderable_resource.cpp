#include "wayland_renderable_resource.h"

WaylandRenderableResource::WaylandRenderableResource()
{}

void WaylandRenderableResource::bind()
{
    // Bind the FBO associated with the Wayland surf)ace
}

void WaylandRenderableResource::swap()
{
    // 1. Swap the EGL buffers for the subsurface
    // eglSwapBuffers(display, surface);

    // 2. Commit the Wayland surface to make it visible
    // wl_surface_commit(wayland_surface);
}
