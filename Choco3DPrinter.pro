#-------------------------------------------------
#
# Project created by QtCreator 2016-04-14T11:18:11
#
#-------------------------------------------------

QT       += 3dcore gui serialport opengl 3drender 3dinput

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Choco3DPrinter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    devicedialog.cpp \
    figuredialog.cpp \
    filedialog.cpp \
    gcodehandler.cpp \
    scenehandler.cpp \
    scenewindow.cpp

HEADERS  += mainwindow.h \
    devicedialog.h \
    figuredialog.h \
    filedialog.h \
    gcodehandler.h \
    scenehandler.h \
    scenewindow.h

FORMS    += mainwindow.ui \
    devicedialog.ui \
    figuredialog.ui \
    filedialog.ui
