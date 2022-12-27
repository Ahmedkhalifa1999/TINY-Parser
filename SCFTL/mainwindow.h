#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <fstream>
#include <string>
#include "fileeditor.h"
#include <stdio.h>

extern std::string temp;
extern  std::string file;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_NewFolder_clicked();

    void on_OpenFolder_clicked();

    void on_AboutBTN_clicked();

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
