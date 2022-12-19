#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("D:/Faculty/Senior 2/Semester 1/Design of Compilers/Project/SCFTL/Resources/SCFTL-logos/SCFTL-logos_transparent_1_400x400.png"));
    MainWindow w;
    qInfo() << "C++ Style Info Message";
    w.show();
    return a.exec();
}
