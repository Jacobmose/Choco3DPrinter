#include "devicedialog.h"
#include "ui_devicedialog.h"

DeviceDialog::DeviceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceDialog)
{
    btnNumber = 0;
    ui->setupUi(this);
}

DeviceDialog::~DeviceDialog()
{
    delete ui;
}

void DeviceDialog::on_deviceDialogSDCardBtn_clicked()
{
    btnNumber = 1;
    close();
}

void DeviceDialog::on_deviceDialogUSBBtn_clicked()
{
    btnNumber = 2;
    close();
}
