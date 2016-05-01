#include "gcodehandler.h"

GCodeHandler::GCodeHandler()
{

}

QStringList GCodeHandler::getGCodesFromFile(QString fileName)
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

QStringList GCodeHandler::getFigureFileDirectory()
{
    QDir figureDir("C:/Users/jacobmosehansen/Desktop/Test");
    figureDir.setNameFilters(QStringList("*.gcode"));
    figureDir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);

    QStringList figureList = figureDir.entryList();

    for(int i=0; i<figureList.count(); i++)
    {
        figureList[i];
    }

    return figureList;
}

void GCodeHandler::handleAndSendGCodes(QString fileName)
{
    QSerialPort serial;
    serial.setPortName("");

    QString name = fileName;    

    QString lineData;
    lineData.append("\r");

    if(serial.open(QIODevice::ReadWrite))
    {
        serial.setBaudRate(QSerialPort::Baud57600);
        serial.setDataBits(QSerialPort::Data8);
        serial.setParity(QSerialPort::NoParity);
        serial.setStopBits(QSerialPort::OneStop);
        serial.setFlowControl(QSerialPort::NoFlowControl);

        QFile file("C:/Users/jacobmosehansen/Desktop/Test/" + name);

        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream i(&file);
            while(!i.atEnd())
            {
                //serial.write("M119");
                lineData = i.readLine();
                QByteArray ba = lineData.toLatin1();
                serial.write(ba);

                //Check for ack
                if(serial.readLine() == "ok")
                {
                    serial.write((const char*)lineData.data());
                } else {
                    //Wrong read
                }
            }
            file.close();
        }
        serial.close();
    } else {
        //Serial Error
    }
}

void GCodeHandler::sendGCode()
{
    QSerialPort serial;
    serial.setPortName("");

    if(serial.open(QIODevice::ReadWrite))
    {
        serial.setBaudRate(QSerialPort::Baud57600);
        serial.setDataBits(QSerialPort::Data8);
        serial.setParity(QSerialPort::NoParity);
        serial.setStopBits(QSerialPort::OneStop);
        serial.setFlowControl(QSerialPort::NoFlowControl);

        serial.write("M119");

        serial.close();
    } else {
        //Serial Error
    }

}
