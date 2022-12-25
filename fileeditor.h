#ifndef FILEEDITOR_H
#define FILEEDITOR_H

#include <QWidget>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Scanner.h"
using namespace std;
extern vector<Token> Tokens;
extern string ScannerOutput;
namespace Ui {
class FileEditor;
}

class FileEditor : public QWidget
{
    Q_OBJECT


public:
    explicit FileEditor(QWidget *parent = nullptr);
    ~FileEditor();
    string fileName;
    string code;

private slots:
    void on_Save_clicked();

    void on_OpenFile_clicked();

    void on_OpenFile_2_clicked();

    void on_OpenFile_3_clicked();

    void on_NewFile_clicked();

    void on_Compile_clicked();



private:
    Ui::FileEditor *ui;

    void SaveProcedure();
};



#endif // FILEEDITOR_H
