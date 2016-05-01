#ifndef SCENEWINDOW_H
#define SCENEWINDOW_H

#include <QWindow>

class SceneWindow : public QWindow
{
    Q_OBJECT
public:
    explicit SceneWindow(QScreen *screen = 0);
    ~SceneWindow();

protected:
    virtual void keyPressEvent(QKeyEvent *e);
};

#endif // SCENEWINDOW_H
