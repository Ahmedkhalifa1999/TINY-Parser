#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SyntaxTreeWidget.h"
#include "SyntaxTree.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SyntaxTree *tree = new SyntaxTree();
    SyntaxTreeWidget *treeWidget = new SyntaxTreeWidget(tree);
    this->setCentralWidget(treeWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

