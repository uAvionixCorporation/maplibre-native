#include <EGL/egl.h>
#include <mbgl/gl/renderer_backend.hpp>

#include "egl_shared_backend.h"

EGLSharedBackend::EGLSharedBackend()
    : mbgl::gl::RendererBackend(mbgl::gfx::ContextMode::Shared)
{}

// mbgl::gfx::RendererBackend& getRendererBackend()
// {
//     return *this;
// }

// void setPrimaryRenderable(mbgl::gfx::Renderable& renderable)
// {
//     primaryRenderable = &renderable;
// }

mbgl::gfx::Renderable& EGLSharedBackend::getDefaultRenderable()
{
    return *primaryRenderable;
}

void EGLSharedBackend::activate()
{
    /* eglMakeCurrent(...) */
}

void EGLSharedBackend::deactivate()
{
    /* eglMakeCurrent(..., NULL) */
}

mbgl::gl::ProcAddress EGLSharedBackend::getExtensionFunctionPointer(const char* name)
{
    return (mbgl::gl::ProcAddress)eglGetProcAddress(name);
}

void EGLSharedBackend::updateAssumedState()
{
    // State tracking logic
}
