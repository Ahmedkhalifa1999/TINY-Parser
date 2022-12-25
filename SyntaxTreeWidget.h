#ifndef SYNTAXTREEWIDGET_H
#define SYNTAXTREEWIDGET_H

#include <QDialog>
#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>
#include "SyntaxTree.h"

#define NODE_VERTICAL_SEPARATION 40
#define NODE_HORIZONTAL_SEPARATION 40

class SyntaxTreeWidget : public QGraphicsView
{
    Q_OBJECT

public:
    SyntaxTreeWidget(SyntaxTree *tree, QWidget *parent = nullptr);

private:
    QGraphicsScene *scene;

    int getTreeWidth(SyntaxTree *tree);

    void drawTree(SyntaxTree *tree, int x = 0, int y = 0);
};

#endif // SYNTAXTREEWIDGET_H
