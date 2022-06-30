#ifndef ESCAPE_H
#define ESCAPE_H

#include <QGraphicsTextItem>

class Escape: public QGraphicsTextItem{
public:
    Escape(QGraphicsItem * parent=0);
    void reduction();
    int getEscapes();
private:
    int escape;
};

#endif
