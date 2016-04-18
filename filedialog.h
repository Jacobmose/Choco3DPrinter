#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QDialog>

namespace Ui {
class FileDialog;
}

class FileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileDialog(QWidget *parent = 0);
    ~FileDialog();

private slots:
    void on_fileDialogCancelBtn_clicked();

    void on_fileDialogNextBtn_clicked();

private:
    Ui::FileDialog *ui;
};

#endif // FILEDIALOG_H
