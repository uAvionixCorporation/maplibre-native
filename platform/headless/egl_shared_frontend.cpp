#include "egl_shared_frontend.h"

EGLSharedRendererFrontend::EGLSharedRendererFrontend()
    : threadPool(mbgl::Scheduler::GetBackground(), uniqueID)
{}

EGLSharedRendererFrontend::~EGLSharedRendererFrontend()
{}

void EGLSharedRendererFrontend::reset()
{}

void EGLSharedRendererFrontend::setObserver(mbgl::RendererObserver&)
{}

void EGLSharedRendererFrontend::update(std::shared_ptr<mbgl::UpdateParameters>)
{}

const mbgl::TaggedScheduler& EGLSharedRendererFrontend::getThreadPool() const
{
    return threadPool;
}
