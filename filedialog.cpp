#include "filedialog.h"
#include "ui_filedialog.h"

FileDialog::FileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileDialog)
{
    ui->setupUi(this);
}

FileDialog::~FileDialog()
{
    delete ui;
}

void FileDialog::on_fileDialogCancelBtn_clicked()
{
    close();
}

void FileDialog::on_fileDialogNextBtn_clicked()
{
    //Test
}
