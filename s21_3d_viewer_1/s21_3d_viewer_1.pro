QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    widget.cpp \
    ../s21_3D_Viewer_1.0.c

HEADERS += \
    mainwindow.h \
    widget.h \
    ../QtGifImage-master/src/gifimage/qgifimage.h

FORMS += \
    mainwindow.ui \
    widget.ui


include (../QtGifImage-master/src/gifimage/qtgifimage.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


