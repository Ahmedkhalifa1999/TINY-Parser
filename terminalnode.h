#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
class TerminalNode : public QGraphicsItem
{
public:
    TerminalNode();
    TerminalNode(std::string text);

     //outer bounding for the object
    QRectF boundingRect() const;
    //Important to paint the object
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //value to tell us if object is pressed or not
    bool hovered;
    QString nodetext;
protected:
    void mouseHoverEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // TERMINALNODE_H
