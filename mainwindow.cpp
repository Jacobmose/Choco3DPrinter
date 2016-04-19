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
    deviceDialog.setModal(true);
    deviceDialog.exec();
}
