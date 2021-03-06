QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bestresultmodel.cpp \
    bestresultsdialog.cpp \
    fielddelegate.cpp \
    gameboardmodel.cpp \
    main.cpp \
    saperwindow.cpp \
    savedialog.cpp

HEADERS += \
    bestresultmodel.h \
    bestresultsdialog.h \
    fielddelegate.h \
    gameboardmodel.h \
    saperwindow.h \
    savedialog.h \
    settings.h

FORMS += \
    bestresultsdialog.ui \
    saperwindow.ui \
    savedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
