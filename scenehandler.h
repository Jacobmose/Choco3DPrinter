#ifndef SCENEHANDLER_H
#define SCENEHANDLER_H

// 3d Render includes
#include <Qt3DCore/QCamera>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QAspectEngine>
#include <Qt3DInput/QInputAspect>
#include <Qt3DRender/QFrameGraph>
#include <Qt3DRender/QSceneLoader>
#include <Qt3DRender/QRenderAspect>
#include <Qt3DRender/QForwardRenderer>

class SceneHandler: public QObject
{
public:
    SceneHandler(Qt3DRender::QSceneLoader *loader) : m_loader(loader) { }

    void onStatusChanged();

private:
    void walkEntity(Qt3DCore::QEntity *e, int depth = 0);

    Qt3DRender::QSceneLoader *m_loader;
};

#endif // SCENEHANDLER_H
