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
    this->fileName=file;
    ui->CodeArea->setText(NULL);
    ui->CodeArea->setText(QString::fromStdString(this->code));
    int index= this->fileName.find_last_of('/');
    cout<<"filename: "<<this->fileName;
    cout<<"fileeditior: index= "<<index<<endl;

    if(index!=-1)
    {
        ui->FileNameLabel->setText(QString::fromStdString(this->fileName.substr(index+1,this->fileName.length()-1)));
    }
    else
    {
        ui->FileNameLabel->setText(QString::fromStdString("untitled"));
    }


}

FileEditor::~FileEditor()
{
    delete ui;
}

void FileEditor::SaveProcedure()
{
    QString text= ui->CodeArea->toPlainText();
    temp=text.toStdString();
    if((this->fileName)=="")
    {
       (this->fileName) = (QFileDialog::getOpenFileName(this, ("Open File"),"C://")).toStdString();
    }
    ofstream MyFile(this->fileName);
    string Text=text.toStdString();
    MyFile << Text;
    qInfo() <<"Save clicked";
    this->code=Text;
    int index= this->fileName.find_last_of('/');
    ui->FileNameLabel->setText(QString::fromStdString(this->fileName.substr(index+1,this->fileName.length()-1)));
}


void FileEditor::on_Save_clicked()
{

  SaveProcedure();

}




void FileEditor::on_OpenFile_clicked()
{
    QString fileNames = QFileDialog::getOpenFileName(this, ("Open File"),"C://");
    file=fileNames.toStdString();
    if(file!="")
    {
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

    int index= this->fileName.find_last_of('/');
    ui->FileNameLabel->setText(QString::fromStdString(this->fileName.substr(index+1,this->fileName.length()-1)));
    }
    else
    {
        //do nothing
    }




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
    file=fileNames.toStdString();
    if(file!="")
    {
    this->fileName=file;
    this->code="";
    ui->CodeArea->setText(QString::fromStdString(this->code));
    qInfo() <<"New Clicked";
    int index= this->fileName.find_last_of('/');
    ui->FileNameLabel->setText(QString::fromStdString(this->fileName.substr(index+1,this->fileName.length()-1)));
    }
    else
    {
        //do nothing
    }
}


void FileEditor::on_Compile_clicked()
{
    SaveProcedure();
    while(this->fileName=="")
    {
        SaveProcedure();
    }
    qInfo() <<"Compile clicked";
    ScannerOutput="";
     qInfo() <<"line 90";
    Tokens= getTokenList(this->code);
     qInfo() <<"line 92";
     qInfo() <<(QString::fromStdString(to_string( Tokens.size())));
     qInfo() <<"line 94";
    for(unsigned long long loop=0;loop<Tokens.size();loop++)
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

