#include "node.h"

Node::Node()
{
    hovered = false;
}
//outer most edge of our shape
Node::Node(SyntaxTree * treeNode)
{
    hovered = false;
    this->treeNode = treeNode;
}

QRectF Node::boundingRect() const
{
    return QRectF(100,100,100,50);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush (Qt::white);
/*
    if(hovered)
    {
        brush.setColor(Qt::red);
    }
    else
    {
        brush.setColor(Qt::white);
    }
    */

    painter -> fillRect(rec,brush);
    painter -> setFont(QFont("Arial",12,-1,true));
    painter -> drawText(105,115,treeNode->getValue());

    if(treeNode->getType() >= ASSIGN_STATEMENT)
    {
        painter -> drawRect(rec);
    }
    else if(treeNode->getType() <= IDENTIFIER_EXPRESSION)
    {
         painter->drawEllipse(rec);
    }
}

void Node::mouseHoverEvent(QGraphicsSceneMouseEvent *event)
{
    hovered = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    hovered = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
