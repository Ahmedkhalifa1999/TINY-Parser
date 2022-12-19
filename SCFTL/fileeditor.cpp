#include "fileeditor.h"
#include "ui_fileeditor.h"
#include "mainwindow.h"
#include "qfiledialog.h"
#include "compiler.h"
vector<Token> Tokens;
string ScannerOutput;
FileEditor::FileEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileEditor)
{
    ui->setupUi(this);
    this->setWindowTitle("SCFTL");
    qInfo() <<"From file editor.cpp";
    qInfo() <<(QString::fromStdString(this->code));
    this->code=temp;
    ui->CodeArea->setText(QString::fromStdString(this->code));
}

FileEditor::~FileEditor()
{
    delete ui;
}




void FileEditor::on_Save_clicked()
{
    QString text= ui->CodeArea->toPlainText();
    ofstream MyFile(this->fileName);
    string Text=text.toStdString();
    MyFile << Text;
    qInfo() <<"Save clicked";
    this->code=Text;

}




void FileEditor::on_OpenFile_clicked()
{
    QString fileNames = QFileDialog::getOpenFileName(this, ("Open File"),"C://");
    string file=fileNames.toStdString();
    this->fileName=file;
    ifstream MyReadFile(file);
    string carrier;

    this->code="";
    while (getline (MyReadFile,carrier)) {
      // Output the text from the file
      this->code+=carrier+"\n";
      //qInfo() << (QString::fromStdString(carrier));
    }

    ui->CodeArea->setText(QString::fromStdString(this->code));
    qInfo() <<"Open clicked";






}
void FileEditor::on_OpenFile_2_clicked()
{

}

void FileEditor::on_OpenFile_3_clicked()
{

}

void FileEditor::on_NewFile_clicked()
{
    QString fileNames = QFileDialog::getOpenFileName(this, ("Open File"),"C://");
    string file=fileNames.toStdString();
    this->fileName=file;
    this->code="";
    ui->CodeArea->setText(QString::fromStdString(this->code));
    qInfo() <<"New Clicked";
}


void FileEditor::on_Compile_clicked()
{
    qInfo() <<"Compile clicked";
    ScannerOutput="";
     qInfo() <<"line 90";
    Tokens= getTokenList(this->code);
     qInfo() <<"line 92";
     qInfo() <<(QString::fromStdString(to_string( Tokens.size())));
     qInfo() <<"line 94";
    for(int loop=0;loop<Tokens.size();loop++)
    {
        qInfo() <<"line 96";
        ScannerOutput+=Tokens[loop].Value+",  "+Tokens[loop].Type+"\n";
        qInfo() <<(QString::fromStdString(Tokens[loop].Type+"  "+Tokens[loop].Value+"\n"));
    }
    Compiler *C = new Compiler;
    C->setAttribute(Qt::WA_DeleteOnClose);
    C->show();
    this->close();
}

