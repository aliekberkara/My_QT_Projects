#ifndef DURATION_H
#define DURATION_H

#include <QGraphicsTextItem>

class Duration: public QGraphicsTextItem{
public:
    Duration(QGraphicsItem * parent=0);
    void reduction();
    int getDuration();
private:
    int duration;
};
#endif
