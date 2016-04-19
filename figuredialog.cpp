#include "figuredialog.h"
#include "ui_figuredialog.h"

FigureDialog::FigureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FigureDialog)
{
    ui->setupUi(this);

    getFigureFileDirectory();
}

FigureDialog::~FigureDialog()
{
    delete ui;
}

void FigureDialog::on_figureDialogNextBtn_clicked()
{
    QStringList test;
    QString string;

    modelTest = new QStringListModel(this);

    ui->figureListView->setSelectionMode(QAbstractItemView::ExtendedSelection);

    foreach(const QModelIndex &index,
            ui->figureListView->selectionModel()->selectedIndexes())
        test.append(index.data(Qt::DisplayRole).toString());

    foreach(string, test)

    modelTest->setStringList(getGCodesFromFile(string));

    //modelTest->setStringList(test);

    ui->listView->setModel(modelTest);
}

void FigureDialog::on_figureDialogCancelBtn_clicked()
{
    close();
}

QStringList FigureDialog::getGCodesFromFile(QString fileName)
{
    QString name = fileName;
    QFile file("C:/Users/jacobmosehansen/Desktop/Test/" + name);

    QStringList fileData;
    QString lineData;

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream i(&file);
        while(!i.atEnd())
        {
            lineData = i.readLine();
            fileData.append(lineData);

        }
        file.close();
    }

    return fileData;
}

void FigureDialog::getFigureFileDirectory()
{
    stringListModel = new QStringListModel(this);

    QDir figureDir("C:/Users/jacobmosehansen/Desktop/Test");
    figureDir.setNameFilters(QStringList("*.gcode"));
    figureDir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);

    QStringList figureList = figureDir.entryList();

    for(int i=0; i<figureList.count(); i++)
    {
        figureList[i];
    }

    stringListModel->setStringList(figureList);

    ui->figureListView->setModel(stringListModel);
}
