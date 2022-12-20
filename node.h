#ifndef NODE_H
#define NODE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include "SyntaxTree.h"
class Node : public QGraphicsItem
{
public:
    Node();
    Node(SyntaxTree *treeNode);

     //outer bounding for the object
    QRectF boundingRect() const;
    //Important to paint the object
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //value to tell us if object is pressed or not
    bool hovered;
    SyntaxTree *treeNode;
protected:
    void mouseHoverEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // NODE_H
