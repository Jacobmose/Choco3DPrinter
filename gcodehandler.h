#ifndef GCODEHANDLER_H
#define GCODEHANDLER_H

#include <QStringList>
#include <QDir>
#include <QTextStream>
#include <QtSerialPort/QtSerialPort>


class GCodeHandler
{    
public:
    GCodeHandler();
    ~GCodeHandler();

    QStringList getGCodesFromFile(QString);
    QStringList getFigureFileDirectory();

    void handleAndSendGCodes(QString);
    void sendGCode();

    QString figureFileName;

};

#endif // GCODEHANDLER_H
