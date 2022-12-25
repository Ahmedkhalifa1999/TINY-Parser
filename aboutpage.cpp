#include "aboutpage.h"
#include "ui_aboutpage.h"

AboutPage::AboutPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutPage)
{
    ui->setupUi(this);
    this->setWindowTitle("About SCFTL");
}

AboutPage::~AboutPage()
{
    delete ui;
}
