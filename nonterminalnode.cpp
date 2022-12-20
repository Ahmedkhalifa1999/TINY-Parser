#include "nonterminalnode.h"

NonTerminalNode::NonTerminalNode()
{
    hovered = false;
}
//outer most edge of our shape
NonTerminalNode::NonTerminalNode(std::string text)
{
    hovered = false;
    nodetext = QString::fromStdString(text);
}

QRectF NonTerminalNode::boundingRect() const
{
    return QRectF(0,0,100,50);
}

void NonTerminalNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush (Qt::white);

    if(hovered)
    {
        brush.setColor(Qt::red);
    }
    else
    {
        brush.setColor(Qt::white);
    }
    painter -> fillRect(rec,brush);
    painter -> setFont(QFont("Arial",12,-1,true));
    painter -> drawText(5,25,nodetext);
    painter -> drawRect(rec);
}

void NonTerminalNode::mouseHoverEvent(QGraphicsSceneMouseEvent *event)
{
    hovered = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void NonTerminalNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    hovered = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
