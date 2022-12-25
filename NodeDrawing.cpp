#include "NodeDrawing.h"

NodeDrawing::NodeDrawing()
{
    hovered = false;
}
//outer most edge of our shape
NodeDrawing::NodeDrawing(SyntaxTree * treeNode, int x, int y)
{
    hovered = false;
    this->treeNode = treeNode;
    this->x = x - NODE_WIDTH/2;
    this->y = y - NODE_HEIGHT/2;
}

QRectF NodeDrawing::boundingRect() const
{
    return QRectF(x, y, NODE_WIDTH, NODE_HEIGHT);
}

void NodeDrawing::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

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
    painter -> drawText(x + 5, y + 15,treeNode->getValue());

    if(treeNode->getType() >= ASSIGN_STATEMENT)
    {
        painter -> drawRect(rec);
    }
    else if(treeNode->getType() <= IDENTIFIER_EXPRESSION)
    {
         painter->drawEllipse(rec);
    }
}

void NodeDrawing::mouseHoverEvent(QGraphicsSceneMouseEvent *event)
{
    hovered = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void NodeDrawing::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    hovered = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
