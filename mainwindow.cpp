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
