#ifndef APPLE_H
#define APPLE_H

#include <stdlib.h>
#include <time.h>

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>

class Apple:public QGraphicsRectItem{
public:
    Apple(qreal x, qreal y,qreal w,qreal h);
    ~Apple();

    void randomizePosition(QGraphicsRectItem *head, std::vector<QGraphicsRectItem*>& tail);
};



#endif // APPLE_H
