#-------------------------------------------------
#
# Project created by QtCreator 2015-06-13T10:55:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = controller
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../colorDetection/colorDetector.cpp \
    colorDetectController.cpp

HEADERS  += mainwindow.h \
    ../colorDetection/colorDetector.h \
    colorDetectController.h

FORMS    += mainwindow.ui

CONFIG += c++11
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.10


INCLUDEPATH += "/usr/local/opt/opencv/include" \

LIBS += -L"/usr/local/opt/opencv/lib" \
         -lopencv_core \
         -lopencv_highgui \
         -lopencv_imgproc

