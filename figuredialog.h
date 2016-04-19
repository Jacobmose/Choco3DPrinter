#ifndef FIGUREDIALOG_H
#define FIGUREDIALOG_H

#include <QDialog>
#include <QDir>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>

#include <QModelIndex>

#include "gcodehandler.h"

namespace Ui {
class FigureDialog;
}

class FigureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FigureDialog(QWidget *parent = 0);
    ~FigureDialog();

    QString getSelectedListViewItem();

private slots:

    void on_figureDialogNextBtn_clicked();

    void on_figureDialogCancelBtn_clicked();

private:
    Ui::FigureDialog *ui;
    QStringListModel *stringListModel;
    QStringListModel *modelTest;
    GCodeHandler *gcodeHandle;
    void showFigureFileDirectory();

};

#endif // FIGUREDIALOG_H
