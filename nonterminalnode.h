#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
class NonTerminalNode : public QGraphicsItem
{
public:
    NonTerminalNode();
    NonTerminalNode(std::string text);

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

#endif // NONTERMINALNODE_H
