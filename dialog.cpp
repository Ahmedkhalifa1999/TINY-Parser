#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

    QPen blackPen (Qt::black);
    blackPen.setWidth(6);

    ui->graphicsView->setScene(scene);

    Node = new Node("Hello");

    scene -> addItem(Node);

}

Dialog::~Dialog()
{
    delete ui;
}

