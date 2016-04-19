#ifndef GCODEHANDLER_H
#define GCODEHANDLER_H

#include <QStringList>
#include <QDir>
#include <QTextStream>

class GCodeHandler
{    


public:
    GCodeHandler();
    ~GCodeHandler();

    QStringList getGCodesFromFile(QString);
    QStringList getFigureFileDirectory();
    void sendGCode(QString);

    QString figureFileName;
};

#endif // GCODEHANDLER_H
