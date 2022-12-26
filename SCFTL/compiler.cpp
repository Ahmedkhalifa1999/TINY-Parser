#include "compiler.h"
#include "ui_compiler.h"
#include "fileeditor.h"
#include "errors.h"
#include "parser.h"
#include "SyntaxTreeWidget.h"
#include "SyntaxTree.h"
#include <QMessageBox>
bool GrammerIsTrue=true;
Compiler::Compiler(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Compiler)
{
    ui->setupUi(this);
    this->setWindowTitle("SCFTL");
    ui->TokensWriter->setText(QString::fromStdString(ScannerOutput));
    if(GrammerIsTrue)
    {
        QPixmap pix(":/Resources/Resources/correct.png");
        ui->grammerlabel->setPixmap(pix);
    }
    else
    {
        QPixmap pix(":/Resources/Resources/wrong.png");
        ui->grammerlabel->setPixmap(pix);
    }

}

Compiler::~Compiler()
{
    delete ui;
}

void Compiler::on_pushButton_2_clicked()
{

}


void Compiler::on_ReturnToEditBTN_clicked()
{
    FileEditor *F = new FileEditor;
    F->show();
    this->close();
}


void Compiler::on_MainMenuBTN_clicked()
{
    MainWindow *W= new MainWindow;
    W->show();
    this->close();
}


void Compiler::on_ParseTreeBTN_clicked()
{
    if(GrammerIsTrue)
    {
        SyntaxTree *tree=P->getOutputTree();
        SyntaxTreeWidget *treeWidget = new SyntaxTreeWidget(tree);
        treeWidget->show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("The Grammar is not correct to draw a parse tree");
        msgBox.exec();
    }

}


void Compiler::on_DisplayErrorsBTN_clicked()
{
    Errors *E= new Errors;
    E->show();
}

