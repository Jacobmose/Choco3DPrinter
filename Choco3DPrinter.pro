#-------------------------------------------------
#
# Project created by QtCreator 2016-04-14T11:18:11
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Choco3DPrinter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    devicedialog.cpp \
    figuredialog.cpp \
    filedialog.cpp \
    gcodehandler.cpp

HEADERS  += mainwindow.h \
    devicedialog.h \
    figuredialog.h \
    filedialog.h \
    gcodehandler.h

FORMS    += mainwindow.ui \
    devicedialog.ui \
    figuredialog.ui \
    filedialog.ui
