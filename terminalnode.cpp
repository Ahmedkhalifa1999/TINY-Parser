#include "terminalnode.h"

TerminalNode::TerminalNode()
{
    hovered = false;
}
//outer most edge of our shape
TerminalNode::TerminalNode(std::string text)
{
    hovered = false;
    nodetext = QString::fromStdString(text);
}

QRectF TerminalNode::boundingRect() const
{
    return QRectF(0,0,100,50);
}

void TerminalNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    painter ->fillRect(rec,brush);
    painter -> setFont(QFont("Arial",12,-1,true));
    painter ->drawText(5,25,nodetext);
    painter->drawEllipse(rec);
}

void TerminalNode::mouseHoverEvent(QGraphicsSceneMouseEvent *event)
{
    hovered = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void TerminalNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    hovered = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
