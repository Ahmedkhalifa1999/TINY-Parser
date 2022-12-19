#include "compiler.h"
#include "ui_compiler.h"
#include "fileeditor.h"
Compiler::Compiler(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Compiler)
{
    ui->setupUi(this);
    this->setWindowTitle("SCFTL");
    ui->TokensWriter->setText(QString::fromStdString(ScannerOutput));
}

Compiler::~Compiler()
{
    delete ui;
}
