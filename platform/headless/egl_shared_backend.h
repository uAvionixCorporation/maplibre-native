#include <mbgl/gl/renderer_backend.hpp>
#include <mbgl/gfx/renderable.hpp>
#include <mbgl/gl/renderable_resource.hpp>

class EGLSharedBackend final : public mbgl::gl::RendererBackend {
public:
    EGLSharedBackend();

    // Now returns the specific subsurface renderable
    //mbgl::gfx::RendererBackend& getRendererBackend() { return *this; }

    // We no longer implement Renderable here.
    // We receive it from the platform layer.
    // void setPrimaryRenderable(mbgl::gfx::Renderable& renderable) {
    //     primaryRenderable = &renderable;
    // }

    mbgl::gfx::Renderable& getDefaultRenderable() override;

protected:
    void activate() override;
    void deactivate() override;

    mbgl::gl::ProcAddress getExtensionFunctionPointer(const char* name) override;

    void updateAssumedState() override;

private:
    mbgl::gfx::Renderable* primaryRenderable = nullptr;
};
