#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <devicedialog.h>
#include <figuredialog.h>
#include <gcodehandler.h>
#include <QPushButton>

#include <Qt3DCore/QCamera>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QAspectEngine>
#include <Qt3DInput/QInputAspect>
#include <Qt3DRender/QFrameGraph>
#include <Qt3DRender/QSceneLoader>
#include <Qt3DRender/QRenderAspect>
#include <Qt3DRender/QForwardRenderer>

#include <QSurface>

#include "scenehandler.h"
#include "scenewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_newPrintBtn_clicked();

private:
    Ui::MainWindow *ui;
    void initializeScene();



};

#endif // MAINWINDOW_H
