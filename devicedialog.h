#ifndef DEVICEDIALOG_H
#define DEVICEDIALOG_H

#include <QDialog>
#include <figuredialog.h>
#include <filedialog.h>

namespace Ui {
class DeviceDialog;
}

class DeviceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceDialog(QWidget *parent = 0);
    ~DeviceDialog();

private slots:
    void on_deviceDialogSDCardBtn_clicked();

    void on_deviceDialogUSBBtn_clicked();

private:
    Ui::DeviceDialog *ui;
};

#endif // DEVICEDIALOG_H
