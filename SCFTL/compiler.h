#ifndef COMPILER_H
#define COMPILER_H

#include <QWidget>
#include <string>
namespace Ui {
class Compiler;
}

class Compiler : public QWidget
{
    Q_OBJECT

public:
    explicit Compiler(QWidget *parent = nullptr);
    ~Compiler();

private:
    Ui::Compiler *ui;
};

#endif // COMPILER_H
