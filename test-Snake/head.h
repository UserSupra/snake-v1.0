#ifndef HEAD_H
#define HEAD_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include "EnumDirection.h"

class Head : public QGraphicsRectItem
{
public:
    Head(qreal x,qreal y,qreal w,qreal h);
    void moveHead(Direction direction);
};

#endif // HEAD_H
