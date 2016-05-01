#include "scenewindow.h"

#include <QKeyEvent>
#include <QGuiApplication>
#include <QOpenGLContext>

SceneWindow::SceneWindow(QScreen *screen) : QWindow(screen)
{
    setSurfaceType(QSurface::OpenGLSurface);

    QSurfaceFormat format;

    if(QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL)
    {
        format.setVersion(4, 3);
        format.setProfile(QSurfaceFormat::CoreProfile);
    }

    format.setDepthBufferSize(24);
    format.setSamples(4);
    format.setStencilBufferSize(8);
    setFormat(format);
    create();
}

SceneWindow::~SceneWindow()
{
}

void SceneWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
        case Qt::Key_Escape:
            QGuiApplication::quit();
            break;

        default:
            QWindow::keyPressEvent(e);

    }

}
