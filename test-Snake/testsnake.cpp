#include "testsnake.h"
#include "ui_testsnake.h"

testsnake::testsnake(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::testsnake)
{
    ui->setupUi(this);
    graphicScene = new QGraphicsScene(ui->graphicsView);
    graphicScene->setBackgroundBrush(Qt::black);
    ui->graphicsView->setScene(graphicScene);
    ui->graphicsView->setAlignment(Qt::AlignTop|Qt::AlignLeft);

    head = new Head(0,0,20,20);
    graphicScene->addItem(head);
    apple = new Apple(0,0,20,20);
    apple->randomizePosition(head, tail.getTail());
    graphicScene->addItem(apple);

    isInGame = false;
    point = 0;

    QFont gameOverFont("Fantasy", 30);
    QPushButton *gameOver = new QPushButton("GameOver!");
    gameOver->setStyleSheet("background-color : transparent; color : cyan");
    gameOver->setFont(gameOverFont);

    QFont replayFont("Fantasy", 15);
    QPushButton *replay = new QPushButton("Replay!");
    replay->setStyleSheet("background-color : transparent; color : orange");
    replay->setFont(replayFont);

    GraphicGameOver = graphicScene->addWidget(gameOver);
    GraphicReplay = graphicScene->addWidget(replay);
    GraphicGameOver->setPos( 200 - gameOver->width()/2, 100);
    GraphicReplay->setPos(200 - replay->width()/2, 160);
    GraphicGameOver->setZValue(1);
    GraphicReplay->setZValue(1);

    GraphicGameOver->setVisible(false);
    GraphicReplay->setVisible(false);

    QObject::connect(replay, &QPushButton::clicked, this, &testsnake::onReplay);

}

void testsnake::onReplay(){
    head->setPos(0,0);
    tail.initialize();
    GraphicGameOver->setVisible(false);
    GraphicReplay->setVisible(false);
    bufferDirection = null;
    direction = null;
    isInGame = false;
    point = 0;
    setFocus();

}

bool testsnake::isAWall(){
    bool status = true;
    QPointF pos = head->scenePos();
    switch (direction) {
        case right:{
            if(pos.x() < 380){
                status = false;
            }
            break;
        }case left:{
            if(pos.x() > 0){
                status = false;
            }
            break;
        }case up:{
            if(pos.y() > 0){
                status = false;
            }
            break;
        }case down:{
            if(pos.y() < 380){
                status = false;
            }
            break;
        }
    }

    return status;
}

bool testsnake::isAnApple(){
    bool status = false;
    QPointF positionHead = head->scenePos();
    QPointF positionApple = apple->scenePos();
    switch (direction) {
        case right:{
            if(positionHead.x()+20 == positionApple.x() && positionHead.y() == positionApple.y()){
                status = true;
            }
            break;
        }case left:{
            if(positionHead.x()-20 == positionApple.x() && positionHead.y() == positionApple.y()){
                status = true;
            }
            break;
        }case up:{
            if(positionHead.x() == positionApple.x() && positionHead.y()-20 == positionApple.y()){
                status = true;
            }
            break;
        }case down:{
            if(positionHead.x() == positionApple.x() && positionHead.y()+20 == positionApple.y()){
                status = true;
            }
            break;
        }
    }

    return status;
}

bool testsnake::isATail(){
    bool status = false;
    QPointF positionHead = head->scenePos();
    std::vector<QGraphicsRectItem*>::iterator it = tail.getTail().begin();
    while(it != tail.getTail().end() && status == false){
        switch (direction) {
            case right:{
                if(positionHead.x()+20 == (*it)->x() && positionHead.y() == (*it)->y()){
                    status = true;
                }
                break;
            }case left:{
                if(positionHead.x()-20 == (*it)->x() && positionHead.y() == (*it)->y()){
                    status = true;
                }
                break;
            }case up:{
                if(positionHead.x() == (*it)->x() && positionHead.y()-20 == (*it)->y()){
                    status = true;
                }
                break;
            }case down:{
                if(positionHead.x() == (*it)->x() && positionHead.y()+20 == (*it)->y()){
                    status = true;
                }
                break;
            }
        }
        it++;
    }

    return status;
}

void testsnake::move(){
    if(!isAWall() && !isATail()){
        if(isAnApple()){
            point++;
            ui->point->setText(QString::number(point));
            graphicScene->addItem(tail.pushTail(head->pos()));
            apple->randomizePosition(head, tail.getTail());
        }else{
            QPointF positionHead = head->pos();
            tail.updateTailPosition(positionHead);
        }

        head->moveHead(direction);

        bufferDirection = direction;
    }else if(isInGame){
        GraphicGameOver->setVisible(true);
        GraphicReplay->setVisible(true);
        isInGame = false;
    }
}
void testsnake::keyPressEvent(QKeyEvent *event){

    if(!isInGame && !GraphicGameOver->isVisible()){
        isInGame = true;
        timerId = startTimer(125);
    }

    switch (event->key()) {
        case Qt::Key_Right:{
            if(bufferDirection != left)
                direction = right;
            break;
        }case Qt::Key_Left:{
            if(bufferDirection != right)
                direction = left;
            break;
        }case Qt::Key_Up:{
            if(bufferDirection != down)
                direction = up;
            break;
        }case Qt::Key_Down:{
            if(bufferDirection != up)
                direction = down;
            break;
        }
    }
}
void testsnake::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    if (isInGame) {
        move();
    }else{
        killTimer(timerId);
    }
}

testsnake::~testsnake()
{
    delete head;
    delete apple;
    delete GraphicReplay;
    delete GraphicGameOver;
    delete ui;
}

