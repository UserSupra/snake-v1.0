#include "apple.h"

Apple::Apple(qreal x,qreal y,qreal w,qreal h):QGraphicsRectItem(x,y,w,h)
{
    QBrush color(Qt::red);
    QPen border(Qt::NoPen);
    setBrush(color);
    setPen(border);
}

void Apple::randomizePosition(QGraphicsRectItem *head, std::vector<QGraphicsRectItem*>& tail){
    srand (time(NULL));

    int randomX;
    int randomY;
    bool isOk;
    do{
        isOk = true;
        randomX = 20*(rand() % 20);
        randomY = 20*(rand() % 20);
        if(head->x() != randomX || head->y() != randomY){
            std::vector<QGraphicsRectItem*>::iterator iterator = tail.begin();
            while(iterator != tail.end()){
                if((*iterator)->x() != randomX || (*iterator)->y() != randomY){
                    iterator++;
                }else{
                    isOk = false;
                    break;
                }
            }
        }else{
            isOk = false;
        }
    }while(isOk == false);
    setX(randomX);
    setY(randomY);
}

Apple::~Apple(){
}
