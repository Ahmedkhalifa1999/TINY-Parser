#ifndef COMPILER_H
#define COMPILER_H

#include <QWidget>
#include <string>
#include "mainwindow.h"
extern bool GrammerIsTrue;
namespace Ui {
class Compiler;
}

class Compiler : public QWidget
{
    Q_OBJECT

public:
    explicit Compiler(QWidget *parent = nullptr);
    ~Compiler();

private slots:
    void on_pushButton_2_clicked();

    void on_ReturnToEditBTN_clicked();

    void on_MainMenuBTN_clicked();

private:
    Ui::Compiler *ui;
};

#endif // COMPILER_H
