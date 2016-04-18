#include "devicedialog.h"
#include "ui_devicedialog.h"

DeviceDialog::DeviceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceDialog)
{
    ui->setupUi(this);

    //figureDialog = new FigureDialog;
    //fileDialog = new FileDialog;
}

DeviceDialog::~DeviceDialog()
{
    delete ui;
}

void DeviceDialog::on_deviceDialogSDCardBtn_clicked()
{
    FigureDialog figureDialog;
    figureDialog.setModal(true);
    figureDialog.exec();
    close();
}

void DeviceDialog::on_deviceDialogUSBBtn_clicked()
{
    FileDialog fileDialog;
    fileDialog.setModal(true);
    fileDialog.exec();
    close();
}
