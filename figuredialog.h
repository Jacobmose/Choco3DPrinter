#ifndef FIGUREDIALOG_H
#define FIGUREDIALOG_H

#include <QDialog>
#include <QDir>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>

#include <QModelIndex>

#include <QDirIterator>

namespace Ui {
class FigureDialog;
}

class FigureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FigureDialog(QWidget *parent = 0);
    ~FigureDialog();   

private slots:

    void on_figureDialogNextBtn_clicked();

    void on_figureDialogCancelBtn_clicked();

private:
    Ui::FigureDialog *ui;
    QStringListModel *stringListModel;
    QStringListModel *modelTest;
    QDirIterator *dirIterator;
    void getFigureFileDirectory();
    QStringList getGCodesFromFile(QString);
};

#endif // FIGUREDIALOG_H
