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
    fileeditor.cpp \
    main.cpp \
    mainwindow.cpp \
    Parser.cpp \
    runtimevariables.cpp

HEADERS += \
    NodeDrawing.h \
    Scanner.h \
    SyntaxTree.h \
    SyntaxTreeWidget.h \
    aboutpage.h \
    compiler.h \
    fileeditor.h \
    headers.h \
    mainwindow.h \
    Parser.h \
    runtimevariables.h

FORMS += \
    aboutpage.ui \
    compiler.ui \
    fileeditor.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Resources/151030-200.png \
    Resources/3820673-200.png \
    Resources/ASU.png \
    Resources/ASU_50.png \
    Resources/Logo.png \
    Resources/MainMenu.png \
    Resources/SCFTL-logos.zip \
    Resources/SCFTL-logos/2155164-200.png \
    Resources/SCFTL-logos/3820673-200_1_50x50.png \
    Resources/SCFTL-logos/Home.png \
    Resources/SCFTL-logos/My project.png \
    Resources/SCFTL-logos/Pngtreevector_house_icon_4013710_100x100.png \
    Resources/SCFTL-logos/SCFTL-logos.jpeg \
    Resources/SCFTL-logos/SCFTL-logos_black.png \
    Resources/SCFTL-logos/SCFTL-logos_transparent.png \
    Resources/SCFTL-logos/SCFTL-logos_transparent_1_400x400.png \
    Resources/SCFTL-logos/SCFTL-logos_white.png \
    Resources/SCFTL-logos/Tree.png \
    Resources/SCFTL-logos/about.png \
    Resources/SCFTL-logos/compile.png \
    Resources/SCFTL-logos/edit.png \
    Resources/SCFTL-logos/error-icon.png \
    Resources/SCFTL-logos/error.png \
    Resources/SCFTL-logos/file-open-2.png \
    Resources/SCFTL-logos/file-open-2_1_50x50.png \
    Resources/SCFTL-logos/file-open-2_30x30.png \
    Resources/SCFTL-logos/intel-bi-endian-compiler.png \
    Resources/SCFTL-logos/logo_info.txt \
    Resources/SCFTL-logos/pngfind.com-save-icon-png-2201567.png \
    Resources/SCFTL-logos/save.png \
    Resources/SCFTL-logos/—Pngtree—vector house icon_4013710.png \
    Resources/SCFTL.png \
    Resources/SCFTL_50.jpg \
    Resources/correct.png \
    Resources/information-about-us-icon-16.png \
    Resources/new.png \
    Resources/png-clipart-computer-icons-icon-design-house-symbol-qualifications-wales-main-menu-angle-building.png \
    Resources/png-transparent-menu-icon-icon-design-hamburger-button-house-css-sprites-user-interface-home-page-triangle-thumbnail.png \
    Resources/wrong.png
