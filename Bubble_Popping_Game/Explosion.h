#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Explosion:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public :
    Explosion(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif
