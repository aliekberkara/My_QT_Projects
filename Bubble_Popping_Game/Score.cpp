#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    setPlainText(QString("Vurulan Balon Sayısı: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Score::replication(){
    score++;
    setPlainText(QString("Vurulan Balon Sayısı: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}
