#ifndef BALLOON_H
#define BALLOON_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QMouseEvent>

class Balloon : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public :
    Balloon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
public slots:
    void move();
};

#endif
