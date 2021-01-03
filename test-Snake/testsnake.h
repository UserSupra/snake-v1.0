#ifndef TESTSNAKE_H
#define TESTSNAKE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPointF>
#include <QFont>
#include <QPushButton>

#include <iostream>

#include <QGraphicsProxyWidget>

#include <snaketail.h>
#include <apple.h>
#include <QString>
#include "head.h"
#include "EnumDirection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class testsnake; }
QT_END_NAMESPACE

class testsnake : public QWidget
{
    Q_OBJECT

public:
    testsnake(QWidget *parent = nullptr);
    ~testsnake();

protected:
    void keyPressEvent(QKeyEvent *e);
private slots:
    void onReplay();
private:
    QGraphicsProxyWidget *GraphicGameOver;
    QGraphicsProxyWidget *GraphicReplay;

    Ui::testsnake *ui;
    QGraphicsScene *graphicScene;

    Direction direction;
    Direction bufferDirection;

    Head *head;
    Apple *apple;
    SnakeTail tail;

    bool isInGame;
    int point;

    bool isAWall();
    bool isAnApple();
    bool isATail();

    void move();
    void timerEvent(QTimerEvent *e);
    int timerId;
};
#endif // TESTSNAKE_H
