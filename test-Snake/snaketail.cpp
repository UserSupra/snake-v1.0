#include "snaketail.h"

SnakeTail::SnakeTail()
{
}

QGraphicsRectItem* SnakeTail::pushTail(QPointF position){
    QGraphicsRectItem *rec = new QGraphicsRectItem(0,0,20,20);
    rec->setPos(position);
    QBrush color(Qt::yellow);
    QPen border(Qt::NoPen);
    rec->setBrush(color);
    rec->setPen(border);

    tail.push_back(rec);

    return rec;
}

void SnakeTail::updateTailPosition(QPointF& positionHead){
    if(tail.size() != 0){
        if(tail.size() > 1){
            std::vector<QGraphicsRectItem*>::iterator it = tail.begin();
            while(it+1 != tail.end()){
                ( *it )->setPos( (*(it+1))->pos() );
                it++;
            }
        }
        tail.back()->setPos(positionHead);
    }
}

void SnakeTail::initialize(){
    std::vector<QGraphicsRectItem*>::iterator it = tail.begin();
    while(it != tail.end()){
        delete( *it );
        it++;
    }
    tail.clear();
}

std::vector<QGraphicsRectItem*>& SnakeTail::getTail(){
    return tail;
}

SnakeTail::~SnakeTail()
{
    std::vector<QGraphicsRectItem*>::iterator it = tail.begin();
    while(it != tail.end()){
        delete( *it );
        it++;
    }
}

