#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileeditor.h"
#include "qfiledialog.h"
using namespace std;
QString fileNames;
string temp="";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("SCFTL");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_NewFolder_clicked()
{
    fileNames = QFileDialog::getOpenFileName(this, ("Open File"),"C://");
    string file=fileNames.toStdString();
    FileEditor *F = new FileEditor;
    F->setAttribute(Qt::WA_DeleteOnClose);
    F->fileName=file;
    F->show();
    this->close();






}


void MainWindow::on_OpenFolder_clicked()
{
    fileNames = QFileDialog::getOpenFileName(this, ("Open File"),"C://");
    string file=fileNames.toStdString();

    ifstream MyReadFile(file);
    string carrier;


    while (getline (MyReadFile,carrier)) {
      // Output the text from the file
      temp+=carrier+"\n";
      //qInfo() << (QString::fromStdString(carrier));
    }
    FileEditor *F = new FileEditor;
    F->setAttribute(Qt::WA_DeleteOnClose);
    F->fileName=file;
    F->code=temp;
    qInfo() << (QString::fromStdString(F->code));
    F->show();
    this->close();
}

