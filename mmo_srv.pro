#-------------------------------------------------
#
# Project created by QtCreator 2015-05-17T23:54:07
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = mmo_srv
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

include(includes.pri)

HEADERS += \
    core/memoryallocator.h \
    math/abstract2vector.h \
    math/abstractmatrix.h \
    math/main.h

SOURCES += \
	    core/memoryallocator.cpp

#HEADERS += math/*.h \
#	    core/*.h

INCLUDEPATH += math \
		core
