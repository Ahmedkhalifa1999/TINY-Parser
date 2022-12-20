#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QtCore>
#include <QGraphicsScene>
#include <QtGui>
#include "nonterminalnode.h"
#include "terminalnode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

    QGraphicsScene *scene;

    NonTerminalNode *nonTerminalNode;
    TerminalNode *terminalNode;
};
#endif // DIALOG_H
