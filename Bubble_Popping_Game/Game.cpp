#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Balloon.h"
#include <QBrush>
#include <QImage>



Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720);
    setBackgroundBrush(QImage(":/images/img/arkaplan.png"));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);

    player = new Player();
    scene->addItem(player);

    score = new Score();
    score->setPos(score->x()+950, score->y());
    scene->addItem(score);

    duration=new Duration();
    duration->setPos(duration->x(),duration->y());
    scene->addItem(duration);

    escape = new Escape();
    escape->setPos(escape->x()+950, escape->y()+25);
    scene->addItem(escape);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(appear()));
    timer->start(1000);

    show();
}
