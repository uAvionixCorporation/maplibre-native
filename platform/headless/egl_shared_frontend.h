#pragma once

#include <mbgl/renderer/renderer_frontend.hpp>
#include <mbgl/actor/scheduler.hpp>

class EGLSharedRendererFrontend : public mbgl::RendererFrontend {
public:
    EGLSharedRendererFrontend();
    ~EGLSharedRendererFrontend() override;

    void reset() override;
    void setObserver(mbgl::RendererObserver&) override;

    void update(std::shared_ptr<mbgl::UpdateParameters>) override;
    const mbgl::TaggedScheduler& getThreadPool() const override;
const mbgl::util::SimpleIdentity uniqueID;
private:
    mbgl::TaggedScheduler threadPool;

};
