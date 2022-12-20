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

    nonTerminalNode = new NonTerminalNode("Hello");
    terminalNode = new TerminalNode("Yes");
    terminalNode->setPos(100,100);
    scene -> addItem(nonTerminalNode);
    scene -> addItem(terminalNode);
}

Dialog::~Dialog()
{
    delete ui;
}

