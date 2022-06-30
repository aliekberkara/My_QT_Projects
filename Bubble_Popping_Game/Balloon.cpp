#include "Balloon.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"
#include <QKeyEvent>
#include "Explosion.h"
#include <QMouseEvent>
#include <QtWidgets>

extern Game * game;

Balloon::Balloon(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    QString paths[] = {
        ":/images/img/0.png",
        ":/images/img/1.png",
        ":/images/img/2.png",
        ":/images/img/3.png",
        ":/images/img/4.png",
        ":/images/img/5.png",
        ":/images/img/6.png"
    };

    int random_num = rand()%1200;
    setPos(random_num, 0);

    setPixmap(QPixmap(paths[rand() % 7]).scaled(50,50));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(25);
}

void Balloon::move()
{
    setPos(x(), y()+10);
    if(pos().y()>=720){
        game->escape->reduction();
        scene()->removeItem(this);
        delete this;
    }
}

void Balloon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::MouseButton::LeftButton){
        Explosion * explosion = new Explosion();
        explosion->setPos(x(), y());
        scene()->addItem(explosion);
    }
}

