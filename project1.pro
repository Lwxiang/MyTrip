#-------------------------------------------------
#
# Project created by QtCreator 2014-08-28T09:16:44
#
#-------------------------------------------------

QT       += core gui
QT       += webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project1
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    titlebar.cpp \
    toolbar.cpp \
    contentwidget.cpp \
    statubar.cpp \
    newtrippage.cpp \
    nowtrippage.cpp \
    pasttrippage.cpp \
    photoholder.cpp \
    photocontent.cpp \
    photocontrol.cpp \
    maparea.cpp \
    diaryholder.cpp \
    diarycontrol.cpp \
    diarycontent.cpp

HEADERS  += widget.h \
    titlebar.h \
    toolbar.h \
    contentwidget.h \
    statubar.h \
    newtrippage.h \
    nowtrippage.h \
    pasttrippage.h \
    photoholder.h \
    photocontent.h \
    photocontrol.h \
    maparea.h \
    diaryholder.h \
    diarycontrol.h \
    diarycontent.h

FORMS    += widget.ui \
    titlebar.ui \
    toolbar.ui \
    contentwidget.ui \
    statubar.ui \
    newtrippage.ui \
    nowtrippage.ui \
    pasttrippage.ui \
    photoholder.ui \
    photocontent.ui \
    photocontrol.ui \
    maparea.ui \
    diaryholder.ui \
    diarycontrol.ui \
    diarycontent.ui

RESOURCES += \
    image.qrc

RC_ICONS = myappico.ico
