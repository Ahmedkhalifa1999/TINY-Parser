QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    NodeDrawing.cpp \
    Scanner.cpp \
    SyntaxTree.cpp \
    SyntaxTreeWidget.cpp \
    aboutpage.cpp \
    compiler.cpp \
    errors.cpp \
    fileeditor.cpp \
    main.cpp \
    mainwindow.cpp \
    parser.cpp \
    runtimevariables.cpp

HEADERS += \
    NodeDrawing.h \
    SyntaxTree.h \
    SyntaxTreeWidget.h \
    aboutpage.h \
    compiler.h \
    errors.h \
    fileeditor.h \
    headers.hpp \
    mainwindow.h \
    parser.h \
    runtimevariables.h \
    scanner.hpp

FORMS += \
    aboutpage.ui \
    compiler.ui \
    errors.ui \
    fileeditor.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    Resources.qrc
