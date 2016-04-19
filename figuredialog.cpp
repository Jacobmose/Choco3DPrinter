#include "figuredialog.h"
#include "ui_figuredialog.h"

FigureDialog::FigureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FigureDialog)
{
    ui->setupUi(this);

    showFigureFileDirectory();
}

FigureDialog::~FigureDialog()
{
    delete ui;
}

void FigureDialog::on_figureDialogNextBtn_clicked()
{
    modelTest = new QStringListModel(this);

    QString itemName;
    itemName = getSelectedListViewItem();

    modelTest->setStringList(gcodeHandle->getGCodesFromFile(itemName));

    ui->listView->setModel(modelTest);
}

void FigureDialog::on_figureDialogCancelBtn_clicked()
{
    close();
}

QString FigureDialog::getSelectedListViewItem()
{
    QString itemName;

    ui->figureListView->setSelectionMode(QAbstractItemView::ExtendedSelection);

    foreach(const QModelIndex &index,
            ui->figureListView->selectionModel()->selectedIndexes())
        itemName = index.data(Qt::DisplayRole).toString();

    return itemName;
}

void FigureDialog::showFigureFileDirectory()
{
    QStringList fileDirectoryList;

    fileDirectoryList = gcodeHandle->getFigureFileDirectory();

    stringListModel = new QStringListModel(this);

    stringListModel->setStringList(fileDirectoryList);

    ui->figureListView->setModel(stringListModel);
}
