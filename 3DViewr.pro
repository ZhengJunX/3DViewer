#-------------------------------------------------
#
# Project created by QtCreator 2019-01-16T14:00:50
#
#-------------------------------------------------

QT       += core gui opengl widgets xml axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3DViewr
TEMPLATE = app
RC_ICONS = favicon.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        MainWindow.cpp \
    ExcelOperation.cpp \
    PointCloudViewer.cpp

HEADERS += \
        MainWindow.h \
    ExcelOperation.h \
    PointCloudViewer.h

FORMS += \
        MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# win32:CONFIG(release, debug|release): LIBS += -L$$PWD/QGLViewer/lib/ -lQGLViewer2
# else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/QGLViewer/lib/ -lQGLViewer2d
# else:unix: LIBS += -L$$PWD/QGLViewer/lib/ -lQGLViewer2

INCLUDEPATH += $$PWD/QGLViewer
DEPENDPATH += $$PWD/QGLViewer

win32 {
        # Seems to be needed for Visual Studio with Intel compiler
        # DEFINES *= WIN32

        # Use native OpenGL drivers with Qt5.5
        # No longer implicit since the ANGLE driver is now an alternative
        LIBS += -lopengl32 -lglu32

        isEmpty( QGLVIEWER_STATIC ) {
                CONFIG(debug, debug|release) {
                        LIBS *= -L$$PWD/QGLViewer/lib/ -lQGLViewerd2
                } else {
                        LIBS *= -L$$PWD/QGLViewer/lib/ -lQGLViewer2
                }
        } else {
                DEFINES *= QGLVIEWER_STATIC
                CONFIG(debug, debug|release) {
                        LIBS *= $$PWD/QGLViewer/lib/libQGLViewerd2.a
                } else {
                        LIBS *= $$PWD/QGLViewer/lib/libQGLViewer2.a
                }
        }
}

win32 {
        !designer {
                exists( $${ROOT_DIRECTORY}/examples/qglviewer.rc ) {
                        RC_FILE = $${ROOT_DIRECTORY}/examples/qglviewer.rc
                }
        }
}

