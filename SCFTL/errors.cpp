#include "errors.h"
#include "ui_errors.h"
#include "fileeditor.h"
Errors::Errors(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Errors)
{

    ui->setupUi(this);
    string errorsStr;
    if(P->err.empty())
    {
     errorsStr="No errors";
     cout<<"No errors";
    }
    else
    {
     errorsStr="";

    for(int looper=0;looper<(P->err).size();looper++)
    {
        cout<<to_string(*next(P->err.begin(),looper));
         errorsStr+=to_string(*next(P->err.begin(),looper))+"\n";
    }
    }
    ui->ErrorsTXT->setText(QString::fromStdString(errorsStr));
}

Errors::~Errors()
{
    delete ui;
}
