#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);



}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newPrintBtn_clicked()
{
  DeviceDialog deviceDialog;
  FigureDialog figureDialog;
  FileDialog fileDialog;

  deviceDialog.setModal(true);
  deviceDialog.exec();

  switch (deviceDialog.btnNumber)
  {
    case 0:
      break;
    case 1:
          figureDialog.setModal(true);
          figureDialog.exec();
      break;
    case 2:
          fileDialog.setModal(true);
          fileDialog.exec();
      break;
    default:
      break;
  }
}

void initializeScene()
{
    SceneWindow *window = new SceneWindow();
    //QWidget *container = QWidget::createWindowContainer(window);


    Qt3DCore::QAspectEngine engine;
    Qt3DInput::QInputAspect *inputAspect = new Qt3DInput::QInputAspect();
    engine.registerAspect(new Qt3DRender::QRenderAspect());
    engine.registerAspect(inputAspect);

    QVariantMap data;
    data.insert(QStringLiteral("surface"), QVariant::fromValue(static_cast<QSurface *>(window)));
    data.insert(QStringLiteral("eventSource"), QVariant::fromValue(window));
    engine.setData(data);

    // root entity
    Qt3DCore::QEntity *sceneRoot = new Qt3DCore::QEntity();

    // camera scene
    Qt3DCore::QCamera *camera = new Qt3DCore::QCamera(sceneRoot);
    camera->setFieldOfView(25);
    camera->setNearPlane(1);
    camera->setFarPlane(1000);
    camera->setViewCenter(QVector3D(0, 3, 0));

    inputAspect->setCamera(camera);

    Qt3DRender::QFrameGraph *frameGraphComponent = new Qt3DRender::QFrameGraph(sceneRoot);
    Qt3DRender::QForwardRenderer *forwardRenderer = new Qt3DRender::QForwardRenderer();
    forwardRenderer->setCamera(camera);
    forwardRenderer->setClearColor(Qt::blue);
    frameGraphComponent->setActiveFrameGraph(forwardRenderer);
    sceneRoot->addComponent(frameGraphComponent);

    // scene loader
    Qt3DCore::QEntity *sceneLoaderEntity = new Qt3DCore::QEntity(sceneRoot);
    Qt3DRender::QSceneLoader *sceneLoader = new Qt3DRender::QSceneLoader(sceneLoaderEntity);

    SceneHandler sceneHandler(sceneLoader);

    QObject::connect(sceneLoader, &Qt3DRender::QSceneLoader::statusChanged, &sceneHandler, &SceneHandler::onStatusChanged);

    sceneLoaderEntity->addComponent(sceneLoader);

    QUrl fileName;

    fileName = QUrl::fromLocalFile("file:://C:/Users/jacobmosehansen/Desktop/IKT/20mm_hollow_cube.stl");
    sceneLoader->setSource(fileName);

    engine.setRootEntity(sceneRoot);

}
