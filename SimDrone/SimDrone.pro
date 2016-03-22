#-------------------------------------------------
#
# Project created by QtCreator 2016-03-08T14:10:22
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimDrone
TEMPLATE = app


SOURCES += main.cpp\
        simdrone.cpp

HEADERS  += simdrone.h \
    checksum.h \
    dataHandle.h \
    dataStructureDefine.h \
    messageIDDefine.h

FORMS    += simdrone.ui
