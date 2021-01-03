#ifndef SNAKETAIL_H
#define SNAKETAIL_H

#include <vector>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <exception>
#include <iostream>

class SnakeTail
{
public:
    SnakeTail();
    ~SnakeTail();

    QGraphicsRectItem* pushTail(QPointF position);
    void updateTailPosition(QPointF& positionHead);
    void initialize();

    std::vector<QGraphicsRectItem*>& getTail();
private:
    std::vector<QGraphicsRectItem*> tail;
};

#endif // SNAKETAIL_H
