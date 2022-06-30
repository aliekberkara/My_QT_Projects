#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Explosion.h"
#include "Balloon.h"
#include <QMouseEvent>
#include <QtWidgets>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

}

void Player::appear(){
    Balloon * balloon = new Balloon();
    scene()->addItem(balloon);
}
