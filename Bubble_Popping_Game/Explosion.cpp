#include "Explosion.h"
#include "Balloon.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"
#include <QThread>

extern Game * game;

Explosion::Explosion(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/img/patlama.png").scaled(50,50));

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Explosion::move()
{
    QList<QGraphicsItem *> explosion = collidingItems();

    for(int i=0, n=explosion.size(); i<n; ++i){
        if(typeid(*(explosion[i])) == typeid(Balloon)){

            game->score->replication();

            scene()->removeItem(explosion[i]);
            scene()->removeItem(this);

            delete explosion[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()+10);
    if(pos().y()>720){
        scene()->removeItem(this);
        delete this;
    }
}
