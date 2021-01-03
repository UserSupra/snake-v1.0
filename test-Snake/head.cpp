#include "head.h"

Head::Head(qreal x,qreal y,qreal w,qreal h):QGraphicsRectItem(x,y,w,h)
{
    QBrush color(Qt::yellow);
    QPen border(Qt::NoPen);
    setBrush(color);
    setPen(border);
}
void Head::moveHead(Direction direction){
    switch (direction) {
        case right:{
            moveBy(20,0);
            break;
        }case left:{
            moveBy(-20,0);
            break;
        }case up:{
            moveBy(0,-20);
            break;
        }case down:{
            moveBy(0,20);
            break;
        }
    }
}
